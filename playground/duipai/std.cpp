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
namespace qiqi {
    const int M = 3;
    void main() {
        array<int,M> p,mx,mn;
        for (int i = 0; i < M; i++) {
            cin >> p[i] >> mx[i];
        }
        {
            array<int,M> o; iota(all(o),0);
            sort(all(o),[&](int a,int b) {
                return p[a] < p[b];
            });
            array<int,M> tp = p,tmx = mx;
            for (int i = 0; i < M; i++) {
                p[i] = tp[o[i]];
                mx[i] = tmx[o[i]];
            }
        }
        int n;
        cin >> n;
        for (int i = 0; i < M; i++) {
            mn[i] = max(0,n-(mx[(i+1)%3]+mx[(i+2)%3]));
        }
        vll a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        const ll inf = 1e18;
        sort(all(a));
        ll ans = inf,sum = 0;
        for (int i = 0; i < mn[0]; i++) {
            sum += abs(a[i]-p[0]);
        }
        for (int i = 0; i < mn[2]; i++) {
            sum += abs(a[n-i-1]-p[2]);
        }
        a = vll(a.begin()+mn[0],a.end()-mn[2]);
        n = sz(a); mx[0] -= mn[0]; mx[2] -= mn[2];
        for (int i = 0; i < n; i++) {
            sum += abs(a[i]-p[1]);
        }
        vll sl(n),sr(n+1);
        for (int i = 0; i < n; i++) {
            sl[i] = abs(a[i]-p[0])-abs(a[i]-p[1]);
            sr[i] = abs(a[i]-p[2])-abs(a[i]-p[1]);
        }
        partial_sum(all(sl),sl.begin());
        sl.insert(sl.begin(),0);
        for (int i = n-1; i >= 0; i--) {
            sr[i] += sr[i+1];
        }
        int l = max(n-mx[2], 0),r = min(n,mx[1]);
        multiset<ll> s;
        for (int i = l; i <= r; i++) {
            s.emplace(sr[i]);
        }
        for (int i = 0; i <= mx[0]; i++) {
            int pl = max(i,n-mx[2]),pr = min(n,i+mx[1]);
            if (pl > n) {
                break;
            }
            while (r < pr) {
                r++;
                s.emplace(sr[r]);
            }
            while (l < pl) {
                s.erase(s.find(sr[l]));
                l++;
            }
            if (!s.empty()) {
                ans = min(ans,sum+sl[i]+(*s.begin()));
            }
        }
        cout << ans << '\n';
    }
}
int main() {
//	clock_t st = clock();
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (T--) {
        qiqi::main();
    }

//	cout << (double)(clock()-st)/CLOCKS_PER_SEC;
    return 0;
}
