#pragma once

int table[4][2] = {
	{0, 0},
	{0, 1},
	{1, 0},
	{1, 1}
};

//Check each run
int checkStepORTable(int input[], int outputL, int check) {

	int inclusiveOr[4] = { 0, 1, 1, 1 };

	check = 0;

	for (int i = 0; i < 4; i++) {

		if (input[0] == table[i][0] && input[1] == table[i][1]) {

			if (outputL == inclusiveOr[i]) {

				check = 1;
				break;
			}

		}

	}

	return check;
}

int getDesiredOROutput(int inputs[]) {

	if (inputs[0] == 1 || inputs[1] == 1) {
		return 1;
	}
	else {
		return 0;
	}

}

int returnProperInput(float output) {
	if (output > 0) {
		return 1;
	}
	else {
		return  0;
	}
}

