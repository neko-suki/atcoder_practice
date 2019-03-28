#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<pair<int,int>> vp(n);
  for(int i = 0;i < n;i++){
    cin >> vp[i].second >> vp[i].first;
  }
  sort(begin(vp), end(vp), greater<pair<int,int>>());

  long long tmp_sum = 0;
  long long num = 0;
  map<int,int> M;
  stack<int> s;
  for(int i = 0;i < k;i++){
    if (M.count(vp[i].second) == 0){
      num++;
    } else {
      s.push(vp[i].first);
    }
    tmp_sum += vp[i].first;
    M[vp[i].second]++;
  }
  long long ans = tmp_sum + num*num;
  for(int i = k;i < vp.size() && num != k;i++){
    //pop
    if (M.count(vp[i].second) == 0){
      num++;
      int tmp = s.top();s.pop();
      tmp_sum -= tmp;
      tmp_sum += vp[i].first;
      M[vp[i].second]++;
      ans=  max(ans, tmp_sum + num * num);
    }
  }
  cout << ans << endl;
}
