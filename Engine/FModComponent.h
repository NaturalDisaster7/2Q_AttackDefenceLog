#pragma once
#include "Components/Base/Component.h"
#include "External/FMod/fmod.hpp"
#include "External/FMod/fmod_errors.h"
#include <iostream>


/*
����

������
�ݺ� ��� ȿ����	FMOD_DEFAULT | FMOD_LOOP_NORMAL
���� ���� ȿ����	FMOD_DEFAULT | FMOD_LOOP_OFF (�Ǵ� �׳� FMOD_DEFAULT)
���� ��� BGM		FMOD_CREATESTREAM | FMOD_LOOP_NORMAL

*/

class FModComponent : public Component
{
public:
	static void CheckError(FMOD_RESULT result) {
		if (result != FMOD_OK) {
			std::cerr << "FMOD Error: " << FMOD_ErrorString(result) << std::endl;
			exit(-1);
		}
	}

	void Play(const std::string& path);

	/*void OnCreate() override;*/
	void OnStart() override;
	void OnDestroy() override;

	void SetPlayType(FMOD_MODE type) { playType = type; }
	FMOD_MODE GetPlayType() const { return playType; }

private:
	FMOD_MODE playType = FMOD_DEFAULT;
	FMOD::System* fmodSystem = nullptr;
	FMOD::Sound* sound = nullptr;
	FMOD::Channel* channel = nullptr;

};