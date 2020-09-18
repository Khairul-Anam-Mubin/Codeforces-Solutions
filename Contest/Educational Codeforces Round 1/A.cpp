#include <bits/stdc++.h>
using namespace std ;

int main() {
    int tc ;
    cin >> tc ;
    while(tc--) {
        long long n ;
        cin >> n ;
        long long x = log2(n) ;
        long long now = pow(2LL , x + 1LL) - 1LL;
        long long sum = (n * (n + 1)) / 2LL ;
        long long res = sum - now ;
        res -= now ;
        cout << res << "\n" ;
    }
    return 0 ;
}
 