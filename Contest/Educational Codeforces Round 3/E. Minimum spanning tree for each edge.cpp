/***
**                      ALLAHU AKBAR
**
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <bits/stdc++.h>
using namespace std;
 
#define F            first
#define S            second  
#define PB           push_back
#define MP           make_pair
#define File         F();
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define Precision(a) cout << fixed << setprecision(a)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Faster       cin.tie(0);cout.tie(0); 
#define Test         int test;cin >> test;for(int tc = 1; tc <= test; tc++)

#define MOD          998244353
#define INF9         2147483647
#define INF18        9223372036854775806
#define eps          1e-8 

const double pi = 2 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void F(){
    #ifndef ONLINE_JUDGE 
        Fin;
        Fout; 
    #endif
}
template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> void Print(T ar[] , int a , int b) {for (int i = a; i + 1 <= b ; i++)cout << ar[i] << " ";cout << ar[b] << "\n";}
template <typename T> void Print(T ar[] , int n) {for (int i = 0; i + 1 < n; i++)cout << ar[i] << " ";cout << ar[n - 1] << "\n";} 
template <typename T> void Print(const vector<T> &v) {for (int i = 0; i + 1 < v.size() ; i++) cout << v[i] << " ";cout << v.back() << "\n";}

/*....................Kruskal Algrithm.................*/
// mxN have to define before...
const int mxN = 200000;
struct DSU {
    vector <int> parent;
    vector <int> siz;
    DSU(int mxN) {
        mxN <<= 1;
        parent.resize(mxN + 1);
        siz.resize(mxN + 1);
    }
    void Makeset(int n) {
        for (int i = 0 ; i <= n ; i++) {
            parent[i] = n + i;
            parent[n + i] = n + i;
            siz[n + i] = 1;
        }
    }
    int Find(int u) {
        if (parent[u] == u) return u ;
        return parent[u] = Find(parent[u]) ;
    }
    void Union(int u , int v) {
        u = Find(u);
        v = Find(v);
        if (u != v) {
            if (siz[u] < siz[v]) swap(u , v);
            parent[v] = u;
            siz[u] += siz[v];
        }
    }
    bool SameSet(int u , int v) {
        return (Find(u) == Find(v)) ;
    }
    void MoveUtoSetV(int u , int v) {
        if (SameSet(u , v)) return;
        int x = Find(u);
        int y = Find(v);
        siz[x]--;
        siz[y]++;
        parent[u] = y;
    }
    int Size(int u) {
        return siz[Find(u)];
    }
} dsu(mxN + 5);
struct MST {
    vector <pair<int, pair<int , int>>> edges;
    vector <pair<int, pair<int , int>>> mstedges;
    int nodes;
    long long mstcost;
    void ProcessKruskal() {
        sort(edges.begin() , edges.end());
        int cnt = 0 ;
        for (auto it : edges) {
            int u = it.second.first;
            int v = it.second.second;
            int w = it.first;
            if (!dsu.SameSet(u , v)) {
                dsu.Union(u , v);
                int x = min(u , v);
                int y = max(u , v);
                int u = x;
                int v = y;
                mstedges.push_back(make_pair(w , make_pair(u , v)));
                cnt++ , mstcost += w;
            }
        }
    }
    void Init(int n , const vector<pair<int , pair<int , int>>> &_edges) {
        Init(n);
        edges = _edges;
    }
    void Init(int n) {
        nodes = n;
        mstcost = 0;
        dsu.Makeset(nodes);
        edges.clear();
        mstedges.clear();
    }
    void AddEdge(int u, int v, int w) {
        edges.push_back(make_pair(w , make_pair(u , v)));
    }
    void ShowEdgeList() {
        for (auto it : edges) {
            cout << it.second.first + 1 << " -> " << it.second.second + 1<< " " ;
            cout << it.first << "\n";
        }
    }
    void ShowMSTEdgeList() {
        for (auto it : mstedges) { 
            cout << it.second.first + 1 << " -> " << it.second.second + 1<< " = ";
            cout << it.first << "\n";
        }    
    }
} mst;

