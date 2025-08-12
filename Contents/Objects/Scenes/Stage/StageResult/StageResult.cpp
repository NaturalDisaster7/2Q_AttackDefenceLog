#include "StageResult.h"
#include "Components/Base/GameObject.h"
#include "Scene/SceneManager.h"
#include "Datas/EngineData.h"
#include "Application/AppPaths.h"
#include "Platform/Input.h"

void StageResult::OnCreate()
{
	// winPanel �ʱ�ȭ
	GameObject* winPanelObject = new GameObject();
	winPanelObject->GetTransform().SetUnityCoords(false);
	Singleton<SceneManager>::GetInstance().GetCurrentScene()->AddGameObject(winPanelObject);
	winPanel = winPanelObject->AddComponent<BitmapRenderer>();
	winPanel->CreateBitmapResource(Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"\\..\\Resource\\UI\\Result\\victory_ui_1.png");

	winPanelObject->SetRenderLayer(EngineData::RenderLayer::UI);
	winPanelObject->GetTransform().SetPosition(93.5f, 159.0f);
	winPanel->SetOrderInLayer(100000);

	// winMark �ʱ�ȭ
	GameObject* winMarkObject = new GameObject();
	winMarkObject->GetTransform().SetUnityCoords(false);
	Singleton<SceneManager>::GetInstance().GetCurrentScene()->AddGameObject(winMarkObject);
	winMark = winMarkObject->AddComponent<BitmapRenderer>();
	winMark->CreateBitmapResource(Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"\\..\\Resource\\UI\\Result\\victory_ui_b2.png");

	winMarkObject->SetRenderLayer(EngineData::RenderLayer::UI);
	winMarkObject->GetTransform().SetPosition(93.5f, 159.0f);
	winMark->SetOrderInLayer(100000);

	// defeatPanel �ʱ�ȭ
	GameObject* defeatPanelObject = new GameObject();
	defeatPanelObject->GetTransform().SetUnityCoords(false);
	Singleton<SceneManager>::GetInstance().GetCurrentScene()->AddGameObject(defeatPanelObject);
	defeatPanel = defeatPanelObject->AddComponent<BitmapRenderer>();
	defeatPanel->CreateBitmapResource(Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"\\..\\Resource\\UI\\Result\\defeat_ui_1.png");

	defeatPanelObject->SetRenderLayer(EngineData::RenderLayer::UI);
	defeatPanelObject->GetTransform().SetPosition(93.5f, 159.0f);
	defeatPanel->SetOrderInLayer(100000);

	// defeatMark �ʱ�ȭ
	GameObject* defeatMarkObject = new GameObject();
	defeatMarkObject->GetTransform().SetUnityCoords(false);
	Singleton<SceneManager>::GetInstance().GetCurrentScene()->AddGameObject(defeatMarkObject);
	defeatMark = defeatMarkObject->AddComponent<BitmapRenderer>();
	defeatMark->CreateBitmapResource(Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"\\..\\Resource\\UI\\Result\\defeat_ui_b2.png");

	defeatMarkObject->SetRenderLayer(EngineData::RenderLayer::UI);
	defeatMarkObject->GetTransform().SetPosition(93.5f, 159.0f);
	defeatMark->SetOrderInLayer(100000);
}

void StageResult::OnStart()
{
	winPanel->SetActive(false);
	winMark->SetActive(false);

	defeatPanel->SetActive(false);
	defeatMark->SetActive(false);
}

void StageResult::OnUpdate()
{
	if (Input::leftButtonDown)
	{
		SetPanelState(ResultPanelState::Win);
	}
	
	if (Input::rightButtonDown)
	{
		SetPanelState(ResultPanelState::Defeat);
	}
}

void StageResult::SetPanelState(ResultPanelState state)
{

	switch (state)
	{
	case None:
		winPanel->SetActive(false);
		winMark->SetActive(false);
		defeatPanel->SetActive(false);
		defeatMark->SetActive(false);
		break;
	case Win:
		winPanel->SetActive(true);
		winMark->SetActive(true);
		defeatPanel->SetActive(false);
		defeatMark->SetActive(false);
		break;
	case Defeat:
		winPanel->SetActive(false);
		winMark->SetActive(false);
		defeatPanel->SetActive(true);
		defeatMark->SetActive(true);
		break;
	}
}
