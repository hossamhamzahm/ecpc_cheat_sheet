#include<bits/stdc++.h>
using namespace std;




int perm_cnt = 0;
vector<int> p = {0, 1, 2, 3};

// after all iterations perm_cnt =  4! = 24
do{
    perm_cnt++;
} while(next_permutation(p.begin(), p.end()));



// find the permutation of n numbers while removing the repeated elements 
long long perm(int n, int r){
    long long ans = 1;

    for(int i=r+1; i<=n; i++) ans *= i;

    return ans;
}