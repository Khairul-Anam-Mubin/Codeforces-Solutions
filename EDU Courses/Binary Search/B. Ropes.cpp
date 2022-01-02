#include <bits/stdc++.h>
using namespace std;

vector <double> v;
int n, k;
bool Good(double mid) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += floor(v[i] / mid);
    }
    return (sum >= k);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    double lo = 0, hi = 1e8;
    for (int i = 1; i <= 100; i++) {
        double mid = (lo + hi) / 2.0;
        if (Good(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
        //cout << lo << " " << mid << " " << hi << "\n";
    }
    cout << setprecision(20) << lo << "\n";
    return 0;
}