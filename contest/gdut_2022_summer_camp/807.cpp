//QQ 1351966042
//ID U2FsdGVkX1

#include <cstdio>
#include <cstring>
#include <algorithm>

int cmp(const char *a, const char *b) {
  const int lena = strlen(a), lenb = strlen(b);
  int l=0, r=0;
  while(l < lena && r < lenb) {
    if (a[l] > b[r]) { return 1; }
    else if (a[l] < b[r]) { return -1; }
    ++l; ++r;

    if (l == lena && lena < lenb) { l = 0; }
    else if (r == lenb && lena > lenb) { r = 0; }
  }

  if (lena == lenb) { return 0; }
  else {
    if (lena < lenb) {
      int pos = 0; int l = lena, r = 0;
      while(l < lenb) {
        if (b[pos] < b[l]) { return -1; }
        else if (b[pos] > b[l]) { return 1; }
        ++pos; ++l;
      }
      while(r < lena) {
        if (b[pos] < a[r]) { return -1; }
        else if (b[pos] > a[r]) { return 1; }
        ++pos; ++r;
      }
    } else if (lena > lenb) {
      int pos = 0; int l = lenb, r = 0;
      while(l < lena) {
        if (a[pos] < a[l]) { return 1; }
        else if (a[pos] > a[l]) { return -1; }
        ++pos; ++l;
      }
      while(r < lenb) {
        if (a[pos] < b[r]) { return 1; }
        else if (a[pos] > b[r]) { return -1; }
        ++pos; ++r;
      }
    }
  }
  return 0;
}

char arr[5001][21];
int main() {
  int t, n;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i=0; i<n && scanf("%s", arr[i]); ++i);
    std::qsort(arr, n, sizeof(*arr), (int (*)(const void*, const void*)) cmp);
    for(int i=0; i<n; ++i) {
      printf("%s", arr[i]);
    } putchar(10);
  }
  return 0;
}
