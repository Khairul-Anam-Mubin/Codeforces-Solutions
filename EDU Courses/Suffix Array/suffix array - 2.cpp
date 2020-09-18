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
        int n = a.size();
        vector <int> cnt(n , 0);
        vector <pair<pair<int , int>, int>> a_new(n);
        vector <int> pos(n);
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
    void ShowSuffixArray() {
        for (int i = 0; i < n; i++) {
            cout << sar[i] << " " << s.substr(sar[i] , n - sar[i]) << "\n";
        }
    }
};
int main() {
    string s; cin >> s;
    SuffixArray sf(s);
    sf.BuildSuffixArray();
    //sf.ShowSuffixArray();
    for (int i = 0; i < sf.sar.size() ; i++) {
        cout << sf.sar[i] << " ";
    }
    return 0;
}