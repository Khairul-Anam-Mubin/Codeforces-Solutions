#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long double c;
    cin >> c;
    long double lo, hi, mid;
    lo = 0 , hi = 1e6;
    for (int i = 1; i <= 100; i++) {
        mid = (lo + hi) / 2.0;
        long double calc = mid * mid + sqrt(mid);
        if (calc < c) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << setprecision(20);
    cout << mid << "\n";
    return 0;
}