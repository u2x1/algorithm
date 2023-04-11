#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int a[20] ;
int mx = 1e9 + 10 , mm = 0 ;
int main(){
    int n ;
    cin >> n ;
    while(n --){
        int a, b ;
        scanf("%d%d",&a,&b) ;
        mx = min(mx , a / b) ;
        mm = max(mm , a / (b + 1) + 1) ;
    }

    cout << mm <<" " <<  mx; 
    return 0 ;
}
