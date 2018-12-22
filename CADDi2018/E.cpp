#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long ll;

ll solve(int n, vector<int> & in){
  const long double log2 = 1;
  vector<double> in_log(n);
  for(int i = 0;i < n;i++){
    in_log[i] = std::log2(in[i]);
  }

  vector<ll> b(n);
  b[0] = 0;
  for(int i = 1;i < n;i++){
    if (in[i] >= in[i-1]){
      b[i] = b[i-1];
    } else {
      double tmp_b_i = in_log[i-1] - in_log[i] + b[i-1];
      b[i] = static_cast<ll>(ceil(tmp_b_i));
      assert(b[i] >= -1);
      if (b[i]%2 == 1 || b[i]%2 == -1)b[i]++;
    }
  }

  /*
  // debug
  cout <<"b: ";
  for(int i = 0;i < n;i++){
    cout << b[i] <<" ";
  }
  cout << endl;
  // debug end
  */
  vector<ll> c(n);
  c[n-1] = 1;
  for(int i = n-2;i >= 0;i--){
    if (in[i] >= in[i+1]){
      c[i] = c[i+1];
    } else {
      double tmp_c_i = in_log[i+1] - in_log[i] + c[i+1];
      c[i] = static_cast<ll>(ceil(tmp_c_i));
      if (c[i]%2 == 0)c[i]++;
    }
  }

  // debug
  /*
  cout << "c: " ;
  for(int i = 0;i < n;i++){
    cout << c[i] <<" ";
  }
  cout << endl;
  */
  //

  ll neg_sum = accumulate(begin(c), end(c), 0LL);
  ll pos_sum = accumulate(begin(b), end(b), 0LL);
  ll ret = min(pos_sum, neg_sum);

  vector<ll> d(n);//decrease value for negative
  d[n-1] = neg_sum;
  for(int i = n-2;i >= 0;i--){
    neg_sum = neg_sum - 1 - (c[i] - c[i+1]) * (i+1);
    d[i] = neg_sum;
  }
  /*
  //debug
  cout << "d: ";
  for(int i = 0;i < n;i++){
    cout << d[i] <<" ";
  }
  cout << endl;
  // debug
  */
  // [0,i) should be negative
  for(int neg_range = 1;neg_range < n;neg_range++){
    pos_sum -= (b[neg_range] - b[neg_range-1]) * (n - neg_range);
    //cout << neg_range <<" " << pos_sum << endl;
    ll tmp = pos_sum + d[neg_range-1];
    ret = min(ret, tmp);
  }
  return ret;
}


int main(){
  int n;
  cin>>n;
  vector<int> in(n);
  for(int i = 0;i < n;i++){
    cin >> in[i];
  }
  cout << solve(n, in) << endl;
  return 0;
}
