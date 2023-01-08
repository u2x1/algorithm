#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define REDIR        freopen("data.in", "r", stdin);

struct Elem {
  int val;
  Elem* next = NULL;
};

int main() {
  int l; scanf("%d", &l);
  int t; scanf("%d", &t);
  Elem head;
  Elem* last = &head;
  orep(i, 0, l) {
    int tmp; scanf("%d", &tmp);
    last = last->next = new Elem { tmp, NULL };
  }
  Elem endFlag = { 101, NULL };
  last->next = &endFlag;
  int op, x, y;
  while(t--) {
    scanf("%d%d", &op, &x);
    if (op == 1) {
      Elem* cur = &head;   --x;
      while(x--) { cur = cur->next; }
      cur->next = cur->next->next;
    } else if (op == 2) {
      scanf("%d", &y);
      Elem* cur = &head;
      --x;
      while(x--) {
        cur = cur->next;
      }
      cur->next = new Elem { y, cur->next };
    }
    else {
      Elem* cur = &head;
      while(x--) {
        cur = cur->next;
      }
      const int i = cur->val;
      Elem* n = cur->next;
      while(n->val == i) {
        cur->val += i;
        n = n->next;
      }
      cur->next = n;
    }
    Elem* pt = head.next;
    while(pt != NULL && pt->val != 101) {
      printf("%d ", pt->val);
      pt = pt->next;
    } NL;
  }

  return 0;
}
