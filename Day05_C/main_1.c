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
			if (max < rowPos*width+colPos) 
				max = rowPos*width+colPos;
			
			rowValue = height/2;
			colValue = width/2;

			rowPos = colPos = 0;
		}
	}
	printf("The maximum boarding pass value is %d\n", max);
	return 0;
}
