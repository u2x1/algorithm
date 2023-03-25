#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
std::string poo, ino;

void preo(const std::string in, const std::string po) {
  // std::cout << in << " " << po; NL;
  if (po.size()) { std::cout << po.back(); }
  if (po.size() <= 1) { return; }
  const char root = po.back(); const int p = in.find(root);
  preo(in.substr(0, p), po.substr(0, p));
  preo(in.substr(p+1), po.substr(p, po.size()-p-1));
}

// void preo(const int l, const int r) {
//   const char root = poo[r];
//   std::cout << root;
//   if (l == r) { return; }
//   const int p = ino.find(root);
//   std::cout << ": " << p; NL;
//   preo(l, p-1);
//   // preo(p, r-1);
// }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> ino >> poo;
  // ino = " " + ino;
  // poo = " " + poo;
  // preo(1, ino.size()-1);
  preo(ino, poo);



  return 0;
}
