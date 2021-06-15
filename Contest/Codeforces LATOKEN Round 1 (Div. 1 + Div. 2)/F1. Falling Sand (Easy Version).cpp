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

struct StronglyConnectedComponent {
    vector <vector <int>> g , gr;
    vector <bool> vis;
    vector <int> order, sccid;
    int nodes , edges , scc = 0;

    void Init(int _nodes) {
        nodes = _nodes;
        edges = 0;
        scc = 0;
        g.clear();
        gr.clear();
        g.assign(nodes + 1 , {});
        gr.assign(nodes + 1, {});
        order.clear();
        vis.assign(nodes + 1, 0);
        sccid.resize(nodes + 1);
    } 
    void AddEdge(int u , int v) {
        if (u == -1 || v == -1) return;
        g[u].push_back(v);
        gr[v].push_back(u);
        edges++;
    }
    void Init() {
        for (int i = 0; i <= nodes; i++) vis[i] = 0;
    }
    void Dfs1(int u) {
        if (vis[u]) return;
        vis[u] = 1;
        for (int v : g[u]) Dfs1(v);
        order.push_back(u);
    }
    void TopSort() {
        Init();
        for (int i = 0; i < nodes; i++) { 
            if (!vis[i]) Dfs1(i);
        }
        reverse(order.begin() , order.end());
    }
    void Dfs2(int u, int id) {
        if (vis[u]) return;
        vis[u] = 1;
        sccid[u] = id;
        for (int v : gr[u]) Dfs2(v , id);
    }
    void KosarajuSCC() {
        TopSort();
        Init();
        for (int i : order) {
            if (!vis[i]) {
                Dfs2(i , scc);
                scc++;
            }
        }
    }
    int GetAns() {
        vector <int> here(nodes + 1);
        for (int i = 0; i < scc; i++ ) {
            here[i] = 1;
        }
        for (int i = 0; i < nodes; i++) {
            for (int j : g[i]) {
                if (sccid[i] != sccid[j])
                    here[sccid[j]] = 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < scc; i++) ans += here[i];
        return ans;
    }
};
vector <vector <int>> col; 
int GetRow(int r , int c) {
    auto it = lower_bound(col[c].begin(), col[c].end(), r);
    if (it == col[c].end()) return -1;
    return (*it);
}
int main() {
    FasterIO
    StronglyConnectedComponent scc;
    int n, m; cin >> n >> m;
    char ar[n + 1][m + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
        }
    }
    int hudai[m];
    for (int i = 0; i < m; i++) cin >> hudai[i];
    int tot_id = 0;
    int id[n + 1][m + 1];
    col.assign(m + 1, {});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            id[i][j] = -1;
            if (ar[i][j] == '#') {
                id[i][j] = tot_id++;
                col[j].push_back(i);
            }
        }
    }
    scc.Init(tot_id);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ar[i][j] == '.') continue;
            if (i != 0 && ar[i - 1][j] == '#') {
                scc.AddEdge(id[i][j] , id[i - 1][j]);
            }
            int x = GetRow(i + 1 , j);
            if (x != -1) scc.AddEdge(id[i][j] , id[x][j]);
            if (j != 0) {
                int x = GetRow(i , j - 1);
                if (x != -1) 
                    scc.AddEdge(id[i][j] , id[x][j - 1]);
            }
            if (j + 1 < m) {
                int x = GetRow(i , j + 1);
                if (x != -1) 
                    scc.AddEdge(id[i][j] , id[x][j + 1]);
            }
        }
    }
    scc.KosarajuSCC();
    cout << scc.GetAns() << "\n";
    return 0;
}
