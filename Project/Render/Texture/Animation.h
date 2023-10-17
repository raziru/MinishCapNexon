#pragma once
class Animation
{
public:
	Animation(wstring file, UINT frameX, UINT frameY, UINT nFrames = 0, float updateTime = 0.1f);
	Animation(vector<Frame*> frames, float UpdateTime = 0.1f);
	~Animation();

	void Update();
	void Render();

	void Play();
	void Stop();

	void SetAll(bool isLoop = true);
	void SetPart(int start, int end, bool isLoop = true);
	void SetIndex(vector<UINT> indices, bool isLoop = true);

	void SetEndEvent(function<void()> EndEvent) { this->EndEvent = EndEvent; }

	Vector2 Size() { return actions[0]->Size();	}

private:
	vector<Frame*> frames;
	vector<Frame*> actions;

	float updateTime;
	float frameTime;
	float playTime;

	bool isLoop = true;
	bool isPlay= true;

	UINT curPlayIndex = 0;

	function<void()> EndEvent = nullptr;


};


