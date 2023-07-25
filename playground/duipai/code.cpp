#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define eb emplace_back
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define ull unsigned ll
#define i128 __int128

using namespace std;

int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字「加」在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 '0' 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}

const ll inf = 1e18;

namespace qiqi {
	mt19937_64 gen(random_device{}());
	const ll V = 1e9,M = 1e8,N = 1e5;
	int n,T; pll q[N]; ll p[N],vis[N];
	bool chk(pll k) {
		if (k.fi < 0 || (k.fi == 0 && k.se < 0)) {
			k.fi = -k.fi; k.se = -k.se;
		}
		ll x = V*k.fi+k.se;
		int cnt = 0;
		for (int i = 0,j = 0; i < n; i++) {
			if (vis[i] != T) {
				ll y = p[i]+x;
				while (vis[j] == T || p[j] < y) {
					j++;
				}
				if (j == n || p[j] != y) {
					return 0;
				}
				vis[i] = vis[j] = T;
				cnt+=2;
				if (cnt == n) {
					return 1;
				}
			}
		}
		return 0;
	}
	void main() {
		n = read() * 2;
		for (int i = 0; i < n; i++) {
			q[i].fi = read(); q[i].se = read();
			q[i].fi += M; q[i].se += M;
			p[i] = V*q[i].fi+q[i].se;
		}
		// if (n > 10000) {
		// 	shuffle(q,q+n,gen);
		// }
		sort(p,p+n);
    p[n] = inf;
		vector<pll> ans;
		for (int i = 1; i < n; i++) {
			pll k = pair(q[i].fi-q[0].fi,q[i].se-q[0].se);
			T++;
			if (chk(k)) {
				ans.eb(k);
				if (k != pll(0,0)) {
					ans.eb(-k.fi,-k.se);
				}
			}
		}
    printf("%d\n", (int)sz(ans));
		for (auto [x,y]:ans) {
      printf("%lld %lld\n", x, y);
		}
	}
}
int main() {
//	clock_t st = clock();
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);

	int T = read();
	while (T--) {
		qiqi::main();
	}
//	cout << (double)(clock()-st)/CLOCKS_PER_SEC;
	return 0;
}
