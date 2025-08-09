﻿#include "BettleManager.h"
#include <random>
#include <cmath>
#include "../LiveObject/Player.h"
#include "../LiveObject/Enemy.h"
#include "../LiveObject/LiveObject.h"
#include "AttackPatternManager.h"
#include "Components/Base/GameObject.h"
#include "Components/Base/MonoBehavior.h"



void BettleManager::OnStart() {
	//m_Enemy = owner->GetQuery()->FindByName("Enemytmp")->GetComponent<Enemy>();
	//m_Player = owner->GetQuery()->FindByName("Playertmp")->GetComponent<Player>();
	m_Player->SetSpiritData(m_Enemy->GetSpiritAmount());
	m_PattenManager = owner->GetQuery()->FindByName("AttackPattenManager")->GetComponent<AttackPatternManager>();
}

void BettleManager::OnUpdate() {
	SetStateFormPattern();
	ChangeFinalState();
}

// -> 생성자로 넣어야 할듯?
void BettleManager::SetForStart(AttackPatternManager* pattenManager) {
	m_PattenManager = pattenManager;
}


// 하드코딩용 : 입력 패턴 고정



// 노드 인풋 
void BettleManager::SetInputNode(std::vector<int> InputNode) {
	nowNode = InputNode;
}

//들어온 입력 노드에 따라서 공격, 방어를 처리하는 함수
void BettleManager::SetStateFormPattern() {	
	std::unordered_map<std::string, pattern*> tmpTimePatten = m_PattenManager->TimeOutPatten();  // 패턴이 공격 시간이 지났다면 
	for (const auto& pair : tmpTimePatten) {
		if (pair.second->PattenID.substr(0, 2) == "EP")            //적 패턴일시
		{
			m_Enemy->SetState("Enemy_AttackSuccess");			 // 적 공격 성공
			if (m_Player->GetDefenseRate() >= RandomReturn(100)) {
				m_Player->SetState("Player_Defence");			 // 방어
			}
			else {
				m_Player->SetState("Player_Hit");   			// 피격됨
				m_Player->GetDamage(
					ConvertHPDamageToPos(pair.second->lastPosition, m_Enemy->GetAttack() )); // 상중하 적용한 데미지
			}
			// 기세 계산
			m_Enemy->RestoreSpiritDamage(  
				ConvertSpiritDamageToPos(pair.second->lastPosition, m_Enemy->GetSpiritAttack() )); // 적은기세를 회복
			m_Player->GetSpiritdamage(  
				ConvertSpiritDamageToPos(pair.second->lastPosition, m_Enemy->GetSpiritAttack() ));  // 플레이어는 기세를 잃음
		}
		m_PattenManager->SubPattern(pair.second->PattenID, "Time");
	}

	if (nowNode.size() < 1) return;

	pattern* tmpCorPatten = m_PattenManager->CorrectPattern(nowNode);
	// 입력이 적, 플레이어의 패턴과 맞을 경우
	if (tmpCorPatten != nullptr) {
		if (tmpCorPatten->PattenID.substr(0, 2) == "EP") {
			m_Enemy->SetState("Enemy_AttackSuccess");
			if ((tmpCorPatten->PlayingAttackTime) <= 0.5f) {  // 플레이어가 0.5초 이내에 가드시 -> 패링
				std::vector<int> tmp = tmpCorPatten->NodePatten;
				tmp.erase(std::remove(tmp.begin(), tmp.end(), 0), tmp.end());
				onParry.Invoke(tmp.front());			

				m_Player->SetState("Player_Perry");
				m_Player->RestoreSpiritDamage(
					ConvertSpiritDamageToPos(tmpCorPatten->lastPosition, m_Enemy->GetSpiritAttack() ));  // 기세 변경
				m_Enemy->GetSpiritdamage(
					ConvertSpiritDamageToPos(tmpCorPatten->lastPosition,m_Enemy->GetSpiritAttack() ));
			}
			else {
				std::vector<int> tmp = tmpCorPatten->NodePatten;
				tmp.erase(std::remove(tmp.begin(), tmp.end(), 0), tmp.end());
				onGuard.Invoke(tmp.front());

				m_Player->SetState("Player_Guard");		// 가드
				m_Enemy->RestoreSpiritDamage(
					ConvertSpiritDamageToPos(tmpCorPatten->lastPosition, m_Enemy->GetSpiritAttack() ));  // 기세 변경
				m_Player->GetSpiritdamage(
					ConvertSpiritDamageToPos(tmpCorPatten->lastPosition, m_Enemy->GetSpiritAttack()));
			}
			m_PattenManager->SubPattern(tmpCorPatten->PattenID, "Enemy");
		}
		else {
			m_Player->SetState("Player_AttackSuccess");   // 플레이어의 공격 성공
			m_Player->SetEndAttack();
			if (m_Enemy->GetDefenseRate() >= RandomReturn(100))
				m_Enemy->SetState("Enemy_Defence"); // 방어

			else {
				m_Enemy->SetState("Enemy_Hit"); // 피격됨`
				m_Enemy->GetDamage(
					ConvertHPDamageToPos(tmpCorPatten->lastPosition, m_Player->GetAttack() ));
			}
			m_Player->RestoreSpiritDamage(
				ConvertSpiritDamageToPos(tmpCorPatten->lastPosition, m_Player->GetSpiritAttack() ));
			m_Enemy->GetSpiritdamage(
				ConvertSpiritDamageToPos(tmpCorPatten->lastPosition, m_Player->GetSpiritAttack() ));


			m_PattenManager->SearchAndDestroyCouple(tmpCorPatten->PattenID);
			m_PattenManager->SubPattern(tmpCorPatten->PattenID, "Player");
		}
	}

	// 입력이 기존 가이드라인, 적 공격과 다를경우
	else {
		pattern* tmpPatten = m_PattenManager->failPattern(nowNode);
		if (tmpPatten != nullptr) {   // 실패한 패턴이 있는 경우

			if (tmpPatten->PattenID.substr(0, 2) == "EP") {
				m_Enemy->SetState("Enemy_AttackSuccess");			 // 적 공격 성공
				if (m_Player->GetDefenseRate() >= RandomReturn(100)) {
					m_Player->SetState("Player_Defence");			 // 방어
				}
				else {
					m_Player->SetState("Player_Hit");   			// 피격됨
					m_Player->GetDamage(
						ConvertHPDamageToPos(tmpPatten->lastPosition, m_Enemy->GetAttack() ));
				}
				m_Player->RestoreSpiritDamage(
					ConvertSpiritDamageToPos(tmpPatten->lastPosition, m_Player->GetSpiritAttack() )); // 기세 계산
				m_Enemy->GetSpiritdamage(
					ConvertSpiritDamageToPos(tmpPatten->lastPosition, m_Player->GetSpiritAttack() ));

				m_PattenManager->SubPattern(tmpPatten->PattenID, "Enemy");
			}
			else {
				m_Player->SetState("Player_AttackFail");
				m_Player->SetEndAttack();
				m_PattenManager->SearchAndDestroyCouple(tmpPatten->PattenID);
				m_PattenManager->SubPattern(tmpPatten->PattenID, "Player");
			}
		}
	}

	nowNode.clear();
}

