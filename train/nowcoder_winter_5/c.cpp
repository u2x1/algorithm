#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';


void bigger(bool swaped) { std::cout << (swaped ? '<' : '>'); }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);

  std::string strA, strB; std::cin >> strA >> strB;

  if (strA == strB) { std::cout << "="; return 0; }
  if (strA.size() == strB.size()) { std::cout << "!"; return 0; }

  bool swaped = 0;
  if (strA.size() < strB.size()) { std::swap(strA, strB); swaped = 1; }

  const char tp = strA[0];
  int dropA = 0; orep(i, 0ul, strA.size()) { if(strA[i] == tp) { dropA++; } else { break; } }
  int dropB = 0; orep(i, 0ul, strB.size()) { if(strB[i] == tp) { dropB++; } else { break; } }

  if (strA.size() - dropA < strB.size() - dropB) {
    std::cout << "!"; return 0;
  }

  if (strA.size() - dropA == strB.size() - dropB) {
    for(int i = dropA, j = dropB; i < strA.size(); ++i, ++j) {
      if (strB[j] == tp && strA[i] != tp) { bigger(swaped); return 0;  }
      if (strA[i] != strB[j]) { break; }
    }
    std::cout << "!"; return 0;
  }

  bigger(swaped);

  return 0;
}
