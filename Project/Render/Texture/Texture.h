#pragma once
class Texture
{
private:
	Texture( ID3D11ShaderResourceView* srv, ScratchImage& image);
	~Texture();
public:

	void SetPS(UINT slot = 0);

	Vector2 GetSize() { return Vector2(image.GetMetadata().width, image.GetMetadata().height); }

	static Texture* GetTexture(wstring file);
	static void Delete();

private:
	ScratchImage image;

	ID3D11ShaderResourceView* srv;

	static map<wstring, Texture*> textures;


};



