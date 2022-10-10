#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
map<long long,int> m;
long long a;                                          
int main()
{
	freopen("F:\\alldate\\Data0.txt","r",stdin);
	while(scanf("%lld",&a)!=EOF){
		auto temp = m.find(a);
		if(temp!=m.end()){
			*temp++;
		}
		else m.insert({a,1});
		
	} 
	int maxn=-1;//maxn is answer
	int maxni=0;
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second>maxni){
			maxni=it->second;
			maxn=it->first;
		}
	}
	fclose(stdin);

	return 0;
}
