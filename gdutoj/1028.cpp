#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>
#include <cstdlib>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;
const int mod = 19260817;
const int INF = 0x7f7f7f7f;
const int N = 1 * 1e7 + 10; // <=======================================
typedef pair<int, int> PII;
typedef long long ll;
const double PI = 3.1415926;

int dx[] = {-1, 0, 1, 0, 0}, dy[] = {0, 1, 0, -1, 0};
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int f[N], maxn = 4;
void solve() {
	int m;
	cin >> m;
	m = m % 3210136;
	if (f[m]) // <=========================================================
		cout << f[m] << endl;
	else {
		for (int i = maxn; i <= m; i ++) {
			f[i] = (f[i - 1] + 2 * f[i - 2]) % mod;
		}
		cout << f[m] << endl;
	}

	maxn = max(maxn, m);
	return ;
}

int main(void) {
//	freopen("C:\\Users\\rain\\Desktop\\test\\in.txt", "r", stdin);
//	freopen("C:\\Users\\rain\\Desktop\\test\\out.txt", "w", stdout);
	int t ;
	f[1] = 1, f[2] = 3, f[3] = 5;
	cin >> t;

	while (t--) {
		solve();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}