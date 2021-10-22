//Sgtree de min
#include <bits/stdc++.h>
using namespace std;
#define maxx 100010
typedef pair<int,int> ii;
typedef long long ll;

ll sgtree[4*maxx],arr[maxx];
void update(int id, int l,int r, ll x, ll v){
	if(l == r) sgtree[id] = v;
	else if(l > x || r < x) return;
	else{
		int m = (l+r) >> 1;
		if(m >= x) update(id<<1,l,m,x,v);
		else update(id<<1|1,m+1,r,x,v);
		sgtree[id] = min(sgtree[id<<1], sgtree[id<<1|1]);

	}
}
ll query(int id,int l,int r, ll x,ll y){
	if(l >= x && r <= y) return sgtree[id];
	else if(l > y || r < x) return 1e9+7;
	else {
		int m = (l+r) >> 1;
		return min(query(id<<1,l,m,x,y),query(id<<1|1, m+1,r,x,y));
	}
}
int main() {
	int n,m; cin >> n >> m;
	for(int i = 1; i <= n; i++) {cin >> arr[i]; update(1,1,n,i,arr[i]);}
	for(int i = 1; i <= m; i++){
		ll a,b,c; cin >> a >> b >> c;
		if(a == 1) update(1,1,n,b+1,c);
		else cout << query(1,1,n,b+1,c) << "\n";
	}
	return 0;
}
