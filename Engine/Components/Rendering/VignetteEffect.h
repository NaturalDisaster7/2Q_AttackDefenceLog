#pragma once
#include "pch.h"
#include "Components/Rendering/RenderComponent.h"

/* 25.08.10 | �ۼ��� : �̼�ȣ
* ��� : ���Ʈ ȿ���� �̹����� ���� ��Ű�� ������Ʈ
���� : �ش� ȿ�� ������ �̹����� �������� ���߿� ��µ�

*/
// <example>
// #include "TestVignetteObject.h"
// #include "Components/Base/GameObject.h"
// #include "Application/AppPaths.h"
// 
// void TestVignetteObject::OnCreate()
// {
// 	vignette = owner->AddComponent<VignetteEffect>();
// 	bitmap = owner->AddComponent<BitmapRenderer>();
// }
// 
// void TestVignetteObject::OnStart()
// {
// 	bitmap->CreateBitmapResource(Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"\\..\\..\\Resource\\Mouse\\testB.png");
// 	vignette->SetBitmap(bitmap->GetResource()->GetBitmap().Get());
// 	vignette->SetColor({ 1.0f, 0.0f,0.0f,1.0f });
// 	vignette->SetEffectSize(0.8f);
// 	vignette->SetStrength(0.4f);
// 
// 	vignette->SetOrderInLayer(10000);
// }
// </example>

/// <summary>
/// Vignette ȿ���� bitmap �̹����� ���� ��Ű�� ������Ʈ
/// </summary>
class VignetteEffect : public RenderComponent
{
public:
	void OnCreate() override;
	void OnStart() override;
	void Render(D2DRenderManager* manager);

	/// <summary>
	/// ȿ���� ���� ��ų ��Ʈ���� �����ϴ� �Լ�
	/// </summary>
	void SetBitmap(ID2D1Bitmap1* pBitmap);

	/// <summary>
	/// ȿ�� ũ�⸦ �����ϴ� �Լ� ( ���� Ŭ���� ȿ���� ������ Ŀ�� )
	/// </summary>
	void SetEffectSize(float value);

	/// <summary>
	/// ȿ���� ������ �����ϴ� �Լ� ( ���� Ŭ���� ȿ���� �� �����ϰ� ���� )
	/// </summary>
	void SetStrength(float value);

	/// <summary>
	/// ȿ���� ���� �����ϴ� �Լ� ( RGBA )
	/// </summary>
	/// <param name="color4F">D2D1_VECTOR_4F�� 0.0f ~ 1.0f ��</param>
	void SetColor(D2D1_VECTOR_4F color4F);
private:
	Microsoft::WRL::ComPtr<ID2D1Effect> vignetteEffect;
	float effectSize = 1.0f;
	float strength = 1.0f;
	D2D1_VECTOR_4F color{};

	ID2D1Bitmap1* refBitmap;
};

