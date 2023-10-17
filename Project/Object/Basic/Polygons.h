#pragma once
class Polygons:public Transform
{
public:
	Polygons(float radius, UINT sectorCount = 36, Vector4 color = {1,0,0,1});
	~Polygons();

	void Render();

private:
	vector<VertexColor> vertices;
	vector<UINT>         indices;

	VertexBuffer* vertexBuffer;
	IndexBuffer*  indexBuffer;


	VertexShader* vertexShader;

	PixelShader*  pixelShader;

	MatrixBuffer* worldBuffer;
};



