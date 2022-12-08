#include <cstdio>
#include <cstring>

// 读取str字符串，以pos作为起点，将其转变为int类型数字
int read(const char* str, int &pos) {
  int x = 0;
  while(str[pos] == ' ') { ++pos; } // 忽略空格
  while(str[pos] <= '9' && str[pos] >= '0') {
    x = x*10+str[pos]-'0';
    ++pos;
  }
  while(str[pos] == ' ') { ++pos; } // 忽略空格
  return x;
}

// 根据操作符决定计算方法
int _calc(int a, int b, char c) {
  switch(c) {
    case '+':
      return a+b; break;
    case '-':
      return a-b; break;
    case '*':
    case 'x':
    case 'X':
      return a*b; break;
    case '/':
      return a/b; break;
    default:  //理论上不应该出现这种情况
      return -1;
  }
}

int calc(char *str) {
  int pos = 0;  // 以字符串的下标0开始读入表达式
  int a = read(str, pos); // 读入第一个数字a
  char op = str[pos++];   // 读入操作符
  int b = read(str, pos); // 读入第二个数字b
  return _calc(a, b, op); // 计算并返回结果
}

int main() {
  char str[] = "124 + 124";
  printf("%d", calc(str));
  return 0;
}