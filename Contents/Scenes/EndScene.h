﻿#pragma once
#include "Scripts/SceneCore.h"

class EndScene : public Scene
{
protected:
	void OnEnterImpl() override;
	void OnExitImpl() override;
	void UpdateImpl() override;

private:
	GameObject* inputObj;
	GameObject* trail;
	GameObject* testObj;
	GameObject* SoundEndObj;
};