//범위 안의 값을 랜덤하게 return
int  BettleManager::RandomReturn(int MaxInt) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, MaxInt); // 1 ~ 10 사이의 정수
	int randomValue = dist(gen);
	return randomValue;
}

// State정하기
void BettleManager::ChangeFinalState() {
	if (m_Player->GetHp() <= 0.0f) {
		m_Player->SetState("Player_Dead");
	}
	if (m_Enemy->GetHp() <= 0.0f) {
		m_Enemy->SetState("Enemy_Dead");
	}


	if (m_Enemy->GetIsRestore() || m_Player->GetIsRestore()) // 적과 아군 둘중 그로기가 끝나고 회복해야한다면
	{
		m_Enemy->ResetSpiritAmount();  // 서로 기세게이지가 절반으로 돌아감
		m_Player->ResetSpiritAmount();
		m_Enemy->SetIsRestore(false);  // 기세 게이지 회복 표시
		m_Player->SetIsRestore(false);
	}
	else if ( (!m_Player->GetIsGroggy()) && m_Player->GetNowSpiritAmount() <= 0.0f) {
		m_Player->SetState("Player_Groggy");
		m_Player->SetIsGroggy(true);
	}
	else if ( (!m_Enemy->GetIsGroggy()) && m_Enemy->GetNowSpiritAmount() <= 0.0f) {
		m_Enemy->SetState("Enemy_Groggy");
		m_Enemy->SetIsGroggy(true);
	}
	

}




//상중하에 따라서 체력 데미지 리턴하는 함수 만들기
float BettleManager::ConvertHPDamageToPos(AttackPosition lastPos, float HpDamage) {
	switch (lastPos)
	{
	case UpNode:      return  HpDamage * 1.25f;
	case MiddleNode:  return  HpDamage;
	case LowNode:     return  HpDamage * 0.75f;
	default:		  return  0.0f;
	}
}

//상중하에 따라서  기세 데미지 리턴하는 함수 만들기
float BettleManager::ConvertSpiritDamageToPos(AttackPosition lastPos, float SpiritDamage) {
	switch (lastPos)
	{
	case UpNode:      return SpiritDamage * 0.75f;
	case MiddleNode:  return SpiritDamage;
	case LowNode:     return SpiritDamage * 1.25f;
	default:		  return 0.0f;
	}
}
