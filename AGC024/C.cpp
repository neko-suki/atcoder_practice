#include <iostream>
#include <vector>
using namespace std;

bool canSolve(const int n, vector<int> & in){
  if (in[0] != 0)return false;
  for(int i = 1;i < n;i++){
    if (in[i-1] + 1 < in[i])return false;
  }
  return true;
}

long long solve(const int n, vector<int> & in){
  if (!canSolve(n, in))return -1;
  long long ans = 0;
  int l = 0;
  while(l < in.size()){
    int r = l;
    for(;r < in.size();r++){
      if (in[l] + r - l != in[r])break;
    }
    ans += in[r-1];
    l = r;
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  vector<int> in(n);
  for(int i = 0;i < n;i++){
    cin >> in[i];
  }
  cout << solve(n, in) << endl;
  return 0;
}
