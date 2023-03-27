#include <stdio.h>

typedef struct{
	
	int date;
	char geo[50];
	char dguid[50];
	char agegroup[50];
	char sex[50];
	char indicators[50];
	char characteristics[50];
	char UOM[50];
	int UOM_ID;
	char scalarfactor[50];
	int scalarID;
	char vector[50];
	char coordinate[50];
	double value;
	char status;
	char symbol;
	char terminate;
	int decimals;
}statscan;
	
	//https://www.youtube.com/watch?v=rbVt5v8NNe8&t=369s&ab_channel=PortfolioCourses
	
int main(void){
	
	FILE *file = fopen("statscan_diabetes1.csv", "r");
	
	if(file == NULL){
		printf("Error opeing the file.\n");
		return 1;
	}
	
	statscan stats[211];
	
	int read = 0;
	int records = 0;
	
	
	do{
		
	
		read = fscanf(file,"%d,%49[^,],%49[^,],%49[^,],%49[^,],%49[^,],%49[^,],%49[^,],%d,%49[^,] ,%d,%49[^,],%49[^,],%lf %c %c %c %d\n",
			                     &stats[records].date,
                                 stats[records].geo,
                                 stats[records].dguid,
	                             stats[records].agegroup,
	                             stats[records].sex,
	                             stats[records].indicators,
	                             stats[records].characteristics,
	                             stats[records].UOM,
	                             &stats[records].UOM_ID,
	                             stats[records].scalarfactor,
	                             &stats[records].scalarID,
	                             stats[records].vector,
	                             stats[records].coordinate,
	                             &stats[records].value,
	                             &stats[records].status,
	                             &stats[records].symbol,
	                             &stats[records].terminate,
	                             &stats[records].decimals);

		if(read == 18){
			records++;
		}
		
		if(read != 18 && !feof(file)){
			printf("File format incorrect. \n");
			return 1;
			}
		
		if(ferror(file)){
			printf("Error reading the file.\n");
			return 1;
			}		
		
	}while(!feof(file));
	
	fclose(file);
	
	
	printf("\n%d records read. \n\n", records);
	
	
	printf("|REF_DATE (year) \t\t|\tGeo \t\t| \tAge Group \t\t|\tSex\t\t|\t Value \t\t|");
	for (int i = 0; i< records; i++){
		printf("|%d|%s|%s|%s|%.2lf|", stats[i].date,
		                              stats[i].geo,
		                              stats[i].agegroup,
		                              stats[i].sex,
		                              stats[i].value);
		                              printf("\n");

		}	
	
	return(0);
	} 

