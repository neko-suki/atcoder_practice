#include <iostream>
#include <map>
#include <climits>
using namespace std;

const long long maxi = 1LL << 31;

int main(){
  map<long long,int> M;
  int n;
  cin >> n;
  for(int i = 0;i < n;i++){
    int tmp;
    cin >> tmp;
    M[tmp]++;
  }
  
  int ans = 0;
  for(long long sum = maxi;sum >=2 ;sum /= 2){
    auto itr = M.begin();
    for(;itr != M.end();itr++){
      long long cur = (*itr).first;
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
