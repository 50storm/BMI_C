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


struct bmi_data_type{

   double height;
   double weight;
   double bmi;

};




int is_valid_input(double);
void showErrMsg(const char * , double );


int main(int argc, const char * argv[]) {
    FILE *fp;
    //fp = fopen("data.dat","a+");
    fp = fopen("data.dat","r");
    if( fp == NULL ){
        printf("File[data.dat] does not exist.¥n");
    
        return -1;


    }
    char read_data [20];
    printf("Read by fscanf() --------------------------------------\n");
    
    //while(fscanf( fp, "%s", read_data) != EOF){
    //    printf( "%s\n", read_data);
    //}

    printf("Read by fgets() ----------------------------------------\n");
    while (fgets(read_data, 256, fp) != NULL) {
        printf("%s", read_data);
    }


    int fat, thin, normal;
    double h, w, bmi;
    
    int flg_h=1;
    while (1) {
        printf("Please input your height (cm):");
        scanf("%lf",&h );

        flg_h = is_valid_input(h);
        if(flg_h)break;
        else showErrMsg("height",h);
    }
    
    
    int flg_w=1;
    while (flg_w) {
        printf("Please input your weight (cm):");
        scanf("%lf",&w);
        
        flg_w = is_valid_input(w);
        if(flg_w)break;
        else showErrMsg("weight",w);
   } 
    
    
    
    bmi = w*10000/(h*h);
    fat = (bmi>25.0);
    thin = (bmi<=18.5);
    normal = (!fat) && (!thin);
    
    printf("BMI=%4.1f FAT:%d NORMANL:%d THIN:%d\n", bmi, fat, normal, thin);
    
    if(fat) printf("You are fat\n");
    else if(thin) printf("You are thin\n");
    else printf("You are normal\n");	
    




    //書き込み
    fprintf(fp, "BMI=%4.1f FAT:%d NORMANL:%d THIN:%d\n", bmi, fat, normal, thin);
    
    fclose(fp);

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

void showErrMsg(const char *msg ,double h){
    printf("Wrong input:%s:%f \n\n",msg, h);

};
