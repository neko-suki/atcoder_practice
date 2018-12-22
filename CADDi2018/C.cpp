#include <iostream>
using namespace std;

typedef long long ll;

ll mypow(ll n,ll p){
  if (p == 0)return 1;
  if (p == 1)return n;
  ll ret=mypow(n,p/2);
  ret=ret*ret;
  if (p&1)ret=ret*n;
  return ret;
}

ll getMul(int n, ll val, int num){
  return mypow(val, num/n);
}

long long solve(int n, ll p){
  ll ret = 1;
  for(ll i = 2;i*i <= p;i++){
    int num = 0;
    while(p % i == 0 && p/i != 0){
      p /= i;
      num++;
    }
    if (num != 0){
      ret *= getMul(n, i, num);
    }
  }
  if (p != 1){
    ret *= getMul(n, p, 1);
  }
  return ret;
}

int main(){
  int n;
  ll p;
  cin >> n >> p;
  cout << solve(n, p) << endl;
  return 0;
}
