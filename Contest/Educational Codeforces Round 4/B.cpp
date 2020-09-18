#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    array <int , 2> ar[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> ar[i][0];
        ar[i][1] = i;
    }
    sort(ar + 1 , ar + n + 1);
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += abs(ar[i][1] - ar[i + 1][1]);
    }
    cout << ans << "\n";
    return 0;
}