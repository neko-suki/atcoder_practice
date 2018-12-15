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
  return;
  stack<Number> tmp;
  while(!S.empty()){
    tmp.push(S.top());
    S.pop();
  }

  //cout <<"dump: " ;
  while(!tmp.empty()){
    Number top = tmp.top(); tmp.pop();
    assert(top.len > 0);
    //for(int i = 0;i < top.len ;i++){
      //cout << (char)('a' + top.val-1);
    //}
    //cout <<" ";
  }
  //cout << endl;
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

int add(stack<Number> & S, int val, const int length){
  int new_val = val;
  stack<Number> tmp_stack;
  while(!S.empty()){
    Number top = S.top();
    S.pop();
    if (top.val != val){
      Number a = {top.len-1, top.val};
      Number b = {1        , top.val+1};
      if (a.len != 0){
	S.push(a);
      }
      S.push(b);
      break;
    } else if (top.val == val){
      Number a = {top.len, 1};
      tmp_stack.push(a);
    }
  }

  if (S.empty()){
    new_val = new_val + 1;
    while(!tmp_stack.empty()){
      Number top = tmp_stack.top();
      tmp_stack.pop();
      S.push(top);
    }

    Number top = S.top();
    S.pop();
    Number a = {top.len-1, top.val};
    Number b = {1,new_val};
    if (a.len != 0){
      S.push(a);
    }
    S.push(b);
  } else {
    while(!tmp_stack.empty()){
      S.push(tmp_stack.top());
      tmp_stack.pop();
    }
  }
  return new_val;
}

int solve(vector<int> & in){
  stack<Number> S;
  const int n = in.size();
  int val = 1;
  int length = in[0];
  S.push((Number){in[0], val});
  for(int i = 1;i < n;i++){
    //dump(S);
    if (length < in[i]){
      //cout <<"push" << endl;
      S.push((Number){in[i] - length, 1});
    } else if (length == in[i]){
      //cout << "add" << endl;
      val = max(val, add(S, val, in[i]));
    } else if (in[i] < length){
      //cout <<"decrease add " << endl;
      decrease(S, length, in[i]);
      //dump(S);
      val = max(val, add(S, val, in[i]));
    }
    length = in[i];
    //dump(S);
  }
  return val;
}

int main(){
  int n;
  cin >> n;
  vector<int> in(n);
  for(int i = 0;i < n;i++){
    cin >> in[i];
  }
  cout << solve(in) << endl;
  return 0;
}
