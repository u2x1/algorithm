#include <cstdio>
#include <cstring>
#define LEN 999999
char arr[LEN], tmp[LEN];

int weight(const char c) {
  if (c>='a' && c<='z') { return c-'a'; }
  if (c>='A' && c<='Z') { return c-'A'; }
  return -1;
}

bool cmp(const char a, const char b) {
  const int x = weight(a), y = weight(b);
  if (x==y) { return a > b; }
  return x < y;
}

void msort(const int l, const int r) {
  if (r - l <= 1) return;
  int mid = l + ((r - l) >> 1);
  msort(l, mid), msort(mid, r);
  for (int i = l, j = mid, k = l; k < r; ++k) {
    if (j == r || (i < mid && cmp(arr[i], arr[j])))
      tmp[k] = arr[i++];
    else
      tmp[k] = arr[j++];
  }
  for (int i = l; i < r; ++i) arr[i] = tmp[i];
}


int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    scanf("%s", arr);
    const int len = strlen(arr);
    msort(0, len);
    printf("%s\n", arr);
  }

  return 0;
}
