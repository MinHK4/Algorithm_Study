// https://www.acmicpc.net/problem/1647

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

struct info{
  int a, b, cost;
};

vector<int> level;
vector<int> parent;

bool cmp(info a, info b){
  return a.cost < b.cost;
}

int find(int cur){
  if(cur != parent[cur])
    parent[cur] = find(parent[cur]);
  return parent[cur];
}

void unify(int a, int b){
  if(level[a] < level[b])
    parent[a] = b;
  else{
    parent[b] = a;
    if(level[a] == level[b])
      level[a]++;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N, M;
  cin >> N >> M;
  level.resize(N+1, 1);
  parent.resize(N+1);
  for(int i=1; i<=N; i++)
    parent[i] = i;

  vector<info> infos(M);
  for(int i=0; i<M; i++)
    cin >> infos[i].a >> infos[i].b >> infos[i].cost;
  sort(infos.begin(), infos.end(), cmp);

  int ans = 0;
  int max_edge = -1;
  for(int i=0; i<M; i++){
    int roota = find(infos[i].a);
    int rootb = find(infos[i].b);
    if(roota != rootb){
      unify(roota, rootb);
      ans += infos[i].cost;
      max_edge = max(max_edge, infos[i].cost);
    }
  }

  cout << ans-max_edge;
}

/*
MST 구현하고 두 마을로 나눠주기 위해서 가장 큰 간선 배제해주기
*/