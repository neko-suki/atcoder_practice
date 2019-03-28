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

const int N = 100000;
long long sum[N];
long long p_sum[2][N];

int mini[N];
int maxi[N];
long long ans[N];

void preproc(int n, const vector<int> & in){
  // copute sum
  sum[0] = in[0];
  REP(i, 1, n){
    sum[i] = in[i] + sum[i-1];
  }
  
  p_sum[0][0] = in[0];
  for(int i = 2;i < n;i+=2){
    p_sum[0][i] = in[i] + p_sum[0][i-2];
  }
  long long last = n%2 == 0 ? p_sum[0][n-2] : p_sum[0][n-1];

  for(int i = 1;i <= n/2; i++){
    if (i == 1){
      maxi[1] = 1e9;
      mini[i] = ((in[i] + in[2*i])) / 2;
    } else {
      maxi[i] = mini[i-1];
      mini[i] = ((in[i] + in[2*i])) / 2;
    }
    ans[i] = sum[i-1] + last - p_sum[0][2*i - 2];
    //cout << i <<" " << mini[i] <<" " << maxi[i] <<" " << ans[i] << endl;
  }
  maxi[1] = 1e9;
}

long long solve(int query, int n){
  int l =1, r = n/2;

  int cnt = 50;
  while(l < r && cnt){
    int mid = (l+r)/2;
    if (mini[mid] < query && query <= maxi[mid])return ans[mid];
    if (query <= mini[mid]){
      l = mid+1;
    } else if (maxi[mid] < query){
      r = mid-1;
    }
  }
  return ans[l];
}

int main(){
  int n , q;
  //cin >> n >> q;
  scanf("%d%d", &n, &q);
  vector<int> in(n);
  rep(i,n){
    scanf("%d", &in[i]);
  }
  int a = n%2 == 1 ? -1e9 : 0;
  if (n%2 == 1){
    in.emplace_back(-1e9);
    n++;
  }
  sort(begin(in), end(in), greater<int>());
  preproc(n, in);
  rep(i,q){
    int query;
    scanf("%d", &query);
    cout << solve(query, n) << endl;
  }
  return 0;
}
 
 
