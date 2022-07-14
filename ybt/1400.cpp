#include <cstdio>
#include <cstring>

char toUpper(char a) {
  const int diff = 'a' - 'A';
  if (a >= 'a' && a <= 'z') { a -= diff; }
  return a;
}

int main() {
  char c;
  char target[20];
  int i = 0;
  for(; (c = getchar()) != '\n'; ++i) {
    target[i] = toUpper(c);
  } target[i] = '\0';

  char word[20]; int wordPos = 1;
  int cnt = 0, startPos = -1, retPos = -1;
  for(int i = 0; (c=toUpper(getchar())) != EOF && c != '\n'; ++i) {
    if (c == ' ') {
      while(++i && (c=toUpper(getchar())) != EOF && c != '\n' && c == ' ');
    }
    if (c != EOF && c != '\n') {
      startPos = i;
      word[0] = c;
      while (++i && (c=toUpper(getchar())) != EOF && c != '\n' && c != ' ') {
        word[wordPos++] = c;
      } word[wordPos] = '\0';
      if(strcmp(word, target) == 0) {
        ++cnt;
        if (retPos == -1) { retPos = startPos; };
      }
      wordPos = 1;
    }
  }

  if (cnt != 0) {
    printf("%d %d", cnt, retPos);
  } else {
    printf("-1");
  }
  return 0;
}
