#include <cstdio>
#include <set>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int arr[n][m];
  orep(i, 0, n) {
    orep(j, 0, m) {
      scanf("%d", &arr[i][j]);
    }
  }
  int rst[k+1] = {};
  std::set<int> st;
  orep(i, 0, m) {
    orep(j, 0, n) {
      rst[arr[j][i]] += st.insert(arr[j][i]).second;
    }
    st.clear();
  }

  crep(i, 1, k) {
    printf("%d ", rst[i]);
  }

  return 0;
}
