#include <cstdio>
#include <random>
#include <ctime>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int m = 4e5;

  srand(time(NULL));

  FILE* f = fopen("data.in", "w");
  fprintf(f, "%d\n", m);
  orep(i, 0, m) {
    fprintf(f, "%d ", rand());
  }

  return 0;
}
