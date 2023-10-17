#include "Framework.h"
#include "BinaryWriter.h"


BinaryWriter::BinaryWriter(wstring path)
{
	path = L"_TextData/" + path;

	file = CreateFile
	(
		path.c_str(),
		GENERIC_WRITE,
		0, 0,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		nullptr
	);
}

BinaryWriter::~BinaryWriter()
{
	CloseHandle(file);
}

void BinaryWriter::WriteData(int data)
{
	WriteFile(file, &data, sizeof(int), &size, nullptr);
}

void BinaryWriter::WriteData(UINT data)
{
	WriteFile(file, &data, sizeof(UINT), &size, nullptr);

}

void BinaryWriter::WriteData(float data)
{
	WriteFile(file, &data, sizeof(float), &size, nullptr);

}

void BinaryWriter::WriteData(string data)
{
	UINT dataSize = data.size();

	WriteData(dataSize);

	WriteFile(file, data.data(), sizeof(char) * dataSize, &size, nullptr);

}

void BinaryWriter::WriteData(wstring data)
{
	UINT dataSize =  data.size();

	WriteData(dataSize);

	WriteFile(file, data.data(), sizeof(wchar_t) * dataSize, &size, nullptr);
}

void BinaryWriter::WriteData(Vector2 data)
{
	WriteData(data.x);
	WriteData(data.y);

}

void BinaryWriter::WriteData(Vector3 data)
{
	WriteData(data.x);
	WriteData(data.y);
	WriteData(data.z);

}

void BinaryWriter::WriteData(Vector4 data)
{
	WriteData(data.x);
	WriteData(data.y);
	WriteData(data.z);
	WriteData(data.w);
}

void BinaryWriter::WriteData(Transform data)
{
	WriteData(data.scale);
	WriteData(data.rotation);
	WriteData(data.translation);

}

void BinaryWriter::WriteData(void* data, UINT dataSize)
{
	WriteFile(file, data, dataSize, &size, nullptr);
}
