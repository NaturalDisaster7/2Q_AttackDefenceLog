#include "FModComponent.h"

void FModComponent::Play(const std::string& path)
{
	CheckError(fmodSystem->createSound(path.c_str(), playType, nullptr, &sound));
	CheckError(fmodSystem->playSound(sound, nullptr, false, &channel));
}

void FModComponent::OnStart()
{
	CheckError(FMOD::System_Create(&fmodSystem));
	CheckError(fmodSystem->init(512, FMOD_INIT_NORMAL, nullptr));
}

void FModComponent::OnDestroy()
{
	if (fmodSystem) {
		fmodSystem->close();
		fmodSystem->release();
		fmodSystem = nullptr;
	}
}
