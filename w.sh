#!/bin/sh
set -e

function f {
if [ ! -f "$1.cpp" ]; then
cat > $1.cpp <<EOF
#include <cstdio>

#define orep(i,a,b)  for(int i=(a); i< (b); ++i)
#define crep(i,a,b)  for(int i=(a); i<=(b); ++i)
#define abs(a)       ((a)<0?-(a):(a))
#define min(a,b)     ((a)<(b)?(a):(b))
#define min3(a,b,c)  min(min(a,b),c)
#define max(a,b)     ((a)>(b)?(a):(b))
#define max3(a,b,c)  max(max(a,b),c)
#define HIT          printf("entered <%s> at ln:%d\n", __FUNCTION__, __LINE__); fflush(stdout);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define NL           putchar(10);
#define REDIR        freopen("../../data.in", "r", stdin);


int main() {
  scanf("%

  printf("

  return 0;
}
EOF
fi

vim $1.cpp
# printf "======= source code  =======\n"
# # grep -Ev '^ *$|////$|^ *//' $1.cpp
# grep -Ev '^ *$' $1.cpp
g++ -Wall $1.cpp
printf "======= input stage  =======\n"

input=$(</dev/stdin)

printf "\n======= output stage  =======\n"

time (echo $input | ./a.out)


printf "\n"
read -n 1 -p "> wanna copy source code? (y/n) > " yn
if [ $yn = "y" ] ; then
  cat $1.cpp | xclip -selection clipboard
  printf "\ncopied."
else
  printf "\n\n"
  f $1
fi
}

f $1
