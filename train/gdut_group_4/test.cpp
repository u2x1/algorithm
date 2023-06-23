#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

char S[50] = " ababa";
char T[50] = " aba";
int n = 5, m = 3;

int Find_Answer () {
int j = 1 , ans = 0;
for ( int i = 1; i <= n ; i ++) {
 if (S[ i] != T[j ]) j = 1;
 if (S[ i] == T[j ]) j ++;
 if (j > m) {
  ans ++;
   j = 1;
   }
 }
 return ans ;
}
signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cout << Find_Answer();

  return 0;
}
