#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, p , q;
    cin >> n >> p >> q;
    string s; cin >> s;
    if (p < q) swap(p , q);
    if (n % p == 0) {
        cout << n / p << "\n";
        for (int i = 0 ; i < n; i += p) {
            cout << s.substr(i , p) << "\n";
        } 
    } else if (n % q == 0) {
        cout << n / q << "\n";
        for (int i = 0; i < n; i += q) {
            cout << s.substr(i , q) << "\n";
        }
    } else {
        for (int i = p; i <= n ; i += p) {
            if ((n - i) % q == 0) {
                cout << i / p + (n - i) / q << "\n";
                for (int j = 0; j < i; j += p) {
                    cout << s.substr(j , p) << "\n";
                }
                for (int j = i; j < n; j += q) {
                    cout << s.substr(j , q) << "\n";
                }
                return 0;
            }
        }
        for (int i = q; i <= n; i += q) {
            if ((n - i) % p == 0) {
                cout << i / q + (n - i) / p << "\n";
                for (int j = 0; j < i; j += q) {
                    cout << s.substr(j , q) << "\n";
                }
                for (int j = i; j < n; j += p) {
                    cout << s.substr(j , p) << "\n";
                }
                return 0;
            }
        }
        cout << "-1\n";
    }
    return 0;
}