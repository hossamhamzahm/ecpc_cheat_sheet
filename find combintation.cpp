#include <bits/stdc++.h>
using namespace std;

// C(n, k) = P(n, k)/k! = n!/ k!(n-k)!
// Notice that C(n, k) = C(n, n-k);



vector<vector<int>> combinations;
vector<int> combination;

int n=20;
int k=5;


void get_combinations(int i=0, int last_val=0){
    if(i == k){
        combinations.push_back(combination);
        return ;
    }

    for(int j=last_val+1; j<=n; j++){
        // DO
        combination.push_back(j);

        //RECURSE
        get_combinations(i+1, j);

        // UNDO
        combination.pop_back();
    }
}



ll nCr(int n, int r){
    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    ll p = 1, k = 1;

    if (n - r < r)
        r = n - r;

    while (r) {
        p *= n;
        k *= r;

        // gcd of p, k
        long long m = __gcd(p, k);

        p /= m;
        k /= m;

        n--;
        r--;
    }

    return p;
}
