#include "VignetteEffect.h"
#include "Platform/D2DRenderManager.h"

void VignetteEffect::OnCreate()
{
	renderManager->CreateVignetteEffect(&vignetteEffect);
}

void VignetteEffect::OnStart()
{
	
}

void VignetteEffect::Render(D2DRenderManager* manager)
{
	assert(refBitmap && "VignetteEffect has no bitmap");

	vignetteEffect->SetInput(0, refBitmap);
	vignetteEffect->SetValue(D2D1_VIGNETTE_PROP_COLOR, color); // ??
	vignetteEffect->SetValue(D2D1_VIGNETTE_PROP_TRANSITION_SIZE, effectSize); // ȿ�� ũ��
	vignetteEffect->SetValue(D2D1_VIGNETTE_PROP_STRENGTH, strength); // ���� 
	manager->DrawImage(vignetteEffect.Get()); // vignette ȿ�� ���
}

void VignetteEffect::SetBitmap(ID2D1Bitmap1* pBitmap)
{
	if (!pBitmap) return;

	refBitmap = pBitmap;
}

void VignetteEffect::SetEffectSize(float value)
{
	effectSize = value;
}

void VignetteEffect::SetStrength(float value)
{
	strength = value;
}

void VignetteEffect::SetColor(D2D1_VECTOR_4F color4F)
{
	color = color4F;
}