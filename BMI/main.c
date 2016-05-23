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

enum menu {REGISTER = 1 , DISPLAY = 2, EXIT = 9, ERR = -1  };
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
   double height;
   double weight;
   double bmi;

};

struct flg_type{
    int height;
    int weight;
    int poo;
};

/*prototype*/
int show_menu(void);
int is_valid_input(double);
void showErrMsg(const char * , double , int);


int main(int argc, const char * argv[]) {
    struct bmi_data_type data;
    struct flg_type flg;

    time_t timer;
    struct tm *local;
    struct tm *utc;

    /* 現在時刻を取得 */
    timer = time(NULL);
	local = localtime(&timer); 
	/*
    printf("%4d/", local->tm_year + 1900);
    printf("%2d/", local->tm_mon + 1);
    printf("%2d ", local->tm_mday);
    printf("%2d:", local->tm_hour);
    printf("%2d:", local->tm_min);
    printf("%2d", local->tm_sec);
    printf(" %d\n", local->tm_isdst);
	*/
	
    data.year = local->tm_year + 1900;
    data.month = local->tm_mon + 1;
    data.day = local->tm_mday;
    data.hour = local->tm_hour;
    data.min = local->tm_min;
    data.sec = local->tm_sec;
    
    /*charに変換*/
    sprintf(data.str_year, "%d", data.year);
    printf("%s", data.str_year);
    sprintf(data.str_month, "%02d", data.month);
    printf("%s", data.str_month);
    sprintf(data.str_day, "%02d", data.day);
    printf("%s", data.str_day);
    sprintf(data.str_hour, "%02d", data.hour);
    printf("%s", data.str_hour);
    sprintf(data.str_min, "%02d", data.min);
    printf("%s", data.str_min);
    sprintf(data.str_sec, "%02d", data.sec);
    printf("%s", data.str_sec);

    printf("\n");
    printf("\n");
   /* 結合*/
    char filename [50]="bmi";
    printf("----------------------\n");
    strcat(filename, data.str_year);
    strcat(filename, data.str_month);
    strcat(filename, data.str_day);
    strcat(filename, ".dat");
    printf("%s",filename);
//return 0;
 
/*
    fprintf(filename,  "%s%s%s%s%s%s%s" ,  data.str_year, data.str_month, data.str_day, data.str_hour,  data.str_hour,  data.str_min, data.str_sec);
printf("%s", filename);

*/
    int i_menu;
    i_menu = show_menu();

    switch(i_menu){
    case REGISTER:
            printf("####  Registration  ####\n");
            flg.height=1;
            while (1) {
                printf("Please input your height (cm):");
                scanf("%lf",&data.height );

                flg.height = is_valid_input(data.height);
                if(flg.height)break;
                else showErrMsg("height", data.height, 0 );
            }
            
            flg.weight=1;
            while (1) {
                printf("Please input your weight (cm):");
                scanf("%lf",&data.weight);
                
                flg.weight = is_valid_input(data.weight);
                if(flg.weight)break;
                else showErrMsg("weight",data.weight, 0 ) ;
           } 
            
            flg.poo=1;
            while (1) {
                printf("Did you poo today?[yes:1,no:0]:");
                scanf("%d",&data.poo);
                
                flg.poo = is_valid_input(data.poo);
                if(flg.poo)break;
                else showErrMsg("poo", 0.0, data.poo);
           } 
            
            data.bmi = data.weight*10000/(data.height*data.height);
            data.fat = (data.bmi>25.0);
            data.thin = (data.bmi<=18.5);
            data.normal = (!data.fat) && (!data.thin);
            
            printf("BMI=%4.1f FAT:%d NORMANL:%d THIN:%d\n", data.bmi, data.fat, data.normal, data.thin);
            
           
            if(data.fat) printf("You are fat\n");
            else if(data.thin) printf("You are thin\n");
            else printf("You are normal\n");

            FILE *fp;
		//fp = fopen("bmi.dat","a+");
            //個別
            fp = fopen(filename,"a+");
            fprintf(fp,  "%4d-%02d-%02d-%02d-%02d-%02d-%02d\n" ,      data.year, data.month, data.day, data.hour,  data.hour,  data.min, data.sec);
            fprintf(fp, "BMI=%4.1f FAT:%d NORMANL:%d THIN:%d\n", data.bmi, data.fat, data.normal, data.thin);
            fclose(fp);
            break;

    case DISPLAY:
    printf("Display\n");
    


    break;
    }
    return 0;

}

int is_valid_input(double val){
    //printf("%f",val);
    if(val <= 0){
	return 0;
    }else{
	return 1;
    }

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
    printf("======================================\n");
    printf("   Register BMI DATA(presskey:1)      \n");
    printf("   Disply BMI DATA(presskey:2)        \n");
    printf("   Exit(presskey:9)                   \n");
    printf("======================================\n");
    printf("===>>:");
    scanf("%d",&i_menu);
    if( i_menu == REGISTER || i_menu==DISPLAY || i_menu == EXIT ){
        return i_menu;
    }else {
        //   printf("Please select 1 or 2 or9 \n");
        return -1;
    }
     
}
