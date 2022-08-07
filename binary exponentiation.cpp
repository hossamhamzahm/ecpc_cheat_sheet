
// binary exponentiation O(log(N))
long long Pow(int a, int n){
    long long res = 1;

    while(n){
        if(n%2){    
            n--;
            res *=a;
        }
        else{
            a *= a;
            n/=2;
        }
    }

    return res;
}