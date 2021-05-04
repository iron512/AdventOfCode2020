#include <stdio.h>

int main(int argc, char const *argv[]) {
	int height = 128; int width = 8;

	if (argc != 2)
		printf("Wrong parameters passed. Please run using again using the correct syntax:\n\n./pitri <input_file_name>\n\n");

	FILE *fp = fopen(argv[1], "r");
	
	char c;

	int rowValue = height/2;	
	int colValue = width/2;

	int rowPos = 0;
	int colPos = 0;

	int max = 0;
	int min = 1000;

	int tot = 0;

	while ((c = fgetc(fp)) != EOF) {
		switch (c) {
			case 'B':
				rowPos += rowValue;
			case 'F':
				rowValue /= 2;
			break;
			case 'R':
				colPos += colValue;
			case 'L':
				colValue /= 2;
			break;
		}


		if (c == '\n'){
			int val = rowPos*width+colPos;

			if (max < val) 
				max = val;
			if (min > val) 
				min = val;
		
			tot+= val;

			rowValue = height/2;
			colValue = width/2;

			rowPos = colPos = 0;
		}
	}

	//i got the total boarding pass sum, the max and the min
	//The sum of all the numbers from 0 to N is equal to (N+1*N)/2, to the sum 
	//of all the numbers from M to N is equal to (N+1*N)/2 - (M*M-1)/2. Since in the total, our number
	//is not present, subtracting the total from the result, returns our boarding pass seat.

	int place = (((max+1)*max)/2 - (((min-1)*min))/2) - tot;

	printf("Your boarding pass value is %d\n", place);
	return 0;
}
