#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int n, k; std::cin >> n >> k;
    std::vector<int> con(n-k+1);
    for(auto &x : con) { std::cin >> x; }
    const auto calInv = [](const auto &v) {
        int ret = 0;
        for(int i = 0; i < v.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                ret += (v[j] >= v[i]);
            }
        }
        return ret;
    };
    const auto calInv2 = [](const auto &v, const int x) {
        int ret = 0;
        for(int i = 1; i < v.size(); ++i) {
            ret += (v[i] >= x);
            for(int j = 1; j < i; ++j) {
                ret += (v[j] >= v[i]);
            }
        }
        return ret;
    };
    std::vector<int> _p(k); std::iota(all(_p), 0);
    do {
        if (calInv(_p) != con.front()) { continue; }
        auto p = _p;
        std::vector<int> son(n), in(n);
        std::vector<int> prev(n+1, -1), next(n+1, -1);
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (p[j]+1 == p[i]) { prev[i] = j; next[j] = i; }
            }
        }
        for (int i = 0; i < k; ++i) {
            if (p[i] == 0) { prev[i] = n; next[n] = i; }
        }
        bool fail = 0;
        for (int __ = 1; __ < n-k+1; ++__) {
            for(int i = 1; i < k; ++i) {
                if (p[i] > p[0]) { p[i]--; }
            }
            fail = 1;
            for(int x = 0; x < k; ++x) {
                if (calInv2(p, x) == con[__]) {
                    fail = 0;
                    auto v = std::vector(p.begin()+1, p.end());
                    for(auto &y : v) { if (y >= x) { ++y; } }
                    v.push_back(x);
                    p = v;
                    break;
                }
            }
            if (fail) { break; }
            for(int i = 0; i < k-1; ++i) {
                const int l = __+i, r = __+k-1;
                if (p[i] == p.back()-1) {
                    // l -> r
                    prev[next[l]] = r; prev[r] = l; next[r] = next[l]; next[l] = r;
                }
                if (p[i] == p.back()+1) {
                    // r -> l
                    next[prev[l]] = r; next[r] = l; prev[r] = prev[l];  prev[l] = r;
                }
            }
        }
        if (fail) { continue; }
        std::vector<int> ret(n);
        for(int i = next[n], cnt = 1;; i = next[i], ++cnt) {
            if (! ~next[i]) { ret[i] = cnt; break; }
            ret[i] = cnt;
        }
//        while(q.empty()) {
//            int idx = q.front(); q.pop();
//            ret[idx] = o++;
//            if(--in[son[idx]] == 0) {
//                q.emplace(son[idx]);
//            }
//        }
        for(auto x : ret) { std::cout << x << " "; }
        exit(0);
    } while(std::next_permutation(all(_p)));

    return 0;
}

