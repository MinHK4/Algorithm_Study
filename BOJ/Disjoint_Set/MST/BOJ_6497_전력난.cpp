// https://www.acmicpc.net/problem/6497

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

// 집합의 최상위 부모 찾아주기(path compression)
int find(int cur){
  if(cur != parent[cur])
    parent[cur] = find(parent[cur]);
  return parent[cur];
}

// 다른 집합 합쳐주기
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
  
  while(1){
    
    cin >> N >> M;

    if(N==0 && M==0)
      break;

    level.resize(N, 1);
    parent.resize(N, 0);
    for(int i=0; i<N; i++)
      parent[i] = i;

    // Maximum Spanning Tree 구해주기
    infos.resize(M);
    for(int i=0; i<M; i++)
      cin >> infos[i].a >> infos[i].b >> infos[i].cost;
    sort(infos.begin(), infos.end(), comp);
    

    // MST 구성은 하되 그 안에 포함되지 않는 간선들만 모아주기
    int ans = 0;
    for(int i=0; i<M; i++){
      int roota = find(infos[i].a);
      int rootb = find(infos[i].b);
      if(roota != rootb)
        unify(roota, rootb);
      else
        ans += infos[i].cost;
    }

    cout << ans << '\n';
  }
}

/*
Minimum Spanning Tree 기본 구현하되
MST 안에 속하지 못 하는 edge들의 합이 최대 절약 비용이 됨
*/ 