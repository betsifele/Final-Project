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
	
	//
	
int main(void){

	double ontarioaverage[200]= {0};
	double quebecaverage[200] = {0};
	double britishcolumbiaaverage[200] = {0};
	double albertaaverage[200] = {0};

	double nationalaverage[200];

	double average2015[200] = {0};
	double average2016[200] = {0};
	double average2017[200] = {0};
	double average2018[200] = {0};
	double average2019[200] = {0};
	double average2020[200] = {0};
	double average2021[200] = {0};


	double averageage35to49[200] = {0};
	double averageage60to64[200] = {0};
	double averageage65[200] = {0};

	double canadaavg[200] = {0}, quebecavg[200] = {0}, ontarioavg[200] = {0}, albertaavg[200] = {0}, britishcavg[200] = {0};
	int cancount = 0, quecount = 0, ontcount = 0, albcount = 0, bccount = 0;
	double sumcanavg = 0, sumqueavg = 0, sumontavg = 0, sumalbavg = 0, sumbcavg = 0;

  
	FILE *file = fopen("statscan_diabetes.csv", "r");
	char line [MAX_LINE_LENGTH];
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
	int count = 0,count2015 = 0,count2016 = 0, count2017 = 0, count2018 = 0, count2019 = 0, count2020 = 0, count2021 = 0;
	double sumaverage2015 = 0,sumaverage2016,sumaverage2017,sumaverage2018,sumaverage2019,sumaverage2020,sumaverage2021;
  
	printf("\n| Line:\t| Year  \t| Geo\t\t\t\t\t\t\t\t| Age Group\t\t\t\t| Sex\t\t| Value\t|\n");
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
    
		if(!strcmp(dataform.geo, "\"Canada (excluding territories)\""))
			canadaavg[cancount++] = dataform.value;
		if(!strcmp(dataform.geo, "\"Quebec\""))
			quebecavg[quecount++] = dataform.value;
		if(!strcmp(dataform.geo, "\"Ontario\""))
			ontarioavg[ontcount++] = dataform.value;
		if(!strcmp(dataform.geo, "\"Alberta\""))
			albertaavg[albcount++] = dataform.value;
		if(!strcmp(dataform.geo, "\"British Columbia\""))
			britishcavg[bccount++] = dataform.value;
	
    
		if(stats.date == 2015){
			average2015[count2015++] = stats.value;      
		}else if(stats.date == 2016){
			average2016[count2016++] = stats.value; 
		}else if(stats.date == 2017){
			average2017[count2017++] = stats.value;
		}else if(stats.date == 2018){
			average2018[count2018++] = stats.value; 
		}else if(stats.date == 2019){
			average2019[count2019++] = stats.value;
		}else if(stats.date == 2020){
			average2020[count2020++] = stats.value;
		}else if(stats.date == 2021){
			average2021[count2021++] = stats.value;
		}
		printf("|%-3d\t| %d\t\t| %-32s\t| %-20s\t| %-8s\t| %.2lf\t|\n", row, stats.date, stats.geo, stats.agegroup, stats.sex, stats.value);
	}
  
	for(int i = 0; i<(
  
	printf("\n%d is the Alberta count\n", albcount);
	for(int i = 0; i<(sizeof(albertaavg)/sizeof(albertaavg[0]));i++){
		if(albertaavg[i] != 0){
			sumalbavg += albertaavg[i];
		}
	}
	
	printf("The average for Canada excluding territories (all years and age groups): %.2lf%\n", sumalbavg/albcount);
  
	printf("\n%d is the ontario count\n", ontcount);
	for(int i = 0; i<(sizeof(ontarioavg)/sizeof(ontarioavg[0]));i++){
		if(ontarioavg[i] != 0){
			sumontavg += ontarioavg[i];
		}
	}
	
	printf("The average for the province of Quebec (all years and age groups): %.2lf%\n", sumalbavg/albcount);
  
	printf("\n%d is the ontario count\n", ontcount);
	for(int i = 0; i<(sizeof(ontarioavg)/sizeof(ontarioavg[0]));i++){
		if(ontarioavg[i] != 0){
			sumontavg += ontarioavg[i];
		}
	}
	
	printf("The average for the province of Ontario (all years and age groups): %.2lf%\n", sumontavg/ontcount);

	printf("\n%d is the 2015 count\n", count2015);
	for(int i = 0; i<(sizeof(average2015)/sizeof(average2015[0]));i++){
		if(average2015[i] != 0){
			sumaverage2015 += average2015[i];
      
		printf("%.2lf \n",average2015[i]);
		}
	}
	
	printf("The average for the province of Alberta (all years and age groups): %.2lf%\n", sumalbavg/albcount);
  
	printf("\n%d is the ontario count\n", ontcount);
	for(int i = 0; i<(sizeof(ontarioavg)/sizeof(ontarioavg[0]));i++){
		if(ontarioavg[i] != 0){
			sumontavg += ontarioavg[i];
		}
	}
  
  //sumaverage2015 = ((sumaverage2015)/count2015);
  /*
  printf("the sum is %.2lf and the average is  \n",sumaverage2015);

  for(int i = 0; i<(sizeof(average2016)/sizeof(average2016[0]));i++){
    if(average2016[i] != 0){
      sumaverage2016 += average2016[i];
    printf("Average 2015: %.2lf \n",average2015[i]);
    }
  }
	*/

  
	return(0);
	} 
