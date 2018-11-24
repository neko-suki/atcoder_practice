#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

ll solve(const int n, const vector<int> & in){
  ll lsum = 0, rsum = 0;
  priority_queue<int, vector<int>, greater<int> > lq;
  priority_queue<int> rq;

  for(int i = 0;i < n;i++){
    lq.push(in[i]);
    lsum += in[i];
  }
  for(int i = 2 * n;i < 3*n;i++){
    rq.push(in[i]);
    rsum += in[i];
  }
  ll ans = lsum - rsum;
  vector<ll> forward_sum(3*n, 0);
  vector<ll> backward_sum(3*n, 0);

  forward_sum[n-1] = lsum;
  for(int i = n;i < 2*n;i++){
    if (lq.top() < in[i]){
      lsum = lsum - lq.top() + in[i];
      lq.pop();
      lq.push(in[i]);
    }
    forward_sum[i] = lsum;
  }

  backward_sum[2*n] = rsum;
  for(int i = 2*n-1;i >= n;i--){
    if (rq.top() > in[i]){
      rsum = rsum - rq.top() + in[i];
      rq.pop();
      rq.push(in[i]);
    }
    backward_sum[i] = rsum;
  }


  for(int i = n-1;i < 2*n;i++){
    ans = max(ans, forward_sum[i] - backward_sum[i+1]);
  }
  return ans;
}


int main(){
  int n;
  cin >> n;
  vector<int> in(3*n);
  for(int i = 0;i <3* n;i++){
    cin >> in[i];
  }
  cout << solve(n, in) << endl;
  return 0;
}
