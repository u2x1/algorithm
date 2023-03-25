#include<bits/stdc++.h>
//#include <cstdio>
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define drep(i,a,b) for (int i = (a); i >= (b); --i)
#define grep(i,u) for (int i = head[u],v = e[i].v; i; v = e[i = e[i].nxt].v)
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>
#define fi first
#define se second
#define eb emplace_back
#define mp make_pair
using namespace std;
LL read() {
    LL  x = 0,y = 1; char ch = getchar(); while (!isdigit(ch)) {if (ch == '-') y = -y; ch = getchar();}
    while (isdigit(ch)) {x = x*10+ch-'0'; ch = getchar();} return x*y;
}
namespace qiqi {
    const int N = 5e7+5,M = 2005,INF = 0x3f3f3f3f; int n,m,s,t,ecnt,cur[N],head[N],dep[N];
    vector<int> p[M][M]; struct Data {int x0,y0,x1,y1;} a[N]; struct Edge {int v,f,nxt;} e[N];
    void add(int u,int v,int f) {e[++ecnt] = (Edge){v,f,head[u]}; head[u] = ecnt;}
    void f_add(int u,int v,int f) {add(u,v,f); add(v,u,0);}
    bool bfs(int s,int t) {
        rep(i,1,t) {cur[i] = head[i]; dep[i] = 0;}
        queue<int> q; dep[s] = 1; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            grep(i,u) if (!dep[v] && e[i].f) {
                dep[v] = dep[u]+1; q.push(v);
            }
        }
        return dep[t] != 0;
    }
    int dfs(int u,int t,int f) {
        if (!f || u == t) return f; int res = 0,k;
        for (int &i = cur[u],v = e[i].v; i; v = e[i = e[i].nxt].v) {
            if (dep[v] == dep[u]+1 && (k = dfs(v,t,min(f,e[i].f)))) {
                res += k; f -= k; e[i].f -= k; e[i^1].f += k; if (!f) break;
            }
        }
        return res;
    }
    int Dinic(int s,int t) {int res = 0; while (bfs(s,t)) res += dfs(s,t,INF); return res;}
    void main() {
        n = read(); m = read(); s = n+m+1; t = s+1;
        ecnt = 1; rep(i,1,t) head[i] = 0;
        rep(i,1,n) {
            int x0 = read(),y0 = read(),x1 = read(),y1 = read();
            a[i] = (Data){x0,y0,x1,y1}; f_add(s,i,1);
            rep(j,x0,x1) rep(k,y0,y1) p[j][k].eb(i);
        }
        rep(i,n+1,n+m) {
            int x0 = read(),y0 = read(),x1 = read(),y1 = read(); f_add(i,t,1);
            rep(x,x0,x1) rep(y,y0,y1) for (auto j:p[x][y]) {
                if ((min(x1,a[j].x1)-max(x0,a[j].x0))*(min(y1,a[j].y1)-max(y0,a[j].y0))*2 >= (a[j].x1-a[j].x0)*(a[j].y1-a[j].y0)) f_add(j,i,1);
            }
        }
        rep(i,1,n) rep(j,a[i].x0,a[i].x1) rep(k,a[i].y0,a[i].y1) p[j][k].clear();
        printf("%d\n",Dinic(s,t));
    }
}
int main() {
    int T = read(); while (T--) qiqi::main();
    putchar('aa');
    return 0;
}
