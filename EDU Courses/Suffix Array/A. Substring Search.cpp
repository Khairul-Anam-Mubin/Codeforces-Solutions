#include <bits/stdc++.h>
using namespace std;

// Complexity O(N * LogN) [radix_sort used]
struct SuffixArray{
    string s;
    int n;
    vector <int> sar;
    SuffixArray(string _s) {
        s = _s;
        s += "$";
        n = s.size();
        sar.resize(n);
        BuildSuffixArray();
    }
    void BuildSuffixArray() {
        vector <int> c(n);
        vector <pair<char,int>> a(n);
        for (int i = 0; i < n; i++) { 
            a[i] = {s[i] , i};
        }
        sort(a.begin() , a.end());
        for (int i = 0; i < n; i++) {
            sar[i] = a[i].second;
        }
        c[sar[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[sar[i]] = c[sar[i - 1]];
            } else {
                c[sar[i]] = c[sar[i - 1]] + 1;
            }
        }
        for (int k = 0; (1 << k) < n; k++) {
            vector <pair<pair <int , int>, int>> a(n);
            for (int i = 0; i < n; i++) {
                a[i] = {{c[i] , c[(i + (1 << k)) % n]} , i};
            }
            Radix_Sort(a);
            for (int i = 0; i < n; i++) { 
                sar[i] = a[i].second;
            }
            c[sar[0]] = 0;
            for (int i = 1; i < n; i++) {
                if (a[i].first == a[i - 1].first) {
                    c[sar[i]] = c[sar[i - 1]];
                } else {
                    c[sar[i]] = c[sar[i - 1]] + 1;
                }
            }
        }
    }
    void Radix_Sort(vector <pair<pair<int , int>, int>> &a) {
        vector <int> cnt(n , 0);
        vector <int> pos(n);
        vector <pair<pair<int , int>, int>> a_new(n);
        for (auto it : a) {
            cnt[it.first.second]++;
        }
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto it: a) {
            int i = it.first.second;
            a_new[pos[i]] = it;
            pos[i]++;
        }
        a.swap(a_new);
        cnt.assign(n , 0);
        for (auto it : a) {
            cnt[it.first.first]++;
        }
        pos[0] = 0;
        for (int i = 1; i < n; i++) { 
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto it: a) {
            int i = it.first.first;
            a_new[pos[i]] = it;
            pos[i]++;
        }
        a.swap(a_new);
    }
    // Binary search Complexity O(logN * t)
    bool IsSubstring(string &t) { // Query 
        if ((int)t.size() > (int)s.size()) {
            return false;
        }
        int low = 0;
        int high = n - 1;
        int tlen = t.size();
        while (low <= high) {
            int mid = (low + high) >> 1;
            string cur = s.substr(sar[mid] , min(tlen , n));
            if (cur == t) {
                return true;
            } else if (cur < t) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
    void ShowSuffixArray() {
        for (int i = 0; i < n; i++) {
            cout << sar[i] << " " << s.substr(sar[i] , n - sar[i]) << "\n";
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string t; cin >> t;
    int q; cin >> q;
    SuffixArray sf(t);
    sf.ShowSuffixArray();
    while (q--) {
        string s;
        cin >> s;
        if (sf.IsSubstring(s)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}