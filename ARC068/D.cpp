#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(int n, vector<int> &in){
  int p = 0;
  int ret = n;
  int num = 0;
  while(p < in.size()){
    int cnt = 0, now = in[p];
    while(p < in.size() && in[p] == now){
      cnt++;
      p++;
    }
    if (cnt >= 2){
      ret -= cnt - 2;
      num++;
    }
  }
  ret -= num;
  if (num%2 == 1)ret--; 
  return ret;
}

int main(){
  int n;
  cin >> n;
  vector<int> in(n);
  for(int i = 0;i < n;i++){
    cin >> in[i];
  }
  sort(begin(in), end(in));
  cout << solve(n, in) << endl;
  return 0;
}
