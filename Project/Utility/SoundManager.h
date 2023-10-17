#pragma once

#define MAX_CHANNEL 10//���� ��ĥ�� �ִ� �ѵ�

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

	void AddSound(string key, string path, bool stream = false);//stream: ������ ������ �ٽ�Ʋ���ִ� ������ǿ�

	void   Play(string key, float volume = 0.1f);
	void   Stop(string key);
	void  Pause(string key);
	void Resume(string key);

private:
	map<string, SoundInfo*> sounds;

	System* system;
};
