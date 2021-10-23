// [CodeChef-ECJAN20I] 
#include <bits/stdc++.h>
using namespace std;

struct point {
    point(int x_, int y_):x(x_),y(y_) {}

    bool operator <(const point& other) { 
        if(x == other.x) return y < other.y;
        return x < other.x;
    } 

    int x; int y;
};

int cross(point a, point b) {
    return a.x*b.y - a.y*b.x; 
}

bool cw(point a, point b, point c) { 
    point Vab = {b.x - a.x, b.y - a.y}; 
    point Vbc = {c.x - b.x, c.y - b.y}; 
    return cross(Vab, Vbc) < 0; 
}

bool ccw(point a, point b, point c) { 
    point Vab = {b.x - a.x, b.y - a.y};
    point Vbc = {c.x - b.x, c.y - b.y};
    return cross(Vab, Vbc) > 0; 
}

int main() {
    int k; scanf(" %d", &k);
    while(k--) {
        vector<point> points;
        set<pair<int, int>> ms;
        int n,r; scanf(" %d %d", &n,&r);
        for(int i = 0; i < n; i++) {
            int x, y; scanf("%d %d", &x, &y);
            if(ms.find({x, y}) == ms.end()) {
                points.push_back({x, y});
                ms.insert({x, y});
            }
        }

        sort(points.begin(), points.end());

        vector<point> upper;
        vector<point> lower;

        for(int i = 0; i < points.size(); i++) {

            while(upper.size() >= 2 && !cw(upper[upper.size()-2], upper[upper.size()-1], points[i])) {
                upper.pop_back();
            }

            while(lower.size() >= 2 && !ccw(lower[lower.size()-2], lower[lower.size()-1], points[i])) {
                lower.pop_back();
            }
            upper.push_back(points[i]);
            lower.push_back(points[i]);
        }

        vector<point> ans = lower;
        for(int i = upper.size()-2; i >= 1; i--) {
            ans.push_back(upper[i]);
        }
        if(ans.size() <= r) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
