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
const ll mod =   1000000007;
inline ll modadd(ll a,ll b){a %= mod;b %= mod;return (a+b)%mod;}
inline ll modsub(ll a,ll b){a %= mod;b %= mod;a-=b;a%=mod;if (a<0)a+=mod;return a;}
inline ll modmul(ll a,ll b){a %= mod;b %= mod;return (a*b)%mod;}
inline ll modeq(ll a,ll b,ll m){a = (a%m+m)%m; b = (b%m+m)%m;return a == b;}
ll modpow(ll n,ll p){
  if (p == 0)return 1;
  if (p == 1)return n%mod;
  ll ret=modpow(n,p/2);
  ret=ret*ret%mod;
  if (p&1)ret=ret*n%mod;
  return ret;
}
/*
ll mypow(ll n,ll p){
  if (p == 0)return 1;
  if (p == 1)return n;
  ll ret=mypow(n,p/2);
  ret=ret*ret;
  if (p&1)ret=ret*n;
  return ret;
}
*/
ll getinv(ll a){return modpow(a,mod-2);}

const int N = 1000;
const int M = N * N + 1;
long long fact[M];
void preproc(){
  fact[0] = 1;
  REP(i, 1, M){
    fact[i] = modmul(fact[i-1], i);
  }
}

long long combination(int n, int r){
  ll tmp = fact[n];
  ll tmp2 = modmul(fact[n-r], fact[r]);
  tmp = modmul(tmp, getinv(tmp2));
  return tmp;
}

long long get_count(int i, vector<int> & col){
  auto itr = upper_bound(col.begin(), col.end(), i);
  if (itr == col.end())return 0; // imposible
  int num = col.size() - (itr - col.begin());
  return num;
}

long long solve(int r, int c, vector<int> & row, vector<int> & col){
  const int lim = r * c+1;
  long long ret = 1;
  set<int> rset, cset;
  rep(i,r)rset.insert(row[i]);
  rep(j,c)cset.insert(col[j]);
  if (rset.size() != row.size())return 0;
  if (cset.size() != col.size())return 0;
  sort(row.begin(), row.end());
  sort(col.begin(), col.end());

  int decided = 0;
  for(int i = r*c;i > 0;i--){
    if (rset.count(i) != 0 && cset.count(i) != 0){
      // do nothing
    } else if (rset.count(i) != 0){
      ll tmp = get_count(i, col);
      ret = modmul(ret, tmp);
    } else if (cset.count(i) != 0){
      ll tmp = get_count(i, row);
      ret = modmul(ret, tmp);
    } else {
      ll tmp1 = get_count(i, col);
      ll tmp2 = get_count(i, row);
      ret = modmul(ret, modsub(modmul(tmp1, tmp2), decided));
    }
    decided++;
  }
  return ret;
}
 
int main(){
  preproc();
  int n,m;
  cin >> n >> m;
  vector<int> row(n);
  vector<int> col(m);
  rep(i,n)cin >> row[i];
  rep(i,m)cin >> col[i];
  cout << solve(n, m, row, col) << endl;
  return 0;
}
 
 
