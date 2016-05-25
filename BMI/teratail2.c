#include <stdio.h>

int main()
{
    char buf[100];
    int suma = 0;
    int sumb = 0;
    int sumc = 0;
    FILE *fp = fopen("data.txt", "r");
    if(fp != NULL)
    {
        while(fgets(buf, 100, fp) != NULL)
        {
            int a, b, c;
            int count = sscanf(buf, "A:%d B:%d C:%d", &a, &b, &c);
            if(count == 3)
            {
                suma += a;
                sumb += b;
                sumc += c;
            }
        }
        printf("A:%d B:%d C:%d\n", suma, sumb, sumc);
        fclose(fp);
    }
    return 0;
}