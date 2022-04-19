// https://www.acmicpc.net/problem/13335

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

struct Truck { 
  int weight, dist; 
};

int main(){

  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, W, L;
  cin >> N >> W >> L;

  queue<Truck> waiting; 
  for (int i=0; i<N; i++) {
    int w; cin >> w;
    waiting.push({w, 0});
  }

  deque<Truck> bridge;
  int bw = 0;
  int time = 0;

  /* 대기중인 트럭과 다리위의 트럭이 모두 비어 있을때까지 */
  while (!waiting.empty() || !bridge.empty()) {
      
    /* 시간 증가 */
    time++;

    /* 다 건넌 트럭 다리위에서 빼주기 */
    if (!bridge.empty()) {
      Truck t = bridge.front(); 
      if (t.dist == W) { 
        bridge.pop_front(); 
        bw -= t.weight;
      }
    }
    
    /* 현재 다리의 무게 + 위의 트럭의 무게 <= 최대하중 이면 */
    /* 건너길 시작한 트럭 다리위에 넣어주기 */
    if (!waiting.empty()) {
      Truck t = waiting.front();
      if (bw + t.weight <= L) { 
        bridge.push_back(t); 
        waiting.pop(); 
        bw += t.weight;
      }
    }

    /* 매 단위시간마다, 다리 위에 있는 모든 트럭들이 1 단위길이 만큼 이동 */
    for (Truck &t : bridge) {
      t.dist++;
    }
  }

  cout << time;
}

/*
queue, deque을 모두 이용한 자료구조 시뮬레이션 문제
*/