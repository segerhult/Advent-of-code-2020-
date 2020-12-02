#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <error.h>
#include <limits.h>
#include <time.h>


int fileOpen(int num){
	
	
	int size = 0;
	char buffer[201];
	int numbers[201];
    size_t len = num;
    ssize_t read;
	FILE* file;
	
	file = fopen("list.txt", "r");

	if (file == NULL){
		exit(EXIT_FAILURE);
	}

	clock_t begin = clock();

	while (fgets (buffer,201,file )!= NULL){

		numbers[size] = atoi(buffer);
	
		size++;
	}
	for (int num1 = 0; num1 < 201; num1++)
	{
		
		for ( int num2 = 0; num2 < 201; num2++)
		{
            for ( int num3 = 0; num3 < 201; num3++)
		    {
			    int add = numbers[num1] + numbers[num2] + numbers[num3];
			
			    if (add == 2020 && numbers[num1] != 0 && numbers[num2] != 0 && numbers[num3] != 0){
				  
				    int correct = numbers[num1] + numbers[num2] + numbers[num3];

				    int success = numbers[num1] * numbers[num2] * numbers[num3];

				    printf("%d + %d + %d = %d: multiplied is %d\n", numbers[num1], numbers[num2], numbers[num3], correct ,success );
			    }
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