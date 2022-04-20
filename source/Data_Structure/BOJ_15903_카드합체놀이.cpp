// https://www.acmicpc.net/problem/15903

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  ll n, m;
  cin >> n >> m;

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  while(n--){
    ll temp; cin >> temp;
    pq.push(temp);
  }

  while(m--){
    ll top1 = pq.top(); 
    pq.pop();
    ll top2 = pq.top(); 
    pq.pop();
    
    pq.push(top1+top2);
    pq.push(top1+top2);
  }

  ll sum = 0;
  while(!pq.empty()){
    sum += pq.top();
    pq.pop();
  }
  cout << sum;
}

// PQ 이용한 예제 문제