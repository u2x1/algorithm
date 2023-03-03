const int p = 1000000007;
const int maxN = 1e6+5;
long long fac[maxN];

long long inv(long long a) {
  int e = p-2; long long ret = 1;
  while(e) {
    if (e&1) { ret = (ret*a)%p; }
    e/=2; a = a*a%p;
  }
  return ret;
}

long long c(int m, int n) {
  return fac[m] * inv(fac[m-n])%p * inv(fac[n])%p;
}

long long init() {
  frac[0] = frac[1] = 1;
  orep(i, 2, n+1) { frac[i] = frac[i-1]*i%p; }
}
