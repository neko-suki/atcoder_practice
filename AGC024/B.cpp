#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> index(n);
  for(int i = 0;i < n;i++){
    int tmp;
    cin >> tmp;
    tmp--;
    index[tmp] = i;
  }
  int ans = n-1;
  int len = 1;
  int p = 1;
  int now = index[0];
  for(int i = 1;i < n;i++){
    if (index[i] > now){
      len = len + 1;
      ans = min(ans, n - len);
    } else {
      len = 1;
    }
    now = index[i];
  }
  cout << ans << endl;

  return 0;
}
