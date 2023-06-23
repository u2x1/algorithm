#include <iostream>
#include <cassert>
#include <cctype>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
// int c1[maxN];
// int cr1[maxN], cr2[maxN];
// int cq[maxN], cqr[maxN];
int cnt[200];
int fact[100];
const int mod = 998244353;

int N;
std::string s;

long long f(int idx) {
  int l = -1, r = 99999999;
  orep(i, idx, N) {
    if (isupper(s[i])) { l = i; }
    if (l == -1 && islower(s[i])) { r = i; }
  }
  if (r < l) { return 0; }
  long long ret = 1;
  int q = 0; long long x = 1;
  for(int pos = idx; pos < N; ++pos) {
    if (s[pos] != '?') { continue; }
    if (pos < l || pos > r) {
      ret = ret * 26 % mod;
    } else {
      x = x * 26 % mod; ++q;
    }
  }
  if (q) {
    ret = ret*(x*q%mod)%mod;
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  // fact[0] = 1;
  // orep(i, 1, 100) { fact[i] = fact[i-1] * i % mod; }
  std::cin >> s;
  s = ' ' + s;
  N = s.size();
  // orep(i, 1ul, s.size()) {
  //   c1[i] = c1[i-1] + (isupper(s[i]) != 0);
  //   cq[i] = cq[i-1] + (s[i] == '?');
  //   cr1[s.size()-i+1] = cr1[s.size()-i+2] + (isupper(s[s.size()-i+1]) != 0);
  //   cr2[s.size()-i+1] = cr2[s.size()-i+2] + (islower(s[s.size()-i+1]) != 0);
  //   cqr[s.size()-i+1] = cqr[s.size()-i+2] + (s[s.size()-i+1] == '?');
  // }
  long long ret = 0;
  int has = 0; int q = 0;
  orep(i, 1ul, s.size()) {
    if (q > 26-has) { break; }
    if (s[i] == '?') {
      std::cout << "?: ";
      orep(c, 'A', 'Z'+1) {
        if (cnt[c]) {
          long long a = 1;
          for (int x = 26-has, j = q; j; --j, --x) { a = a*x%mod; }
          a = a * f(i+1) % mod;
          ret += a;
          ret %= mod;
        } else {
          if (q == 0) { continue; }
          long long a = 1;
          for(int x = 25-has, j = q-1; j; --j, --x) { a = a*x%mod; }
          a = a * q % mod;
          a = a * f(i+1) % mod;
          ret += a;
          ret %= mod;
        }
      }
      std::cout << ret; NL;
    } else if (islower(s[i])) {
      continue;
    } else if (isupper(s[i])) {
      std::cout << "upper: ";
      if (cnt[s[i]]) {
        if (q > 26-has) { break; }
        long long a = 1;
        for (int x = 26-has, j = q; j; --j, --x) { a = a*x%mod; }
        a = a * f(i+1) % mod;
        ret += a;
        ret %= mod;
      } else {
          if (q == 0) { continue; }
          long long a = 1;
          for(int x = 25-has, j = q-1; j; --j, --x) { a = a*x%mod; }
          a = a * q % mod;
          a = a * f(i+1) % mod;
          ret += a;
          ret %= mod;
      }
      std::cout << ret; NL;
    }
    cnt[s[i]]++;
    // std::cout << "hi" << s[i]; NL;
    if (isupper(s[i]) && ++has && cnt[s[i]] == 2) { break; }
    if (s[i] == '?') { ++q; }
  }
  // orep(i, 1ul, s.size()) { std::cout << c1[i] << " ";  } NL;
  // orep(i, 1ul, s.size()) { std::cout << cr1[i] << " ";  } NL;
  // orep(i, 1ul, s.size()) { std::cout << cr2[i] << " ";  } NL;
  orep(i, 1ul, s.size()) {
    if (islower(s[i])) {

    }
  }
  std::cout << ret;

  return 0;
}
