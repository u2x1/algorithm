#include <iostream>
#include <iomanip>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t;
  std::cout << std::setprecision(10);
  while(t--){
    double a, b, c, d; std::cin>>a >> b>>c>>d;
    int pt[4][2] = { {0,0}, {a,0}, {0,b}, {a,b} };
    bool inside = (a*a+b*b) > (c*c+d*d) && (a>0 == c>0) && (b>0 == d>0);
    double ret = -1, ds = -1;
    orep(i, 0, 4) {
      double d = (c-pt[i][0]) * (c-pt[i][0]) + (d-pt[i][1]) *(d-pt[i][1]); 
      if (d > ds) {
        if (inside) {
          ret = sqrt(d)*sqrt(d)/2;
          ds = d;
        }
      }
    }
    std::cout << ret << NL;
  }

  return 0;
}
