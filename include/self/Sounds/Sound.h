#ifndef __SOUND_H__
#define __SOUND_H__
#include <AL/al.h>
#include <AL/alc.h>
#include <string>
#include <vector>
#include <unordered_map>

enum class SoundStatus {
   Stopped,
   Paused,
   Playing
};

class Sound {
   public:
       Sound();
       ~Sound();
   
       // Check if sound was properly initialized
       bool isValid() const;
   
       // Load sound from a file
       bool loadFromFile(const std::string& filename);
       
       // Play, pause, stop controls
       bool play();
       void pause();
       void stop();
       
       SoundStatus getStatus() const;
       void setVolume(float volume);
       float getVolume() const;
       void setPitch(float pitch);
       float getPitch() const;
       void setPosition(float x, float y, float z);
       void setLooping(bool looping);
       bool isLooping() const;
   
   private:
       ALuint source;
       ALuint buffer;
       
       SoundStatus status;
       bool m_isValid;
       
       static std::unordered_map<std::string, ALuint> s_buffers;
       
       static ALuint loadSoundFile(const std::string& filename);
   };

#endif // __SOUND_H__