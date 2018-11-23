#include <iostream>
using namespace std;

typedef long long ll;

string solve(int n, ll a, ll b, ll c, ll d){
  for(int i = 0;i < n-1;i++){
    ll l = a + i * c - (n-i-1) * d; // minimum possible
    ll r = a + i * d - (n-i-1) * c; // maximum possible
    if (l > r)swap(l , r);
    if (l <= b && b <= r)return "YES";
  }
  return "NO";
}

int main(){
  int n;
  ll a, b, c, d;
  cin >> n >> a>> b >> c>> d;
  cout << solve(n, a, b, c, d) << endl;

  return 0;
}
