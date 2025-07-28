#include "AudioSystem.h"
#include <tuple>
#include "Utils/StringConvert.h"

void AudioSystem::Initialize()
{
	CheckError(FMOD::System_Create(&fmodSystem));
	CheckError(fmodSystem->init(128, FMOD_INIT_NORMAL, nullptr));
}

void AudioSystem::Register(const std::vector<SoundInfo>& soundlist)
{
	//for (const auto& it : soundlist)
	//{
	//	const std::wstring& id = std::get<0>(it);
	//	const std::wstring& path = std::get<1>(it);
	//	FMOD_MODE mode = std::get<2>(it);

	//	//�ߺ�����
	//	if(sounds.count(id)) continue;

	//	FMOD::Sound* sound = nullptr;
	//	fmodSystem->createSound(StringConvert::WstringToString(path).c_str(), mode, nullptr, &sound);
	//	sounds[id] = sound;
	// struct ��ü ����� �ڵ�
	//}
	for (const auto& it : soundlist)
	{
		if (sounds.count(it.id)) continue;

		FMOD::Sound* sound = nullptr;
		fmodSystem->createSound(StringConvert::WstringToString(it.id).c_str(), it.mode, nullptr, &sound);
		sounds[it.id] = sound;
	}
}


void AudioSystem::PlaySound(const std::wstring& id)
{
	CheckError(fmodSystem->playSound(sounds[id], muteGroup, false, &channel));
}


void AudioSystem::UnRegister()
{
	for (auto& it : sounds) {
		it.second->release();
		it.second = nullptr;
	}
	//Fmod�� release�� �����ؾ��� , delete ���� Fmod ���� ���ҽ� �ջ� ��������
	sounds.clear();
}

void AudioSystem::Setvolume(float state)
{
	muteGroup->setVolume(state);
}
