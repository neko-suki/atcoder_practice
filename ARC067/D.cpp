//Disjoint Set

//Accepted 
//uva 793,273,10685
//
#include<iostream>
#include<vector>
#include <map>
#include <vector>

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
  int n, k, l;
  
  cin >> n >> k >> l;
  DisjointSet road(n), train(n);
  for(int i = 0;i < k;i++){
    int a, b;
    cin >> a >> b;
    a--;b--;
    road.merge(a, b);
  }

  for(int i = 0;i < l;i++){
    int a,b;
    cin >> a>> b;
    a--;b--;
    train.merge(a,b);
  }

  map<int, vector<int> > M_road;
  for(int i = 0;i < n;i++){
    int cur = road.find_set(i);
    M_road[cur].emplace_back(cur);
  }

  vector<int> ans(n, 0);
  for(auto itr = M_road.begin(); itr != M_road.end(); ++itr){
    auto ref = (*itr).second;
    map<int,int> M_cnt;
    for(auto node : ref){
      M_cnt[train.find_set(node)]++;
    }
    for(auto node:ref){
      ans[node] = M_cnt[train.find_set(node)];
    }
  }
  for(int i = 0;i < n;i++){
    if (i)cout <<"  ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
