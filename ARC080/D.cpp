#include <iostream>
using namespace std;

const int N = 100;
char result[N][N];
bool visited[N][N] = {0};

int dy[] = {0,  0, 1, -1};
int dx[] = {1, -1, 0, 0};

void dfs(int n, int y, int x){
  if (visited[y][x])return;
  visited[y][x] = true;
  for(int i = 0;i < 4;i++){
    int ney = y + dy[i], nex = x + dx[i];
    if (0 <= ney && ney < n && 0 <= nex && nex < n &&
	result[ney][nex] == result[y][x]){
      dfs(n, ney, nex);
    }
  }
}

bool check(int n, const int w, const int b){
  int w_cnt = 0, b_cnt = 0;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if (!visited[i][j]){
	if (result[i][j] == '#')b_cnt++;
	if (result[i][j] == '.')w_cnt++;
	dfs(n, i, j);
      }
    }
  }
  return w == w_cnt && b == b_cnt;
}

void solve(const int w_cnt, const int b_cnt){
  const int n = 100;
  for(int i = 0;i < n/2;i++){
    for(int j = 0;j < n;j++){
      result[i][j] = '#';
    }
  }
  for(int i = n/2;i < n;i++){
    for(int j = 0;j < n;j++){
      result[i][j] = '.';
    }
  }


  {
    int w_tmp = w_cnt;
    int nowy = 0;
    int nowx = 0;
    while(w_tmp){
      result[nowy][nowx] = '.';
      nowx += 2;
      if (nowx == n){
	nowy += 2;
	nowx = 0;
      }
      w_tmp--;
    }
  }
  {
    int b_tmp = b_cnt;
    int nowy = n/2+1;
    int nowx = 0;
    while(b_tmp){
      result[nowy][nowx] = '#';
      nowx += 2;
      if (nowx == n){
	nowy += 2;
	nowx = 0;
      }
      b_tmp--;
    }
  }

  bool isok = check(n, w_cnt, b_cnt);
  cout << isok << endl;

}


int main(){
  int w, b;
  cin >> w >> b;
  solve(w, b);
  return 0;
}
