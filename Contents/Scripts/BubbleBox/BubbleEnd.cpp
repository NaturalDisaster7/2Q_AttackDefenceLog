#include "BubbleEnd.h"
#include "Components/Base/GameObject.h"
#include "Scene/SceneManager.h"
#include "Application/AppPaths.h"
#include "../Engine/Utils/GameTime.h"
#include "scripts/GameManager.h"
#include "../Engine/Systems/AudioSystem.h"

void BubbleEnd::OnUpdate()
{
	if (StartCheck) CheckInput();
}

void BubbleEnd::OnCreate()
{
	owner->SetRenderLayer(EngineData::UI);
	owner->GetTransform().SetUnityCoords(false);
	owner->GetTransform().SetPosition(-200.0f, -100.0f);


	input = owner->AddComponent<InputSystem>();

	for (int i = 0; i < 9; i++)
	{
		texts.push_back(owner->AddComponent<BitmapRenderer>());

		std::wstring path = L"\\..\\Resource\\Oh\\Ha\\background\\ending\\ending_text\\";
		std::wstring numStr = std::to_wstring(i + 1) + L".png";
		path += numStr;

		texts[i]->CreateBitmapResource(Singleton<AppPaths>::GetInstance().GetWorkingPath() + path);
		texts[i]->SetActive(false);
		texts[i]->SetOrderInLayer(19000);
		texts[i]->SetUseCustomRect(true);
	}

	count = 0;
	texts[count]->SetActive(true);
	timer = 0.0f;

	StartCheck = true;
}

void BubbleEnd::OnStart()
{
	/*Singleton<GameManager>::GetInstance().SetGameState(Pause);*/
	/*Singleton<AudioSystem>::GetInstance().PauseSound();*/
}

void BubbleEnd::OnDestroy()
{
}

void BubbleEnd::CheckInput()
{
	timer += Singleton<GameTime>::GetInstance().GetDeltaTime();
	if (timer > delaytime) // �ð��� �� ��������
	{
		if (Input::leftButtonDown) // ���� Ŭ�� ������
		{
			if (count < 9) // 0 ~ 9�� �ϳ��� �����ϱ�
			{
				texts[count]->SetActive(true);
				count++;
				timer = 0.0f;
			}

			if (count == 9) // 10�� ������ �� ��Ȱ��ȭ�ϰ� ȥ�� ���
			{
				Singleton<SceneManager>::GetInstance().LoadScene(SceneCount::TITLE); // MenuScene���� �̵�
			}
		}
	}

	if (count < 9 && texts[count]->IsActiveSelf() && timer < delaytime) // ������ ������ ����ϱ�
	{
		rectY = texts[count]->GetResource()->GetBitmap()->GetSize().height * timer / delaytime;
		std::cout << rectY << std::endl;
	}

	if (count < 9)
	{
		texts[count]->SetDestRect({ 0, 0, texts[count]->GetResource()->GetBitmap()->GetSize().width, rectY });
		texts[count]->SetSrcRect({ 0, 0, texts[count]->GetResource()->GetBitmap()->GetSize().width, rectY });
	}
}
