// https://www.acmicpc.net/problem/15828

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  queue<int> q;
  while(1){
    int temp;
    cin >> temp;

    if(temp == -1)
      break;

    if(temp == 0)
      q.pop();
    
    else if(q.size() < N)
      q.push(temp);
  }

  if(q.empty())
    cout << "empty";
  else{
    while(!q.empty()){
      cout << q.front() << ' ';
      q.pop();
    }
  }
}

// queue 자료구조로 Router 개념 구현하기