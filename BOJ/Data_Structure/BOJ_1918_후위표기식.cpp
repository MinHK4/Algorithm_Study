// https://www.acmicpc.net/problem/1918

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

// 연산자 우선 순위 지정해주기
int pr(char c){
    if(c=='(') return 0;
    else if(c=='+' || c=='-') return 1;
    else if(c=='*' || c=='/') return 2;
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string str;
  cin >> str;

  stack<char> S;
  string ans = "";
  
  for(auto c: str){    
      // 문자면 그냥 추가
      if('A'<=c && c<='Z') ans += c;
      
      // 여는 괄호는 바로 스택에 push 
      else if(c=='(') S.push(c);
      
      // 닫는 괄호는 여는 괄호 만날때까지 스택 pop
      else if(c==')'){
          while(S.top()!='('){
              ans += S.top();
              S.pop();
          }
          S.pop();
      }

      // 자신 보다 낮은 우선순위 연산자는 다 빼주고 자기 push
      else {
          while(!S.empty() && pr(S.top()) >= pr(c)){
              ans += S.top();
              S.pop();
          }
          S.push(c);
      }
  }

  // 남아있는 연산자 반영
  while(!S.empty()){
      ans += S.top();
      S.pop();
  }

  cout << ans;
}