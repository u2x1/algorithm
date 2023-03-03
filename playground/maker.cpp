#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

std::string genData() {

}

std::string f1(std::string data) {

}

std::string f2(std::string data) {

}


struct Case { std::string data, s1, s2; }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  const int t = 10;
  int passed = 0;
  std::vector<Case> unpassed;
  orep(i, 0, t) {
    const std::string data = genData();
    const std::string s1 = f1(data), s2 = f2(data);
    if (s1 != s2) { 
      unpassed.push_back({data, s1, s2});
    }
    else { passed++; }
  }
  std::cout << "pass rate " << t-unpassed << "/" << t <<"."; NL;
  orep(i, 0ul, unpassed.size()) {
    std::cout << "# " << i; NL;
    std::cout << "f1:\n" << ; NL;
    std::cout << "f2:"; NL;

  }

  return 0;
}
