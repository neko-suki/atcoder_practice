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

int gcd(int w,int m){
  while(1){
    if (w %  m==0)return m;
    int temp;
    temp = w%m;
    w = m;
    m = temp;
  }
}

long long lcm(long long w,long long m){
  return (w*m)/gcd(w,m) ;//w > m
}

int main(){
  long long n,m;
  string s, t;
  cin >> n >> m;
  cin >> s >> t;
  long long l = lcm(max(n,m), min(n, m));
  map<long long, char> M;
  for(long long s_i = 0;s_i < n;s_i++){
    M[s_i * l/n] = s[s_i];
  }

  bool fg = true;
  for(int t_i = 0 ;t_i < m;t_i++){
    if (M.count(t_i * l/m) != 0 && M[t_i*l/m] != t[t_i]){
      fg = false;
    }
  }
  if (fg)cout << l << endl;
  else cout << -1 << endl;
  return 0;
}
 
 
