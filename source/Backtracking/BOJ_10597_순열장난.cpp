// https://www.acmicpc.net/problem/10597

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> ans;
vector<bool> checked;
string str;
int max_num;
int len;
bool done = false;

void backtrack(int idx){

  // end case
  if(idx >= len){
    done = true;
    return;
  }

  // 한 자리 숫자 넣을 수 있을 때
  int num1 = str[idx]-'0';
  if(!done && num1 >= 1 && !checked[num1]){
    checked[num1] = true;
    ans.push_back(num1);
    backtrack(idx+1);
    if(done)
      return;
    else{
      checked[num1] = false;
      ans.pop_back();
    }
  }

  // 두 자리 숫자 넣을 수 있을 때
  if(idx+1 <len){
    int num2 = num1*10 + str[idx+1]-'0';
    if(!done && num2 <= max_num && !checked[num2]){
      checked[num2] = true;
      ans.push_back(num2);
      backtrack(idx+2);
      if(done)
        return;
      else{
        checked[num2] = false;
        ans.pop_back();
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> str;
  len = str.length();
  if(len <= 9)
    max_num = len;
  else
    max_num = 9 + (len-9) / 2;
  checked.resize(max_num+1, false);

  backtrack(0);

  for(int x : ans)
    cout << x << ' ';
}

/*
1~N 까지의 수가 그대로 있기 때문에
크기나 수의 개수에 대해서 확정을 하고 들어갈 수 있고
수열의 크기가 크지 않기 때문에 모든 나눠보는 경우를 체크해봐주면 된다
따라서 Backtracking 기법으로 접근
*/ 