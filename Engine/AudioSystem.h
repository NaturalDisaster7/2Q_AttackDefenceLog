#pragma once
#include "Utils/Singleton.h"
#include <unordered_map>
#include "External/FMod/fmod.hpp"
#include "External/FMod/fmod_errors.h"
#include <string>
#include <iostream>

/*



*/


class AudioSystem : public Singleton<AudioSystem>
{
public:

	void Initialize();
	void Register(const std::vector<std::tuple<std::wstring, std::wstring, FMOD_MODE>>& sounds);
	void PlaySound(const std::string& id, float volume = 1.0f);
	void UnRegister();



	static void CheckError(FMOD_RESULT result) {
		if (result != FMOD_OK) {
			std::cerr << "FMOD Error: " << FMOD_ErrorString(result) << std::endl;
			exit(-1);
		}
	}

private:
	FMOD::System* fmodSystem = nullptr;
	std::unordered_map<std::string, FMOD::Sound*> sounds;
};

