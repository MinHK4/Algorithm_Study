// https://www.acmicpc.net/problem/23369

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int n, t;
  cin >> n >> t;

  deque<char> d;
  for(int i=0; i<n; i++)
    d.push_back('a'+i);
  
  if(t % n)
    cout << t/n + 1 << '\n';
  else
    cout << t/n << '\n';
  
  while(t){
    if(t>=n){
      cout << d.back() << ' ';
      char temp = d.back();
      d.pop_back();
      d.push_front(temp);
      t -= n;
    }
    else{
      cout << d[t-1];
      t = 0;
    }
  }
}

/*
그리디 알고리즘
최소한의 횟수만 시키기 위해서는 한 번 꺼낼 때 최대한 많은 수를 꺼내야함
따라서 n크기만큼(가장 뒤에 것을) 꺼내다가 
남아있는 초가 n보다 작아지면 그때 해당하는 위치의 것을 꺼냄
앞뒤 뺴고 넣고가 가능하고 random access가 가능한 deque 사용
*/