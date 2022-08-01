#!/bin/sh
set -e

if [ ! -f "$1.cpp" ]; then
cat > $1.cpp <<EOF
#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  scanf("%

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
EOF
fi

vim $1.cpp
printf "======= source code  =======\n"
# grep -Ev '^ *$|////$|^ *//' $1.cpp
grep -Ev '^ *$|////$' $1.cpp
printf '\n\n'
g++ -Wall -D BENCHMARK $1.cpp
printf "======= program io  =======\n"
./a.out
