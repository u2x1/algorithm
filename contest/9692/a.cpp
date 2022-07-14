#include <iostream>
#ifdef BENCHMARK
#include <ctime>
#endif
using namespace std;

int main() {
  int n;
  cin >> n;
  int one_cnt = 0, max_len = 0, len = 0;
  bool inOnes = 0;
  char c;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    if (c == '1') {
      ++one_cnt;
      if (inOnes) { ++len; }
      else { len = 1; inOnes = 1; }
    } else if (c == '0') {
      if (inOnes) {
        if (max_len < len) { max_len = len; }
        inOnes = 0;
      }
    }
  }
  if (max_len < len) { max_len = len; }

#ifdef BENCHMARK
  clock_t start_clock = clock();
#endif

  cout << one_cnt - max_len;

#ifdef BENCHMARK
  cout << "\n  runtime: " << (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000 << " ms\n";
#endif

  return 0;
}
