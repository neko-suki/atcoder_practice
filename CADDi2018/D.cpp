#include <iostream>
#include <vector>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<int> in(n);
  bool has_odd = false;
  for(int i = 0;i < n;i++){
    cin >> in[i];
    if (in[i]%2 != 0)has_odd= true;
  }
  if (has_odd)cout <<"first" << endl;
  else cout <<"second" << endl;
  return 0;
}
