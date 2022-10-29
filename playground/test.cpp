#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>
using namespace std;
const int mod = 1000000007;
const int N = 1e7;
typedef pair<int, int> PII;
long long temp[20], co[N][20], n, ans;
using namespace std;
int cnt;

void dfs(const int u, const long long sum) {
	if (u == 10) {
		if (sum == n) {
			for (int i = 0; i < 10; i++) {
				co[ans][i] = temp[i];
      }
			ans++;
		}
    cnt++;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		temp[u] = i;
		dfs(u + 1, sum + i);
	}
}

int main(void) {
	cin >> n;
	if (n <= 9 || n >= 31) {
		cout << 0;
		return 0;
	} else {
		dfs(0, 0);
  }
	cout << ans << endl;
	for (int i = 0; i < ans; i++) {
		for (int j = 0; j < 10; j++)
			cout << co[i][j] << ' ';
		cout << endl;
	}

	return 0;
}
