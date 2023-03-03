#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int inord[maxN], preord[maxN];

int lson[31], rson[31];

int out(int inl, int inr, int prel, int prer) {
  const int root = preord[prel];
  if (inl == inr) { return -1; }
  const int pos = std::find(inord+inl, inord+inr, root) - (inord+inl);
  lson[root] = out(inl+pos+1, inr, prel+pos+1, prer);
  rson[root] = out(inl, inl+pos, prel+1, prel+pos+1);
  return root;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) { std::cin >> inord[i]; }
  orep(i, 0, n) { std::cin >> preord[i]; }
  
  memset(lson, -1, sizeof(lson));
  memset(rson, -1, sizeof(rson));

  std::queue<int> q; q.push(out(0, n, 0, n));
  bool fst = 1;
  while(!q.empty()){
    const int node = q.front(); q.pop();
    if (!fst) { std::cout << " ";}
    std::cout << node;
    if (lson[node] != -1) { q.push(lson[node]); }
    if (rson[node] != -1) { q.push(rson[node]); }
  }

  return 0;
}
