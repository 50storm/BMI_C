//
//  main.c
//  BMI
//
//  Created by 五十嵐博司 on 2016/05/18.
//  Copyright © 2016年 五十嵐博司. All rights reserved.
//
//True : 1  / False : 0

//file mode
//http://simd.jugem.jp/?eid=46

//http://dixq.net/forum/viewtopic.php?f=3&t=7073
//http://oshiete.goo.ne.jp/qa/2920993.html
//メニュー
//ファイルがない=>新規データ作成、ファイルがある=>データ追加、データ削除
//データをファイルに保存
//データを削除できる
//データを修正できる（難しそう）
//日付、名前、うんち
//うんちが3日出てない。便秘注意！

#include <stdio.h>
#include <time.h>
#include <string.h>
#define DEBUG 1
#define println()(printf("\n"))

/* enum */
enum menu {REGISTER = 1 , DISPLAY_DATA = 2, DISPLAT_ALL_DATA = 3,  EXIT = 9, ERR = -1  };
struct bmi_data_type{
	int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
	char str_year[5];
    char str_month[3];
    char str_day[3];
    char str_hour[3];
    char str_min[3];
    char str_sec[3];
	int fat;
    int thin;
    int normal;
    int poo;    
    int steps;
	double height;
    double weight;
    double bmi;
};
struct  input_date_type{
    int year;
    int month;
    int day;
    char str_year[5];
    char str_month[3];
    char str_day[3];
};


/*  prototype functions */
int show_menu(void);
int isGreaterThan0(double);
void showErrMsg(const char * , double , int);
void setDateTime(struct bmi_data_type *);
void addYYYYMMDD(char [],  struct bmi_data_type *);
void addInYYYYMMDD(char [], struct input_date_type *);
void registerData(struct bmi_data_type *, char[]);
void writeDayData(struct bmi_data_type *, char []);
void setStrInDate(struct input_date_type *);
int showAllData();

int main(int argc, const char * argv[]) {
	struct bmi_data_type data;
    struct input_date_type in_date;


	setDateTime(&data);
	char filename[50]="bmi";

	switch(show_menu()){
		case REGISTER:
			registerData(&data, filename);
			break;

        case DISPLAY_DATA:
 
            printf("Please input year[yyyy]:\n");
            scanf("%d", &in_date.year);
/*
            ret = scanf("%d", yyyy)
            if(ret != 1){
                scanf("%*s");
                continue;
            }else{
                break;
            }

*/

            printf("Please input month[mm]:\n");
            scanf("%d", &in_date.month);

            printf("Please input day[dd]:\n");
            scanf("%d", &in_date.day);

            setStrInDate(&in_date);
            addInYYYYMMDD(filename, &in_date);


            FILE *fpDay;
          
#if DEBUG == 1
            println();
            printf("%s\n", filename);
            println();
#endif
            fpDay = fopen(filename,"r");
            if( fpDay == NULL ){
                 printf("File[%s] does not exist.\n",filename);
                 return -1;
            }
            char read_day_data [20];
            char pg_data[20];
            //printf("Read by fscanf() --------------------------------------\n");
            
            //while(fscanf( fp, "%s", read_data) != EOF){
            //    printf( "%s\n", read_data);
            //}

            printf("Read by fgets() ----------------------------------------\n");
            int j=0;

            while (fgets(read_day_data, 256, fpDay) != NULL) {
            /*
                printf("%c¥n", read_day_data[0]);
                printf("%c¥n", read_day_data[1]);
                printf("%c¥n", read_day_data[2]);
                printf("%c¥n", read_day_data[3]);
                printf("%c¥n", read_day_data[4]);
                printf("%c¥n", read_day_data[5]);
              */  
                printf("%s", read_day_data);
                
              //  fputs(read_day_data, fpDay);
              // pg_data[j] = read_day_data[j];
              // j=j+1;


            }
            //printf("%s", pg_data);//最後だけ


            break;

		case DISPLAT_ALL_DATA:
            showAllData();
			break;
		case EXIT:
			printf("Bye!\n");
			break;
	}
	return 0;
}

