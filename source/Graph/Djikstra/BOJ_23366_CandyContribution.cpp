// https://www.acmicpc.net/problem/23366

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<vector<pii>> G;
vector<int> max_candy;

// 시작정점부터 시작해서 인접한 정점들까지의 최단거리 update해주기
// pq에는 현재까지 얻은 정점들까지의 cost값을 기준으로 {dist, pos} 저장
void dijkstra(int start){
  priority_queue<pii> pq;
  pq.push({max_candy[start], start});

  while(!pq.empty()){
    int cur_candy = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    // 현재 지점까지 유지하고 있는 사탕 수에 대한 저장 값이
    // 방금 pq에서 얻은 값보다 더 많은 경우에는 넘어가기
    if(max_candy[cur] > cur_candy)
      continue;

    // 현재 위치에서의 인접 정점들에 대해서
    // 새롭게 거리를 구해서 더 작은 값을 얻게 되면 업데이트 해주기
    for(pii x : G[cur]){
      int taxed_candy = (int)floor((double)cur_candy * (100-x.second) / 100);
      if(taxed_candy > max_candy[x.first]){
        max_candy[x.first] = taxed_candy;
        pq.push({taxed_candy, x.first});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int n, m;
  cin >> n >> m;
  G.resize(n+1);
  max_candy.resize(n+1, -1);
  
  int s, t, c;
  cin >> s >> t >> c;

  while(m--){
    int src, dst, cost;
    cin >> src >> dst >> cost;
    G[src].push_back({dst, cost});
    G[dst].push_back({src, cost});
  }

  max_candy[s] = c;
  dijkstra(s);

  cout << max_candy[t];
}

/*
다익스트라 알고리즘을 이용해서 풀이
원래는 거리 값을 구해서 그 최솟값을 갱신해가면 되지만
문제 조건 상 남아있는 사탕의 개수를 구해서 그 최댓값을 갱신해가는 방식으로 풀이
*/ 