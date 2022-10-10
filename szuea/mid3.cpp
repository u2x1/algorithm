#include <cstdio>
#include <cstring>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

const int SIZE = 100000;

struct Node { Node *child = NULL; int val; } mp[SIZE];

void display(const int val) {
  Node *x = &mp[val % SIZE];
  while(x != NULL) { printf("<%d> -> ", x->val); x = x->child; }
  NL;
}

void insert(const int val) {
  Node *x = &mp[val % SIZE];
  while((x->child) != NULL) { x = x->child; }
  x->child = new Node { NULL, val };
}

bool findAndRm(const int val) {
  Node *lx = &mp[val % SIZE], *x = lx->child;
  while(x != NULL) {
    if (x->val == val) {
      lx->child = x->child;
      free(x);
      return 1;
    }
    lx = x;
    x = x->child;
  }
  return 0;
}


int read() {
  int x = 0; char ch = 0;
  while (ch < '0' || ch > '9') { ch = getchar(); }
  while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
  return x;
}

int n;

int cal(int a) {
  while(!(a&1)) { a>>=1; }
  return a;
}

int main() {
  int t = read();
  while(t--) {
    n = read();
    int b[n];
    orep(i, 0, n) {
      insert(cal(read()));
    }
    orep(i, 0, n) {
      b[i] = cal(read());
    }
    std::sort(b, b+n);
    bool flag = 1;
    orep(i, 0, n) {
      bool done = 0;
      while (b[i]) {
        if (findAndRm(b[i])) { done = 1; break; }
        b[i] >>= 1; 
      }
      if (!done)  { flag = 0; break; }
    }
    printf(flag ? "YES" : "NO"); NL;
  }

  return 0;
}
