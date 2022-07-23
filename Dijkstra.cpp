#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
using namespace std;
typedef long long ll;
const long long N = 2e5+5, M = 1e9+7, OO = 0x3f3f3f3f, HS = 31, HS2 = 47, M2 = 1e9+9;
const double PI = acos(-1);


// Dijkstra:

// dijkstra works with directed and 
// undirected non-negative weights 


// adj[parent].pb({child, weight})
vector<pair<ll, ll>> adj[N];
ll n, m, u, v, c;
ll dis[N];
ll parent[N];


// O(log(n)(n+m)) instead of 
//  O(n*log(n)*(n+m))
void Dijkstra(int start){
    for(int i=0; i<=n; i++) dis[i] = OO;
    dis[start] = 0;

    // weight to reach the node, the node
    priority_queue<pair<ll, ll>> pq; // insertion in O(log(N)) because it is sorted
    pq.push({0, start});

    while(!pq.empty()){
        ll nd = pq.top().second;
        ll ndc = -pq.top().first; // notice we returned the weight to positive again
        pq.pop();


        if(dis[nd] != ndc) continue;

        // Relaxation
        for(auto ch : adj[nd]){
            ll ch_nd = ch.first;
            ll ch_c = ch.second;

            if(dis[ch_nd] > dis[nd] + ch_c){
                dis[ch_nd] = dis[nd] + ch_c; 
                pq.push({-dis[ch_nd], ch_nd});
                
                parent[ch_nd] = nd;
            }
        }
    }
}
