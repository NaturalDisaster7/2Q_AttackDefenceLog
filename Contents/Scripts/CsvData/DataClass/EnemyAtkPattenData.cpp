﻿#include "EnemyAtkPattenData.h"
#include "Utils/StringConvert.h"


void EnemyAtkPattenData::SetData(std::vector<std::wstring> tmp) {
	if (tmp[0] == L"") return;
	ePatternID = StringConvert::WstringToString(tmp[0].c_str()); // 적의 공격 패턴 ID를 저장
	atkPetternGroup = std::stoi(tmp[1]);       // 적의 공격 그룹을 저장
	eNodepattern = StringConvert::WstringToString(tmp[2].c_str());;  // 적의 노드 패턴을 저장
	eAtkCoolDown = std::stof(tmp[3].c_str()); // 적의 공격 쿨타임을 저장
	if (tmp[4] != L"null")	eComboCoolDown = std::stof(tmp[4].c_str()); // 적의 연격딜레이를 저장
	else eComboCoolDown = 0.0f;
}

void EnemyAtkPattenData::PrintMap() {
	std::cout << "Node_pattern_ID: " << ePatternID << " ";
	std::cout << "atkPetternGroup: " << atkPetternGroup << " ";
	std::cout << "eNodepattern: " << eNodepattern << " ";
	std::cout << "eAtkCoolDown: " << eAtkCoolDown << " ";
	std::cout << "eComboCoolDown: " << eComboCoolDown << std::endl;
}