int showAllData(){
            printf("Displaying log...\n");

            FILE *fp;
            fp = fopen("bmi.dat","r");
            if( fp == NULL ){
                 printf("File[data.dat] does not exist.\n");
                 return -1;
            }
            char read_data [20];
            printf("Read by fscanf() --------------------------------------\n");
            char *wp;

            while(fscanf( fp, "%s", read_data) != EOF){
                printf( "%s\n", read_data);

                wp = strtok(read_data, "=");

                printf("%s\n", wp);
                //printf("%c\n", wp[0]);
                

                /*
                printf("%c\n", read_data[0]);
                printf("%c\n", read_data[1]);
                printf("%c\n", read_data[2]);
                printf("%c\n", read_data[3]);
                printf("%c\n", read_data[4]);
                printf("%c\n", read_data[5]);
                printf("%c\n", read_data[6]);
                printf("%c\n", read_data[7]);
                printf("%c\n", read_data[8]);
                printf("%c\n", read_data[9]);
                printf("%c\n", read_data[10]);
                printf("%c\n", read_data[11]);
                printf("%c\n", read_data[12]);
                printf("%c\n", read_data[13]);
                */

            }
/*
            //printf("Read by fgets() ----------------------------------------\n");
            while (fgets(read_data, 256, fp) != NULL) {
                printf("%s", read_data);
                printf("%c\n", read_data[0]);
                printf("%c\n", read_data[1]);
                printf("%c\n", read_data[2]);
                printf("%c\n", read_data[3]);
                printf("%c\n", read_data[4]);
                printf("%c\n", read_data[5]);
                printf("%c\n", read_data[6]);
                printf("%c\n", read_data[7]);
                printf("%c\n", read_data[8]);
                printf("%c\n", read_data[9]);
                printf("%c\n", read_data[10]);
                printf("%c\n", read_data[11]);
                printf("%c\n", read_data[12]);
                printf("%c\n", read_data[13]);

            }
*/
	return 0;
}


int isGreaterThan0(double val){
	if(val <= 0.0 ){
        printf("val <= 0.0 ");
        println();
        printf("%f",val);
		return 0;
	}else{
        printf("NOT val <= 0.0 ");
        println();
        printf("%f",val);
		return 1;
	}
}



void registerData(struct bmi_data_type *data, char filename[]){
	int ret;
    //addYYYYMMDD(filename, &data);
    addYYYYMMDD(filename, data);

	printf("####  Registration  ####\n");
	while (1) {
		printf("Please input your height (cm):");
		ret = scanf("%lf",&data->height );
#if DEBUG  == 1
        println();
        printf("%d", ret);println();
        printf("%f", data->height );println();
        println();

#endif        
		if(ret != 1){
			scanf("%*s");
			continue;
		}else{
			if(isGreaterThan0(data->height))break;
			else showErrMsg("height", data->height, 0 );
		}
	}

	while (1) {
		printf("Please input your weight (cm):");
		ret = scanf("%lf",&data->weight);
    
		if(ret != 1){
			scanf("%*s");
			continue;
		}else{
            //10-
			if(isGreaterThan0(data->weight))break;
			else showErrMsg("weight",data->weight, 0 ) ;
		}
	} 

	while (1) {
		printf("Did you poo today?[yes:1,no:0]:");
		scanf("%d",&data->poo);
		if(ret != 1){
			scanf("%*s");
			continue;
		}else{
			if(data->poo >= 0 && data->poo <= 1){
				break;
			}else{
				showErrMsg("poo", 0.0, data->poo);  
			}
		} 
	}


    while (1) {
        printf("How many steps did you walk today?:");
        scanf("%d",&data->steps);
        if(ret != 1){
            scanf("%*s");
            continue;
        }else{
            if(isGreaterThan0(data->steps))break;
            else showErrMsg("steps",0.0, data->steps);
        }  
    }
	data->bmi = data->weight*10000/(data->height*data->height);
	data->fat = (data->bmi>25.0);
	data->thin = (data->bmi<=18.5);
	data->normal = (!data->fat) && (!data->thin);

	printf("BMI=%4.1f FAT:%d NORMANL:%d THIN:%d POO:%d STEPS:%d \n",
            data->bmi, data->fat, data->normal, data->thin, data->poo, data->steps);	

	int flg_save;
	while (1) {

		printf("Do you want to save this data ?[yes:1,no:0]:");
		ret = scanf("%d",&flg_save);
		if(ret != 1){
			scanf("%*s");
			continue;
		}else{
			if(flg_save==1){
				FILE *fp;
				fp = fopen(filename,"w");
				fprintf(fp, "BMI=%4.1f FAT:%d NORMANL:%d THIN:%d POO:%d  STEPS:%d \n", 
                        data->bmi, data->fat, data->normal, data->thin, data->poo, data->steps);
				fclose(fp);
				printf("Your data has been saved.[filename:%s]" , filename);
				println();
                /*log*/
                fp = fopen("bmi.dat","a+");
                fprintf(fp, "BMI=%4.1f FAT:%d NORMANL:%d THIN:%d POO:%d   STEPS:%d \n", 
                        data->bmi, data->fat, data->normal, data->thin, data->poo, data->steps);
                fclose(fp);
            

				break;
			}else{
                break;
            }
		}


	}

}




