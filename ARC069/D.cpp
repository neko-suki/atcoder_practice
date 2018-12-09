#include <iostream>
#include <cassert>
using namespace std;

bool check(char me, char query, char left, char right){
  if (
      (me == 'S' && query == 'o') ||
      (me == 'W' && query == 'x')
      ){
    return left == right;
  } else   if (
      (me == 'S' && query == 'x') ||
      (me == 'W' && query == 'o')
      ){
    return left != right;
  }
  assert(false);
}

char decide(char me, char query, char left){
  if (me == 'S'){
    if (query == 'o'){
      return left;
    } else if (query == 'x'){
      return left == 'S' ? 'W' : 'S';
    }
  } else if (me == 'W'){
    if (query == 'o'){
      return left == 'S' ? 'W' : 'S';
    } else if (query == 'x'){
      return left;
    }
  }
  assert(false);
}

string check(const int n, const char a, const char b, const string & query){
  string ret;
  ret += string(1, a);
  ret += string(1, b);
  char last = decide(ret[0], query[0], ret[1]);
  for(int i = 1;i < n-1;i++){
    ret += string(1, decide(ret[i], query[i], ret[i-1]));
  }
  if (last == ret[n-1] &&
      check(ret[n-1], query[n-1], ret[n-2], ret[0])){
    return ret;
  }
  return "";
}

string solve(const int n, const string & in){
  char str[3] = "SW";
  for(int i = 0;i < 2;i++){
    for(int j = 0;j < 2;j++){
      string tmp = check(n, str[i], str[j], in);
      if (tmp.size() != 0)return tmp;
    }
  }
  return "-1";
}


int main(){
  int n;
  string in;
  cin >> n >> in;
  cout << solve(n, in) << endl;

  return 0;
}
