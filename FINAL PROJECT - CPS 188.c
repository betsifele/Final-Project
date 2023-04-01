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

double yearlyaverages(char str[], struct data arr[], int row){
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
	printf("%s Yearly Averages\n-------------------\n", str);
	printf("2015 Average: %.2lf\n", sum2015avg/num2015ofinstances);
	printf("2016 Average: %.2lf\n", sum2016avg/num2016ofinstances);
	printf("2017 Average: %.2lf\n", sum2017avg/num2017ofinstances);
	printf("2018 Average: %.2lf\n", sum2018avg/num2018ofinstances);
	printf("2019 Average: %.2lf\n", sum2019avg/num2019ofinstances);
	printf("2020 Average: %.2lf\n", sum2020avg/num2020ofinstances);
	printf("2021 Average: %.2lf\n\n", sum2021avg/num2021ofinstances);
	
	return (avg);
}

double yearaverage(int year, char str[], struct data arr[], int row){
	
	double sumavg = 0, numofinstances = 0;
	char pt1[50] = "\"";
	char pt2[50] = "\"";
	strcat(pt1, str);
	strcat(pt1,pt2);
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(arr[i].geo, pt1)){
			if(arr[i].date == year){
				sumavg += arr[i].value;
				numofinstances++;
			}
		}
	}
	double avg = sumavg/numofinstances;
	return (avg);
}

void agegroupaverages(char str[], struct data arr[], int row){
	double sumavg = 0, numofinstances = 0;
	double sum35_49avg = 0, num35_49ofinstances = 0;
	double sum50_64avg = 0, num50_64ofinstances = 0;
	double sum65avg = 0, num65ofinstances = 0;
	
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
			
			if(!strcmp(arr[i].agegroup, "\"35 to 49 years\"")){
				num35_49ofinstances++;
				sum35_49avg += arr[i].value;
		   }else if(!strcmp(arr[i].agegroup, "\"50 to 64 years\"")){
				num50_64ofinstances++;
				sum50_64avg += arr[i].value;
			}else if(!strcmp(arr[i].agegroup, "\"65 years and over\"")){
				num65ofinstances++;
				sum65avg += arr[i].value;
			}
		}
	}
	
	printf("%s Age Group Averages\n----------------------------------------\n", str);
	printf("35 to 49 years Age Group Average: %.2lf\n", sum35_49avg/num35_49ofinstances);
	printf("50 to 64 years Age Group Average: %.2lf\n", sum50_64avg/num50_64ofinstances);
	printf("65 years and over Age Group Average: %.2lf\n\n", sum65avg/num65ofinstances);
	
}
	
