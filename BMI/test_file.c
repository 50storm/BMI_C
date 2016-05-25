#include <stdio.h>
#include <stdlib.h>
#define MAXCNT 10

typedef struct {        // 構造体の宣言
    char name[16];
    float height;
    float weight;
} shape_t;

int main()
{
    int i, mt;
    FILE *fp;
    shape_t stars[MAXCNT];  // 構造体配列の宣言

    if( (fp = fopen( "starsdata.txt", "r" )) == NULL ) {
        printf( "ファイルがオープンできません\n" );
        exit( 1 );
    }
    for( i = 0; i < MAXCNT; i++ ) {
        if( fscanf( fp, "%s %f %f\n"      // 構造体配列への読み込み
        , stars[i].name, &stars[i].height, &stars[i].weight ) != 3 ) break;
    }
    fclose( fp );

    // 本来なら、入力したデータを関数などに渡して使います
    // たとえば一番背の高い人を調べる関数
    // int whoIsTallest( shape_t stars[], int num ) など
    // 関数との受け渡しは次回のTipsで ...

    mt = 3;  // ここでは3が返されたことにします
    printf( "The tallest is %s(%.1fcm)\n", stars[mt].name, stars[mt].height );

    return 0;
}
