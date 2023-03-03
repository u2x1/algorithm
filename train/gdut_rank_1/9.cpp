#include <iostream>
#include <cstdio>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e4+5;
int arr[maxN];
struct Man { int id=0, times=0; long long money=0; } mans[maxN];
bool operator<(const Man& a, const Man& b) {
  if (a.money > b.money) {
    return 1;
  } else if (a.money < b.money) {
    return 0;
  }
  if (a.times > b.times) {
    return 1;
  } else if (a.times < b.times) {
    return 0;
  }
  if (a.id < b.id) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n+1) { mans[i].id = i; }
  orep(i, 0, n) {
    long long sum = 0ll;
    int k; std::cin >> k;
    orep(j, 0, k) {
      long long a, b; std::cin >> a >> b;
      mans[a].money += b;
      mans[a].times++;
      sum += b;
    }
    mans[i+1].money -= sum;
  }
  
  std::sort(mans+1, mans+n+1);
  orep(i, 1, n+1) {
    printf("%d %.2f\n", mans[i].id, mans[i].money/100.0);
  }

  return 0;
}
