#include <cstdio>

#define cfor(i,a,b,step)  for(auto i=(a); i!=(b); i+=step)
#define NL           putchar(10);

char arr[9];
int ret;

int prime[10005], pCnt; bool notPrime[10005];
void initPrime() {
  prime[0] = 2; pCnt = 1;
  cfor(i, 2, 10005, 1) {
    cfor(j, 0, pCnt, 1) {
      if (i % prime[j] == 0) { notPrime[i] = 1; break; }
    }
    if (!notPrime[i]) { prime[pCnt++] = i; }
  }
}

bool checkPrime(const int x) {
  if (x < 10005) { return !notPrime[x]; }
  cfor(i, 0, pCnt, 1) {
    if (x % prime[i] == 0) { return 0; }
  }
  return 1;
}

int day[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31};
int primeInMon[] = { 2,3,5,7,11,13,17,19,23,29,31,37 };
int ans[60000], ansCnt = 0;

void initAns() {
  int a[1000], aCnt = 0;
  cfor(mon, 1, 13, 1) {
    cfor(j, 0, 11, 1) {
      if (primeInMon[j] > day[mon]) { continue; }
      const int mmdd = mon*100+primeInMon[j];
      if (checkPrime(mmdd)) { a[aCnt++] = mmdd; }
    }
  }
  cfor(i, 0, aCnt, 1) {
    cfor(j, 1, 10000, 1) {
      int date = j*10000+a[i];
      if (checkPrime(date)) {
        ans[ansCnt++] = date;
      }
    }
  }
  for(int i = 4; i < 10000; i+=4) {
    const int yyyymmdd = i*10000+229;
    if (((i % 100) || (!(i % 400))) && checkPrime(yyyymmdd)) {
      ans[ansCnt++] = yyyymmdd;
    }
  }
}

int main() {
  initPrime();
  initAns();
  int t; scanf("%d", &t);
  char arr[10];
  while(t--) {
    scanf("%s", arr);
    int ret = 0;
    cfor(i, 0, ansCnt, 1) {
      int cur = ans[i]; bool flag = 1;
      for(int j = 7; j >= 0; --j, cur/=10) {
        if (arr[j] != '-' && arr[j]-'0' != cur%10)
          { flag = 0; break; }
      }
      ret += flag;
    }
    printf("%d", ret); NL;
  }
  return 0;
}