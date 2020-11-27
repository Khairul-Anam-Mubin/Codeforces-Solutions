/***
**      Bismillahir Rahmanir Rahim                
**              ALLAHU AKBAR
**
**     Author: Khairul Anam Mubin (__Broly__)
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <bits/stdc++.h>
using namespace std;
 
#define F            first
#define S            second  
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define Precision(a) cout << fixed << setprecision(a)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Test         int test;cin >> test;for(int tc = 1; tc <= test; tc++)
 
#define INF9         2147483647
#define INF18        9223372036854775806
#define eps          1e-8 
 
const double pi = 2 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template <typename T> T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
template <typename T> T Exgcd(T a,T b,T &x,T &y) {if(a<0){T d=Exgcd(-a,b,x,y);x=-x;return d;}   if(b<0){T d=Exgcd(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=Exgcd(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInvPrime (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T ModInvNotPrime(T a , T m) {T x , y ;Exgcd(a , m , x , y) ;x %= m ;if(x < 0) x += m ;return x ;}
template <typename T> typename std::vector<T>::iterator Insert_sorted (std :: vector<T> & vec, T const& item) {return vec.insert (std::upper_bound( vec.begin(), vec.end(), item ), item);}
template <typename T> inline string ToBinary(T n) {string r ;while(n != 0) {r = ( n % 2 == 0 ? "0" : "1" ) + r ; n >>= 1;} return r ;} 
long long BinaryToDecimal(string s) {int len = s.size();long long n = 0, p = 1;for (int i = len - 1; i >= 0; i-- , p *= 2) n += p * (s[i] - '0');return n;}

char Uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char Lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
bool Isalpha(char ch){if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
int Strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
string Intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> Linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.push_back(s);return v;}
template <typename T> void Print(T ar[] , int a , int b) {for (int i = a; i + 1 <= b ; i++)cout << ar[i] << " ";cout << ar[b] << "\n";}
template <typename T> void Print(T ar[] , int n) {for (int i = 0; i + 1 < n; i++)cout << ar[i] << " ";cout << ar[n - 1] << "\n";} 
template <typename T> void Print(const vector<T> &v) {for (int i = 0; i + 1 < v.size() ; i++) cout << v[i] << " ";cout << v.back() << "\n";}

//int dx[] = {0 , 0 , -1 , 1 , -1 , -1 , 1 , 1 , 0} ;  // right , left , up , down
//int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 , -1 , 1 , 0} ;

struct DSU {
    vector <int> parent;
    vector <int> siz;
    DSU(int mxN) {
        mxN <<= 1;
        parent.resize(mxN + 1);
        siz.resize(mxN + 1);
    }
    void Makeset(int n) {
        for (int i = 1 ; i <= n ; i++) {
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
} dsu(200010);
struct CycleFind {
    vector <pair <int , int>> edges;
    vector <vector <int>> g;
    vector <int> par;
    vector <int> col;
    vector <int> mark;
    vector <vector <int>> cycles; 
    int NumOfCycles = 0;
    int N ;
    void Init(int n) {
        if (NumOfCycles) {
            for (int i = 0; i <= NumOfCycles; i++) cycles[i].clear();
        }
        N = n;
        NumOfCycles = 0;
        par.resize(n + 2);
        col.assign(n + 2 , 0);
        mark.assign(n + 2 , 0);
        edges.clear();
        g.resize(n + 2);
        for (int i = 0; i <= n; i++)g[i].clear();
    } 
    void TakeEdges(vector <pair <int , int>> ve) {
        edges = ve;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
    }
    void Dfs(int u , int p) {
        if (col[u] == 2) return; 
        if (col[u] == 1) { // Backtracking through parents and marking the cycles
            NumOfCycles++;
            int cur = p;
            mark[cur] = NumOfCycles;
            while (cur != u) {
                cur = par[cur];
                mark[cur] = NumOfCycles;
            }
            return;
        }
        col[u] = 1; // Partially visited
        par[u] = p; 
        for (int v : g[u]) {
            if (v == p) continue;
            Dfs(v , u);
        }
        col[u] = 2; // completely visited
    }
    void Cycle() {
        Dfs(1 , 0);
        cycles.resize(NumOfCycles + 1);
        for (int i = 0; i <= N; i++) {
            if (mark[i]) {
                cycles[mark[i]].emplace_back(i);
            }
        }
        //Print_Cycles();
    }
    void Print_Cycles(  ) {
        for (int i = 1; i <= NumOfCycles; i++) {
            cout << i << " : ";
            for (int j = 0; j < cycles[i].size(); j++) {
                cout << cycles[i][j] << " ";
            }
            cout << "\n";
        }
    }
} cf;
int main() {
    FasterIO
    Test {
        int n; cin >> n;
        vector <pair <int , int>> vec;
        for (int i = 0; i < n; i++) {
            int u , v; cin >> u >> v;
            vec.emplace_back(u , v);
        }
        cf.Init(n);
        cf.TakeEdges(vec);
        cf.Cycle();
        //cf.Print_Cycles();
        dsu.Makeset(n + 1);
        for (int u = 1; u <= n; u++) {
            for (int v: cf.g[u]) {
                if (!cf.mark[v]) {
                    dsu.Union(u , v);
                }
            }
        }
        ll ans = (n * (n - 1LL));
        map <int , int> done;
        for (int i = 1; i <= n; i++) {
            int par = dsu.Find(i);
            if (!done[par]) {
                done[par] = 1;
                ll sz = dsu.Size(par);
                ans -= (sz * (sz - 1LL)) / 2LL;
            } 
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
    total paths in a tree = (n * (n - 1) / 2)
    as there is only one cycle so there are two ways to reach each of the nodes with 
    that cycle so ((n * (n - 1)) / 2) * 2 = (n * (n - 1)) ways
    but outside the cycle, 
    in the tree part where we don't have to consider the cycles 
    there are only (n * (n - 1)) / 2 path ways. 
    so we have to subtract it from total paths.
*/
