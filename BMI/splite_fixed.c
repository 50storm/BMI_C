// 固定バージョン
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 100
#define NELEMS(a) (sizeof(a) / sizeof(a[0]))

static int in(const char *s, const char c);

int split(char *ary[], int len, const char *s, const char *delimiter)
{
  char buf[BUF_SIZE];
  
  int i, j;
  for (i = 0; i < len && *s != '\0'; i++) {
    while (in(delimiter, *s))
      s++;
    for (j = 0; j < BUF_SIZE && *s != '\0' && !in(delimiter, *s); j++, s++)
      buf[j] = *s;
      puts(buf);
    
    buf[j] = '\0';
    if (j == 0) break;
    ary[i] = strdup(buf);
  }
  
  return i;
}

static int in(const char *s, const char c)
{
  int i;
  for (i = 0; s[i] != '\0'; i++)
    if (s[i] == c) return 1;
  return 0;
}

int main(void)
{
  char str[] = "I stand here today humbled by the task before us, "
               "grateful for the trust you have bestowed, "
               "mindful of the sacrifices borne by our ancestors.";
  char delimiter[] = " ";
  
  int len, i;
  char *ary[100];
  
  len = split(ary, NELEMS(ary), str, delimiter);
  
  for (i = 0; i < len; i++)
    printf("%2d : [%s]\n", i, ary[i]);
  
  return 0;
}