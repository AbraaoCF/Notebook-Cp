//Count inversion with BIT
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxx 200005
ll bit[maxx],arr[maxx],mir[maxx],a;

ll query(ll i){
    ll sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (i&-i);
    }
    return sum;
}
 void add(ll i){
    while(i <= a){
        bit[i] += 1;
        i += (i&-i);
    }
    return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		cin.ignore();
		cin >> a;
		map<ll,int>dicio;
		memset(bit,0,sizeof bit);	
		ll cont = 0;
		
		for(int j = 1; j <= a; j++){cin >> arr[j]; mir[j] = arr[j];}
		sort(mir,mir+a+1);
		for(int j = 1; j <= a; j++)dicio[mir[j]] = j;
		
		for(int j = 1; j <= a; j++){
			cont += query(a) - query(dicio[arr[j]]);
			add(dicio[arr[j]]);
		}
		cout << cont << "\n";
	}
	return 0;
}
