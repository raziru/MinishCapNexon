#pragma once
class BinaryReader
{
public:
	BinaryReader(wstring path);
	~BinaryReader();

	    int ReadInt();
	   UINT ReadUINT();
	  float ReadFloat();

	 string ReadString();
	wstring ReadWString();

	Vector2 ReadVector2();
	Vector3 ReadVector3();
	Vector4 ReadVector4();

	void ReadData(OUT void** data, UINT dataSize);

	bool Succeeded();
private:
	HANDLE file = nullptr;
	DWORD size = 0;
};
