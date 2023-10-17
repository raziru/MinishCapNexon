#pragma once

#define MAX_CHANNEL 10//음악 겹칠수 있는 한도

struct SoundInfo
{
	~SoundInfo()
	{
		sound->release();
	}

	  Sound* sound;
	Channel* channel;
};

class SoundManager : public Singleton<SoundManager>
{
	friend class Singleton;
private:
	SoundManager();
	~SoundManager();

public:
	void Update();

	void AddSound(string key, string path, bool stream = false);//stream: 음악이 끝나면 다시틀어주는 배경음악용

	void   Play(string key, float volume = 0.1f);
	void   Stop(string key);
	void  Pause(string key);
	void Resume(string key);

private:
	map<string, SoundInfo*> sounds;

	System* system;
};
