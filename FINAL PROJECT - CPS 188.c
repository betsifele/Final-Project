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
	double sum2015avg = 0, num2015ofinstances = 0;
	double sum2016avg = 0, num2016ofinstances = 0;
	double sum2017avg = 0, num2017ofinstances = 0;
	double sum2018avg = 0, num2018ofinstances = 0;
	double sum2019avg = 0, num2019ofinstances = 0;
	double sum2020avg = 0, num2020ofinstances = 0;
	double sum2021avg = 0, num2021ofinstances = 0;
	
	printf("The average percetage of the population that is diagnosed with diabetes (for all years and age groups):\n");
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"Canada (excluding territories)\"")){
			
			numofinstances++;
			sumavg += datalist[i].value;
		}
	}
	for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"Canada (excluding territories)\"")){
			
			if((datalist[i].date == 2015)){
				
			num2015ofinstances++;
			sum2015avg += datalist[i].value;
			
		   }else if((datalist[i].date == 2016)){
			
			num2016ofinstances++;
			sum2016avg += datalist[i].value;
			
			}else if((datalist[i].date == 2017)){
				
				num2017ofinstances++;
				sum2017avg += datalist[i].value;
				
			}else if((datalist[i].date == 2018)){
				
				num2018ofinstances++;
				sum2018avg += datalist[i].value;
				
			}else if((datalist[i].date == 2019)){
				
				num2019ofinstances++;
				sum2019avg += datalist[i].value;
			}else if((datalist[i].date == 2020)){
				num2020ofinstances++;
				sum2020avg += datalist[i].value;
			}else if((datalist[i].date == 2021)){
				num2021ofinstances++;
				sum2021avg += datalist[i].value;
			}
			}
	}
	double canavg = sumavg/numofinstances;
	printf("Canada (excluding territories) Total Average: %.2lf\n", canavg);
	printf("Canada (excluding territories) Yearly Average\n");
	printf("2015 Average: %.2lf\n", sum2015avg/num2015ofinstances);
	printf("2016 Average: %.2lf\n", sum2016avg/num2016ofinstances);
	printf("2017 Average: %.2lf\n", sum2017avg/num2017ofinstances);
	printf("2018 Average: %.2lf\n", sum2018avg/num2018ofinstances);
	printf("2019 Average: %.2lf\n", sum2019avg/num2019ofinstances);
	printf("2020 Average: %.2lf\n", sum2020avg/num2020ofinstances);
	printf("2021 Average: %.2lf\n", sum2021avg/num2021ofinstances);
	
	
	
	sumavg = 0; numofinstances = 0;
	sum2015avg = 0; num2015ofinstances = 0;
	sum2016avg = 0; num2016ofinstances = 0;
	sum2017avg = 0; num2017ofinstances = 0;
	sum2018avg = 0; num2018ofinstances = 0;
	sum2019avg = 0; num2019ofinstances = 0;
	sum2020avg = 0; num2020ofinstances = 0;
	sum2021avg = 0, num2021ofinstances = 0;
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"Quebec\"")){
			numofinstances++;
			sumavg += datalist[i].value;
		}
	}for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"Quebec\"")){
			
			if((datalist[i].date == 2015)){
				
			num2015ofinstances++;
			sum2015avg += datalist[i].value;
			
		   }else if((datalist[i].date == 2016)){
			
			num2016ofinstances++;
			sum2016avg += datalist[i].value;
			
			}else if((datalist[i].date == 2017)){
				
				num2017ofinstances++;
				sum2017avg += datalist[i].value;
				
			}else if((datalist[i].date == 2018)){
				
				num2018ofinstances++;
				sum2018avg += datalist[i].value;
				
			}else if((datalist[i].date == 2019)){
				
				num2019ofinstances++;
				sum2019avg += datalist[i].value;
			}else if((datalist[i].date == 2020)){
				num2020ofinstances++;
				sum2020avg += datalist[i].value;
			}else if((datalist[i].date == 2021)){
				num2021ofinstances++;
				sum2021avg += datalist[i].value;
			}
				
			}
	}
	
	double queavg = sumavg/numofinstances;
	printf("\n\nQuebec Total Average: %.2lf\n", queavg);
	
	printf("\nQuebec Yearly Averages\n--------------\n");
	printf("2015 Average: %.2lf\n", sum2015avg/num2015ofinstances);
	printf("2016 Average: %.2lf\n", sum2016avg/num2016ofinstances);
	printf("2017 Average: %.2lf\n", sum2017avg/num2017ofinstances);
	printf("2018 Average: %.2lf\n", sum2018avg/num2018ofinstances);
	printf("2019 Average: %.2lf\n", sum2019avg/num2019ofinstances);
	printf("2020 Average: %.2lf\n", sum2020avg/num2020ofinstances);
	printf("2021 Average: %.2lf\n", sum2021avg/num2021ofinstances);
	
	sumavg = 0;
	numofinstances = 0;
	sum2015avg = 0; num2015ofinstances = 0;
	sum2016avg = 0; num2016ofinstances = 0;
	sum2017avg = 0; num2017ofinstances = 0;
	sum2018avg = 0; num2018ofinstances = 0;
	sum2019avg = 0; num2019ofinstances = 0;
	sum2020avg = 0; num2020ofinstances = 0;
	sum2021avg = 0; num2021ofinstances = 0;
	
	
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"Ontario\"")){
			numofinstances++;
			sumavg += datalist[i].value;
		}
	}for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"Ontario\"")){
			
			if((datalist[i].date == 2015)){
				
			num2015ofinstances++;
			sum2015avg += datalist[i].value;
			
		   }else if((datalist[i].date == 2016)){
			
			num2016ofinstances++;
			sum2016avg += datalist[i].value;
			
			}else if((datalist[i].date == 2017)){
				
				num2017ofinstances++;
				sum2017avg += datalist[i].value;
				
			}else if((datalist[i].date == 2018)){
				
				num2018ofinstances++;
				sum2018avg += datalist[i].value;
				
			}else if((datalist[i].date == 2019)){
				
				num2019ofinstances++;
				sum2019avg += datalist[i].value;
			}else if((datalist[i].date == 2020)){
				num2020ofinstances++;
				sum2020avg += datalist[i].value;
			}else if((datalist[i].date == 2021)){
				num2021ofinstances++;
				sum2021avg += datalist[i].value;
			}
				
			}
	}
	
	double ontavg = sumavg/numofinstances;
	printf("\nOntario Total Average: %.2lf\n", ontavg);
	
	printf("\nOntario Yearly Averages\n--------------\n");
	printf("2015 Average: %.2lf\n", sum2015avg/num2015ofinstances);
	printf("2016 Average: %.2lf\n", sum2016avg/num2016ofinstances);
	printf("2017 Average: %.2lf\n", sum2017avg/num2017ofinstances);
	printf("2018 Average: %.2lf\n", sum2018avg/num2018ofinstances);
	printf("2019 Average: %.2lf\n", sum2019avg/num2019ofinstances);
	printf("2020 Average: %.2lf\n", sum2020avg/num2020ofinstances);
	printf("2021 Average: %.2lf\n", sum2021avg/num2021ofinstances);
	
	
	sumavg = 0;
	numofinstances = 0;
	sum2015avg = 0; num2015ofinstances = 0;
	sum2016avg = 0; num2016ofinstances = 0;
	sum2017avg = 0; num2017ofinstances = 0;
	sum2018avg = 0; num2018ofinstances = 0;
	sum2019avg = 0; num2019ofinstances = 0;
	sum2020avg = 0; num2020ofinstances = 0;
	sum2021avg = 0; num2021ofinstances = 0;
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"Alberta\"")){
			numofinstances++;
			sumavg += datalist[i].value;
		}
	}for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"Alberta\"")){
			
			if((datalist[i].date == 2015)){
				
			num2015ofinstances++;
			sum2015avg += datalist[i].value;
			
		   }else if((datalist[i].date == 2016)){
			
			num2016ofinstances++;
			sum2016avg += datalist[i].value;
			
			}else if((datalist[i].date == 2017)){
				
				num2017ofinstances++;
				sum2017avg += datalist[i].value;
				
			}else if((datalist[i].date == 2018)){
				
				num2018ofinstances++;
				sum2018avg += datalist[i].value;
				
			}else if((datalist[i].date == 2019)){
				
				num2019ofinstances++;
				sum2019avg += datalist[i].value;
			}else if((datalist[i].date == 2020)){
				num2020ofinstances++;
				sum2020avg += datalist[i].value;
			}else if((datalist[i].date == 2021)){
				num2021ofinstances++;
				sum2021avg += datalist[i].value;
			}
				
			}
	}
	double albavg = sumavg/numofinstances;
	printf("\nAlberta Total Average: %.2lf\n", albavg);
	
	printf("\nAlberta Yearly Averages\n--------------\n");
	printf("2015 Average: %.2lf\n", sum2015avg/num2015ofinstances);
	printf("2016 Average: %.2lf\n", sum2016avg/num2016ofinstances);
	printf("2017 Average: %.2lf\n", sum2017avg/num2017ofinstances);
	printf("2018 Average: %.2lf\n", sum2018avg/num2018ofinstances);
	printf("2019 Average: %.2lf\n", sum2019avg/num2019ofinstances);
	printf("2020 Average: %.2lf\n", sum2020avg/num2020ofinstances);
	printf("2021 Average: %.2lf\n", sum2021avg/num2021ofinstances);
	
	
	sumavg = 0;
	numofinstances = 0;
	sum2015avg = 0; num2015ofinstances = 0;
	sum2016avg = 0; num2016ofinstances = 0;
	sum2017avg = 0; num2017ofinstances = 0;
	sum2018avg = 0; num2018ofinstances = 0;
	sum2019avg = 0; num2019ofinstances = 0;
	sum2020avg = 0; num2020ofinstances = 0;
	sum2021avg = 0; num2021ofinstances = 0;
	
	
	for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"British Columbia\"")){
			numofinstances++;
			sumavg += datalist[i].value;
		}
	}for(int i = 0; i < row+1; i++){
		if(!strcmp(datalist[i].geo, "\"British Columbia\"")){
			
			if((datalist[i].date == 2015)){
				
			num2015ofinstances++;
			sum2015avg += datalist[i].value;
			
		   }else if((datalist[i].date == 2016)){
			
			num2016ofinstances++;
			sum2016avg += datalist[i].value;
			
			}else if((datalist[i].date == 2017)){
				
				num2017ofinstances++;
				sum2017avg += datalist[i].value;
				
			}else if((datalist[i].date == 2018)){
				
				num2018ofinstances++;
				sum2018avg += datalist[i].value;
				
			}else if((datalist[i].date == 2019)){
				
				num2019ofinstances++;
				sum2019avg += datalist[i].value;
			}else if((datalist[i].date == 2020)){
				num2020ofinstances++;
				sum2020avg += datalist[i].value;
			}else if((datalist[i].date == 2021)){
				num2021ofinstances++;
				sum2021avg += datalist[i].value;
			}
				
			}
	}
	
	double bcavg = sumavg/numofinstances;
	printf("\nBritish Columbia Total Average: %.2lf\n", bcavg);
	
	printf("\nBritsih Columbia Yearly Averages\n--------------\n");
	printf("2015 Average: %.2lf\n", sum2015avg/num2015ofinstances);
	printf("2016 Average: %.2lf\n", sum2016avg/num2016ofinstances);
	printf("2017 Average: %.2lf\n", sum2017avg/num2017ofinstances);
	printf("2018 Average: %.2lf\n", sum2018avg/num2018ofinstances);
	printf("2019 Average: %.2lf\n", sum2019avg/num2019ofinstances);
	printf("2020 Average: %.2lf\n", sum2020avg/num2020ofinstances);
	printf("2021 Average: %.2lf\n", sum2021avg/num2021ofinstances);
	
	
	sumavg = 0;
	numofinstances = 0;
	sum2015avg = 0; num2015ofinstances = 0;
	sum2016avg = 0; num2016ofinstances = 0;
	sum2017avg = 0; num2017ofinstances = 0;
	sum2018avg = 0; num2018ofinstances = 0;
	sum2019avg = 0; num2019ofinstances = 0;
	sum2020avg = 0; num2020ofinstances = 0;
	sum2021avg = 0; num2021ofinstances = 0;
	
	
	
	
	return(0);
	} 


