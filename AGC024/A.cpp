#include <iostream>
using namespace std;
main(){
  long long a, b, c, k;
  cin >> a>>b>>c>>k;
  if (k%2 == 0)cout << a-b << endl;
  else cout << b-a << endl;
  return 0;
}