void addInYYYYMMDD(char filename[], struct input_date_type *date){

#if DEBUG  == 1
    printf("=============addInYYYYMMDD=========================\n");
    printf("%s\n", filename);
    printf("=============addInYYYYMMDD=========================\n");   
#endif
    strcat(filename, date->str_year);
    strcat(filename, date->str_month);
    strcat(filename, date->str_day);
    strcat(filename, ".dat");

#if DEBUG  == 1
    printf("=============addInYYYYMMDD=========================\n");
    printf("%s\n", filename);
    printf("=============addInYYYYMMDD=========================\n");   
#endif
}

void addYYYYMMDD(char filename[], struct bmi_data_type *data){

	strcat(filename, data->str_year);
	strcat(filename, data->str_month);
	strcat(filename, data->str_day);
	strcat(filename, ".dat");

    #if DEBUG  == 1
	printf("=============addYYYYMMDD=========================\n");
	printf("%s\n", filename);
	printf("=============addYYYYMMDD=========================\n");   
    #endif
}

void showErrMsg(const char *msg , double d_val, int i_val){
	if( i_val == 0 && d_val !=0.0 )
	{
		printf("Wrong input:%s:%f \n\n",msg, d_val);
	}
	else if( i_val != 0 && d_val ==0.0 )
	{
		printf("Wrong input:%s:%d \n\n",msg, i_val);
	}
}

int show_menu(void){
	int i_menu;
	int ret;
	while(1){
		printf("======================================\n");
		printf("   Register BMI DATA(presskey:1)      \n");
		printf("   Disply BMI DATA(presskey:2)        \n");
        printf("   Disply  ALL BMI DATA(presskey:3)   \n");
		printf("   Exit(presskey:9)                   \n");
		printf("======================================\n");
		printf(":");
		ret = scanf("%d",&i_menu);
#if DEBUG  == 1
        println();
        printf("%d", ret);println();
        printf("%d", i_menu);println();
        println();

#endif
		if(ret != 1){
			scanf("%*s");
			continue;
		}else{
			if( i_menu == REGISTER|| i_menu==DISPLAY_DATA || i_menu==DISPLAT_ALL_DATA || i_menu == EXIT ){
				return i_menu;
			} else {
				continue;
			}
		}
	}
}


void setStrInDate(struct input_date_type *in_date){
    sprintf(in_date->str_year, "%d", in_date->year);
    sprintf(in_date->str_month, "%02d", in_date->month);
    sprintf(in_date->str_day, "%02d", in_date->day);
#if DEBUG  == 1
    printf("----------setStrInDate------\n");
    printf("%s\n",in_date->str_year);
    printf("%s\n",in_date->str_month);
    printf("%s\n",in_date->str_day);
    
#endif



}

void setDateTime(struct bmi_data_type *data){
#if DEBUG  == 1
	printf("----------setDateTime------\n");
#endif
	time_t timer;
	struct tm *local;
	struct tm *utc;

	timer = time(NULL);
	local = localtime(&timer);

	data->year = local->tm_year + 1900;
	data->month = local->tm_mon + 1;
	data->day = local->tm_mday;
	data->hour = 
    local->tm_hour;
	data->min = local->tm_min;
	data->sec = local->tm_sec;

	sprintf(data->str_year, "%d", data->year);
	sprintf(data->str_month, "%02d", data->month);
	sprintf(data->str_day, "%02d", data->day);
	sprintf(data->str_hour, "%02d", data->hour);
	sprintf(data->str_min, "%02d", data->min);
	sprintf(data->str_sec, "%02d", data->sec);

#if DEBUG  == 1
	printf("%s", data->str_year);
	printf("%s", data->str_month);
	printf("%s", data->str_day);
	printf("%s", data->str_hour);
	printf("%s", data->str_min);
	printf("%s", data->str_sec);

	printf("----------setDateTime------\n");
	println();
	println();
	println();
#endif

}
