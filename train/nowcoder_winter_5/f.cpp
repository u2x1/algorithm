#include <iostream>
#include <queue>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];
struct st { int idx; };
bool cmp(const char a, const char b) { return a > b; }
std::string str;
bool operator<(const st a, const st b) { return str[a.idx] < str[b.idx]; }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  std::cin >> str;
  std::priority_queue<st> q;
  int qsz = 0;
  int pos = 0;
  int r = 0;
  for(; r < n; ++r) {
    q.push({r}); ++qsz;
    if (qsz == k) { break; }
  }
  std::string ret;
  while (pos < str.size()) {
    while(qsz != k && r != str.size()) { q.push({r}); ++qsz; }
    while (!q.empty() && q.top().idx < pos) { q.pop(); }
      const int idx = q.top().idx;
      if (!q.empty() && str[pos] < str[idx]) {
        ret += str[idx]; q.pop();
        std::string add = str.substr(pos+1, idx-pos-1);
        std::sort(add.begin(), add.end(), cmp);
        str += add;
        qsz -= add.size();
        pos = q.top().idx+1;
      }
  }

  return 0;
}
