#pragma once

#include "Utils.h";
#include <random>;

class PerceptronMap {

	public: 
		float weights[3];
		int input[2];
		int check = 0, tries = 0, output = 0, wrong = 0, right = 0, error = 0;
		float percent = 100;
		double bias;

		PerceptronMap(int sBias) {
			bias = sBias;
			getRandW();
		}

		float setPercentage(int tries);
		float getOutput();
		int addCorrectnessCounter();
		void updateError(int desiredOutput);

		void updateAllWeights();
		void printResults();
		void getRandW();
		void setRandInput(int step);
};

//Select random weights
void PerceptronMap::getRandW() {

	int i = 0;

	for (i = 0; i < 3; i++) {
		weights[i] = rand() % 10;
	}
}

void PerceptronMap::setRandInput(int step) {

	for (int i = 0; i < 3; i++) {
		
		if (step < 2) {
			input[step] = rand() % 2;
		}

	}

}

float PerceptronMap::setPercentage(int tries) {
	return percent = (wrong / float(tries)) * 100;
}

float PerceptronMap::getOutput() {
	return Sigmoid_Calc((input[0] * weights[0]) + (input[1] * weights[1]) + (bias * weights[2]));
}

int PerceptronMap::addCorrectnessCounter() {

	if (check == 0) {
		return wrong++;
	}
	else if (check == 1) {
		return right++;
	}

}

void PerceptronMap::updateError(int desiredOutput) {
	error = desiredOutput - output;
}

void PerceptronMap::updateAllWeights() {

	for (int i = 0; i < 2; i++) {

		weights[i] = error * input[i] * 1;

	}

	weights[2] = error * bias * 1;

}

void PerceptronMap::printResults() {

	std::cout << "Input1: " << input[0] << " Input2: " << input[1] << std::endl;
	std::cout << "Output: " << output << std::endl;
	std::cout << "Wrong: " << wrong << " Right: " << right << std::endl;
	std::cout << "Percent Wrong: " << percent << std::endl << std::endl;

}
