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
    void main() {
        int n,Q;
        cin >> n >> Q;
        map<pll,ll> c; array<map<pll,ll>,2> id;
        array<vector<vector<pll>>,2> mp;
        for (int i = 0; i < n; i++) {
            ll a,b;
            cin >> a >> b;
            c[pair(a,b)]++;
            if (a != b) {
                while (a != 0 && b != 0) {
                    if (a > b) {
                        int p;
                        auto it = id[1].find(pair(a%b,b));
                        if (it != id[1].end()) {
                            p = it->se;
                        }
                        else {
                            p = id[1][pair(a%b,b)] = sz(id[1]);
                            mp[1].eb();
                        }
                        mp[1][p].eb(0,1);
                        mp[1][p].eb(a/b,-1);
//                        std::cout << a << " " << b << " " << mp[1][p].size() << '\n';
                        a %= b;
                    }
                    else if (a < b) {
                       const ll wtf = b % a;
                        int p;
                        auto it = id[0].find(pair(a,wtf));
                        if(it != id[0].end()){
                            p = it->se;
                        }else{
                            p = id[0][pair(a,wtf)] = sz(id[0]);
                            mp[0].eb();
                        }
                        mp[0][p].eb(0,1);
                        mp[0][p].eb(b/a,-1);
                        b = wtf;
                    }
                    else {
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (auto &vec:mp[i]) {
                sort(all(vec));
//                std::cout << "\n\n";
                ll lst = 0;
                for (auto &[__,k]: vec) {
//                    std::cout << i << " " << __ << " " << k << '\n';
                    lst = (k += lst);
//                    std::cout << i << " " << __ << " " << k << '\n';
                }
//                std::cout << "\n\n";
            }
        }
        const ll inf = 1e18;
        while (Q--) {
            ll a,b;
            cin >> a >> b;
            ll ans = c[pair(a,b)];
            {
                int p,flag = 1;
                {
                    auto it = id[0].find(pair(a,b%a));
                    if (it == id[0].end()) {
                        flag = 0;
                    }else{
                        p = it->se;
                    }
                }
                if(flag){
                    auto it = upper_bound(all(mp[0][p]),pair(b/a,inf));
                    if (it != mp[0][p].begin()) {
                        ans += prev(it)->se;
                    }
                }
            }
            {
                int p,flag = 1;
                {
                    auto it = id[1].find(pair(a%b,b));
                    if(it == id[1].end()){
                        flag = 0;
                    }else{
                        p = it->se;
                    }
                }
                if(flag){
                    auto it = upper_bound(all(mp[1][p]),pair(a/b,inf));
                    if (it != mp[1][p].begin()) {
                        ans += prev(it)->se;
//                        std::cout << prev(it) -> fi << " " << prev(it) -> se << '\n';
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}
int main() {
 clock_t st = clock();
 // freopen("in","r",stdin);
 // freopen("out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int T; cin >> T;
    while (T--) {
        qiqi::main();
    }
 cout << (double)(clock()-st)/CLOCKS_PER_SEC;
    return 0;
}
