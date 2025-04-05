#include "Sound.h"

#include <iostream>
#include <fstream>
#include "sndfile.h"

std::unordered_map<std::string, ALuint> Sound::s_buffers;

Sound::Sound() : source(0), buffer(0), status(SoundStatus::Stopped), m_isValid(false)
{

    ALCcontext *context = alcGetCurrentContext();
    if (!context)
    {
        ALCdevice *device = alcOpenDevice(nullptr);
        if (!device)
            throw std::runtime_error("Failed to open OpenAL device");

        context = alcCreateContext(device, nullptr);
        if (!context)
        {
            alcCloseDevice(device);
            throw std::runtime_error("Failed to create OpenAL context");
        }
        alcMakeContextCurrent(context);
    }

    alGenSources(1, &source);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR)
        throw std::runtime_error("Failed to generate OpenAL source");

    alSourcef(source, AL_PITCH, 1.0f);
    alSourcef(source, AL_GAIN, 1.0f);
    alSource3f(source, AL_POSITION, 0.0f, 0.0f, 0.0f);
    alSource3f(source, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
    alSourcei(source, AL_LOOPING, AL_FALSE);

    m_isValid = true;
}

Sound::~Sound()
{
    stop();
    if (m_isValid && source)
        alDeleteSources(1, &source);
    
}

bool Sound::isValid() const
{
    return m_isValid;
}

ALuint Sound::loadSoundFile(const char* filename)
{
    
    SF_INFO fileInfo;
    fileInfo.format = 0;
    SNDFILE *file = sf_open(filename, SFM_READ, &fileInfo);

    if (!file)
    throw std::runtime_error("Failed to open sound file");
       
    

    std::vector<short> samples(fileInfo.frames * fileInfo.channels);
    sf_read_short(file, samples.data(), samples.size());
    sf_close(file);

    ALenum format;
    if (fileInfo.channels == 1)
        format = AL_FORMAT_MONO16;
    else if (fileInfo.channels == 2)
        format = AL_FORMAT_STEREO16;
    else
    throw std::runtime_error("Unsupported number of channels");


    ALuint buffer;
    alGenBuffers(1, &buffer);
    if (alGetError() != AL_NO_ERROR)
    throw std::runtime_error("Failed to generate OpenAL buffer");

    alBufferData(
        buffer,
        format,
        samples.data(),
        samples.size() * sizeof(short),
        fileInfo.samplerate);

    if (alGetError() != AL_NO_ERROR)
    {
        alDeleteBuffers(1, &buffer);
        throw std::runtime_error("Failed to fill OpenAL buffer");
    }

    return buffer;
}

bool Sound::loadFromFile(const char* filename)
{
    if (!m_isValid)
        return false;
    
   this->filename = filename;
   
    stop();

    
    alSourcei(source, AL_BUFFER, 0);

    
    auto it = s_buffers.find(filename);
    if (it != s_buffers.end())
        buffer = it->second;
    else
    {
        buffer = loadSoundFile(filename);
        if (buffer == 0)
            return false;
        
        s_buffers[filename] = buffer;
    }

    alSourcei(source, AL_BUFFER, buffer);
    return (alGetError() == AL_NO_ERROR);
}

bool Sound::play()
{
    if (!m_isValid || buffer == 0)
        return false;
    

    alSourcePlay(source);
    if (alGetError() != AL_NO_ERROR)
    return false;
    

    status = SoundStatus::Playing;
    return true;
}

void Sound::pause()
{
    if (m_isValid)
    {
        alSourcePause(source);
        status = SoundStatus::Paused;
    }
}

void Sound::stop()
{
    if (m_isValid)
    {
        alSourceStop(source);
        status = SoundStatus::Stopped;
    }
}

SoundStatus Sound::getStatus() const
{
    if (!m_isValid)
        return SoundStatus::Stopped;
    

    if (status != SoundStatus::Stopped)
    {
        ALint state;
        alGetSourcei(source, AL_SOURCE_STATE, &state);

        switch (state)
        {
        case AL_PLAYING:
            return SoundStatus::Playing;
        case AL_PAUSED:
            return SoundStatus::Paused;
        default:
            return SoundStatus::Stopped;
        }
    }

    return status;
}

void Sound::setVolume(float volume)
{
    if (m_isValid)
        alSourcef(source, AL_GAIN, volume);
    
}

float Sound::getVolume() const
{
    if (!m_isValid)
        return 0.0f;

    ALfloat volume;
    alGetSourcef(source, AL_GAIN, &volume);
    return volume;
}

void Sound::setPitch(float pitch)
{
    if (m_isValid)
        alSourcef(source, AL_PITCH, pitch);
    
}

float Sound::getPitch() const
{
    if (!m_isValid)
        return 1.0f;

    ALfloat pitch;
    alGetSourcef(source, AL_PITCH, &pitch);
    return pitch;
}

void Sound::setPosition(vec3 position)
{
    if (m_isValid)
        alSource3f(source, AL_POSITION, position.x,position.y, position.z);
    
}

void Sound::setLooping(bool looping)
{
    if (m_isValid)
        alSourcei(source, AL_LOOPING, looping ? AL_TRUE : AL_FALSE);
    
}

bool Sound::isLooping() const
{
    if (!m_isValid)
        return false;

    ALint looping;
    alGetSourcei(source, AL_LOOPING, &looping);
    return (looping == AL_TRUE);
}