//383C Segtree com lazy + linearization of graph
#include <bits/stdc++.h>
using namespace std;
#define maxx 200010
typedef long long ll;
ll sgtree[8*maxx],lazy[8*maxx],arraux[maxx];
vector<int>ladj[maxx];

int in[maxx],out[maxx], timer = 1, par[maxx];
void dfs( int atual, int last){
	in[atual] = timer;
	timer++;
	for(int e: ladj[atual]){
		if(e!= last) {dfs(e,atual); par[e] = atual;}
	}
	out[atual] = timer;
	timer++;
}

void add(int id,ll l,ll r, ll v){
	ll sz = r-l+1;
	ll mid = (l+r) >> 1;
	sgtree[id] += v*sz;
	lazy[id<<1] += v*(mid-l+1);
	lazy[id<<1|1] += v*(r-mid);
	lazy[id] = 0;
}
void update(int id,ll l, ll r,ll x,ll y,ll v){
	add(id,l,r,lazy[id]/(r-l+1));
	if(l >= x && r <= y) {add(id,l,r,v);}
	else if( l > y || r < x) ;
	else{
		ll m = (l+r) >> 1;
		update(id<<1,l,m,x,y,v);
		update(id<<1|1,m+1,r,x,y,v);
		sgtree[id] = sgtree[id<<1] + sgtree[id<<1|1];
	} 
	
}
ll query(int id,ll l,ll r,ll x,ll y){
	add(id,l,r,lazy[id]/(r-l+1));
	if( l >= x && r <= y){return sgtree[id];}
	else if( l > y || r < x) return 0ll;
	else{
		ll m = (l+r) >> 1;
		return query(id<<1,l,m,x,y) + query(id<<1|1,m+1,r,x,y);
	}
}


int main(){
    ios_base::sync_with_stdio(false);  cin.tie(NULL);
    int n,m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> arraux[i];
    for(int i = 0; i < n-1;i++){
        int a,b; cin >> a >> b;
        ladj[a].push_back(b);
        ladj[b].push_back(a);
    }
    dfs(1,-1);
    for(int i = 1; i <= n; i++) {ll c = arraux[i]; update(1,1,2*n,in[i],in[i],(in[i]&1)? c:-c); }
    
    for(int i = 0; i < m; i++){
        int k; cin >> k;

        if(k == 2){
            int b; cin >> b;
            cout << ((in[b]&1)? 1:-1)*query(1,1,2*n, in[b],in[b]) << "\n";
            }
        
        if(k == 1){
            ll b,c; cin >> b >> c;
            update(1,1,2*n,in[b], out[b], (in[b]&1)? c:-c);
        }
    }

    return 0;
}
