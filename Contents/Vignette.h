#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/BitmapRenderer.h"


class Vignette : public MonoBehavior
{
public:
    void OnCreate() override;
    void OnStart() override;
    void OnUpdate() override;
    D2D1_SIZE_F GetSize();
    void Start(); // 0 -> 1
    void End(); // 1 -> 0

protected:
    float clampf(float v, float minVal, float maxVal)
    { // ������ ���� Ŭ���� �Լ� C++14�� �����ϴ� ���� ����
        return (v < minVal) ? minVal : (v > maxVal ? maxVal : v);
    }

private:
    float progress = 0.0f;
    bool isPlay = false;
    bool isGoingFillUp = true;

    D2D1_SIZE_F size;
    BitmapRenderer* bitmapRenderer{};
};