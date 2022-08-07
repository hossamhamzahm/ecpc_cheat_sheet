#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long ll;
int const N = 2e5 + 5, M = 2e3 + 5, MOD = 1e9 + 7;
const ll OO = 1e18;
// #include"test1.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(t) tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>


int n, m, u, v, c, tot, ans;
vector<pair<int, pair<int, int>>> edges;


struct DSU{
    int par[N], sz[N];

    DSU(int n){
        for(int i = 0; i <= n; i++){
            sz[i] = 1;
            par[i] = i;
        }
    }


    int findParent(int u){
        if(par[u] == u) return u;
        return par[u] = findParent(par[u]);
    }


    void join(int u, int v){
        u = findParent(u);
        v = findParent(v);

        if(u == v) return ;

        if(sz[v] > sz[u]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }

    bool sameSet(int u, int v){
        return findParent(u) == findParent(v);
    }
};


void Kruskal(DSU &dsu){
    sort(edges.begin(), edges.end());

    for(auto edge : edges){
        u = edge.second.first;
        v = edge.second.second;
        c = edge.first;

        if(!dsu.sameSet(u, v)){
            ans += c;
            dsu.join(u, v);
        }
    }
}



int main(){
    FIO

    while(cin >> m >> n){
        if(!m && !n) break;
        edges.clear();
        tot = 0;
        ans = 0;
        DSU dsu(m);

        for(int k = 0; k < n; k++){
            cin >> u >> v >> c;
            edges.pb({c, {u, v}});
            tot += c;
        }

        Kruskal(dsu);

        cout << tot - ans << "\n";
    }

    return 0;
}
