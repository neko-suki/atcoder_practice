#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll solve(int n, const vector<ll> & cost , const vector<ll> &dist ,
	  const vector<ll> &rev_max_cost){
  ll ret = 0;
  for(int i = 0;i < n;i++){
    ret = max(ret, cost[i]);
    if (i + 1 != n){
      ret = max(ret, cost[i] - dist[i] + rev_max_cost[i+1]);
    }
  }
  return ret;
}


ll compute(int n, const ll c, const vector<ll> & dist, const vector<ll> & cal){
  // forward
  vector<ll> cost(n);
  cost[0] = cal[0] - dist[0];
  for(int i = 1;i < n;i++){
    cost[i] = cost[i-1] + cal[i] - dist[i];
  }

  // backward
  vector<ll> rev_cost(n);
  rev_cost[n-1] = cal[n-1] - (c-dist[n-1]);
  for(int i = n-2;i >= 0;i--){
    rev_cost[i] = rev_cost[i+1] + cal[i] - (c - dist[i]);
  }

  vector<ll> rev_max_cost(n);
  rev_max_cost[n-1] = rev_cost[n-1];
  for(int i = n-2;i >= 0;i--){
    rev_max_cost[i] = max(rev_max_cost[i + 1], rev_cost[i]);
  }
  ll ret = solve(n, cost, dist, rev_max_cost);
  return ret;
}

int main(){
  int n;
  ll c;
  cin >> n >> c;
  vector<ll> dist(n), cal(n);
  for(int i = 0;i < n;i++){
    cin >> dist[i] >> cal[i];
  }

  vector<ll> rev_dist(n), rev_cal(n);
  for(int i = 0;i < n;i++){
    rev_dist[i] = c - dist[n-i-1];
    rev_cal[i] = cal[n-i-1];
  }

  ll a = compute(n, c, dist, cal);
  ll b = compute(n, c, rev_dist, rev_cal);

  cout << max(a, b) << endl;

  return 0;
}
