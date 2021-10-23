// [653D] Flow with binary search
#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9;
const int maxx = 100100;
const int SOURCE = maxx-1;
const int SINK = maxx-2;
 
struct edge {
    int to, cap, rev;
    edge(int _to, int _cap, int _rev): to(_to), cap(_cap), rev(_rev){}
};
struct edge_aux{
    int v1,v2,peso;
};
vector<edge> graph[maxx];
vector<edge_aux> graph_aux;
int level[maxx], iter[maxx];
int n,m,x; 
struct dinic {
 
    dinic() {
        fill(level, level+maxx, 0);
        fill(iter, iter+maxx, 0);
    }
 
    void add(int from, int to, int cap) {
        graph[from].push_back(edge(to, cap, graph[to].size()));
        graph[to].push_back(edge(from, 0, graph[from].size()-1));
    }
 
    void bfs(int s) {
        memset(level, -1, sizeof level);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while( !q.empty() ) {
            int actual = q.front();
            q.pop();
            for(int i = 0; i < graph[actual].size(); i++) {
                edge &e = graph[actual][i];
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[actual] + 1;
                    q.push(e.to);
                }
            }
        }
    }
 
    int dfs(int v, int t, int f) {
        if(v == t) return f;
        for(int &i = iter[v]; i < graph[v].size(); i++) {
            edge &e = graph[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
 
    int flow(int start, int to) {
        int ans = 0;
        while(true){
            bfs(start);
            if(level[to] < 0) return ans;
            int f;
            memset(iter, 0, sizeof iter);
            while((f = dfs(start, to, INF)) > 0) ans += f;
        }
    }
}dinic;
void clean(){
    for(int i = 1; i <= n; i++) {
        graph[i].clear();
        level[i] = 0;
        iter[i] = 0;
    }
}
int main(){
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++){
        int a,b,w; cin >> a >> b >> w;
        graph_aux.push_back({a,b,w});
    }
    double left = 0.0, right = 1e6;
    double ans = 0;
    for(int i = 0; i < 100; i++){
        if(i!=0) clean();
        double mid = (left+right)/2;
        for(int j = 0; j < m; j++){
            auto ed = graph_aux[j];
            dinic.add(ed.v1,ed.v2,min(1e6,(ed.peso) / mid));
        }
        int atual = dinic.flow(1,n);
        if(atual < x) right = mid;
        else {ans = max(mid*x,ans); left = mid;}
    }
    cout << setprecision(7) << fixed << ans << "\n";
}
