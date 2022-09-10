#!/bin/sh
set -e

function f {
if [ ! -f "$1.cpp" ]; then
cat > $1.cpp <<EOF
#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  scanf("%

  printf("

  return 0;
}
EOF
fi

vim $1.cpp
g++ -Wall $1.cpp
printf "======= input stage  =======\n"

input=$(</dev/stdin)

printf "\n======= output stage  =======\n"

time (echo $input | ./a.out)


printf "\n"
read -n 1 -p "> wanna copy source code? (y/n) > " yn
if [ $yn = "y" ] ; then
  grep -Ev '^ *//' $1.cpp | xclip -selection clipboard
  printf "\ncopied."
else
  printf "\n\n"
  f $1
fi
}

f $1
