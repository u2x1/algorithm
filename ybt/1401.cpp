#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int cnt = 0, memPos = 0;
int cap, artLen;

void query(int word, int *mem);

int main() {
  scanf("%d%d", &cap, &artLen);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int mem[cap*2];
  memset(mem, -1, sizeof(mem));
  int word;
  for (int i = 0; i < artLen && scanf("%d", &word); ++i) {
    query(word, mem);
  }
  printf("%d", cnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}

void query(int word, int *mem) {
  for (int i = memPos; i < memPos+cap; ++i) {
    if (word == mem[i]) {
      return;
    }
  }
  ++cnt;
  if (memPos == cap) {
    memcpy(mem, mem+cap+1, (cap-1)*sizeof(int));
    mem[cap-1] = word;
    memPos = 0;
  } else {
    mem[memPos+cap] = word;
    ++memPos;
  }
}
