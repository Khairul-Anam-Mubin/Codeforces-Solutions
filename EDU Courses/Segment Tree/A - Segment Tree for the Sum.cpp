#include <bits/stdc++.h>
using namespace std;

/**************************Segment tree*****************************/
struct SegmentTree {
    vector <long long> seg;
    vector <long long> lazy;
    vector <long long> ar;
    void Init(int N) {
        seg.assign(N << 2, 0);
        lazy.assign(N << 2 , 0);
    }
    void Init(const vector <long long> &s) {
        Init(s.size() + 1);
        ar = s;
    }
    void PushDown(int cur , int left , int right) {
        seg[cur] = (right - left + 1) * lazy[cur];
        if (left != right) {        
            lazy[cur << 1] += lazy[cur];  
            lazy[cur << 1 | 1] += lazy[cur];
        }
        lazy[cur] = 0;
    }
    long long Merge(long long x , long long y) {
        return x + y;
    }
    void Build(int cur , int left , int right) {
        lazy[cur] = 0;
        if (left == right) {
            seg[cur] = ar[left];
            return;
        }
        int mid = (left + right) >> 1;
        Build(cur << 1 , left , mid);
        Build(cur << 1 | 1 , mid + 1 , right);
        seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
    }
    void Update(int cur , int left , int right , int pos , long long val) {
        Update(cur , left , right , pos , pos , val);
    }
    void Update(int cur , int left , int right , int l , int r , long long val) {
        if (lazy[cur] != 0) PushDown(cur , left , right);         
        if (l > right || r < left) return;
        if (left >= l && right <= r) {
            lazy[cur] = val;
            PushDown(cur , left , right);
            return ;
        }
        int mid = (left + right) >> 1;
        Update(cur << 1 , left , mid , l , r , val);
        Update(cur << 1 | 1 , mid + 1 , right , l , r , val);
        seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
    }
    long long Query(int cur , int left , int right , int l , int r) {
        if (l > right || r < left) return 0;
        if (lazy[cur] != 0) PushDown(cur , left , right);
        if (left >= l && right <= r) return seg[cur];
        int mid = (left + right) >> 1;
        long long p1 = Query(cur << 1 , left , mid , l , r);
        long long p2 = Query(cur << 1 | 1 , mid + 1 , right , l , r);
        return Merge(p1 , p2);
    }
} T;
int main() {
    int n , m; cin >> n >> m;
    vector <long long> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    T.Init(v);
    T.Build(1 , 0 , n - 1);
    while (m--) {
        int q; cin >> q;
        if (q == 1) {
            int id ; cin >> id;
            long long x; cin >> x;
            T.Update(1 , 0 , n - 1 , id , x);
        } else {
            int l , r; cin >> l >> r;
            cout << T.Query(1 , 0 , n - 1, l , r - 1) << "\n";
        }
    }
    return 0;
}