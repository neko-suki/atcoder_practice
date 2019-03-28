/*
memo for solution
*/
#include <cstdlib> 
#include <numeric>
#include <cstring>
#include <cstdio> 
#include <cfloat> 
#include <map> 
#include <cassert>
#include <cmath> 
#include <climits> 
#include <utility> 
#include <set> 
#include <iostream> 
#include <memory> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <sstream> 
#include <complex> 
#include <stack> 
#include <queue> 
#include <iomanip>
#include<sys/time.h>
using namespace std; 
double e_time(void){static struct timeval now;gettimeofday(&now, NULL);return (double)(now.tv_sec  + now.tv_usec/1000000.0);}
#define REP(i,b,n) for(int i=b;i<n;i++) 
#define rep(i,n)      REP(i,0,n) 
#define pb push_back  
#define mp make_pair 
#define ALL(C)   (C).begin(),(C).end() 
#define fe(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr != (c).end();itr++)
#define BITSHIFT(X)     ( (1<<(X)) )
#define CONTAIN(S,X) ( ((S)&BITSHIFT(X)) != 0)
typedef complex<double>P; 
typedef long long ll; 
typedef unsigned long long ull; 
typedef pair<int,int> pii; 
typedef vector<int> vint;
template<class T> void vp(T &a,int p){rep(i,p)cout << a[i]<<" ";cout << endl;}  
template<class T> T ceilUp(const T& a,const T& b){return (a+b-1)/b;}
const ll mod =   1000000009;
inline ll modadd(ll a,ll b){a %= mod;b %= mod;return (a+b)%mod;}
inline ll modsub(ll a,ll b){a %= mod;b %= mod;a-=b;a%=mod;if (a<0)a+=mod;return a;}
inline ll modmul(ll a,ll b){a %= mod;b %= mod;return (a*b)%mod;}
inline ll modeq(ll a,ll b,ll m){a = (a%m+m)%m; b = (b%m+m)%m;return a == b;}
//ll modpow(ll n,ll p){if (p == 0)return 1;if (p == 1)return n;ll ret=mypow(n,p/2);ret=ret*ret%mod;if (p&1)ret=ret*n%mod;return ret;}
//ll getinv(ll a){return mypow(a,mod-2);}
ll mypow(ll n,ll p){
  if (p == 0)return 1;
  if (p == 1)return n;
  ll ret=mypow(n,p/2);
  ret=ret*ret;
  if (p&1)ret=ret*n;
  return ret;
}

bool beginwith(const string & src, const string &tar){
  if (src.size() < tar.size())return false;
  rep(i, tar.size()){
    if (src[i] == tar[i]);
    else return false;
  }
  return true;
}

bool endwith(const string & src, const string & tar){
  if (src.size() < tar.size())return false;
  rep(i, tar.size()){
    if (tar[tar.size()-i-1] == src[src.size() - i-1]);
    else return false;
  }
  return true;
}

bool solve(string &in){
  const string a = "keyence";
  if (in == a)return true;
  if (beginwith(in, a) || endwith(in, a))return true;

  int n = a.size();
  REP(i, 1, n){
    string t1 = a.substr(0, i), t2 = a.substr(i, n-i);
    if (beginwith(in, t1) && endwith(in, t2))return true;
  }
  return false;
}

int solve(int n, vector<int> & a, vector<int> & b){
  long long req = 0;
  vector<int> dec;
  int ans = 0;
  rep(i,n){
    if (a[i] < b[i]){
      ans++;
      req += b[i] - a[i];
    } else if (a[i] > b[i]){
      dec.pb(a[i] - b[i]);
    }
  }
  sort(dec.begin(), dec.end(), greater<int>());

  //cout << ans << " " << req << endl;
  //!rep(i,dec.size())cout << dec[i] <<" " ;cout << endl;

  rep(i, dec.size()){
    if (req == 0)break;
    ll decrease = min((ll)dec[i], req);
    req -= decrease;
    ans++;

  }
  return req == 0 ? ans : -1;
}
 
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>b[i];
  cout << solve(n, a, b) << endl;

  return 0;
}
 
 
