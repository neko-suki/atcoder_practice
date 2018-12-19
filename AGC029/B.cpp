#include <iostream>
#include <map>
#include <climits>
using namespace std;

const int maxi = 1 << 30;

int main(){
  map<int,int> M;
  int n;
  cin >> n;
  for(int i = 0;i < n;i++){
    int tmp;
    cin >> tmp;
    M[tmp]++;
  }
  
  int ans = 0;
  for(int sum = maxi;sum >=2 ;sum /= 2){
    auto itr = M.begin();
    for(;itr != M.end();itr++){
      int cur = (*itr).first;
      if (cur >= sum || (*itr).second == 0)continue;
      long long tar = sum - cur;
      if (M[tar] != 0){
	if (tar == cur){
	  ans += M[tar]/2;
	  M[cur] = 0;
	} else {
	  ans += min(M[tar], M[cur]);
	  int tmp =  min(M[cur], M[tar]);
	  M[tar] -= tmp;
	  M[cur] -= tmp;
	}
      }
    }
  }
  cout << ans << endl;
  return 0;
}
