#include<bits/stdc++.h>
using namespace std;
/*
one is not a prime number because it contradicts the fundmental therom of Arithmetic
fundmental therom of arithmetic statets that the prime factorization for each composite number is unique.
*/



// Naive prime checking O(n)
bool naive_prime_checking(int n){
    if(n <= 1) return false;

    for(int i=2; i<n; i++){
        if (n%i==0) return false;
    }
    return true;
}


// prime checking O(sqrt(n))
bool is_prime(int n){

    if(n <= 1) return false;

    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }

    return true;
}

// sieve prime checking:
// Can go up to 10^7
void sieve(int n){     // O(N*log(log(N)))
    bool Is_prime[n+1];
    for(int i=0; i<=n; i++){
        Is_prime[i]=true;
    }

    Is_prime[0]=false;
    Is_prime[1]=false;

    // notice the or equal here because the size of the array is n+1
    for(int i=2; i*i<=n; i++){
        if(Is_prime[i]==true){
            for(int j=i*i; j<=n; j+=i){
                Is_prime[j]=false;
            }
        }
    }
}


// factorization O(sqrt(N)):
// results in the prime divisors of the number
vector<int> factorization(int n){

    vector<int> res;

    for(int i=2; i*i<=n; i++){
        while(n%i==0){
            res.push_back(i);
            n /= i;
        }
    }

    if(n!=1) res.push_back(n);

    return res;
}



// optimized
vector<int> factorization(int n){
    vector<int> res;

    while(n%2==0){
        res.push_back(2);
        n /= 2;
    }
    for(int i=3; i*i<=n; i+=2){
        while(n%i==0){
            res.push_back(i);
            n /= i;
        }
    }

    if(n!=1) res.push_back(n);
    return res;
}



//prime factorization using sieve O(log(N))
// look at slide 22 in number theory (ICPC)
void PFS(){
    int arr[1000001];

    int max = 1000000;
    for(int i=0; i<=max; i++) arr[i] = -1;

    for(int i=2; i<=max; i++){
        if(arr[i] == -1){
            arr[i] = i;
            for(int j=i*i; j<=max; j+=i){
                if(arr[j] == -1) arr[j] = i;
            }
        }
    } 

    // in the main
    // vector<int> factorize(n){
    //     vector<int> res;
    //     while(n != 1){
    //         res.push_back(arr[n]);
    //         n /= arr[n];
    //     }
    //     return res;
    // }
}

/*******************************************************************************************************************

Number theory second session

*******************************************************************************************************************/

//get divisors O(N):

vector<int> naive_get_divisors(int n){
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(n%i==0) res.push_back(i);
    }
    return res;
}




// get divisors O(sqrt(N)):

vector<int> get_divisors(int n){
    vector<int> res;
    int i;

    for(i=1; i*i<n; i++){
        if(n%i==0){
            res.push_back(i);
            res.push_back(n/i);
        }
    }
    if(i*i==n) res.push_back(i);     // To prevent redundancy

    return res;
}



// Greatest Common Divisor O():
// Builtin function: __gcd(a, b)

int GCD(int a, int b){
    if(b==0) return a;

    return GCD(b, a%b);
}

// iterative:
int GCD(int a, int b){
    while(b != 0){
        int temp = a%b;
        a = b;
        b = temp;
    }

    return a;
}


// LCM in prime_factorization form:
// builtin function __lcm(a, b)

int LCM(int a, int b){
    return a/__gcd(a, b) *b;   // to avoid overflow
}




/*****************************************************************************************************/

int main(){

    sieve(23);
    cout<<endl<<factorization(18);

    return 0;
}





