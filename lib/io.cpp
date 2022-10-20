#include <cstdio>

inline int read() {
  int x=0; char c=0;
  while(c<'0'  || c>'9') {c=getchar();}
  while(c>='0' && c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}
