#include <cstdio>

int month_day(int year, int yearday, int *pmonth, int *pday) 
{  // Add your code here
if(yearday>367){
  return 0;
}
 int k,leap;
    int tab[2][13]={
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31},  
    };
    
    leap=((year%4==0&&year%100!=0)||(year%400==0));
    printf("leap %d\n", leap);
    
    for(k=1;k < 13 && yearday>tab[leap][k];k++) {
      yearday -= tab[leap][k];
      printf("yearday %d k %d\n", yearday, k);
    }
    *pmonth=k;
    *pday=yearday;
    printf("%d  %d\n",*pmonth,yearday);
    if(*pmonth>13){
      return 0;
    }
  return 1;
}

int main() {
  int pmonth, pday;
  month_day(1996, 366, &pmonth, &pday);
  printf("pMonth %d pDay %d", pmonth, pday);
  return 0;
}
