#include <iostream>
using namespace std;

typedef long long ll;
const int N = 300;
int edge[N][N];

ll solve(int n){
  ll sum = 0;
  for(int i = 0;i < n;i++){
    for(int j = i+1;j < n;j++){
      sum += edge[i][j];
    }
  }
  for(int i = 0;i < n;i++){
    for(int j = i+1;j < n;j++){
      for(int k = 0;k < n;k++){
	if (k == i || k == j)continue;
	if (edge[i][j] > edge[i][k] + edge[k][j])return -1;
	if (edge[i][j] == edge[i][k] + edge[k][j]){
	  sum -= edge[i][j];
	}
      }
    }
  }
  return sum;
}

int main(){
  int n;
  cin >> n;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      cin >> edge[i][j];
    }
  }
  cout << solve(n) << endl;
  return 0;
}
