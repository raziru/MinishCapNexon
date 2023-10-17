#pragma once
class Stage
{
public:
	Stage(Link* link);
	virtual ~Stage() = default;

	virtual void Update();
	virtual void Render();

	virtual void SetOnEvents() =0;
	virtual void SetStage(Link* link);

	BackGround* StageWorld() { return background; }

	bool CheckClear();

	void MonsterCollision();
	void TileCollision();
	void BackgroundCollision();
	

	void PushLink(Link* link, Tile* tile);
	void HideLink(Link* link, Tile* tile);
	void UnhideLink(Link* link, Tile* tile);

	void SpanwMonsterTile(Tile* tile);
	void ChangeBackgroundTile(Tile* tile);
	void FallLinkTile(Link* link, Tile* tile);
	void ChangeableFallTileOn(Link* link, Tile* tile);
	void ChangeableFallTileOff(Link* link, Tile* tile);
	void WallTile(Link* link, Tile* tile);
	void ClearTile(Tile* tile);

	bool& IsClear() { return isClear; }

protected:
	Link* link = nullptr;

	BackGround* background = nullptr;
	vector<BackGround*> backgrounds;

	TileManager* tiles = nullptr;

	MonsterManager* monsters = nullptr;

	vector <function<void()>> Events;

	vector<Vector2> monsterPositions;
	vector<Vector2> tilePositions;
	Vector2 oldPosition;

	bool isClear = true;

};



