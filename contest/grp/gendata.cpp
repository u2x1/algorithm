#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

#define orep(i,a,b)  for(int i=(a); i< (b); ++i)
#define crep(i,a,b)  for(int i=(a); i<=(b); ++i)
#define min(a,b)     ((a)<(b)?(a):(b))
#define min3(a,b,c)  min(min(a,b),c)
#define max(a,b)     ((a)>(b)?(a):(b))
#define max3(a,b,c)  max(max(a,b),c)
#define HIT          printf("<%s> at ln%d\n", __FUNCTION__, __LINE__); fflush(stdout);
#define PTD(v)       printf(#v ": %d\n", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\n", v); fflush(stdout);
#define PTD(v)       printf(#v ": %d\n", v); fflush(stdout);
#define NL           putchar(10);
#define RAND()       srand((unsigned)rand()), rand();


int main() {
  srand((unsigned)time(0));
  FILE* fp_out = fopen("data.in", "w");

//  int n = rand() % 2000, m = 2000000 / n;
//  int n = rand() % 20, m = 200 / n;
  int t = 5;
  fprintf(fp_out, "%d\n", t);
  srand((unsigned)rand());
  while(t--) {
    int n = 2+rand() % 10;
    srand((unsigned)rand());
    int s = rand() % 50;
    srand((unsigned)rand());
    fprintf(fp_out, "%d %d\n", n, s);
    orep(i, 0, n) { 
      fprintf(fp_out, "%d ", rand() % 10);
      srand((unsigned)rand());
    }
    fprintf(fp_out, "\n");
    PTD(n); PTD(s); NL;
  }

  // int k = rand();
  // int midx = n/2, midy = m/2;

  // fprintf(fp_out, "%d %d\n", n, m);
  // fprintf(fp_out, "%d %d %d\n", midx, midy, k);

  // int arr[n+1][m+1] = {};
  // memset(arr, 0, sizeof(arr));
  // crep(i, 1, n) {
  //   crep(j, 1, m) {
  //     arr[i][j] = ((rand() % 2) ? arr[i-1][j] : arr[i][j-1]) + (rand()%k);
  //     srand((unsigned)rand());
  //     fprintf(fp_out, "%d ", arr[i][j]);
  //   }
  //   fprintf(fp_out, "\n");
  // }
  // fclose(fp_out);
  // printf("wrote %d*%d=%d data.", n, m, n*m);

  return 0;
}
