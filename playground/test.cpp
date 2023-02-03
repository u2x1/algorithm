#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e6+5;
char str[maxn];
long long power(int a,int b){
	long long ans=1;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans%10;
}
int main(){
	scanf("%s",str);
	if(strlen(str)<2){
		int m = str[strlen(str)-1]-'0';
		int ans = 1+power(2,m)+power(3,m)+power(4,m);
		ans%=5;cout<<ans;return 0;
	}
	int m=(str[strlen(str)-2]-'0')*10+str[strlen(str)-1]-'0';
	m = m%4==0?4:m%4;
	int ans = 1 + power(2,m)%5 + power(3,m)%5 + power(4,m)%5;
	ans%=5;
	cout<<ans;
}
