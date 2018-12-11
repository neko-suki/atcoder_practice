#include <iostream>
using namespace std;

void solve(const string & in){
  for(int i = 0;i < in.size();i++){
    if (i + 1 < in.size() && in[i] == in[i+1]){
      cout << i+1 <<" " << i+2 << endl;
    }
    if (i + 2 < in.size() && in[i] == in[i+2]){
      cout << i+1 <<" " << i+3 << endl;
    }
  }

  cout << -1 <<" " << -1 << endl;
}


main(){
  string in;
  cin >> in;
  solve(in);
  return 0;
}
