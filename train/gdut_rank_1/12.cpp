#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int heap[maxN], cnt = 1;
int idxofval[maxN];

void push(const int x) {
  heap[cnt++] = x+10000;
  int i = cnt-1;
  idxofval[heap[i]] = i;
  while(i > 1 && heap[i/2] > heap[i]) {
    idxofval[heap[i/2]] = i;
    idxofval[heap[i]] = i/2;
    std::swap(heap[i/2], heap[i]);
    i/=2;
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 0, n) {
    int tmp; std::cin >> tmp;
    push(tmp);
  }
  orep(i, 0, m) {
    int xval, yval;
    std::string pred1, pred2;
    std::cin >> xval; xval+=10000;
    std::cin >> pred1;
    if (pred1 == "and") {
      std::cin >> yval; yval += 10000;
      std::cin >> pred1 >> pred1;
      int x = idxofval[xval], y = idxofval[yval];
      if (x > y) { std::swap(x, y); }
      std::cout << ((y&1 && x==y-1) ? 'T' : 'F'); NL; continue;
    }
    std::cin >> pred1 >> pred2;
    if (pred1 == "a") {
      std::cin >> pred1;
      std::cin >> yval; yval += 10000;
      const int x = idxofval[xval], y = idxofval[yval];
      std::cout << ((x/2==y) ? 'T' : 'F'); NL; continue;
    }
    if (pred2 == "root") {
      const int x = idxofval[xval];
      std::cout << ((x==1) ? 'T' : 'F'); NL; continue;
    } else {
      std::cin >> pred1 >> yval; yval += 10000;
      int x = idxofval[xval], y = idxofval[yval];
      std::cout << ((x==y/2) ? 'T' : 'F'); NL; continue;
    }
  }

  return 0;
}
