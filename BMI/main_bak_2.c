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
   int fat;
   int thin;
   int normal;
   double height;
   double weight;
   double bmi;

};

struct flg_type{
    int height;
    int weight;
};


int is_valid_input(double);
void showErrMsg(const char * , double );


int main(int argc, const char * argv[]) {
    struct bmi_data_type data;
    struct flg_type flg;
  
   while(1){
     switch



   }


    flg.height=1;
    while (1) {
        printf("Please input your height (cm):");
        scanf("%lf",&data.height );

        flg.height = is_valid_input(data.height);
        if(flg.height)break;
        else showErrMsg("height", data.height);
    }
    
    flg.weight=1;
    while (1) {
        printf("Please input your weight (cm):");
        scanf("%lf",&data.weight);
        
        flg.weight = is_valid_input(data.weight);
        if(flg.weight)break;
        else showErrMsg("weight",data.weight);
   } 
    
    
    
    data.bmi = data.weight*10000/(data.height*data.height);
    data.fat = (data.bmi>25.0);
    data.thin = (data.bmi<=18.5);
    data.normal = (!data.fat) && (!data.thin);
    
    printf("BMI=%4.1f FAT:%d NORMANL:%d THIN:%d\n", data.bmi, data.fat, data.normal, data.thin);
    
   
    if(data.fat) printf("You are fat\n");
    else if(data.thin) printf("You are thin\n");
    else printf("You are normal\n");	
    



/*
    //書き込み
    fprintf(fp, "BMI=%4.1f FAT:%d NORMANL:%d THIN:%d\n", bmi, fat, normal, thin);
    
    fclose(fp);

    return 0;
*/
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
