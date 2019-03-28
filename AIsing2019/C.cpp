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

const int N = 400;
bool vis[N][N] = {false};
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void solve(int h, int w, int y, int x, int  & cnt_b, int & cnt_h, const vector<string> & in){
  if (vis[y][x])return;
  if (in[y][x] == '#')cnt_b++;
  else cnt_h++;
  vis[y][x] = true;
  rep(i,4){
    int nex = x + dx[i], ney = y + dy[i];
    if (0 <= ney && ney < h &&
	0 <= nex && nex < w && in[y][x] != in[ney][nex]){
      solve(h, w, ney, nex, cnt_b, cnt_h, in);
    }
  }
}
 
int main(){
  int h, w;
  cin >> h >> w;
  vector<string> in(h);
  rep(i,h)cin>>in[i];
  long long ans = 0;
  rep(i,h){
    rep(j,w){
      if (!vis[i][j]){
	int cnt_b = 0, cnt_h = 0;
	solve(h, w, i, j, cnt_b, cnt_h, in);
	ans += (long long)cnt_b * cnt_h;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
 
 
