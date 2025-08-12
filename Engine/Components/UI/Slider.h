﻿#pragma once
#include "Components/UI/UIComponent.h"
#include "Components/Rendering/BitmapRenderer.h"
#include <Utils/EventDelegate.h>
#include <string>
#include <functional>

/* 25.07.29 | 작성자 : 김정현
게이지 백그라운드, 게이지, 버튼 총 3개를 OnStart에서 등록
이미지를 바꾸고싶으면 Component를 추가후 SetImage(경로) 함수로 이미지 지정
***이때 이미지는 가로세로 다 맞는 그림이어야함 , 리소스 요청시 필수 사항
버튼이 필요없는 슬라이더의 경우 ButtShow에 false를 전달
슬라이더 이동시 void ChangeGauge(float x); void ChangeButtonPosition(float x);에서 x값은 같은값을 던져줘야함
SetPivotSide은 false를 던져줄때 오른쪽에서 왼쪽으로 늘어나도록함 ( 기능 미완성이라 안쓰는게 좋음 )

25.08.01 | 작성자 : 김정현
함수 등록 (void형태에 float을 매개변수로 받는 예: 사운드 조절함수)를 등록
버튼기능 True일때 버튼의 클릭해서 놓는위치나 바탕누른 위치를 float 값으로 반환후 invoke를 통해 float값 전달
이미지 셋팅하면 그거에 맞춰서 길이 자동 조절
*/


class Slider : public UIComponent
{
public:
	void OnCreate() override;
	void OnStart() override;
	void Update() override;

	void SetPivotSide( bool isLeft);

	//이미지들을 셋팅 및 가져오는 함수
	void SetGaugeBackgroundImage(std::wstring path);
	BitmapRenderer* GetGaugeBackgroundImage();
	void SetGaugeBarImage(std::wstring path);
	BitmapRenderer* GetGaugeBarImage();
	void SetGaugeButtonImage(std::wstring path);
	BitmapRenderer* GetGaugeButtonImage();


	void SetSliderLayer(int gauge , int background, int button);



	//GaugeRect셋팅함수(첫 시작 게이지 받아옴)
	void SetGaugeRectValue();
	D2D1_RECT_F GetGaugeRectValue();

	//GaugeRect셋팅함수(게이지 어느정도인지 셋팅)
	void ChangeGauge(float x);

	//Button위치셋팅함수
	void ChangeButtonPosition(float x);

	//Button안보이는용도(체력바)

	void ButtonShow(bool setvalue);

	//
	size_t AddOnClickEvent(std::function<void(float)> fn);

	void RemoveOnClickEventById(size_t id);

	//
	bool IsMouseOver(const Vector2& mousePos) const override;
	bool IsMouseOverBackground(const Vector2& mousePos) const;

	void SetSize();
	void SetBackSize();

	void ButtonEvent();

	void SetDelegate(std::function<void(float)> fn);

	float GetPointValue();


private:
	BitmapRenderer* GaugeBackground{};
	BitmapRenderer* GaugeBar{};
	BitmapRenderer* BarButton{};



	D2D1_RECT_F GaugeBarBackGroundDestRect{};
	D2D1_RECT_F GaugeBarBackGroundSrcRect{};
	D2D1_RECT_F GaugeBarRect{};
	D2D1_RECT_F ButtonDestRect{};
	D2D1_RECT_F BarButSrctonRect{};

	//마우스 감지 박스 2개
	D2D1_RECT_F ButtonRect{};
	D2D1_RECT_F BackGroundRect{};

	//비트맵 사이즈 변수
	D2D1_SIZE_F size;
	D2D1_SIZE_F sizeButton;

	D2D1_SIZE_F sizeBackground;

	bool HandleValue = true;
	bool pivotIsLeft = true;
	bool OnButton = false;

	bool checkPush = false;


	EventDelegate<float> onClickEvent; // void()형만 받는 클릭 이벤트 
};