#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

std::vector<long long> num;
long long rst, ops;

long long ksm(long long a, const long long b) {
  long long exp = a;
  a %= b;
  long long ret = 1ll;
  while (exp) {
    if (exp & 1ll) {
      ret = (a*ret) % b;
    }
    a = (a*a) % b;
    exp >>= 1;
  }
  return ret;
}

char curOp[20];
bool dfs(int depth, const char op, const long long accu) {
  if (depth == ops) {
    if (accu == rst) {
      std::cout << num[0];
      orep(i, 0, ops) {
        std::cout << curOp[i] << num[i+1];
      }
      std::cout << "=" << rst;
      return 1;
    } else {
      return 0;
    }
  }
  curOp[depth] = op; 
  long long nex;
  switch(op) {
    case '-':
      nex = accu-num[depth+1]; break;
    case '+':
      nex = accu+num[depth+1]; break;
    case '#':
      if (accu <= 0 || num[depth+1] == 0) { return 0; }
      nex = ksm(accu, num[depth+1]);
      break;
  }
  return dfs(depth+1, '+', nex)
      || dfs(depth+1, '-', nex)
      || dfs(depth+1, '#', nex);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  long long tmp; char c;
  std::cin >> tmp; num.push_back(tmp);
  while(1) {
    std::cin >> c;
    if (c == '=') { std::cin >> rst; break; }
    ops++;
    std::cin >> tmp;
    num.push_back(tmp);
  }
  if (! (dfs(0, '+', num[0])
      || dfs(0, '-', num[0])
      || dfs(0, '#', num[0]))) {
    std::cout << -1;
  }

  return 0;
}
