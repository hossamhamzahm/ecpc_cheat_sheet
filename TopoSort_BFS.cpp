#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
const int N = 1e5;


int m, a, b;
int vis[N], par[N], IN[N];
vector<int> adj[N], order;


void BFS(int start, int arr[]){
    queue<int>q;
    
    for(int i=0; i<m; i++){
        if(IN[arr[i]] == 0){
            vis[arr[i]] = 1;
            q.push(arr[i]);
        }
    }

    while(!q.empty()){
        int nd = q.front(); q.pop();
        order.push_back(nd);

        for(auto ch : adj[nd]){
            IN[ch]--;
            if(IN[ch] == 0) q.push(ch);
        }
    }

}





int main(){
    cin>>m;

    int arr[m];
    
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        IN[b]++;
        arr[i] = a;
    }

    BFS(1, arr);

    for(auto ch : order){
        cout<<ch<<endl;
    }

    return 0;
}