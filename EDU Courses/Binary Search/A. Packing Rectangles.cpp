#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll w, h, n;
bool Good(ll mid) {
    ll tot = (mid / w) * (mid / h);
    return (tot >= n);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> h >> n;
    ll lo = 0 , hi = 1;
    while (!Good(hi)) hi *= 2;
    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        if (Good(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
    return 0;
}