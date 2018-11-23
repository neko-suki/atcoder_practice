#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
public:
  vector<int> rank,p;
  
  DisjointSet(){}
  DisjointSet(int size){
    rank.resize(size,0);
    p.resize(size,0);
    for(int i =0;i < size;i++){
      make_set(i);
    }
  }
  void make_set(int x){
    p[x]=x;
    rank[x]=0;
  }
  void merge(int x,int y){
    link(find_set(x),find_set(y));
  }
  void link(int x,int y){
    if (rank[x]>rank[y]){
      p[y]=x;
    }else {
      p[x]=y;
      if ( rank[x] ==rank[y])rank[y]+=1;
    }
  }
  int find_set(int x){
    if (x != p[x])p[x]=find_set(p[x]);
    return p[x];
  }
};


int main(){
  int n, m;
  cin >> n >> m;
  DisjointSet dj(n);
  vector<int> in(n);
  for(int i = 0;i < n;i++){
    cin >> in[i];
    in[i]--;
  }
  for(int j = 0;j < m;j++){
    int a,b;
    cin >> a >>b;
    a--;
    b--;
    dj.merge(a,b);
  }
  int ans = 0;
  for(int i = 0;i < n;i++){
    if (dj.find_set(i) == dj.find_set(in[i])){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
