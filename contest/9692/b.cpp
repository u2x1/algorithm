#include <iostream>
#include <cstring>
#ifdef BENCHMARK  ////
#include <ctime>  ////
#endif            ////
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  char s[20];
  int sum = 0, len;
  bool flag = 1;
  while (flag) {
    cin >> s; len = strlen(s);
    for(int i = 0; i < len; ++i)  {
      if (s[i] == 'a') {
        ++sum;
      } else if (s[i] == '.') {
        flag = 0;
        break;
      }
    }
  }


#ifdef BENCHMARK
  clock_t start_clock = clock();
#endif

  cout << sum;

#ifdef BENCHMARK
  cout << "\n  runtime: " << (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000 << " ms\n";
#endif

  return 0;
}
