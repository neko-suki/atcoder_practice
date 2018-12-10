#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isTopLeft(int a, int b, int now, set<pair<int,int> > & S){
  for(int i = 0;i < now;i++){
    int new_a = a + now / 3, new_b = b + now % 3;
    if (S.count({a, b}) != 0){
      return false;
    }
  }
  return true;
}

void countUp(int a, int b,
	     long long H, long long W,
	     set<pair<int,int> >& S,
	     vector<long long> &cnt){
  for(int i = 0;i < 9;i++){
    int dec_a = i / 3, dec_b = i % 3;
    int base_a = a - dec_a, base_b = b - dec_b;
    if (base_a < 0 || base_b < 0 ||
	base_a + 3 >= H || base_b + 3 >= W){
      continue;
    }

    if (isTopLeft(base_a, base_b, i, S)){
      int tmp = 1;
      for(int j = i+1;j < 9;j++){
	int new_a = base_a +  j / 3;
	int new_b = base_b + j % 3;
	if (S.count({new_a, new_b}) != 0){
	  tmp++;
	}
      }
      cnt[tmp]++;
      cnt[0]--;
    }
  }
}


int main(){
  long long h, w;
  int n;
  set<pair<int,int> > S;
  cin >> h >> w >> n;

  vector<pair<int,int> > in(n);
  for(int i  = 0;i < n;i++){
    cin >> in[i].first >> in[i].second;
  }

  vector<long long> ans(10);
  ans[0] = (h - 2) * (w - 2);

  for(int i = 0;i < n;i++){
    countUp(in[i].first, in[i].second, h, w, S, ans);
  }
  for(int i = 0;i < 10;i++){
    cout << ans[i] << endl;
  }
  return 0;
}
