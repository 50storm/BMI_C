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
enum menu {REGISTER = 1 , DISPLAY = 2, EXIT = 9, ERR = -1  };


struct bmi_data_type{
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


int show_menu(void);
int is_valid_input(double);
void showErrMsg(const char * , double , int);


int main(int argc, const char * argv[]) {
    struct bmi_data_type data;
    struct flg_type flg;

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
    

    break;

    case DISPLAY:
    printf("Display\n");
    


    break;
    }
    return 0;




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
