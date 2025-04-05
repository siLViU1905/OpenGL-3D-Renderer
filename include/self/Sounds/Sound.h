#ifndef __SOUND_H__
#define __SOUND_H__
#include "../../AL/al.h"
#include "../../AL/alc.h"
#include <string>
#include <vector>
#include <unordered_map>
#include "../Objects/vec3.h"

enum class SoundStatus
{
    Stopped,
    Paused,
    Playing
};

class Sound
{
    std::string filename;

    ALuint source;
    ALuint buffer;

    SoundStatus status;
    bool m_isValid;

    static std::unordered_map<std::string, ALuint> s_buffers;

    static ALuint loadSoundFile(const char* filename);
public:
    Sound();
    ~Sound();

    bool isValid() const;

    bool loadFromFile(const char* filename);

    bool play();
    void pause();
    void stop();

    SoundStatus getStatus() const;
    void setVolume(float volume);
    float getVolume() const;
    void setPitch(float pitch);
    float getPitch() const;
    void setPosition(vec3 position);
    void setLooping(bool looping);
    bool isLooping() const;

};

#endif // __SOUND_H__