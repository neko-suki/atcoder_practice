#include <iostream>
using namespace std;

int main(){
  string in;
  cin >> in;
  const int n = in.size();
  long long ans = 0;
  for(int i = 1; i <= n;i++){
    if (in[i-1] == 'u'){
      ans += (n-i) + 2 * (i-1);
    } else {
      ans += (n-i) * 2 + (i-1);
    }
  }
  cout << ans << endl;
  return 0;
}
