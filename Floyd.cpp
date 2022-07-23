#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
using namespace std;
typedef long long ll;
const long long N = 2e5+5, M = 1e9+7, OO = 0x3f3f3f3f, HS = 31, HS2 = 47, M2 = 1e9+9;
const double PI = acos(-1);


ll n, m, u, v, c, start, ed, q;
int nxt[N][N]; //used for path finding
ll dis[N][N];


// negative cycles are not permitted
// Floyd-Warshall:
// an algorithm that finds the shortest path between 
// all pairs of vertices, negative edges are allowed
// it is a dp algorithm using a memo table called dis :)


// O(n^3)
void Floyd(){
    for(int k = 0; k <= 500; k++){
        for(int u = 0; u <= 500; u++){
            for(int v = 0; v <= 500; v++){
                if(dis[u][v] > dis[u][k] + dis[k][v]){
                    dis[u][v] = dis[u][k] + dis[k][v];
                    nxt[u][v] = nxt[u][k];
                }
            }
        }
    }
}



int main(){
    FIO

    cin >> n >> m;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                dis[i][j] = 0;
                nxt[i][j] = j;
            }
            else{
                dis[i][j] = OO;
                nxt[i][j] = OO;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cin >> u >> v >> c;
        dis[u][v] = c;
        dis[v][u] = c;

        nxt[u][v] = v;
        nxt[v][u] = u;
    }
    Floyd();


    cin >> start >> q;
    for(int i = 0; i < q; i++){
        cin >>  ed;

        if(dis[start][ed] != OO){
            cout << dis[start][ed] << "\n";

            // building the path:
            vector<int> path;
            int at = start;

            for(; at != ed; at=nxt[at][ed]){
                path.pb(at);
            }
            path.pb(ed);

            cout << "path:\n";
            for(auto el: path) cout << el <<" ";
            cout << "\n\n";
        }
        else cout << "NO PATH\n";
    }

    return 0;
}

