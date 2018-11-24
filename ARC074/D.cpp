#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

ll solve(const int n, const vector<int> & in){
  int l = n, r = 2 * n;
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

  while(l <= r){
    int ltop = lq.top();
    int rtop = rq.top();

    if (-ltop + in[l] > -rtop + in[r]){
      lq.pop();
      lq.push(in[l]);
      l++;
    } else {
      rq.pop();
      rq.push(in[r]);
      r--;
    }
  }
  return lsum - rsum;
}


int main(){
  int n;
  cin >> n;
  vector<int> in(3*n);
  for(int i = 0;i < n;i++){
    cin >> in[i];
  }
  cout << solve(n, in) << endl;
  return 0;
}
