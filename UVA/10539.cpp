#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1e13
#define SMAXN sqrt(MAXN)

vector<bool> primes(SMAXN+1, true);
vector<ll> almost_primes;

void init(){
    primes[0] = true, primes[1] = true;
    // sieve of Eratosthenes.
    for(ll i = 2; i*i <= SMAXN; i++){
        if(primes[i]){
            for(ll j = i*i; j <= SMAXN; j+= i)
                primes[j] = false;
        }
    }
    // almost Pirme = Prime mulpitles.
    // ex. 1 to 20 => 4(2^1), 8(2^3), 9(3^2), 16(2^4)
    for(ll i = 2; i <= SMAXN; i++){
        if(primes[i]){
            ll x = i*i;
            while(x <= MAXN){
                almost_primes.push_back(x);
                x *= i;
            }
        }
    }
    // no order push_back, to convenient search that we sort it.
    sort(almost_primes.begin(), almost_primes.end());
}

/*
    sieve of Eratosthenes

    Exmaple : 1 to 20
    1  2  3  4  5  6  7  8  9  10
    11 12 13 14 15 16 17 18 19 20

    sqrt(20) ~= 6..? choose => 7.
    for (k = 1 to 7) find multiples k (k is not prime)
        set k is not prime.
        and if(prime[k]) is to avoid redundnacy calculation.
        ex. 6 = in 2 and 3 is already set.

    so sieve of Eratosthenes time complexity = O(n*(ln(ln(n)))).
    is better than Brute-force = O(n*(n^1/2)) or (n^n).
*/

ll binary_search(ll target, ll l, ll r){
    ll mid = l + (r-l)/2;
    if(l <= r){
        if(almost_primes[mid] > target)
            return binary_search(target, l, mid-1);
        else if(almost_primes[mid] < target)
            return binary_search(target, mid+1, r);
        else 
            return mid;
    }
    return l;
}
// UVA online judge AC. but binary search may have bounded problem.
// you can use C++ algorithm：lower_bound & upper_bound to solve and fix.

int main(){
    init();
    
    int times, n = almost_primes.size(); 
    cin >> times;

    while(times-- > 0){
        ll low, high;
        cin >> low >> high;
        // cout << "low = " << binary_search(low,0, n-1) << endl;
        // cout << "higt = " <<  binary_search(high, 0, n-1) << endl;
        cout << binary_search(high, 0, n)-binary_search(low, 0, n) << endl;
        
        // cout << upper_bound(almost_primes.begin(), almost_primes.end(), high) - lower_bound(almost_primes.begin(), almost_primes.end(), low) << endl;
    }

    return 0;
}