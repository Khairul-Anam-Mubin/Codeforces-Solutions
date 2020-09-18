#include <bits/stdc++.h>
using namespace std;

bool IsInteger(string &str) {
    if (str.size() > 1 && str[0] == '0') return false;
    if (str.size() == 0) return false;
    for (char c: str) {
        if (c >= '0' && c <= '9') continue;
        return false;
    } 
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    int len = s.size();
    vector <string> v;
    string tmp = "";
    for (int i = 0; i < len; i++) {
        if (s[i] == ',' || s[i] == ';') {
            v.push_back(tmp);
            tmp = "";
        } else {
            tmp.push_back(s[i]);
        }
    }
    v.push_back(tmp);
    vector <string> intg , word;
    for (int i = 0; i < v.size(); i++) {
        if (IsInteger(v[i])) intg.push_back(v[i]);
        else word.push_back(v[i]);
    }
    if (intg.size() == 0) cout << "-\n";
    else {
        cout << '"';
        for (int i = 0; i + 1 < intg.size(); i++) {
            cout << intg[i] << ",";
        }
        cout << intg.back() << '"' << "\n";
    }
    if (word.size() == 0) cout << "-\n";
    else {
        cout << '"';
        for (int i = 0; i + 1 < word.size(); i++) {
            cout << word[i] << ",";
        }
        cout << word.back() << '"' << "\n";
    }
    return 0;
}