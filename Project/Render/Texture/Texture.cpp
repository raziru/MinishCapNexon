#include "Framework.h"
#include "Texture.h"

map<wstring, Texture*> Texture::textures = {};
// static은 컴파일할때 생기기때문에 헤더가 아닌 cpp에 초기화해야한다.

Texture::Texture(ID3D11ShaderResourceView* srv, ScratchImage& image)
	:image(move(image)),srv(srv)
{

}

Texture::~Texture()
{
	srv->Release();
}

void Texture::SetPS(UINT slot)
{
	DC->PSSetShaderResources(slot, 1, &srv);
}

Texture* Texture::GetTexture(wstring file)
{
	file = L"_Texture/" + file;
	if (textures.count(file)>0)
	{
		return textures[file];
	}

	ScratchImage image;
	LoadFromWICFile(file.c_str(), WIC_FLAGS_IGNORE_SRGB, nullptr, image);

	ID3D11ShaderResourceView* srv;//(read only) 원본보존하고 돌려쓸 데이터들, 광원, 텍스쳐 등등 입력 받음
	//데이터를 gpu에서 읽기만을 원할때 사용하는 변수(이미지외에 다른 정보도 됨) 

	CreateShaderResourceView(DEVICE, image.GetImages(), image.GetImageCount(), image.GetMetadata(), &srv);

	textures.emplace(file, new Texture(srv, image));

	return textures[file];
}

void Texture::Delete()
{
	for (pair<wstring, Texture*> pair : textures)
	{
		delete pair.second;
	}
	textures.clear();
}
