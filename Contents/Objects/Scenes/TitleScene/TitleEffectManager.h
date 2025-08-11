#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/BitmapRenderer.h"

struct EffectProgress {
	BitmapRenderer* bitmapRenderer;
	float alpha = 0.0f;
	Vector2 pos = { 0,0 };
};


class TitleEffectManager : public MonoBehavior
{
public:
	void OnStart() override;
	void OnUpdate() override;
	void OnDestroy() override;
	D2D1_SIZE_F GetSize() { return size; };

	void Start();

protected:
	D2D1_SIZE_F size;
	BitmapRenderer* bitmapRenderer;

	std::vector<EffectProgress> effectProgress;

	bool isPlay = false;

	float progress = 0.0f; // 0~1 ����ȭ ��, �̰� ������� �ִϸ��̼� + ���� ���ư�
};

