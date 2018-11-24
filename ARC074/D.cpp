#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

ll solve(const int n, const vector<int> & in){
  int l = n, r = 2 * n-1;
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
    ll diff = lsum - rsum;
    ll newl = lsum - ltop + in[l];
    int newr = rsum - rtop + in[r];

    if ( newl - rsum >= lsum - newr && newl - rsum > diff){ // take in[l] into left
      lq.pop();
      lq.push(in[l]);
      lsum += in[l] - ltop;
      l++;
    } else if (newl - rsum <= lsum - newr && diff < lsum - newr){
      rq.pop();
      rq.push(in[r]);
      rsum += in[r] - rtop;
      r--;
    } else {
      if (in[l] < in[r])r--;
      else if (in[l] > in[r])l++;
    }
  }
  return lsum - rsum;
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
