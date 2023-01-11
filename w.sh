#!/bin/sh
# set -e

sourceFile="$1.cpp"
inFile=z_$1_in
outFile=z_$1_out

function writeTest {
  if [ -f $inFile ]; then
    return
  fi
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

  printf "Judging...\n\n"
  printf ".....INPUT....\n"
  head -c -1 $inFile > /dev/stdout

  printf "\n\n+...............................+.................\n"
  if [ ! $flag -eq -120 ] ; then
    processOut=$(cat $inFile | ./zout)
    if [ $? -eq 0 ] ; then
      diff -w -W 60 --color -y $outFile <(echo -e "$processOut")
      flag=$?
    else
      flag=-100
    fi
  fi

  printf "\nstatus: "
  if [ $flag -eq 0 ]; then
    echo -e "\e[0;32mACCEPTED\033[0m"
  elif [ $flag -eq -100 ] ; then
    echo -e "\e[0;35mTIME LIMIT EXCEEDED\033[0m"
  elif [ $flag -eq -120 ] ; then
    echo -e "\e[0;33mCOMPILATION ERROR\033[0m"
  else
    echo -e "\e[0;31mWRONG ANSWER\033[0m"
  fi
}

function op {
  read -n 1 -p "> operation? (input(i)/copy(c)) > " yn
  if [ "$yn" = "c" ] ; then
    grep -Ev '^ *//' $sourceFile | xclip -selection clipboard
    printf "\ncopied."
    exit
  elif [ "$yn" = "i" ] ; then
    printf "\n.... input ....\n"
    input=$(</dev/stdin)
    printf "\n.... output ....\n"
    echo $input | ./zout
    printf "\n"
    read -n 1 -p "press any key to continue..."
    printf "\n"
    op
  fi
}

function f {
  if [ ! -f $sourceFile ]; then
  cat > $sourceFile <<EOF
#include <cstdio>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  scanf("%

  printf("

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

writeTest $1
f $1
