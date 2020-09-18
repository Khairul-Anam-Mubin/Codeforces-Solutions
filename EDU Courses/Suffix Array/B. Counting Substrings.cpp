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
            c[sar[i]] = c[sar[i - 1]];
            if (a[i].first != a[i - 1].first) {
                c[sar[i]]++;
            }
        }
        for (int k = 0; (1 << k) < n; k++) {
            vector <pair<pair<int , int>, int>> a(n);
            for (int i = 0; i < n; i++) {
                a[i] = {{c[i] , c[(i + (1 << k)) % n]} , i};
            }
            Radix_Sort(a);
            for (int i = 0; i < n; i++) {
                sar[i] = a[i].second;
            }
            c[sar[0]] = 0;
            for (int i = 1; i < n; i++) {
                c[sar[i]] = c[sar[i - 1]];
                if (a[i].first != a[i - 1].first) { 
                    c[sar[i]]++;
                }
            }
        }
    }
    void Radix_Sort(vector <pair<pair<int , int>, int>> &a) {
        vector <int> cnt(n , 0) , pos(n);
        vector <pair<pair<int , int> , int>> a_new(n);
        for (auto it: a) {
            cnt[it.first.second]++;
        }
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto it : a) {
            int i = it.first.second;
            a_new[pos[i]] = it;
            pos[i]++;
        }
        a.swap(a_new);
        cnt.assign(n , 0);
        for (auto it: a) {
            cnt[it.first.first]++;
        }
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto it : a) {
            int i = it.first.first;
            a_new[pos[i]] = it;
            pos[i]++;
        }
        a.swap(a_new);
    }
    void ShowSuffixArray() {
        for (int i = 0; i < n; i++) {
            cout << sar[i] << " " << s.substr(sar[i] , n - sar[i]) << "\n";
        }
    }
    // Binary search Complexity O(logN * |t|)
    bool IsSubstr(string &t) { // Query 
        if ((int)t.size() > (int)s.size()) {
            return false;
        }
        int low = Lower_Bound(t);
        if (s.substr(sar[low] , min(int(t.size()) , n)) == t) { 
            return true;
        }
        return false;
    }
    int Lower_Bound(string &t) {
        if ((int)t.size() > (int)s.size()) { 
            return 0;
        }
        int low = 0 ,high = n ,tlen = t.size();
        while (low < high) {
            int mid = (low + high) >> 1;
            string cur = s.substr(sar[mid] , min(tlen , n));
            if (t <= cur) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int Upper_Bound(string &t) {
        if ((int)t.size() > (int)s.size()) {
            return 0;
        }
        int low = 0 ,high = n ,tlen = t.size();
        while (low < high) {
            int mid = (low + high) >> 1;
            string cur = s.substr(sar[mid] , min(tlen , n));
            if (t >= cur) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    int SubstrOccurences(string &t) {
        int low = Lower_Bound(t) , up = Upper_Bound(t);
        if (low == up || s.substr(sar[low] , min(int(t.size()) , n)) != t) {
            return 0;
        }
        return (up - low);
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    SuffixArray sf(s);
    //sf.ShowSuffixArray();
    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        cout << sf.SubstrOccurences(t) << "\n";
    }
    return 0;
}