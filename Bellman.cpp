#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
using namespace std;
typedef long long ll;
const long long N = 2e5+5, M = 1e9+7, OO = 0x3f3f3f3f, HS = 31, HS2 = 47, M2 = 1e9+9;
const double PI = acos(-1);


// Bellman Ford:
// It works on directed graphs only. 
// It can  handle negative edges but it can't 
// handle any negative cycles

int n, m;
ll dis[N];
bool cycle = 0;
//       node, child, cost
vector<pair<pair<ll, ll>, ll>> edges;

// O(n*m)
void Bellman(ll src){
    for(int i=0; i<=n; i++) dis[i] = OO;
    dis[src] = 0;

    bool exit;

    for(int i=0; i<=n-1; i++){
        exit = 1;
        for(auto e : edges){
            ll u = e.first.first;
            ll v = e.first.second;
            ll c = e.second;

            // relaxation
            if(dis[v] > dis[u] + c){
                dis[v] = dis[u]+c;
                exit = 0;

                if(i == n-1) cycle = 1;
            }
        }

        if(exit) break;
    }
}