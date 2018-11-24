#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> in(n);
  for(int i = 0;i<n;i++){
    cin >> in[i];
    in[i]--;
  }
  int ans = 0;
  for(int i = 0;i < n;i++){
    if (i == in[i]){
      ans++;
      if (i != n-1){
	swap(in[i], in[i+1]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
