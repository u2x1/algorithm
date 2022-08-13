#include <cstdio>
#include <cstring>

#define orep(i,a,b)  for(int i=(a); i< (b); ++i)
#define crep(i,a,b)  for(int i=(a); i<=(b); ++i)
#define abs(a)       ((a)<0?-(a):(a))
#define min(a,b)     ((a)<(b)?(a):(b))
#define min3(a,b,c)  min(min(a,b),c)
#define max(a,b)     ((a)>(b)?(a):(b))
#define max3(a,b,c)  max(max(a,b),c)
#define HIT          printf("entered <%s> at ln:%d\n", __FUNCTION__, __LINE__); fflush(stdout);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define NL           putchar(10);
#define REDIR        freopen("../../data.in", "r", stdin);

int m, k;
int l=1, r=l;
int curr=0, max;

void print(int i,int j, int *a)
{
	if (j==0) return;
	if (j==1)
	{
		printf("1 %d\n",i);
		return;
	}
	int t=i,x=a[i];
	while (x+a[t-1] <= max)
	{
		x+=a[--t];
	}
	print(t-1,j-1,a);
	printf("%d %d\n",t,i);
}

int main() {
  scanf("%d%d", &m, &k);
  int arr[m+1]={0};
  int a[m+1]={0};
  crep(i, 1, m) { scanf("%d", arr+i); a[i] = arr[i]; arr[i] += arr[i-1]; }

  int dp[k+1][m+1];
  memset(dp, 0x3f, sizeof(dp));
  crep(i, 1, m) { dp[1][i] = arr[i]; }
  crep(kk, 2, k) {
    crep(ii, 1, m) {
      orep(jj, 1, ii) {
        dp[kk][ii] = min(dp[kk][ii], max(dp[kk-1][jj], arr[ii]-arr[jj]));
      }
    }
  }

  max = dp[k][m];
  print(m,k,a);
  return 0;
}
