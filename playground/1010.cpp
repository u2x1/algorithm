#include<bits/stdc++.h>

using namespace std;
#define orep(i, a, b) for(int i = a; i < b; ++i)
const int maxn=105;
int n,m,T,ans,k;
int x[maxn],y[maxn],sur[maxn];
int dx[5]={0,-1,0,0,1},dy[5]={0,0,-1,1,0};

int vis[1000000];

void dfs() {
 int tot=0;
 for(int i=1;i<=k;i++)
  if(sur[i])
   tot++;
 ans=min(ans,tot);
 for(int i=1;i<=k;i++)
  if(sur[i])
   for(int j=1;j<=k;j++)
    if(i!=j&&sur[j]&&abs(x[i]-x[j])+abs(y[i]-y[j])<=1){
     int nx=2*x[j]-x[i],ny=2*y[j]-y[i];
     if(nx>=1&&nx<=n&&ny>=1&&ny<=m){
      int ban=0;
      for(int p=1;p<=k;p++)
       if(sur[p]&&x[p]==nx&&y[p]==ny){
        ban=1;
        break;
       }
      if(ban==0){
       swap(x[i],nx),swap(y[i],ny),sur[j]=0;
       dfs();
       swap(x[i],nx),swap(y[i],ny),sur[j]=1;
      }
     }
    }
}

int main(){
 // scanf("%d",&T);
 // while(T--){
 orep(a, 4, 15) {
   orep(b, 3, 4) {
     k = 1;
     n = a, m = b;
     orep(i, 2, a) {
       orep(j, 2, b) {
         x[k] = i; y[k] = j; sur[k] = 1; ++k;
       }
     }
     --k; ans = k;
     dfs();
     printf("%d %d = %d\n", n-2, m-2, ans);
   }
 }
 return 0;
}
