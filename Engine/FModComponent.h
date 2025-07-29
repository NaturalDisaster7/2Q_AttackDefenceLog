#pragma once
#include "Components/Base/Component.h"
#include "External/FMod/fmod.hpp"
#include "External/FMod/fmod_errors.h"
#include <iostream>


/*
설명

생성시
반복 재생 효과음	FMOD_DEFAULT | FMOD_LOOP_NORMAL
루프 없는 효과음	FMOD_DEFAULT | FMOD_LOOP_OFF (또는 그냥 FMOD_DEFAULT)
루프 재생 BGM		FMOD_CREATESTREAM | FMOD_LOOP_NORMAL

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