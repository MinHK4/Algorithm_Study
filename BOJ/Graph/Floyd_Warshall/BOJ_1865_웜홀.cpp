// https://www.acmicpc.net/problem/1865

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  ll TC;
  cin >> TC;
  while(TC--){
    ll N, M, W;
    cin >> N >> M >> W;
    
    vector<vector<ll>> G(N+1, vector<ll>(N+1, INT_MAX));
    while(M--){
      ll src, dst, cost;
      cin >> src >> dst >> cost;
      G[src][dst] = min(G[src][dst], cost);
      G[dst][src] = min(G[dst][src], cost);
    }
    while(W--){
      ll src, dst, cost;
      cin >> src >> dst >> cost;
      G[src][dst] = -1 * cost;
    }

    // Floyd-Warshall
    for(ll mid=1; mid<=N; mid++){
      for(ll src=1; src<=N; src++){
        for(ll dst=1; dst<=N; dst++)
          G[src][dst] = min(G[src][dst], G[src][mid] + G[mid][dst]);
  
      }
    }

    // answer check & output
    bool flag = false;
    for(ll i=1; i<=N; i++){
      if(G[i][i] < 0){
        flag = true;
        break;
      }
    }
    if(flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

/*
음수 cost가 존재하는 그래프에서의 모든 정점부터 모든 정점끼리의 거리를 구하는 방식으로 접근
-> Floyd-Warshall 알고리즘(Bellman-Ford 풀이도 가능하긴 함)

G[i][j] : i정점부터 j정점까지의 거리
정점 간의 거리는 다양하게 주어질 수 있으므로 입력 받을 때 해당거리의 최소값을 받아서 저장하도록
그래야 음수 사이클이 발생하는지 여부를 확인할 수 있으므로

최소값을 잡아가야하므로 그래프의 초기값으로 큰 값을 잡아주어야 하는데 INT_MAX 사용
뒤에서 덧셈 처리하는 부분이 있기 때문에 long long으로 데이터 선언까지 해줘야
덧셈 overflow없이 계산 가능
*/