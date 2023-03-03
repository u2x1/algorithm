#include <iostream>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];
std::set<std::string> st;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 1, 4) {
    orep(j, 1, 4) {
      orep(k, 1, 4) {
        orep(l, 1, 4) {
          std::string a = std::string{i+'0'};
          std::string b = std::string{j+'0'};
          std::string c = std::string{k+'0'};
          std::string d = std::string{l+'0'};
          std::string s = a + b + c + d;
          orep(i, 0, 4) {
            int ret = 0;
            orep(j, 0, 4) {
              if (i == j) {continue;}
              if (s[i] != s[j]) {  }
            }
            std::cout << s[i]
          }
        }
      }
    }
  }

  return 0;
}