const int po = 25 ; //log(mxN)  
vector < pair <int , int>  > g[mxN] ;
int level[mxN] , weight[mxN] , parent[mxN] ;
int SpTab[mxN][po] ;
int MX[mxN][po] ;   // max edge weight
int MN[mxN][po];    // min edge weight
int root ;          // tree root
int N ;             // Graph size
void Reset() {
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; (1 << j) < N ; j++) {
            SpTab[i][j] = -1 ;
            MX[i][j] = -INF9 ;
            MN[i][j] = INF9 ;
        }
        g[i].clear() ;
    }
}
pair<int , int> LCA(int u , int v) {
    int mn = INF9 , mx = -INF9 ;
    if(level[u] < level[v]) 
        swap(u , v) ;
    int log ;
    for(log = 1 ; (1 << log) <= level[u] ; log++); 
    log-- ;
    for(int i = log ; i >= 0 ; i--) {
        if(level[u] - (1 << i) >= level[v]) {
            mn = min(mn , MN[u][i]) ;
            mx = max(mx , MX[u][i]) ;
            u = SpTab[u][i] ;
        }
    }
    if(u == v) {    // if the root is equal v
        // return u ;
        return make_pair(mn , mx) ;
    }
    for(int i = log ; i >= 0 ; i--) {
        if(SpTab[u][i] != -1 && SpTab[u][i] != SpTab[v][i]) {
            mn = min(mn , min(MN[u][i] , MN[v][i])) ;
            mx = max(mx , max(MX[u][i] , MX[v][i])) ;
            u = SpTab[u][i] ;
            v = SpTab[v][i] ;
        }
    }
    mn = min(mn , min(MN[u][0] , MN[v][0])) ;
    mx = max(mx , max(MX[u][0] , MX[v][0])) ;
    //return parent[u] ; 
    return make_pair(mn , mx) ;
}
void Dfs(int u , int par = -1) {
    if(par == -1) {                 // if tree is root  
        level[u] = weight[u] = 0 ;  // zero level and no weight
        parent[u] = -1 ;            // no parent for root
    }
    for(int j = 0 ; j < g[u].size(); j++) {
        int v = g[u][j].first ;
        int w = g[u][j].second ;
        if(v != par) {              
            parent[v] = u ;
            weight[v] = w ;
            level[v] = level[u] + 1 ;
            Dfs(v , u) ;
        }
    }
}    
void SparseTable() {
    Dfs(root) ;
    for(int i = 0 ; i < N ; i++) {
        SpTab[i][0] = parent[i] ;
        MX[i][0] = MN[i][0] = weight[i] ;
    }
    for(int j = 1 ; (1 << j) < N ; j++) {
        for(int i = 0 ; i < N ; i++) {
            if(SpTab[i][j - 1] != -1) {
                SpTab[i][j] = SpTab[SpTab[i][j - 1]][j - 1] ;
                MX[i][j] = max(MX[i][j - 1] , MX[SpTab[i][j - 1]][j - 1]) ;
                MN[i][j] = min(MN[i][j - 1] , MN[SpTab[i][j - 1]][j - 1]) ;
            }
        }
    }   
}
int main() {
    FasterIO
    int n, m; cin >> n >> m;
    mst.Init(n);
    vector <pair <int , pair <int , int>> > vec;
    map <pair <int , int> , int> mp;
    for (int i = 0; i < m; i++) {
        int u , v , w;
        cin >> u >> v >> w;
        u-- , v--;
        int x = min(u , v);
        int y = max(u , v);
        u = x;
        v = y;
        vec.PB(MP(w , MP(u , v)));
        mp[MP(u , v)] = w;
        mst.AddEdge(u , v , w);
    }
    mst.ProcessKruskal();
    //cout << mst.mstcost << " mst cost\n";
    //mst.ShowMSTEdgeList();
    //mst.ShowEdgeList();
    Reset();
    N = n;
    root = 0;
    map <pair <int , int> , ll > ans;
    for (int i = 0 ; i < mst.mstedges.size() ; i++) {
        int u = mst.mstedges[i].S.F;
        int v = mst.mstedges[i].S.S;
        int x = min(u , v);
        int y = max(u , v);
        int w = mst.mstedges[i].F;
        g[x].PB(MP(y , w));
        g[y].PB(MP(x , w));
        ans[MP(x , y)] = mst.mstcost;
    }
    SparseTable();
    for (int i = 0; i < vec.size(); i++) {
        int u = vec[i].S.F;
        int v = vec[i].S.S;
        int w = vec[i].F;
        int x = min(u , v);
        int y = max(u , v);
        u = x;
        v = y;
        if (ans.find(MP(u , v)) != ans.end()) continue;
        pair <int , int> ok = LCA(u , v);
        ans[MP(u , v)] = (mst.mstcost - ok.S) + mp[MP(u , v)];
    }
    for (auto it : vec) {
        cout << ans[MP(it.S.F , it.S.S)] << "\n";
    }
    return 0;
}