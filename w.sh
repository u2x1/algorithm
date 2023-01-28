#!/bin/sh
# set -e

sourceFile="$1.cpp"
inFile=./.data/z_$1_in
outFile=./.data/z_$1_out

function writeTest {
  if [ -f $inFile ]; then
    return
  fi
  mkdir -p .data
  read -n 1 -p "> write test case? (y/n) > " yn
  printf "\n"
  if [ "$yn" = "y" ] ; then
    printf "======= test case(input)  =======\n"
    input=$(</dev/stdin)
    printf "======= test case(output)  =======\n"
    output=$(</dev/stdin)
    printf '%s\n' "$input"  > $inFile
    printf '%s\n' "$output" > $outFile
    printf "\ndone.\n"
  fi
}

function judge {
  printf "==================================================\n\n"
  printf "Judging...\n"

  if [ ! $flag -eq -120 ] ; then
    processOut=$(timeout 2 bash -c "cat $inFile | ./zout")
    flag=$?
  fi

  printf "\nstatus: "
  if [ $flag -eq 0 ]; then
    diff -q -w $outFile <(echo -e "$processOut") > /dev/null 2>&1
    if [ $? -eq 0 ]; then
      echo -e "${GREEN}AC${NOCOLOR}"
    else
      echo -e "${RED}WA${NOCOLOR}"
      printf "\n.....INPUT....\n"
      head -c -1 $inFile > /dev/stdout
      printf "\n\n.....OUTPUT....\n"
      printf "$processOut\n"
      printf "\n\n+...............................+.................\n"
      diff -w --color -y $outFile <(echo -e "$processOut")
    fi
  elif [ $flag -eq 1 ] ; then
    echo -e "${PURPLE}RE${NOCOLOR}"
  elif [ $flag -eq 124 ] ; then
    echo -e "${PURPLE}TLE${NOCOLOR}"
    printf "\n.....INPUT....\n"
    head -c -1 $inFile > /dev/stdout
  elif [ $flag -eq -120 ] ; then
    echo -e "${YELLOW}CE${NOCOLOR}"
  fi
}

function op {
  read -n 1 -p "> operation? (input(i)/copy(c)/raw(r)) > " yn
  printf "\n"
  if [ "$yn" = "c" ] ; then
    grep -Ev '^ *//' $sourceFile | xclip -selection clipboard
    printf "copied."
    exit
  elif [ "$yn" = "i" ] ; then
    printf "\n.... input ....\n"
    input=$(</dev/stdin)
    printf "\n.... output ....\n"
    echo $input | ./zout
    printf "\n"
    op
  elif [ "$yn" = "r" ] ; then
    printf "\n"
    ./zout
    printf "\n"
  fi
}

function f {
  if [ ! -f $sourceFile ]; then
  cat > $sourceFile <<EOF
#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);

  return 0;
}
EOF
  fi

  flag=0
  vim $sourceFile
  g++ -g -fsanitize=address -Wall -Wextra -Wshadow -o zout -Wall $sourceFile
  if [ ! $? -eq 0 ] ; then
    flag=-120
  fi

  if [ ! -f $inFile ]; then
    printf "\n==================================================\n\n"
    ./zout
  else
    judge
  fi

  printf "\n==================================================\n\n"

  op

  f $1
}

# ----------------------------------
# Colors
# ----------------------------------
NOCOLOR='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHTGRAY='\033[0;37m'
DARKGRAY='\033[1;30m'
LIGHTRED='\033[1;31m'
LIGHTGREEN='\033[1;32m'
YELLOW='\033[1;33m'
LIGHTBLUE='\033[1;34m'
LIGHTPURPLE='\033[1;35m'
LIGHTCYAN='\033[1;36m'
WHITE='\033[1;37m'

writeTest $1
f $1

