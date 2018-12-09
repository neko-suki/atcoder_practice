//Disjoint Set

//Accepted 
//uva 793,273,10685
//
#include<iostream>
#include<vector>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Edge{
public:
  int from,to, cost;
  bool operator<(const Edge & a)const{
    if ( cost != a.cost)return cost<a.cost;
    else if ( from != a.from)return from < a.from;
    return to < a.to;
  }
};

int main(){
  int n;
  long long A, B;
  cin >> n >> A>>B;
  vector<Edge> edge;
  vector<int> in(n);
  for(int i = 0;i < n;i++){
    cin >> in[i];
  }
  for(int i = 0;i < n-1;i++){
    edge.emplace_back((Edge){i, i+1, in[i+1] - in[i]});
  }
  sort(begin(edge), end(edge));

  long long ans = (n-1) * B;
  long long tmp = (n-1) * B;
  for(int i = 0;i < edge.size();i++){
    tmp = tmp - B + edge[i].cost * A;
    ans = min(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}
