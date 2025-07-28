#pragma once
#include "Utils/Singleton.h"
#include <unordered_map>
#include "External/FMod/fmod.hpp"
#include "External/FMod/fmod_errors.h"
#include <string>
#include <iostream>
#include "SoundDatas.h"

/*
FMOD_RESULT playSound(
	FMOD::Sound *sound,         // [1] ����� ���� ��ü
	FMOD::ChannelGroup *group,  // [2] ���� ä�� �׷� (nullptr�̸� �⺻ �׷�), ������Ұ� ���� ����� ������ �Ѱ��� �׷쿡 �������
	bool paused,                // [3] �Ͻ����� ���·� �������� ����
	FMOD::Channel **channel     // [4] ���带 ������ �� �ִ� ä�� ������ (��¿�)
);

AudioSystem�� ��� bgm�� �ѹ��� ��ϰ���
����Ҷ��� struct ��ü�� ���� �� ��ü�� ��� ( Datas���� SoundDatas���)
��� ����� muteGroup���� ����ϱ⶧���� Setvolume �Լ��� ���� ��ü ���� ũ�� ���� ����
*/


class AudioSystem : public Singleton<AudioSystem>
{
public:

	void Initialize();
	void Register(const std::vector<SoundInfo>& sounds);
	void PlaySound(const std::wstring& id);
	void UnRegister();

	void Setvolume(float state);

	static void CheckError(FMOD_RESULT result) {
		if (result != FMOD_OK) {
			std::cerr << "FMOD Error: " << FMOD_ErrorString(result) << std::endl;
			exit(-1);
		}
	}

private:
	FMOD::System* fmodSystem = nullptr;
	FMOD::Channel* channel = nullptr;
	std::unordered_map<std::wstring, FMOD::Sound*> sounds;
	FMOD::ChannelGroup* muteGroup;

};

