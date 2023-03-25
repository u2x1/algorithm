#include <iostream>
#include <climits>
#include <string>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[6];
int champ[6];
std::map<std::string, int> mp;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    orep(j, 1, 6) {
      std::string s; std::cin >> s;
      if (mp[s]) { continue; }
      mp[s] = j;
    }
  }
  int m; std::cin >> m;
  orep(i, 0, m) {
    std::string s; int pos; std::cin >> s >> pos;
    if (mp[s] && pos == mp[s]) { 
      champ[pos]++;
    } else {
      arr[pos]++;
    }
  }
  int ret = 0;
  while(1) {
    bool has = 0;
    orep(i, 1, 6) {
      if (!has && champ[i]) { has = 1; champ[i]--; continue; }
      if (!champ[i] && !arr[i]) { goto fend; }
      if (arr[i]) { arr[i]--; continue; }
      if (champ[i]) { champ[i]--; continue; }
    }
    if (!has) { goto fend; }
    ret++;
    // int mi = 1, micnt = INT_MAX;
    // orep(i, 1, 6) {
    //   if (micnt > arr[i] && champ[mi] != 0) { mi = i; micnt = arr[i]; }
    // }
    // champ[mi]--;

    // orep(i, 1, 6) {
    //   if (i == mi) { continue; }
    //   if (arr[i] == 0 && champ[i] == 0) { goto fend; }
    //   if (arr[i] == 0) { champ[i]--; }
    //   else { arr[i]--; }
    // }
    // ret++;
    // std::cout << "ret: " << mi; NL;
    // std::cout << "arr: ";
    // orep(i, 1, 6) { std::cout << arr[i] << " "; }NL; 
    // std::cout << "champ: ";
    // orep(i, 1, 6) { std::cout << champ[i] << " "; }NL; 
  }

fend:;
  std::cout << ret;
  return 0;
}
