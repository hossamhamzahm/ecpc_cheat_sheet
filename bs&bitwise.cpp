#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
using namespace std;
typedef long long ll;
int const N = 1e5 + 5, M = 2e3 + 5, MOD = 1e9 + 7;
const ll OO = 1e18;
const double eps = 1e-7;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(t) tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>


// Binary search:


// for f(x) : 111111110000000000
// l is pointing to -OO initially (represented as index -1)
// h is pointing to OO initially (represented as index n or n+1 regarding the problem)
int bs_max_smaller_ele(int target){
    int l=-1, m, h=n;

    while(h-l > 1){
        m = l + (h-l)/2;
        if(arr[m] <= target) l = m;
        else h = m;
    }

    return l;
}


int bs(int target){
    int l=0, m, h=n-1;

    while(h >= l){
        m = l + (h-l+1)/2;

        if(target == arr[m]) return m;
        else if(target > arr[m]) l = m+1;
        else h = m-1;
    }
    return -1;
}


// for f(x) : 000000000011111111111
int bs_min_greater_ele(int target){
    int l=-1, m, h=n;

    while(h-l > 1){
        m = l + (h-l)/2;
        if(arr[m] < target) l = m;
        else h = m;
    }

    return h;
}


// searching over floating point numbers
// the for loop is used to avoid infinite loop
double real_num_bs(){
    double l=eps, m, h=1e7;

    for(int i = 0; i < 100; i++){
        m = (l+h)/2;
        if(ok(m)) l = m;
        else h = m;
    }

    return l;
}





// bitwise operations:

// same as __builtin__popcount(n)
int setBitCounter1(int n){
    int ans = 0;
    for(int i=0; i<32; i++){
        if((n&(1<<i))) ans++;
    }
    return ans;
}

// Brian Kernighan’s Algorithm:
int setBitCounter2(int n){
    int ans = 0;

    while(n){
        ans++;
        n &= (n-1);
    }

    return ans;
}


// subsets:
char Set[4] = {'A', 'B', 'C'};

int main(){
    int N = 3;
    int subNum = 1<<N;

    for(int k=0; k<subNum; k++){
        for(int i=0; i<N; i++){
            int checker = 1<<i;

            if((k&checker) != 0){
                cout<<Set[i]<<" ";
            }  
        }
        cout<<"\n";
    }

    return 0;
}




