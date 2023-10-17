#pragma once
class MonsterManager
{
public:
	MonsterManager();
	~MonsterManager();

	void Update();
	void Render();
	
	void SetParent(Transform* parent);

	void SetMonsters(vector<Vector2> positions, UINT count);
	vector<Monster*> GetBody() { return monsters; }

protected:
	vector<Monster*> monsters;
};


