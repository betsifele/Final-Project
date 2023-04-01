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

void yearlyaverages(char str[], struct data arr[], int row){
	double sumavg = 0, numofinstances = 0;
	double sum2015avg = 0, num2015ofinstances = 0;
	double sum2016avg = 0, num2016ofinstances = 0;
	double sum2017avg = 0, num2017ofinstances = 0;
	double sum2018avg = 0, num2018ofinstances = 0;
	double sum2019avg = 0, num2019ofinstances = 0;
	double sum2020avg = 0, num2020ofinstances = 0;
	double sum2021avg = 0, num2021ofinstances = 0;
	
	char pt1[50] = "\"";
	char pt2[50] = "\"";
	strcat(pt1, str);
	strcat(pt1,pt2);
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(arr[i].geo, pt1)){
			
			numofinstances++;
			sumavg += arr[i].value;
		}
	}
	for(int i = 0; i < row+1; i++){
		if(!strcmp(arr[i].geo, pt1)){
			
			if((arr[i].date == 2015)){
				
			num2015ofinstances++;
			sum2015avg += arr[i].value;
			
		   }else if((arr[i].date == 2016)){
			
			num2016ofinstances++;
			sum2016avg += arr[i].value;
			
			}else if((arr[i].date == 2017)){
				
				num2017ofinstances++;
				sum2017avg += arr[i].value;
				
			}else if((arr[i].date == 2018)){
				
				num2018ofinstances++;
				sum2018avg += arr[i].value;
				
			}else if((arr[i].date == 2019)){
				
				num2019ofinstances++;
				sum2019avg += arr[i].value;
			}else if((arr[i].date == 2020)){
				num2020ofinstances++;
				sum2020avg += arr[i].value;
			}else if((arr[i].date == 2021)){
				num2021ofinstances++;
				sum2021avg += arr[i].value;
			}
			}
	}
	double avg = sumavg/numofinstances;
	printf("%s Total Average: %.2lf\n\n", str, avg);
	printf("%s Yearly Average\n-------------------\n", str);
	printf("2015 Average: %.2lf\n", sum2015avg/num2015ofinstances);
	printf("2016 Average: %.2lf\n", sum2016avg/num2016ofinstances);
	printf("2017 Average: %.2lf\n", sum2017avg/num2017ofinstances);
	printf("2018 Average: %.2lf\n", sum2018avg/num2018ofinstances);
	printf("2019 Average: %.2lf\n", sum2019avg/num2019ofinstances);
	printf("2020 Average: %.2lf\n", sum2020avg/num2020ofinstances);
	printf("2021 Average: %.2lf\n\n", sum2021avg/num2021ofinstances);
}
	
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
	
	int row = 0;
  
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
	}
	
	struct data datalist[row];
	
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
	
	
	printf("The average percetage of the population that is diagnosed with diabetes (for all years and age groups):\n\n");
	
	yearlyaverages("Canada (excluding territories)", datalist, row);
	
	yearlyaverages("Quebec", datalist, row);
	
	yearlyaverages("Ontario", datalist, row);
	
	yearlyaverages("Alberta", datalist, row);
	
	yearlyaverages("British Columbia", datalist, row);
	
	
	return(0);
	} 
