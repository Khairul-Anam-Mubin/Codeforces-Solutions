#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin() , v.end());
    int k; cin >> k;
    while (k--) {
        int l , r; cin >> l >> r;
        int lo = 0 , hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (v[mid] <= r) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        int up_bound = lo;
        lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (v[mid] >= l) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        int lo_bound = lo;
        cout << up_bound - lo_bound << " ";
    }
    return 0;
}