#include "AudioSystem.h"

void AudioSystem::Initialize()
{

}

//void AudioSystem::Register(const std::vector<std::tuple<std::wstring, std::wstring, FMOD_MODE>>& sounds)
//{
//	if (sounds.find(id) == sounds.end()) return;
//	//중복방지
//
//	FMOD::Sound* sound = nullptr;
//	fmodSystem->createSound(path.c_str(), mode, nullptr, &sound);
//	sounds[id] = sound;
//}


void AudioSystem::PlaySound(const std::string& id, float volume)
{
	//CheckError(fmodSystem->createSound(path.c_str(), playType, nullptr, &sound));
	//CheckError(fmodSystem->playSound(sound, nullptr, false, &channel));
}

//const std::vector<std::pair<std::wstring, std::wstring>>& pair
void AudioSystem::UnRegister()
{

}
