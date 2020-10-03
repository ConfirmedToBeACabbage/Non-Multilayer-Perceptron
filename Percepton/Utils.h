#pragma once

#include <math.h>;

//Sigmoid function
double Sigmoid_Calc(double x) {
	return x / 1 + abs(x);
}
