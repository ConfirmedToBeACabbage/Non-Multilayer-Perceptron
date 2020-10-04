#pragma once

#include "Utils.h";
#include <random>;

class PerceptronMap {

	public: 
		float weights[3], input[2];
		float percent = 100, bias, error; 

		int check = 0, tries = 0, output = 0, wrong = 0, right = 0;

		PerceptronMap(double sBias) {
			bias = sBias;
			getRandW();
			setRandInput();
		}

		float setPercentage(int tries);
		float getOutput();
		int addCorrectnessCounter();
		void updateError(int desiredOutput);

		void updateAllWeights();
		void printResults();
		void getRandW();
		void setRandInput();
};

//Select random weights
void PerceptronMap::getRandW() {

	int i = 0;

	for (i = 0; i < 3; i++) {
		weights[i] = ((float)rand() / (RAND_MAX)) + 10;
	}
}

void PerceptronMap::setRandInput() {

	for (int i = 0; i < 2; i++) {
		
		input[i] = ((float)rand() / (RAND_MAX));

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

	std::cout << "###Outputs###" << std::endl << "Input1: " << input[0] << " Input2: " << input[1] << std::endl
		<< "Output: " << output << std::endl;

	std::cout << "###Wrong/Right %###" << std::endl << "Wrong: " << wrong << std::endl << " Right: " << right << std::endl
		<< "Percent Wrong: " << percent << std::endl;

	std::cout << "###Weights###" << std::endl << "Weights1: " << weights[0] << std::endl
		<< "Weights2: " << weights[1] << std::endl << "Weights3: " << weights[2] << "Error: " << error << std::endl << std::endl;

}
