#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long ll;
int const N = 1e5 + 5, M = 2e3 + 5, MOD = 1e9 + 7;
const ll OO = 1e18;
// #include"test1.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(t) tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>


int n, q, a, arr[N];
vector<pair<int, pair<int, int>>> edges;


struct SegTree{
    int sz = 1;
    vector<ll> tree;

    SegTree(int n){
        while(sz < n) sz *= 2;
        tree.assign(2*sz, 1e9);
    }


    void build(int cur, int cur_l, int cur_r){
        if(cur_r - cur_l == 1 ){
            if(cur_l < n) tree[cur] = arr[cur_l];
            return ;
        }

        int m = (cur_r + cur_l)/2;
        build(cur*2 +1, cur_l, m);
        build(cur*2 +2, m, cur_r);

        tree[cur] = min(tree[cur*2 +1], tree[cur*2 +2]);
    }


    void update(int idx, ll val){
        update(idx, val, 0, 0, sz);
    }

    void update(int idx, ll val, int cur, int cur_l, int cur_r){
        if(cur_r - cur_l == 1){
            tree[cur] = val;
            return ;
        }

        int m = (cur_r + cur_l)/2;
        if(idx < m) update(idx, val, cur*2 +1, cur_l, m);
        else update(idx, val, cur*2 +2, m, cur_r);

        tree[cur] = min(tree[cur*2 +1], tree[cur*2 +2]);
    }



    ll query(int l, int r){
        return query(l, r, 0, 0, sz);
    }

    ll query(int l, int r, int cur, int cur_l, int cur_r){
        if(l >= cur_r || r <= cur_l) return 1e9;
        if(l <= cur_l && r >= cur_r) return tree[cur];

        int m = (cur_r + cur_l)/2;
        ll left = query(l, r, cur * 2 + 1, cur_l, m);
        ll right = query(l, r, cur * 2 + 2, m, cur_r);

        return min(left, right);
    }
};



int main(){
    FIO
    int t = 1;
    // cin >> t;

    while(t--){
        cin >> n;
        SegTree st(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        st.build(0, 0, st.sz);

        int q, l, r;
        cin >> q;

        for(int k = 0; k < q; k++){
            cin >> l >> r;
            cout << st.query(l, r+1) << "\n";
        }

    }

    return 0;
}
