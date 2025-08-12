#pragma once;

#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/BitmapRenderer.h"


//�׳� ����ü �̰��������� ����; ����
//����

struct EffectProgress {
	BitmapRenderer* bitmapRenderer;

	float alpha = 0.0f; // << �̰͵� progress 1 �������� ���� 1�� ����Ǿ���
	// �׷���, ������ ��Ұ� ���� 1�� �����ϴ� ������ �޶����
	// ����

	float startTimingAlpha = 0.0f;
	float targetTimingAlpha = 1.0f; // progress�� ���൵�� ��ġ�ϴ� ������ 1�ΰ���

	//�׷���?
	//������ �����ִ°���
	//�����ϴ� ������ ����� �� �ְڳ�
	//���� Ư�� ���� A���� �����ϰ� ���� �� �ְڳ�?

	// 0.3���� �����ϰ� �ʹٸ�
	// (progress - 0.3f) * (1.0f / (1.0f - 0.3f))
	// �����ϸ�	
	// (progress - startAlpha) * (1.0f / (1.0f - startAlpha))
	// (progress - startAlpha) * (1.0f / (targetAlpha - startAlpha)) << �̷���, progress = StartAlpha ~ targetAlpha�� ��

	Vector2 startPos = { 0,0 }; // �ʱ�ȭ ��ġ
	Vector2 targetPos = { 0,0 }; // progress 1 �϶� ��ġ

	float startTimingPos = 0.0f;
	float targetTimingPos = 1.0f;
	//��������, startPos + (targetPos - startPos) * progress
	//�̷������� �����

	//�� ���������� ���̶�� �ҷ���
};