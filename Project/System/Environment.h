#pragma once
class Environment:public Singleton<Environment>
{
public:
	Environment();
	~Environment();

	void Update();

	void Set();

	void CreateSamplerState();
	void CreateBlendState();
	void CreateRasterizerState();


private:
	XMMATRIX projectionMatrix;

	
	MatrixBuffer* projectionBuffer;


	ID3D11SamplerState* samplerState;

	ID3D11BlendState* alphaBlend;

	ID3D11RasterizerState * rasterizerState;
};

