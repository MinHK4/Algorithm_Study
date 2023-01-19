// https://www.acmicpc.net/problem/1922

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

struct info{
  int a, b, cost;
};

vector<info> infos;
vector<int> level;
vector<int> parent;
int N, M;

bool comp(info a, info b){
  return a.cost < b.cost;
}

// 집합의 최상위 부모 찾아주기
// path compression 기법을 통해서 O(1) 시간 안에 찾을 수 있게
int find(int cur){
  if(cur != parent[cur])
    parent[cur] = find(parent[cur]);
  return parent[cur];
}

// 집합 합쳐주기
// 다른 집합 여부 확인은 함수 호출 시 확인해서 사용
// 다른 레벨일 때는 작은 걸 큰 쪽으로 합병
// 같은 레베일 때는 둘 중 하나 골라서 합병하고 합병한 애 level 더해주기
void unify(int a, int b){
  if(level[a] < level[b])
    parent[a] = b;
  else if(level[a] > level[b])
    parent[b] = a;
  else{
    parent[b] = a;
    level[a]++;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> N >> M;
  level.resize(N+1, 1);
  parent.resize(N+1, 0);
  for(int i=1; i<=N; i++)
    parent[i] = i;

  // Minimum Spanning Tree 구해주기
  // 간선들의 cost를 기준으로 정렬
  infos.resize(M);
  for(int i=0; i<M; i++)
    cin >> infos[i].a >> infos[i].b >> infos[i].cost;
  sort(infos.begin(), infos.end(), comp);

  // 간선을 하나씩 뽑아서 정점이 같은 집합인지 여부 확인하고
  // 다른 경우에는 MST에 추가해주기
  int ans = 0;
  int cnt = 0;
  for(int i=0; i<M; i++){
    int roota = find(infos[i].a);
    int rootb = find(infos[i].b);
    if(roota != rootb){
      unify(roota, rootb);
      ans += infos[i].cost;
      cnt++;
      if(cnt == N-1)
        break;
    }
  }

  cout << ans;
}

/*
Minimum Spanning Tree 기본 구현
*/ 