int main(void){
	
	FILE *file = fopen("statscan_diabetes.csv", "r");
	FILE *file2 = fopen("statscan_diabetes.csv", "r");
	FILE *plot = fopen("plotdata.txt", "w");
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
	fclose(file);
	fclose(file2);
	
	double canavg, queavg, ontavg, albavg, bcavg;
	
	printf("The average percetage of the population that is diagnosed with diabetes (for all years and age groups):\n\n");
	
	canavg = yearlyaverages("Canada (excluding territories)", datalist, row);
	
	queavg = yearlyaverages("Quebec", datalist, row);
	
	ontavg = yearlyaverages("Ontario", datalist, row);
	
	albavg = yearlyaverages("Alberta", datalist, row);
	
	bcavg = yearlyaverages("British Columbia", datalist, row);
	
	agegroupaverages("Canada (excluding territories)", datalist, row);
	
	agegroupaverages("Quebec", datalist, row);
	
	agegroupaverages("Ontario", datalist, row);
	
	agegroupaverages("Alberta", datalist, row);
	
	agegroupaverages("British Columbia", datalist, row);
	
	if(queavg > ontavg && queavg > albavg && queavg > bcavg)
		printf("Quebec has the highest percentage of diabetes (all years and age groups together)\n\n");
	if(ontavg > queavg && ontavg > albavg && ontavg > bcavg)
		printf("Ontario has the highest percentage of diabetes (all years and age groups together)\n\n");
	if(albavg > ontavg && albavg > queavg && albavg > bcavg)
		printf("Alberta has the highest percentage of diabetes (all years and age groups together)\n\n");
	if(bcavg > ontavg && bcavg > albavg && bcavg > queavg)
		printf("British Columbia has the highest percentage of diabetes (all years and age groups together)\n\n");
	
	if(queavg < ontavg && queavg<albavg && queavg<bcavg)
		printf("Quebec has the lowest percentage of diabetes (all years and age groups together)\n\n");
	if(ontavg<queavg && ontavg<albavg && ontavg<bcavg)
		printf("Ontario has the lowest percentage of diabetes (all years and age groups together)\n\n");
	if(albavg<ontavg && albavg<queavg && albavg<bcavg)
		printf("Alberta has the lowest percentage of diabetes (all years and age groups together)\n\n");
	if(bcavg<ontavg && bcavg<albavg && bcavg<queavg)
		printf("British Columbia has the lowest percentage of diabetes (all years and age groups together)\n\n");
	
	if(queavg > canavg)
		printf("Quebec has a diabetes percentage above the national average\n\n");
	else if(queavg == canavg)
		printf("Quebec has a diabetes percentage equal to the national average\n\n");
	else if(queavg < canavg)
		printf("Quebec has a diabetes percentage below the national average\n\n");
		
	if(ontavg > canavg)
		printf("Ontario has a diabetes percentage above the national average\n\n");
	else if(ontavg == canavg)
		printf("Ontario has a diabetes percentage equal to the national average\n\n");
	else if(ontavg < canavg)
		printf("Ontario has a diabetes percentage below the national average\n\n");
		
	if(albavg > canavg)
		printf("Alberta has a diabetes percentage above the national average\n\n");
	else if(albavg == canavg)
		printf("Alberta has a diabetes percentage equal to the national average\n\n");
	else if(albavg < canavg)
		printf("Alberta has a diabetes percentage below the national average\n\n");
		
	if(bcavg > canavg)
		printf("British Columbia has a diabetes percentage above the national average\n\n");
	else if(bcavg == canavg)
		printf("British Columbia has a diabetes percentage equal to the national average\n\n");
	else if(bcavg < canavg)
		printf("British Columbia has a diabetes percentage below the national average\n\n");
		
	double highestvalue = datalist[0].value, lowestvalue = datalist[0].value;
	
	for(int i = 0; i < row + 1; i++){
		if(highestvalue < datalist[i].value){
			highestvalue = datalist[i].value;
		}
		if(lowestvalue == 0)
			lowestvalue = datalist[i].value;
		if(lowestvalue > datalist[i].value){
			lowestvalue = datalist[i].value;
		}
	}
	
	//printf("Highest value: %.2lf Lowest value: %.2lf", highestvalue, lowestvalue);
	printf("Highest percentage of diabetes in all years and all provinces: \n---------------------------------------------------------------\n");
	for(int i = 0; i < row + 1; i++){
		if(datalist[i].value == highestvalue)
			printf("%s, %d, %.2lf\n", datalist[i].geo, datalist[i].date, datalist[i].value);
	}
	printf("\nLowest percentage of diabetes in all years and all provinces: \n---------------------------------------------------------------\n");
	for(int i = 0; i < row + 1; i++){
		if(datalist[i].value == lowestvalue)
			printf("%s, %d, %.2lf\n", datalist[i].geo, datalist[i].date, datalist[i].value);
	}
	
	fprintf(plot, "2015 %lf %lf %lf %lf %lf\n", yearaverage(2015, "Canada (excluding territories)", datalist, row),
												yearaverage(2015, "Quebec", datalist, row),
												yearaverage(2015, "Ontario", datalist, row),
												yearaverage(2015, "Alberta", datalist, row),
												yearaverage(2015, "British Columbia", datalist, row));
	fprintf(plot, "2016 %lf %lf %lf %lf %lf\n", yearaverage(2016, "Canada (excluding territories)", datalist, row),
												yearaverage(2016, "Quebec", datalist, row),
												yearaverage(2016, "Ontario", datalist, row),
												yearaverage(2016, "Alberta", datalist, row),
												yearaverage(2016, "British Columbia", datalist, row));
	fprintf(plot, "2017 %lf %lf %lf %lf %lf\n", yearaverage(2017, "Canada (excluding territories)", datalist, row),
												yearaverage(2017, "Quebec", datalist, row),
												yearaverage(2017, "Ontario", datalist, row),
												yearaverage(2017, "Alberta", datalist, row),
												yearaverage(2017, "British Columbia", datalist, row));
	fprintf(plot, "2018 %lf %lf %lf %lf %lf\n", yearaverage(2018, "Canada (excluding territories)", datalist, row),
												yearaverage(2018, "Quebec", datalist, row),
												yearaverage(2018, "Ontario", datalist, row),
												yearaverage(2018, "Alberta", datalist, row),
												yearaverage(2018, "British Columbia", datalist, row));
	fprintf(plot, "2019 %lf %lf %lf %lf %lf\n", yearaverage(2019, "Canada (excluding territories)", datalist, row),
												yearaverage(2019, "Quebec", datalist, row),
												yearaverage(2019, "Ontario", datalist, row),
												yearaverage(2019, "Alberta", datalist, row),
												yearaverage(2019, "British Columbia", datalist, row));
	fprintf(plot, "2020 %lf %lf %lf %lf %lf\n", yearaverage(2020, "Canada (excluding territories)", datalist, row),
												yearaverage(2020, "Quebec", datalist, row),
												yearaverage(2020, "Ontario", datalist, row),
												yearaverage(2020, "Alberta", datalist, row),
												yearaverage(2020, "British Columbia", datalist, row));
	fprintf(plot, "2021 %lf %lf %lf %lf %lf\n", yearaverage(2021, "Canada (excluding territories)", datalist, row),
												yearaverage(2021, "Quebec", datalist, row),
												yearaverage(2021, "Ontario", datalist, row),
												yearaverage(2021, "Alberta", datalist, row),
												yearaverage(2021, "British Columbia", datalist, row));
	
	fclose(plot);
	
	return(0);
} 
