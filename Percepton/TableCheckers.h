#pragma once

//Check each run
int checkStepTable(int desiredOuptut, int outputL, int check) {

	if (outputL != desiredOuptut) {
		return check = false;
	}
	else {
		return check = true;
	}

}

int getDesiredOutput(float inputs[], int orTable) {

	float reinterpretInput[2];

	for (int i = 0; i < 2; i++) {

		reinterpretInput[i] = round(inputs[i]);

	}

	if (orTable) {

		if (reinterpretInput[0] == 1 || reinterpretInput[1] == 1) {
			return 1;
		}
		else if(reinterpretInput[0] == 0 && reinterpretInput[1] == 0){
			return 0;
		}

	}
	else {

		if (reinterpretInput[0] == 1 && reinterpretInput[1] == 1) {
			return 1;
		}
		else if (reinterpretInput[0] == 0 || reinterpretInput[1] == 0) {
			return 0;
		}

	}

}

int returnProperOutput(float output) {
	if (output > 0) {
		return 1;
	}
	else {
		return  0;
	}
}

