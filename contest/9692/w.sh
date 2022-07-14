#!/bin/sh
set -e

if [ ! -f "$1.cpp" ]; then
cat > $1.cpp <<EOF
#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> 

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  cout << 

#ifdef BENCHMARK                                              ////
  cout << "\n  run time: "                                    ////
    << (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000  ////
    << " ms\n";                                               ////
#endif                                                        ////

  return 0;
}
EOF
fi

vim $1.cpp
printf "======= source code  =======\n"
grep -v '////' $1.cpp
printf '\n\n'
g++ -Wall -D BENCHMARK $1.cpp
printf "======= program io  =======\n"
./a.out
