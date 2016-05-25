#include <stdio.h>
#include <stdlib.h>
#define MAXCNT 10

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

int main()
{
    int i, mt;
    FILE *fp;
    //shape_t stars[MAXCNT];  // 構造体配列の宣言
    struct bmi_data_type data[MAXCNT];

    if( (fp = fopen( "bmi20160525.dat", "r" )) == NULL ) {
        printf( "ファイルがオープンできません\n" );
        exit( 1 );
    }
    for( i = 0; i < MAXCNT; i++ ) {
        if( fscanf( fp, "%lf\n"  , &data[i].bmi ) != 1 ) break;
    }
    fclose( fp );

    // 本来なら、入力したデータを関数などに渡して使います
    // たとえば一番背の高い人を調べる関数
    // int whoIsTallest( shape_t stars[], int num ) など
    // 関数との受け渡しは次回のTipsで ...

    mt = 3;  // ここでは3が返されたことにします
    printf( "(%f)\n", data[mt].bmi );

    return 0;
}
