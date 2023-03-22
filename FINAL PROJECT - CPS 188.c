#include <stdio.h>


#define Rows 211
#define Columns 18

int main(void){
	
	
	FILE *csvfile = fopen("statscan_diabetes1.csv","r");
	char array [Rows][Columns];
	int row = 0;
	
	while(!feof(csvfile)){
		if(ferror(csvfile)){
			printf("Error Reading file");
			return 1;
		}
		
		
		for(int i = 0;i< Columns;i++){
			if((fscanf(csvfile,"%c", &array[row][i]))== EOF){
				break;
				}
			}
			
		row++;
		
		if(row == Rows){
			break;
			}
		}
	fclose(csvfile);
	
	for(int i = 0;i < Rows;i++){
		for(int j = 0; j < Columns;j++){
			printf("%c",array[i][j]);
			if(j == Columns){
				printf("\n");
			}
		}
	
	return(0);
}
}
