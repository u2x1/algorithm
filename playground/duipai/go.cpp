#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  system("g++ std.cpp -o std");
  system("g++ code.cpp -o code");
  system("g++ gen.cpp -o gen");
  long long cnt = 0;
  std::cout << "Runing on Test #0";
  while(1) {
    system("./gen > in.txt");
    system("./std < in.txt > out_std.txt");
    system("./code < in.txt > out_my.txt");
    if (system("diff --brief out_std.txt out_my.txt > /dev/null")) {
      std::cout << "\nWrong Answer on Test #" << cnt << std::endl << std::endl;
      system("head in.txt"); 
      std::cout << std::endl << "Your Output: " << std::endl;
      system("head out_my.txt");
      std::cout << std::endl << "Std Output: " << std::endl;
      system("head out_std.txt");
      return 0;
    }
    std::cout << std::string(std::to_string(cnt).size(), '\b');
    std::cout << ++cnt;
    std::cout.flush();
  }

  return 0;
}
