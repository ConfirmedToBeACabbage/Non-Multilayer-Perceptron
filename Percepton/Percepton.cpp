// Percepton.cpp : Defines the entry point for the console application.
// This basic percepton neural network will work on trying to return results according to inclusive or. 
// Our data sheet will be entering 3 values (Inluding output) because we want it to train. 
/* Inclusive Or Sheet
	0 0 = 0 
	0 1 = 1 
	1 0 = 1 
	1 1 = 1 
*/

#include "stdafx.h"
#include <iostream>;

using namespace std;

#include "NodeMap.h";
#include "TableCheckers.h";
#include "Utils.h";

void runPerceptron(double bias, int orTableU);

int main()
{
	//Bias input
	double bias;
	cout << "Enter a Bias: ";
	cin >> bias;

	cout << "Test which table? " << endl;
	cout << "0) And Table" << endl;
	cout << "1) Or Table" << endl;
	int orTableU = 0;
	cin >> orTableU; 

	if (orTableU > 0) {
		orTableU = 1;
	}
	else {
		orTableU = 0;
	}

	runPerceptron(bias, orTableU);

    return 0;
}

//Add inputs, weights, and biases function
void runPerceptron(double bias, int orTableU) {

	char quit = ' ';
	int tries = 0, desiredOutput = 0;
	PerceptronMap pM(bias);

	cout << "Type q and hit enter at anytime to quit the sim" << endl;

	while (quit != 'q') {

		//Calculate output function wrapped in Sigmoid function
		pM.getOutput();

		//Make sure the input is either 1 or 0
		pM.output = returnProperOutput(pM.output);


		//Get the desired output for the current inputs
		desiredOutput = getDesiredOutput(pM.input, orTableU);

		//Update the error depending on the output
		pM.updateError(desiredOutput);

		//Calculate new weights
		pM.updateAllWeights();


		//Check if the answer is correct
		pM.check = checkStepTable(desiredOutput, pM.output, pM.check);

		//Set either right or wrong by + 1
		pM.addCorrectnessCounter();


		//Calculate the percentage after a couple first tries
		if (tries >= 2) {
			pM.setPercentage(tries);
		}


		//Print results
		cout << "DesiredOutput: " << desiredOutput << endl;
		pM.printResults();


		//Get new input values with output
		pM.setRandInput();

		tries++;

	}

}