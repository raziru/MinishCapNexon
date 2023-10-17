#include "Framework.h"
#include "Environment.h"


Environment::Environment()
{

    projectionMatrix = XMMatrixOrthographicOffCenterLH
    (
        0.0f, WIN_WIDTH,  //X축
        0.0f, WIN_HEIGHT, //Y축
        0.0f, 1.0f        //Z축 - near frame(z), far frame(z) 화면 z축 한도
        // 범위를 넘으면 그리지 않는다.
    );
    //orthographic:, offcenter: 왼쪽 아래가 (0,0) lefthand: 왼손좌표계 ->시계방향으로 그려야 표현

 
	projectionBuffer = new MatrixBuffer();

    CreateSamplerState();
    CreateBlendState();
    CreateRasterizerState();
}

Environment::~Environment()
{
    delete projectionBuffer;


      alphaBlend->Release();
    samplerState->Release();
}

void Environment::CreateSamplerState()
{
    D3D11_SAMPLER_DESC desc = {};

    desc.Filter          = D3D11_FILTER_MIN_MAG_MIP_POINT;
    desc.AddressU        = D3D11_TEXTURE_ADDRESS_WRAP;//Wrap: 그대로 입력, mirror: 거울 반전, clamp: 한번 그리고 더이상 안그리 -- 잘안쓴다.
    desc.AddressV        = D3D11_TEXTURE_ADDRESS_WRAP;
    desc.AddressW        = D3D11_TEXTURE_ADDRESS_WRAP;
    desc.ComparisonFunc  = D3D11_COMPARISON_NEVER;
    desc.MinLOD          = 0;
    desc.MaxLOD          = D3D11_FLOAT32_MAX;
    //Level of Detail
    
    DEVICE->CreateSamplerState(&desc, &samplerState);
    DC->PSSetSamplers(0, 1, &samplerState);
}

void Environment::CreateBlendState()
{
    //색은 Alpha를 비중으로 합한다.
    D3D11_BLEND_DESC desc = {};
    desc.AlphaToCoverageEnable  = false;
    desc.IndependentBlendEnable = false;
    desc.RenderTarget[0].BlendEnable           = true;
    desc.RenderTarget[0].SrcBlend              = D3D11_BLEND_SRC_ALPHA;
    desc.RenderTarget[0].DestBlend             = D3D11_BLEND_INV_SRC_ALPHA;
    desc.RenderTarget[0].BlendOp               = D3D11_BLEND_OP_ADD;
    desc.RenderTarget[0].SrcBlendAlpha         = D3D11_BLEND_ONE;
    desc.RenderTarget[0].DestBlendAlpha        = D3D11_BLEND_ZERO;
    desc.RenderTarget[0].BlendOpAlpha          = D3D11_BLEND_OP_ADD;
    desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

    DEVICE->CreateBlendState(&desc, &alphaBlend);
    DC->OMSetBlendState(alphaBlend, nullptr, D3D11_DEFAULT_SAMPLE_MASK);
}

void Environment::CreateRasterizerState()
{
    D3D11_RASTERIZER_DESC desc = {};
    desc.FillMode = D3D11_FILL_SOLID;
    desc.CullMode = D3D11_CULL_NONE;
    DEVICE->CreateRasterizerState(&desc, &rasterizerState);
    DC->RSSetState(rasterizerState);


}

void Environment::Update()
{
}

void Environment::Set()
{
    projectionBuffer->SetData(projectionMatrix);

    projectionBuffer->VSSetBuffer(2);
}




