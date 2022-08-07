// initialize pascal
long long p[1001][1001]= {0};
void initialize(){
    // C(0, 0) = 1 
    p[0][0] = 1;
    
    for(int i=1; i<=1000; i++){
        // set every C(n, 0) = 1
        p[i][0] = 1;

        // C(n, r) = C[r-1][n] + C[r-1][n-1]
        for(int j=1; j<i+1; j++){
            p[i][j] = p[i-1][j] + p[i-1][j-1];
        }
    }
}



int main(){
    int n, r;
    cin >> n >> r;

    cout << p[n][r] << endl;
    return 0;
}
