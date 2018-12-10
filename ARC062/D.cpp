#include <iostream>
using namespace std;

main(){
  string in;
  cin >> in;
  int cnt = 0;
  for(int i = 0;i < cnt;i++){
    if (in[i] == 'g')cnt++;
    else cnt--;
  }
  cout << cnt/2 << endl;
}
