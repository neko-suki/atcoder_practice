#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string s;
  cin >> s;
  if (s.size() == 26){
    if (next_permutation(s.begin(), s.end())){
      cout << s << endl;
    } else {
      cout << -1 << endl;
    }
  } else {
    int cnt [26] = {0};
    for(int i = 0;i < 26;i++){
      cnt[s[i]-'a']++;
    }
    for(int i = 0;i < 26;i++){
      if (cnt[i] == 0)
	s = s + string(1, 'a' + i);
    }
  }
  return 0;
}
