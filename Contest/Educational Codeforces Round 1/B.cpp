#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    int q; cin >> q;
    int len = s.size();
    while (q--) {
        int l , r , k; cin >> l >> r >> k;
        int dif = r - l + 1;
        k %= dif;
        l-- , r--;
        int last = r - k + 1;
        int first = last - 1;
        string tmp2 = s.substr(last , r - last + 1);
        string tmp1 = s.substr(l , first - l + 1);
        string tmp = tmp2 + tmp1;
        //cout << tmp1 << "\n";
        //cout << tmp2 << "\n";
        //cout << tmp << "\n";
        for (int i = l, j = 0 ; i <= r; i++, j++) {
            s[i] = tmp[j];
        }
    }
    cout << s << "\n";
    return 0;
}