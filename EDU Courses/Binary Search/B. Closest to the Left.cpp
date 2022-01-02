#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , k; cin >> n >> k;
    vector <int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];
    while (k--) {
        int x; cin >> x;
        int l = 0 , r = n - 1;
        bool found = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ar[mid] > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << l << "\n";
    }
    return 0;
}