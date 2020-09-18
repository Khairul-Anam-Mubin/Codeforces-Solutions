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


struct SegmentTree {
    vector <pair <int , int>> seg;
    vector <long long> lazy;
    vector <int> ar;
    void Init(int N) {
        seg.assign(N << 2 , {});
        lazy.assign(N << 2 , 0);
    }
    void Init(const vector <int> &s) {
        Init(s.size() + 1);
        ar = s;
    }
    void PushDown(int cur , int left , int right) {
        //seg[cur] += (right - left + 1) * lazy[cur];
        if (left != right) {        
            lazy[cur << 1] += lazy[cur];  
            lazy[cur << 1 | 1] += lazy[cur];
        }
        lazy[cur] = 0;
    }
    pair <int , int> Merge(pair<int , int> x , pair <int, int> y) {
        return make_pair(max(x.first , y.first) , min(x.second , y.second));
    }
    void Build(int cur , int left , int right) {
        lazy[cur] = 0;
        if (left == right) {
            seg[cur] = {ar[left] , ar[left]};
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
        //if (lazy[cur] != 0) PushDown(cur , left , right);         
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
    pair<int, int> Query(int cur , int left , int right , int l , int r) {
        if (l > right || r < left) return make_pair(-INF9 , INF9);
        //if (lazy[cur] != 0) PushDown(cur , left , right);
        if (left >= l && right <= r) return seg[cur];
        int mid = (left + right) >> 1;
        pair <int, int> p1 = Query(cur << 1 , left , mid , l , r);
        pair <int, int>p2 = Query(cur << 1 | 1 , mid + 1 , right , l , r);
        return Merge(p1 , p2);
    }
} T;
int main() {
    FasterIO
    int n , m ; cin >> n >> m;
    vector <int> v(n + 1);
    map <int , vector <int>> mp;
    for (int i = 1; i <= n; i++) { 
        cin >> v[i];
        mp[v[i]].emplace_back(i);
    }
    T.Init(v);
    T.Build(1 , 1 , n);
    while (m--) {
        int l , r , x; cin >> l >> r >> x;
        pair <int , int> ans = T.Query(1 , 1 , n , l , r);
        if (ans.first != x) {
            cout << *lower_bound(mp[ans.first].begin() , mp[ans.first].end() , l) << "\n";
        } else if (ans.second != x) {
            cout << *lower_bound(mp[ans.second].begin() , mp[ans.second].end() , l) << "\n";   
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}