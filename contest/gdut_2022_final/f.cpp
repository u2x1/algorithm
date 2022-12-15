#include <cstdio>
#include <set>
#include <map>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 2e5;
std::set<long long> st;
std::map<long long, int> cnt;

int main() {
  int n; scanf("%d", &n);
  long long tmp;
  orep(i, 0, n) {
    scanf("%lld", &tmp);
    st.insert(tmp);
    ++cnt[tmp];
  }
  long long rst = 0;
  while(st.size() > 1) {
    const long long raw = *st.crbegin();
    if (raw < 3) { printf("Lose"); return 0; }
    st.erase(raw);
    rst += cnt[raw];
    st.insert(raw/3);
    cnt[raw/3] += cnt[raw];
  }
  printf("%lld", rst);
  return 0;
}
