/***********************************************************
********************Graph traversal (Unweighted)***********
 ************************************************************/
#include<bits/stdc++.h>
using namespace std;




const int N = 1e5+5;
int lvl[N], par[N]; // for tracking the parent of each node
vector<int> adj[N];


int numOfComponents;
bool isCyclic = false;
int cycles = 0;


bool isBipartite = true;
int col[N];



// O(n+m)
//explores the graph in a layered fashion 
void BFS(int start){
    queue<int> q;
    q.push(start);

    int currLvl = 1;
    lvl[start] = 1;
    par[start] = -1;
    col[start] = 0;

    while(!q.empty()){
        

        int lvlNum = q.size();


        for(int i=0; i<lvlNum; i++){
            
            int nd = q.front(); q.pop();
            
            for(auto ch : adj[nd]){
                if(ch != par[nd]){
                    if(lvl[ch] != -1){
                        isCyclic = true;
                        cycles++;

                        //checking if the graph is Bipartite
                        if(col[nd] == col[ch]) isBipartite = false;
                    }
                    else{
                        lvl[ch] = lvl[nd]+1;
                        q.push(ch);
                        par[ch] = nd;

                        // coloring the child with a color opposite to the node
                        col[ch] = !col[nd];
                    }
                }
            }

        }

        currLvl++;
    }
}



int main(){
    int n, u, v, x;
    cin>>n;
    memset(lvl, -1, sizeof(lvl));

    for(int i=0; i<n-1; i++){
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    for(int i=0; i<n-1; i++){
        if(lvl[i] != -1){
            numOfComponents++;
            BFS(i);
        }
    }


    // print the path to x
    int x; cin>>x;
    vector<int> path;
    while(x != -1){
        path.push_back(x);
        x = par[x];
    }

    reverse(path.begin(), path.end());
    //then print the path

    return 0;
}



