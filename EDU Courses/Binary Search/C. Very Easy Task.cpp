#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, x , y;
    cin >> n >> x >> y;
    if (x > y) swap(x , y);
    ll lo = 0 , hi = 2e9;
    ll ans = hi;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll tot_pos = mid / x + mid / y;
        if (tot_pos >= n - 1) {
            ans = min(ans , mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
        //cout << mid << "\n";
    }
    cout << ans + x << "\n";
    return 0;
}