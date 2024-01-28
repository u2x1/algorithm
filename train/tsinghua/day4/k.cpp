#include <bits/stdc++.h>
#define NL std::cout << '\n'
using ll = long long;
const ll inf = 1e12,mo = 998244353;

void solve(){
	int n, m; std::cin >> n >> m;
	std::map<int, char> rpar, lpar;
	std::map<int, char> lcon, rcon;
	int sum1 = 0, sum2 = 0;
	for(int i = 0, curx = 1, cury = 1; i < n+m-1; ++i) {
		int x;
		std::cin >> x; sum1 ^= x;
		rcon[curx+cury] = x;
		cury = (curx == m ? cury + 1: cury);
		curx = std::min(m, curx+1);
	}
	for(int i = 0, curx = m, cury = 1; i < n+m-1; ++i) {
		int x; std::cin >> x; sum2 ^= x;
		lcon[curx-cury] = x;
		cury = (curx == 1 ? cury + 1: cury);
		curx = std::max(1, curx-1);
	}
	if (sum1 != sum2) { std::cout << -1; exit(0); }
	std::set<std::pair<int, int>> ret;
  std::map<std::pair<int, int>, char> isSet;
	for(int i = 0, curx = 1, cury = 1; i < n+m-1; ++i) {
		if (rcon[curx+cury]) {
			rpar[curx+cury] ^= 1; lpar[curx-cury] ^= 1; isSet[{curx, cury}] = 1;
			ret.emplace(curx, cury);
		}
		cury = (curx == m ? cury+1: cury);
		curx = std::min(m, curx+1);
	}
	const auto isBound = [&](int x, int y) { return x == m || y == 1; };
  const auto flip = [&](int xx, int yy) {
    for (int curx = xx, cury = yy; !isBound(curx, cury); curx--, cury--){
      if (isSet[{curx, cury}]) { continue; }
      for (int x = curx+1, y = cury - 1; !isBound(x, y); x++, y--){
        if (isSet[{x, y}]) { continue; }
        lpar[x-y] ^= 1; isSet[{x, y}] = 1;
        lpar[curx-cury] ^= 1; isSet[{curx, cury}] = 1;
        ret.emplace(x, y); ret.emplace(curx, cury);
        return 1;
      }
    }
    return 0;
  };
	for(int i = 1, curx = 1, cury = n; i < n+m-1; ++i) {
		if (lcon[curx-cury] != lpar[curx-cury]) {
			if (cury != 2 && curx != m-1) {
				flip(curx, cury);
			} else {
				if ((!rpar[curx+cury]) != rcon[curx+cury]) {
          if (ret.find({curx+1, cury-1}) == ret.end()) {
					  ret.emplace(curx+1, cury-1);
          } else {
					  ret.erase({curx+1, cury-1});
          }
          ret.emplace(curx, cury);
				}
			}
		}
		cury = (curx == m-1 ? cury - 1: cury);
		curx = std::min(m-1, curx+1);
	}
	std::cout << ret.size() << "\n";
	for(auto [x, y] : ret) {
		std::cout << y << " " << x << "\n";
	}

	// std::vector mp(n+10, std::vector(m+10, 0));
	// for(auto [x, y] : ret) {
	// 	mp[y][x] = 1;
	// }
	// for(int i = 1; i <= n; ++i) {
	// 	for(int j = 1; j <= m; ++j) {
	// 		std::cout << mp[i][j];
	// 	} std::cout << '\n';
	// }
}

int main(){

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	solve();

	return 0;
}
