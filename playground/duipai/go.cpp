#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << std::endl;

const int maxN = 2e5+5;
int arr[maxN];

int runOnce() {
  system("./gen > in.txt");
  system("./std < in.txt > out_std.txt");
  return system("./code < in.txt > out_my.txt");
}

bool isWrong() {
  return system("diff -w --brief out_std.txt out_my.txt > /dev/null");
}

void out() {
  std::cout << std::endl << "===== INPUT =====: " << std::endl;
  system("head in.txt");
  std::cout << std::endl << "===== Your Output: " << std::endl;
  system("head out_my.txt");
  std::cout << std::endl << "===== Std Output: " << std::endl;
  system("head out_std.txt");
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  system("g++ -O3 std.cpp -o std");
  system("g++ -O3 code.cpp -o code");
  system("g++ -O3 gen.cpp -o gen");

  orep(i, 0, 5) {
    NL;
    std::cout << "#####################################";
    std::cout << " " << i << " ";
    std::cout << "#####################################";
    NL;
    runOnce();
    out();
  }

  std::cout << "#####################################"; NL;
  std::cout << "#####################################"; NL;
  std::cout << "################start################"; NL;
  std::cout << "#####################################"; NL;
  std::cout << "#####################################"; NL;

  long long cnt = 0;
  std::cout << "Runing on Test #0";
  while(1) {
    if (runOnce()) {
      std::cout << "Runtime Error"; NL;
      out();
      return 0;
    }
    if (isWrong()) {
      std::cout << "\nWrong Answer" << cnt; NL; NL;
      out();
      return 0;
    }
    std::cout << std::string(std::to_string(cnt).size(), '\b');
    std::cout << ++cnt;
    std::cout.flush();
  }

  return 0;
}
