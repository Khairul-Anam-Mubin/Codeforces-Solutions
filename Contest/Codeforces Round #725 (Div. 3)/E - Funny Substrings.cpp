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

struct node {
    string fst , lst;
    ll cnt;
    node () {
        cnt = 0;
        fst = "";
        lst = "";
    }
    node(string s) {
        cnt = 0;
        fst = "";
        lst = "";
        Process(s);
    }
    void Process(string s) {
        int len = s.size();
        for (int i = 0; i + 4 <= len; i++) {
            if (s.substr(i , 4) == "haha")
                cnt++;
        }
        fst = s.substr(0 , 3);
        lst = s.substr(max(0 , int(s.size()) - 3) , 3);
    }
};
int main() {
    FasterIO
    Test {
        int n; cin >> n;
        map <string , node> mp;
        string var = "", sign, val;
        for (int i = 0; i < n; i++) {
            cin >> var >> sign;
            string a , b;
            bool concate = 0;
            if (sign.size() == 2) {
                cin >> val;
            } else {
                concate = 1;
                cin >> a >> sign >> b;
            }
            if (concate) {
                string x = mp[a].lst;
                string y = mp[b].fst;
                string z = x + y;
                node tmp(z);

                mp[var].cnt = mp[a].cnt + mp[b].cnt + tmp.cnt;
                if (mp[a].fst.size() < 3) {
                    mp[var].fst = (mp[a].fst + mp[b].fst).substr(0 , 3);
                } else {
                    mp[var].fst = mp[a].fst; 
                }
                if (mp[a].lst.size() < 3) {
                    mp[var].lst = (mp[a].lst + mp[b].lst).substr(max(0 , int(mp[a].lst.size() + mp[b].lst.size()) - 3));
                } else {
                    mp[var].lst = mp[b].lst.substr(max(0 , int(mp[b].lst.size()) - 3) , 3); 
                }
            } else {
                node tmp(val);
                mp[var] = tmp;
            }   
            //cout << mp[var].fst << " " << mp[var].lst << " " << mp[var].cnt << "\n"; 
        }
        cout << mp[var].cnt << "\n";
    }    
    return 0;
}
