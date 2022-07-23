#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;




int vis[N], par[N], 
col[N], depth[N],
numOfNodes[N];

vector<int> adj[N];
int numOfComponents;

bool Bipartite = true;
bool isCyclic = false;
int cycles;


// u: starting Node
// p: parent node
// c: the color
// d: the depth 
void DFS(int u, int p=-1, int c=0,/*in case of tree*/ int d = 0){
    vis[u] = 1;
    par[u] = p;
    col[u] = c;
    depth[u] = d;
    
    for(auto ch : adj[u]){
        if(ch != p){
            if(vis[ch]){
                isCyclic = true;
                cycles++;
                if(col[ch] == col[u]) Bipartite = false;
            }
            else{
            DFS(ch, u, !c, d+1);
            }
        }
    }
}




//Count the number of nodes in a subtree
int DFS_Count(int u, int par = -1){
    numOfNodes[u] = 1;

    for(auto ch : adj[u]){
        if(ch != par){
            numOfNodes[u] += DFS_Count(ch, u);
        }
    }
    return numOfNodes[u];
}




int main(){
    memset(col, -1, sizeof(col));
    int a, nd, ch;
    cin>>a;
    for(int i=0; i<a; i++){
        cin>>nd>>ch;
        adj[nd].push_back(ch);
    }

    for(int i=1; i<=a; i++){
        if(!vis[i]){
            numOfComponents++;
            DFS(i);
        }
    }

    cout<<cycles<<endl;
    
    return 0;
}

