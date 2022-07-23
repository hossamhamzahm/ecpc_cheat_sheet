#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;


vector<int> adj[N], order;
int vis[N], IN[N];


void topoSort_DFS(int u){
    vis[u] = 1;
    
    for(auto ch : adj[u]){
        IN[ch]--;
        
        if(!IN[ch]){
            topoSort_DFS(ch);
        }
    }
    order.push_back(u); 
}