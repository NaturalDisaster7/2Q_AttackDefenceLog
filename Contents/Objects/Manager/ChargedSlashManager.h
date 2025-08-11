#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/BitmapRenderer.h"
#include "../Engine/Utils/EventDelegate.h"
#include "../Engine/Components/Logic/InputSystem.h"

/* 8.11. �ѽ±�
* ��¡�� �������� ������ �Ŵ���
* Ư�� ��ǥ >> 1, 3, 7, 9�� ��� �� �ϳ��� ��¡ ������ �����
* �ش� ��ǥ���� ���콺 ��Ŭ���� ���� ���·� ��ٸ��� ��¡��
*
* ��¡�� ����� �� ���¿���
* ������ �������� ���콺�� ������ ��Ŭ���� ���ԵǸ�
*
* ���Ե� ������ ��ǥ�� ��������
* ������͸� �˻��ؼ�, ���⿡ �°� �׾����� ���� + �ð��ȿ� �׾����� ����
*
* ���� ������ �������̶��, ��Ʋ�Ŵ��� ������ �����ߴٰ� �˸�
* ��Ʋ �Ŵ��� ���ο���, �ð� �����Ҳ���.
*
* Ȥ�ö� �ð��� �ʰ��ȴٸ�, ��Ʋ�Ŵ��� ���ο��� Cancelȣ���� �˷��ٲ���(��������Ʈ)
*
* + ����Ʈ�� �־��ֱ� �Ҳ���
*/


struct SlashCache {
	Vector2 pos; // ��ġ����
	Vector2 normal; // ���⺤��
};

class ChargedSlashManager : public MonoBehavior
{
public:
	void OnStart() override;
	void OnUpdate() override;
	void OnDestroy() override;

	//=========================================================
	// �ܺο��� ȣ�����ٲ�

	void SetUpNodePos(const std::vector<Vector2>& vec); // ��� 9���� ��ǥ ���

	void Start(int n); //�ܺο��� �̰� �ҷ��ָ� ������ << ��������Ʈ�� �ܺο��� ���ñ���
	void Cancel(); // �� ����ġ���� �ǹ��� << ��������Ʈ�� �ܺο��� ȣ������ �Լ���


	//=========================================================
	void Reset(); // ���ο��� ������ ������ ���, �ٽ� ó������ �����ִ� �Լ�

	EventDelegate<> onChargeStart; // �ܺο� �ִ� ������Ʈ(���)�� ��Ȱ��ȭ ���ֱ� ���� ��������Ʈ 
	EventDelegate<> onFinisherSuccess; // ���ο��� ������ �����ߴٴ°� �˷��ִ� ��������Ʈ - ��Ʋ�Ŵ��� ���ο� �ִ� �Լ��� �������� ����

protected:
	float radius = 45.0f; //��¡ ����
	float timer = 0.0f; // Ÿ�̸�(������)	
	bool isPlay = false;

	InputSystem* inputSys; // ���� ���ϰ� ����
	BitmapRenderer* bitmapRenderer; // ��������

	D2D1_SIZE_F size;
private:
	Vector2 nowNormalVec = { 0,0 };
	Vector2 nowPos = { 0,0 };

	bool isInside = false; // ���콺�� ��¡���� ���ο� �ִ����� �Ǵ��ϴ� �÷���

	bool isCharged = false; // ��¡ ������ �����ߴ���

	//bool isMoving = false; // ���� �����̰� �ִ��� << ��¡ ���� ������ ������ ���� ����

	//=========================================================
	// [����] ���콺�� ��Ŭ���� ���� ���·�, ��¡ �����ȿ� �ö󰬴�
	bool CheckingMousInside();

	// [���� 1] ��¡ - �� �ȿ� �󸶳� �ӹ����°�, ����� �ӹ����ٸ� ��¡����
	void Charging();

	// [���� 2] ���콺 ��Ŭ�� ���� ��ġ + �ð� ���� ���� Ȯ��
	// ���� ��ġ�� �׻� 4��(�߾�)��带 �������� ���� ���͸� ������, 1 -> 5 Ȥ�� 9 -> 5 ó��
	void Slashing();
	//=========================================================

	//std::vector<Vector2> nodPos;
	std::vector<SlashCache> slashCache;

};

