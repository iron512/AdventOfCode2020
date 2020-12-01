/*
*	This code could be easily solved with a n^3 code
*	I implemented a n^2logn version. 
*	I'm not totally happy with it, maybe i will release a second version
*/

#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int dicotomy(int* array, int size, int value);
int dicotomy_alg(int* array, int min, int max, int value);

int main(int argc, char const *argv[]) {
	if (argc != 3) {
		cout << "Wrong parameters passed. Please run using again using the correct syntax:\n\n./marco <input_file_name> <wanted_number>\n\n";
		exit(1);
	}

	//set the parameters
	const char* input_file = argv[1];
	int wanted_number = atoi(argv[2]);

	fstream reader;
	reader.open(input_file, fstream::in);

	//count how many inputs are present
	string text;
	int index = 0;
	while(getline (reader, text)) {
		index++;
	}

	int *numbers =  new int[index];
	index = 0;

	reader.close();
	reader.open(input_file, fstream::in);

	while(getline (reader, text)) {
		numbers[index++] = stoi(text);
	}

	//it sorts the array in an ascendent order.
	sort(numbers, numbers+index);

	int firstCandidate = -1;
	int secondCandidate = -1;
	int thirdCandidate = -1;

	bool found = false;
	while (!found) {
		int searching = wanted_number-numbers[++firstCandidate];

		for (int i = 0; i < index && !found; ++i) {
			thirdCandidate = dicotomy(numbers,index,searching - numbers[++secondCandidate]);
			found = (thirdCandidate != -1);
		}
	}

	cout << endl << numbers[firstCandidate] << ", " << numbers[secondCandidate] << " and " << numbers[thirdCandidate] << ": " << numbers[firstCandidate] * numbers[secondCandidate] *numbers[thirdCandidate] << endl << endl;
	return 0;
}

int dicotomy(int* array, int size, int value) {
	//Wrapper function
	return dicotomy_alg(array, 0, size-1, value);
}

int dicotomy_alg(int* array, int min, int max, int value) {
	if (min > max) {
		//not present
		return -1;
	}

	int avg = (min+max)/2;
	if (array[avg] == value) {
		//found it
		return avg;
	} else if (array[avg] > value) {
		//the avg is higher, lower the boundaries
		return dicotomy_alg(array, min, avg-1, value);
	} else {
		//the avg is lower, rise the boundaries
		return dicotomy_alg(array, avg+1, max, value);
	}
}