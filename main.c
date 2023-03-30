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
	
	//
	
int main(void){

  
	FILE *file = fopen("statscan_diabetes.csv", "r");
	char line [MAX_LINE_LENGTH];
  char *token;
  struct statscan stats;

  
	if(file == NULL){
		printf("Error opening the file.\n");
		return 1;
	}

	
	fgets(line,MAX_LINE_LENGTH,file);
	//int read = 0;
	int row = 0;
  printf("| Line:\t\t| REF_DATE (year)\t| Geo\t\t\t\t| Age Group\t\t| Sex\t\t| Value\t\t|\n\n");
  while(fgets(line,MAX_LINE_LENGTH,file)){

    token = strtok(line,",\"");
    if(token == NULL || token[0] == '\0') continue;
    stats.date = atoi(token);
    token = strtok(NULL,",");
    if(token == NULL || token[0] == '\0') continue;
    strcpy(stats.geo, token);
    token = strtok(NULL,",");
    if(token == NULL || token[0] == '\0') continue;
    strcpy(stats.dguid, token);
    token = strtok(NULL,",");
    if(token == NULL || token[0] == '\0') continue;
    strcpy(stats.agegroup, token);
    token = strtok(NULL,",");
    if(token == NULL || token[0] == '\0') continue;
    strcpy(stats.sex, token);
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

ig ujkhkjh gjhkjhvg{}




    
    printf("|%d\t| %d\t\t| %-32s\t| %-16s\t| %-8s\t| %.2lf\t|\n", row, stats.date, stats.geo, stats.agegroup, stats.sex, stats.value);
  }
	/*
	while (fscanf(file, "%d,%49[^,],%49[^,],%49[^,],%49[^,],%49[^,],%49[^,],%49[^,],%d,%49[^,],%d,%49[^,],%49[^,],%lf,%c,%c,%c,%d\n",
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
              &stats[records].decimals) > 15) {
    
    // check if necessary fields are not empty
    if (stats[records].date != 0 &&
        stats[records].geo[0] != '\0' &&
        stats[records].agegroup[0] != '\0' &&
        stats[records].sex[0] != '\0' &&
        stats[records].value != 0.0) {
        records++; // increment record count
    } else if(stats[records].date == 0 ||
              stats[records].geo[0] == '\0' ||
              stats[records].dguid[0]  == 0 ||
              stats[records].agegroup[0] == '\0' |
              stats[records].sex[0] == '\0' ||
              stats[records].indicators[0] == '\0' ||
              stats[records].characteristics[0] == '\0' ||
              stats[records].UOM[0] == '\0' ||
              stats[records].UOM_ID  == 0 || 
              stats[records].scalarfactor[0] == '\0' ||
              stats[records].scalarID  == 0 ||
              stats[records].vector[0] == '\0' ||
              stats[records].coordinate[0] == '\0' ||
              stats[records].value  == 0 ||
              stats[records].status  == 0 ||
              stats[records].symbol == 0 ||
              stats[records].terminate  == 0 ||
              stats[records].decimals   == 0.0
    ) {
        printf("Error Value in Record: %d",records); 
        continue; // skip this record and move on to the next
    }
    
    if(ferror(file)){
			printf("Error reading the file.\n");
			return 1;
			}
}
	
	fclose(file);
	
	
	printf("\n%d records read. \n\n", records);
		
	printf("| Line: \t\t| REF_DATE (year)| Geo\t\t\t\t| Age Group\t\t| Sex\t\t| Value\t\t|\n\n");
	for (int i = 0; i < records; i++) {
		    printf("|       %d\t\t| %d\t\t| %-32s\t| %-16s\t| %-8s\t| %.2lf\t|\n",i + 1, stats[i].date, stats[i].geo, stats[i].agegroup, stats[i].sex, stats[i].value);
		    }
*/
	
	return(0);
	} 
