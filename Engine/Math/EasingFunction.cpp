﻿#include "EasingFunction.h"
#include <cmath>
const double PI = 3.14159265358979323846;
const float PI_F = 3.14159265f;

float easeLinear(float x) { return x; }


float easeInSine(float x) { return 1 - std::cos((x * PI_F) / 2);}
float easeOutSine(float x) { return std::sin((x * PI_F) / 2); }
float easeInOutSine(float x) { return -(std::cos(PI_F * x) - 1) / 2; }


float easeInQuad(float x) { return x * x; }
float easeOutQuad(float x) { return 1 - (1 - x) * (1 - x); }
float easeInOutQuad(float x) { return x < 0.5 ? 2 * x * x : 1 - std::pow(-2 * x + 2, 2) / 2; }


float easeInCubic(float x) { return x * x * x; }
float easeOutCubic(float x) { return 1 - std::pow(1 - x, 3); }
float easeInOutCubic(float x) { return -(std::cos(PI_F * x) - 1) / 2; }


float easeInQuart(float x) { return x * x * x * x; }
float easeOutQuart(float x) { return 1 - std::pow(1 - x, 4); }
float easeInOutQuart(float x) { return x < 0.5 ? 8 * x * x * x * x : 1 - std::pow(-2 * x + 2, 4) / 2; }


float easeInQuint(float x) { return x * x * x * x * x; }
float easeOutQuint(float x) { return 1 - std::pow(1 - x, 5); }
float easeInOutQuint(float x) { return x < 0.5 ? 16 * x * x * x * x * x : 1 - std::pow(-2 * x + 2, 5) / 2; }


float easeInExpo(float x) { return x == 0 ? 0 : std::pow(2, 10 * x - 10); }
float easeOutExpo(float x) { return x == 1 ? 1 : 1 - std::pow(2, -10 * x); }
float easeInOutExpo(float x) {
	return x == 0
		? 0
		: x == 1
		? 1
		: x < 0.5
		? std::pow(2, 20 * x - 10) / 2
		: (2 - std::pow(2, -20 * x + 10)) / 2;
}


float easeInCirc(float x) { return 1 - std::sqrt(1 - std::pow(x, 2)); }
float easeOutCirc(float x) { return std::sqrt(1 - std::pow(x - 1, 2)); }
float easeInOutCirc(float x) {
	return x < 0.5
		? (1 - std::sqrt(1 - std::pow(2 * x, 2))) / 2
		: (std::sqrt(1 - std::pow(-2 * x + 2, 2)) + 1) / 2;
}


float easeInBack(float x) {
	const float c1 = 1.70158;
	const float c3 = c1 + 1;

	return c3 * x * x * x - c1 * x * x;
}
float easeOutBack(float x) {
	const float c1 = 1.70158;
	const float c3 = c1 + 1;

	return 1 + c3 * std::pow(x - 1, 3) + c1 * std::pow(x - 1, 2);
}
float easeInOutBack(float x) {
	const float c1 = 1.70158;
	const float c2 = c1 * 1.525;

	return x < 0.5
		? (std::pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
		: (std::pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
}


float easeInElastic(float x) {
	const float c4 = (2 * PI_F) / 3;

	return x == 0
		? 0
		: (x == 1
			? 1
			: -std::pow(2, 10 * x - 10) * std::sin((x * 10 - 10.75) * c4));
}

float easeOutElastic(float x) {
	const float c4 = (2 * PI_F) / 3;

	return x == 0
		? 0
		: x == 1
		? 1
		: std::pow(2, -10 * x) * std::sin((x * 10 - 0.75) * c4) + 1;
}
float easeInOutElastic(float x) {
	const float c5 = (2 * PI_F) / 4.5;

	return x == 0
		? 0
		: x == 1
		? 1
		: x < 0.5
		? -(std::pow(2, 20 * x - 10) * std::sin((20 * x - 11.125) * c5)) / 2
		: (std::pow(2, -20 * x + 10) * std::sin((20 * x - 11.125) * c5)) / 2 + 1;
}



float easeInBounce(float x) { return 1 - easeOutBounce(1 - x); }
float easeOutBounce(float x) {
	const float n1 = 7.5625;
	const float d1 = 2.75;

	if (x < 1 / d1)
		return n1 * x * x;
	else if (x < 2 / d1)
		return n1 * (x -= 1.5 / d1) * x + 0.75;
	else if (x < 2.5 / d1)
		return n1 * (x -= 2.25 / d1) * x + 0.9375;
	else
		return n1 * (x -= 2.625 / d1) * x + 0.984375;
}
float easeInOutBounce(float x) {
	return x < 0.5
		? (1 - easeOutBounce(1 - 2 * x)) / 2
		: (1 + easeOutBounce(2 * x - 1)) / 2;
}
