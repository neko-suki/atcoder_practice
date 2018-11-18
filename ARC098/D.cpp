#include <iostream>
#include <vector>
using namespace std;

int main(){
  int head = 0, tail = 0;
  int n;
  vector<int> in(n);
  for(int i = 0;i < n;i++){
    cin >> in[i];
  }

  int ans = 0;
  int now = 0;
  for(int i = 0;i < n;i++){
    while(tail < i && (now & in[i]) != 0){
      now = now ^ in[tail];
      tail++;
    }
    now = now ^ in[i];
    ans += head - tail + 1;
  }

  cout << ans << endl;
  return 0;
}
