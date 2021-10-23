//Simple LCA
#include <bits/stdc++.h>
using namespace std;
#define maxx 1002
int depth[maxx],parent[22][maxx],n;
vector<int>ladj[maxx];

void dfs(int u,int p) {
    for (int i = 0; i < (int)ladj[u].size(); i++) {
    	int e = ladj[u][i];
        if (e != p) {
            depth[e] = 1 + depth[u];
            parent[0][e] = u;
            dfs(e, u);
        }
    }
    return;
}

void build(int node) {
	depth[node] = 0;
    dfs(node,-1);
    parent[0][node] = node;
    for(int j = 1; j <= 20; j++){
        for(int i = 0; i <= n; i++){
            parent[j][i] = parent[j-1][parent[j-1][i]];
        
    	}
    }
}

int get_lca(int x, int y) {
    if(depth[x] < depth[y]) swap(x,y);

    for(int i = 20; i >= 0; i--)
        if(depth[x] - depth[y] >= (1 << i))
            x = parent[i][x];

    if(x == y) return x;

    for(int i = 20; i >= 0; i--)
        if(parent[i][x] != parent[i][y]) {
            x = parent[i][x];
            y = parent[i][y];
        }

    return parent[0][x];
}
