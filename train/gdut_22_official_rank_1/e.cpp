#include <iostream>
#include <cstring>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e2+5;
int arr[maxN][maxN];
const int maxF = 1e7;
int last[maxF];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, q; std::cin >> n >> q;
  orep(i, 0, n) {
    orep(j, 0, n) {
      std::cin >> arr[i][j];
    }
  }

  {
    memset(last, -1, sizeof(last));
    last[2] = 1;
    int a = 1, b = 1;
    while(1) {
      int c = a+b;
      if (c >= maxF) { break; }
      last[c] = b;
      a = b; b = c;
    }
  }

  std::string s; std::cin >> s;
  orep(ggg, 0, q) {
    char c = s[ggg];
    if (c == 'L') {
      orep(i, 0, n) {
        int touched = 0;
        orep(j, 1, n) {
          int jj = j;
          while(jj > touched) {
            int a = arr[i][jj-1], b = arr[i][jj];
            if (a == -1 || b == -1) { break; }
            else if (a == 0) { std::swap(arr[i][jj-1], arr[i][jj]); --jj; continue; }
            else {
              if (a > b) { std::swap(a, b); }
              if (last[b] == a) { arr[i][jj-1] = a+b; arr[i][jj] = 0; touched = jj;
                // std::cout << i  << " "<< jj-1  << " become " << a+b<<  " when L at " << touched; NL;
                break; }
              break;
            }
          }
        }
      }
    } else if (c == 'R') {
      orep(i, 0, n) {
        int touched = n;
        for(int j = n-1; j>0; --j) {
          int jj = j;
          while(jj < touched) {
            int a = arr[i][jj-1], b = arr[i][jj];
            if (a == -1 || b == -1) { break; }
            else if (b == 0) { std::swap(arr[i][jj-1], arr[i][jj]); ++jj; continue; }
            else {
              if (a > b) { std::swap(a, b); }
              if (last[b] == a) { arr[i][jj] = a+b; arr[i][jj-1] = 0; touched = jj;
                // std::cout << i  << " "<< jj  << " become " << a+b<<  " when R at " << touched; NL;
                break; }
              break;
            }
          }
        }
      }
    } else if (c == 'U') {
      orep(j, 0, n) {
        int touched = 0;
        orep(i, 1, n) {
          int ii = i;
          while(ii > touched) {
            int a = arr[ii-1][j], b = arr[ii][j];
            if (a == -1 || b == -1) { break; }
            else if (a == 0) { std::swap(arr[ii-1][j], arr[ii][j]); --ii; continue; }
            else {
              if (a > b) { std::swap(a, b); }
              if (last[b] == a) { arr[ii-1][j] = a+b; arr[ii][j] = 0; touched = ii;
                // std::cout << ii-1  << " "<< j  << " become " << a+b<<  " when U at " << touched; NL;
                break; }
              break;
            }
          }
        }
      }
    } else if (c == 'D') {
      orep(j, 0, n) {
        int touched = n;
        for(int i = n-1; i > 0; --i) {
          int ii = i;
          while(ii < touched) {
            int a = arr[ii-1][j], b = arr[ii][j];
            if (a == -1 || b == -1) { break; }
            else if (b == 0) { std::swap(arr[ii-1][j], arr[ii][j]); ++ii; continue; }
            else {
              if (a > b) { std::swap(a, b); }
              if (last[b] == a) { arr[ii][j] = a+b; arr[ii-1][j] = 0; touched = ii;
                // std::cout << ii  << " "<< j  << " become " << a+b<<  " when D at " << touched; NL;
                break; }
              break;
            }
          }
        }
      }
    }
  }

  orep(i, 0, n) {
    orep(j, 0, n) {
      std::cout << arr[i][j] << " "; 
    } NL;
  }

  return 0;
}
