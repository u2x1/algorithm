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
using namespace std;
namespace qiqi {
	void main() {
		int n,l0;
		cin >> n; l0 = n-1;
		if (n == 1) {
			cout << "YES\n1\n";
			return;
		}
		vi a(n),s(l0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < l0; i++) {
			s[i] = a[i+1]-a[i];
		}
		vi fail(l0,-1);
		for (int i = 1,x = -1; i < l0; i++) {
			if (s[x+1] == s[i]) {
				fail[i] = x+1;
			}
			else {
				while (x != -1) {
					if (s[x+1] == s[i]) {
						fail[i] = x+1;
						break;
					}
					x = fail[x];
				}
			}
		}
		int m;
		cin >> m;
		vi b(m);
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		vi p(m); iota(all(p),0);
		sort(all(p),[&](int i,int j) {
			return b[i] > b[j];
		});
		set<int> st;
		for (int l = 0,r = 1; l < m; r++) {
			if (r == m || b[p[l]] != b[p[r]]) {
				vi vec(p.begin()+l,p.begin()+r);
				for (auto x:vec) {
					st.emplace(x);
				}
				for (auto x:vec) {
					auto chk = [&](int p) {
						vi vec; auto it = st.find(p);
						for (int i = 0; i <= l0; i++,it--) {
							vec.eb(*it);
							if (it == st.begin()) {
								break;
							}
						}
						reverse(all(vec));
						it = next(st.find(p));
						for (int i = 1; i <= l0 && it != st.end(); i++,it++) {
							vec.eb(*it);
						}
						if (sz(vec) > l0) {
							int l1 = sz(vec)-1;
							vi t(l1);
							for (int i = 0; i < l1; i++) {
								t[i] = b[vec[i+1]]-b[vec[i]];
							}
							for (int i = 0,x = -1; i < l1; i++) {
								if (s[x+1] == t[i]) {
									x++;
								}
								else {
									while (x != -1) {
										if (s[x+1] == t[i]) {
											x++;
											break;
										}
										else {
											x = fail[x];
										}
									}
								}
								if (x == l0-1) {
									cout << "YES\n";
									for (int j = i-l0; j <= i; j++) {
										cout << vec[j+1]+1 << " \n"[j==i];
									}
									return 1;
								}
							}
						}
						return 0;
					};
					if (chk(x)) {
						return;
					}
				}
				l = r;
			}
		}
		cout << "NO\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	qiqi::main();
	return 0;
}
