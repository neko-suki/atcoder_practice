#include <iostream>
#include <stack>
#include <vector>
#include <cassert>
using namespace std;

typedef struct{
  int len;
  int val;
}Number ;

void dump(stack<Number> S){
  stack<Number> tmp;
  while(!S.empty()){
    tmp.push(S.top());
    S.pop();
  }
  
  cout <<"dump: " ;
  while(!tmp.empty()){
    Number top = tmp.top(); tmp.pop();
    assert(top.len > 0);
    for(int i = 0;i < top.len ;i++){
      cout << (char)('a' + top.val);
    }
    cout <<" ";
  }
  cout << endl;
}

void decrease(stack<Number>  & S, int current_length, int target_length){
  while(!S.empty() && current_length > target_length){
    Number top = S.top();
    if (current_length - top.len >= target_length){
      S.pop();
      current_length -= top.len;
    } else if (current_length - top.len < target_length){
      //S.top().len -= current_length - target_length;
      S.top().len = target_length - (current_length - S.top().len);
      break;
    }
  }
}

bool add(stack<Number> & S, const int length, const int lim){
  stack<Number> tmp_stack;
  while(!S.empty()){
    Number top = S.top();
    S.pop();
    if (top.val != lim){
      Number a = {top.len-1, top.val};
      Number b = {1        , top.val+1};
      if (a.len != 0){
	S.push(a);
      }
      S.push(b);
      while(!tmp_stack.empty()){
	Number tmp = tmp_stack.top();
	tmp_stack.pop();
	tmp.val = 1;
	S.push(tmp);
      }
      return true;
      break;
    } else if (top.val == lim){
      Number a = {top.len, top.val};
      tmp_stack.push(a);
    }
  }

  if (S.empty()){
    return false;
  }
  return true;
}

bool solve(const int lim, vector<int> & in){
  stack<Number> S;
  const int n = in.size();
  int val = 1;
  int length = in[0];
  S.push((Number){in[0], 1});
  for(int i = 1;i < n;i++){
    bool fg = true;
    //dump(S);
    if (length < in[i]){
      //cout <<"push" << endl;
      S.push((Number){in[i] - length, 1});
    } else if (length == in[i]){
      //cout << "add" << endl;
      fg = add(S, in[i], lim);
    } else if (in[i] < length){
      //cout <<"decrease add " << endl;
      decrease(S, length, in[i]);
      //dump(S);
      fg = add(S, in[i], lim);
    }
    if (!fg)return false;
    length = in[i];
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  vector<int> in(n);
  for(int i = 0;i < n;i++){
    cin >> in[i];
  }
  int l = 0, r = n;
  while(l < r){
    int mid = (l+r)/2;
    bool can_solve = solve(mid, in);
    if (can_solve){
      r = mid;
    } else {
      l = mid+1;
    }
  }
  cout << l << endl;
  return 0;
}
