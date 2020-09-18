#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    int freq[26];
    memset(freq , 0 , sizeof(freq));
    for (char c : s) freq[c - 'a']++;
    for (int i = 25; i >= 0; i--) {
        if (freq[i] % 2) {
            for (int j = 0; j < 26; j++) {
                if (i == j) continue;
                if (freq[j] % 2) {
                    freq[j]++;
                    freq[i]--;
                    break;
                }
            }
        }
    }
    char ch = '#';
    string ans = "";
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2) ch = char(i + 'a');
        freq[i] /= 2;
        while (freq[i]) {
            ans.push_back(char(i + 'a'));
            freq[i]--;
        }
    }
    cout << ans;
    if (ch != '#') {
        cout << ch ;
    } 
    reverse(ans.begin() , ans.end());
    cout << ans << "\n";
    return 0;
}