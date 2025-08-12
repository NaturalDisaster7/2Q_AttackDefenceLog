﻿#pragma once
#include "Application/Application.h"
#include "Scene/Scene.h"
#include "Datas/SoundDatas.h"
#include <vector>
#include "Utils/HCURSORChange.h"
#include "Application/AppPaths.h"

namespace SoundApp
{
	class SoundApp : public Application
	{
	public:
		void Initialize() override;
		void Uninitialize() override;

		void CALLBACK MessageProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) override;

	private:
		Scene* testScene{};

		std::vector<SoundResource> soundList;

		std::vector<SoundResource> musiclist = {
		{ L"P_Attack01",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"\\..\\..Resource\\sounds\\attack\\attack_1.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		{ L"P_Attack02", Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"\\..\\..Resource\\sounds\\attack\\attack_2.mp3", FMOD_DEFAULT | FMOD_LOOP_OFF },
		{ L"P_Attack03",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"\\..\\..Resource\\sounds\\attack\\attack_2.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		{ L"P_Break01",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/기세/기세파괴.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		{ L"P_Guard01",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/방어_음/방어_5.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		{ L"P_Guard02",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/방어_음/방어_6.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		{ L"M_Bgm01",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/bgmtest1.mp3",  FMOD_CREATESTREAM | FMOD_LOOP_NORMAL },
		{ L"M_Bgm02",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/bgmtest2.mp3",  FMOD_CREATESTREAM | FMOD_LOOP_NORMAL },
		};

		//std::vector<SoundResource> musiclist = {
		//	{ L"P_Attack01",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/공격/공격_3.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		//	{ L"P_Attack02", Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/attack/attack_4.mp3", FMOD_DEFAULT | FMOD_LOOP_OFF },
		//	{ L"P_Attack03",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/공격/공격_5.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		//	{ L"P_Break01",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/기세/기세파괴.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		//	{ L"P_Guard01",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/방어_음/방어_5.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		//	{ L"P_Guard02",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/방어_음/방어_6.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		//	{ L"M_Bgm01",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/bgmtest1.mp3",  FMOD_CREATESTREAM | FMOD_LOOP_NORMAL },
		//	{ L"M_Bgm02",  Singleton<AppPaths>::GetInstance().GetWorkingPath() + L"/../Resource/sounds/bgmtest2.mp3",  FMOD_CREATESTREAM | FMOD_LOOP_NORMAL },
		//};
		
		HCURSORChange mouse;

		HCURSOR hCursorDefault;
		HCURSOR hCursorClicked;
		bool isMousePressed = false;
	};
}
