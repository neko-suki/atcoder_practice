#include <iostream>
#include <algorithm>
using namespace std;

const int N = 4000;
int wsum[N][N]={0};
int bsum[N][N]={0};
int win[N][N]={0};
int bin[N][N]={0};

int get_sum(int y1, int x1, int y2, int x2, int sum[N][N]){
  int ret = sum[y2][x2];
  if (y1 > 0){
    ret -= sum[y1-1][x2];
  }
  if (x1 > 0){
    ret -= sum[y2][x1-1];
  }
  if (y1 > 0 && x1 > 0){
    ret += sum[y1-1][x1-1];
  }
  return ret;
}

void compute_sum(int n, int in[N][N], int sum[N][N]){
  fill(&sum[0][0], &sum[N-1][0], 0);
  for(int i = 0;i < n;i++){
    for(int j=0;j < n;j++){
      int tmp = in[i][j];
      if (i > 0){
	tmp += sum[i-1][j];
      }
      if (j > 0){
	tmp += sum[i][j-1];
      }
      if (i > 0 && j > 0){
	tmp -= sum[i-1][j-1];
      }
      sum[i][j] = tmp;
    }
  }
}

int solve(const int k, int win[N][N], int bin[N][N]){
  compute_sum(3 * k, win, wsum);
  compute_sum(3 * k, bin, bsum);

  int ret = 0;
  for(int i = 0;i < k;i++){
    for(int j = 0;j < k;j++){
      int tmp1 = get_sum(i, j, i+k-1, j+k-1 , wsum) + get_sum(i+k, j+k, i+k+k-1, j+k+k-1, wsum)
	+ get_sum(i, j+k, i+k-1, j+k+k-1, bsum) + get_sum(i+k, j, i+k+k-1, j+k-1, bsum);
      int tmp2 = get_sum(i, j, i+k-1, j+k-1 , bsum) + get_sum(i+k, j+k, i+k+k-1, j+k+k-1, bsum)
	+ get_sum(i, j+k, i+k-1, j+k+k-1, wsum) + get_sum(i+k, j, i+k+k-1, j+k-1, wsum);
      ret = max({ret, tmp1, tmp2});
    }
  }
  return ret;
}

int main(){
  int n, k;
  cin >> n >> k;
  for(int i = 0;i < n;i++){
    int y, x;
    char color;
    cin >> x >> y >> color;
    y = y % (2 * k);
    x = x % (2 * k);
    
    if (color == 'W'){
      win[y][x]++;
      int ty = y + 2 * k;
      int tx = x + 2 * k;
      win[ty][tx]++;
    } else if (color == 'B'){
      bin[y][x]++;
      int ty = y + 2 * k;
      int tx = x + 2 * k;
      bin[ty][tx]++;
    }
  }

  cout << solve(k, win, bin) << endl;;
  return 0;
}
