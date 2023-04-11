#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          putchar(10);

const int maxN = 1e5+5;
long long arr[maxN];
std::vector<int> son[maxN];
int dep[maxN];
int depcnt[maxN];
long long memo[maxN][50];
int fa[maxN];
int id[maxN];

inline int read() {
	int ret = 0; char c=getchar();
	while(c < '0' || c > '9') { c=getchar(); }
	while(c >= '0' && c <= '9') { ret = ret*10+c-'0'; c=getchar();}
	return ret;
}

inline void write(const long long x) {
  if (x>9) { write(x/10); }
	putchar(x%10+'0');
}

long long find(int x, int y) {
	if (!x && !y) { return 0; }
  if (x > y) { std::swap(x, y); }
  
	if (id[y] < 50 && memo[x][id[y]]) {
		return memo[x][id[y]];
	}
	long long ret = arr[x] * arr[y] + find(fa[x], fa[y]);
	if (id[y] < 50) {
		memo[x][id[y]] = ret;
	}
	return ret;
}

signed main() {
	int n =read(), q=read();
	orep(i, 1, n+1) { arr[i] = read(); }
	orep(u, 2, n+1) {
		int faa = read();
		fa[u] = faa;
		son[faa].push_back(u);
		dep[u] = dep[faa]+1;
		id[u] = depcnt[dep[u]]++;
	}
	orep(i, 0, q) {
		int a = read(), b = read();
		write(find(a, b)); NL;
	}
	
  return 0;
}
