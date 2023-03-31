#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
struct statscan{
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
};

struct data{
	int date;
	char geo[50];
	char agegroup[50];
	char sex[50];
	double value;
};
	
int main(void){
	
	FILE *file = fopen("statscan_diabetes.csv", "r");
	FILE *file2 = fopen("statscan_diabetes.csv", "r");
	char line [MAX_LINE_LENGTH];
	char line2 [MAX_LINE_LENGTH];
	char *token;
	struct statscan stats;
	struct data dataform;
	
  
	if(file == NULL){
		printf("Error opening the file.\n");
		return 1;
	}

	
	fgets(line,MAX_LINE_LENGTH,file);
	//int read = 0;
	int row = 0;
  
	//printf("\n| Line:\t| Year  \t| Geo\t\t\t\t\t\t\t\t| Age Group\t\t\t\t| Sex\t\t| Value\t|\n");
	while(fgets(line,MAX_LINE_LENGTH,file)){

		token = strtok(line,",\"");
		if(token == NULL || token[0] == '\0') continue;
		stats.date = atoi(token);
		dataform.date = atoi(token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.geo, token);
		strcpy(dataform.geo, token);
			
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.dguid, token);

		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.agegroup, token);
		strcpy(dataform.agegroup, token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.sex, token);
		strcpy(dataform.sex, token);
			
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.indicators, token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.characteristics, token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.UOM, token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		stats.UOM_ID = atoi(token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.scalarfactor, token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		stats.scalarID = atoi(token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.vector, token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.coordinate, token);
    
		token = strtok(NULL,",\"");
		if(token == NULL || token[0] == '\0') continue;
		stats.value = atof(token);
		dataform.value = atof(token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		stats.status = token[0];
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		stats.symbol = token[0];
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		stats.terminate = token[0];
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		stats.decimals = atoi(token);
		
		row++;
    
		//printf("|%-3d\t| %d\t\t| %-32s\t| %-20s\t| %-8s\t| %.2lf\t|\n", row, stats.date, stats.geo, stats.agegroup, stats.sex, stats.value);
	}
	
	struct data datalist[row];
	/*int datelist[rows];
	char geolist[rows][MAX_LINE_LENGTH];
	char agegrouplist[rows][MAX_LINE_LENGTH];
	char sexlist[rows][MAX_LINE_LENGTH];
	double valuelist[rows];*/
	
	int counter = 0;
	
	while(fgets(line2,MAX_LINE_LENGTH,file2)){

		token = strtok(line2,",\"");
		if(token == NULL || token[0] == '\0') continue;
		stats.date = atoi(token);
		dataform.date = atoi(token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.geo, token);
		strcpy(dataform.geo, token);
		
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.dguid, token);

		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.agegroup, token);
		strcpy(dataform.agegroup, token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.sex, token);
		strcpy(dataform.sex, token);
			
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.indicators, token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.characteristics, token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.UOM, token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		stats.UOM_ID = atoi(token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.scalarfactor, token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		stats.scalarID = atoi(token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.vector, token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		strcpy(stats.coordinate, token);
    
		token = strtok(NULL,",\"");
		if(token == NULL || token[0] == '\0') continue;
		stats.value = atof(token);
		dataform.value = atof(token);
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		stats.status = token[0];
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		stats.symbol = token[0];
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		stats.terminate = token[0];
    
		token = strtok(NULL,",");
		if(token == NULL || token[0] == '\0') continue;
		stats.decimals = atoi(token);
    
		datalist[counter] = dataform;
		counter++;
	}
	
	/*for(int i =0; i < row+1; i++){
		printf("%d | %d |%s| %s | %s | %.2lf\n", i+1, datalist[i].date, datalist[i].geo, datalist[i].agegroup, datalist[i].sex, datalist[i].value);
	}*/
	
	double sumavg = 0, numofinstances = 0;
	
	printf("The average percetage of the population that is diagnosed with diabetes (for all years and age groups):\n");
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"Canada (excluding territories)\"")){
			
			numofinstances++;
			sumavg += datalist[i].value;
		}
	}
	double canavg = sumavg/numofinstances;
	printf("Canada (excluding territories): %.2lf\n", sumavg/numofinstances);
	
	sumavg = 0;
	numofinstances = 0;
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"Quebec\"")){
			numofinstances++;
			sumavg += datalist[i].value;
		}
	}
	double queavg = sumavg/numofinstances;
	printf("Quebec: %.2lf\n", sumavg/numofinstances);
	
	sumavg = 0;
	numofinstances = 0;
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"Ontario\"")){
			numofinstances++;
			sumavg += datalist[i].value;
		}
	}
	double ontavg = sumavg/numofinstances;
	printf("Ontario: %.2lf\n", sumavg/numofinstances);
	
	sumavg = 0;
	numofinstances = 0;
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"Alberta\"")){
			numofinstances++;
			sumavg += datalist[i].value;
		}
	}
	double albavg = sumavg/numofinstances;
	printf("Alberta: %.2lf\n", sumavg/numofinstances);
	
	sumavg = 0;
	numofinstances = 0;
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"British Columbia\"")){
			numofinstances++;
			sumavg += datalist[i].value;
		}
	}
	double bcavg = sumavg/numofinstances;
	printf("British Columbia: %.2lf\n", sumavg/numofinstances);
	
	sumavg = 0;
	numofinstances = 0;
	
	
	
	//double highestvalue = datalist[0].value, lowestvalue = datalist[0];
	
	return(0);
	} 
