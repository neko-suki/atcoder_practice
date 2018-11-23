#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef long long ll;

bool solve(const int n, const vector<int> & in){
  ll sum = accumulate(in.begin(), in.end(), 0LL);

  if (sum % ((static_cast<long long>(n) * static_cast<long long>(n+1))/2)
	      != 0){
    return false;
  }
  ll k = sum / ((static_cast<long long>(n) * static_cast<long long>(n+1))/2);

  ll ops = 0;
  for(int i = 0;i < n;i++){
    ll tmp = in[(i+1)%n] - in[i] - k;
    if (tmp <= 0 &&  - tmp % n == 0){
      ops += -tmp / n;
    }else return false;
  }
  return ops == k;
}

int main(){
  int n;
  cin >> n;
  vector<int> in(n);
  for(int i = 0;i < n;i++){
    cin >> in[i];
  }
  if (solve(n, in)){
    cout <<"YES" << endl;
  } else {
    cout <<"NO" << endl;
  }
  return 0;
}
