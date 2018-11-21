#include <iostream>
#include <vector>
using namespace std;

int solve(int n, const vector<int> & a){
  int now = 2;
  for(int i = n-2;i >= 0;i--){
    if (a[i] >= 2 * a[i+1])return -1;
    now = now + (a[i] - now % a[i]);
  }
  return now;
}

int main(){
  int n;
  cin >> n;
  vector<int> in(n);
  for(int i = 0;i < n;i++){
    cin >> in[i];
  }
  int ans = solve(n, in);
  if (ans == -1){
    cout << -1 << endl;
  } else {
    cout << ans <<" " << ans + in[0]-1 << endl;
  }
  return 0;
}
