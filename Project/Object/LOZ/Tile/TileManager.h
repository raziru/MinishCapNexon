#pragma once


class TileManager
{
public:
	TileManager(UINT count);
	~TileManager();

	void Update();
	void Render();

	void SetOnEvents(vector<Vector2> positions, vector<function<void()>>Events ,UINT count);
	vector<Tile*> GetBody() { return tiles; }
private:
	vector<Tile*> tiles;
};


