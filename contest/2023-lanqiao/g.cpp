#include <iostream>
#include <string>

#define orep(i, a, b) for(int i = (a); i < (b); ++i)
#define NL std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int k; std::string s, sa, sb; std::cin >> k >> s >> sa >> sb;
  char a = sa[0], b = sb[0];
  long long cnt = 0, ret = 0;
  for(int l = 0, r = k-1; r < s.size(); ++l, ++r) {
    cnt += (s[l] == a);
    if (s[r] == b) {
      ret += cnt;
    }
  }
  std::cout << ret;
	return 0;
}
