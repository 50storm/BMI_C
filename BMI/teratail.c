#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char *fname = "a.txt";
    char str[100];
    char vStr[100];
    int v;
    long sum[3];
    int i;
    int j;
    int count;
    int type;

    for(i = 0; i < 3; i++)
        sum[i] = 0;

    fp = fopen( fname, "r" );
    if(fp != NULL )        {
        while(fgets(str, 100, fp ) != NULL)    {

            type = 0;

            for(i = 0; i < 100; i++) {

                char c = str[i];
                printf("%c\n",c);

                if(c == ':') {
                    count = 0;
                    memset(vStr, 0, 100);
                    puts(vStr);


                    for(j = i + 1; j < 100; j++) {
                        c = str[j];
                        printf("%c\n",c);


                        if(c != ' ')
                            vStr[count] = c;
                        else
                            break;

                        count++;
                    }

                    vStr[count] = '\0';
                    v = atoi(vStr);
                    sum[type] += v;

                    i = j;

                    type++;
                }

            }
        }

        printf("%ld %ld %ld\n", sum[0], sum[1], sum[2]);
    }

    fclose(fp);

    return 0;
}