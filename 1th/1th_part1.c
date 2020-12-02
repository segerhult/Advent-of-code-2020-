#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <error.h>
#include <limits.h>
#include <time.h>


int fileOpen(int num){
	
	
	int size = 0;
	char buffer[200];
	int numbers[200];
    size_t len = num;
    ssize_t read;
	FILE* file;

	
	
	file = fopen("list.txt", "r");
	if (file == NULL){
		exit(EXIT_FAILURE);
	}
	/*if (fgets (buffer,1000,file )!= NULL){
	printf("%s", buffer);
	}*/
	clock_t begin = clock();
	while (fgets (buffer,200,file )!= NULL){
		//printf("%s", buffer);
		//int converter = atoi(buffer);
		numbers[size] = atoi(buffer);
		//printf("%d\n", numbers[size]);
		size++;
	}
	for (int num1 = 0; num1 < 201; num1++)
	{
		
		for ( int num2 = 0; num2 < 201; num2++)
		{
			int add = numbers[num1] + numbers[num2];
			

			if (add == 2020){
				printf("%d + %d\n", numbers[num1], numbers[num2] );
				int correct = numbers[num1] + numbers[num2];
				int success = numbers[num1] * numbers[num2];
				printf("%d\n %d\n", success, correct);
			}
		}
		
	}
	

	//printf("%ld", sizeof(buffer));
	//read = getline(&line, &len, file);
	//printf("%s",line);
	fclose(file);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f", time_spent);
    
    
	
	
}	

void start(int num){
	
	fileOpen(num);
	
	
	exit(EXIT_SUCCESS);
	
	
}

int main(){
	start(0);	
	printf("Exit");
	
	
}