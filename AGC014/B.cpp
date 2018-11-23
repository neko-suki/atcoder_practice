#include <iostream>
#include <vector>
using namespace std;

bool solve(int n, const vector<int> & in){
  for(const auto a : in){
    if (a%2 != 0)return false;
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  vector<int> in(n);
  for(int i = 0;i<n;i++){
    int a,b;
    cin >> a >> b;
    a--;b--;
    in[a]++;
    in[b]++;
  }
  if (solve(n, in))cout << "YES" << endl;
  else cout <<"NO" << endl;
  return 0;
}
