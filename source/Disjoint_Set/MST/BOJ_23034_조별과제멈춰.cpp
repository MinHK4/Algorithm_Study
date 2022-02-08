// https://www.acmicpc.net/problem/23034

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

// MST 구성용 변수들
struct info{
  int a, b, cost;
};

vector<vector<pii>> G;
vector<info> infos;
vector<int> level;
vector<int> parent;
int N, M;

// MST 내에서 DFS 탐색용 변수
vector<bool> visited;
int max_edge;
bool done;

bool comp(info a, info b){
  return a.cost < b.cost;
}

// 같은 집합 내 최상위 부모 찾기(path compression)
int find(int cur){
  if(cur != parent[cur])
    parent[cur] = find(parent[cur]);
  return parent[cur];
}

// 다른 집합 병합시키기
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

// Tree 내에서 DFS 탐색을 하되 
// 목표 찾으면 시작점부터 목표지점까지의 간선 중 최대 cost 찾아놓기 
void DFS(int cur, int target){
  visited[cur] = true;
  
  if (cur == target){
    done = true;
    return;
  }

  for(pii next : G[cur]){
    if(!visited[next.first])
      DFS(next.first, target);
    
    // target 도달 후 연결간선 중 최대 cost 찾기
    if(done){
      max_edge = max(max_edge, next.second);
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> N >> M;
  level.resize(N+1, 1);
  parent.resize(N+1);
  for(int i=1; i<=N; i++)
    parent[i] = i;


  // MST 구성하기
  infos.resize(M);
  for(int i=0; i<M; i++)
    cin >> infos[i].a >> infos[i].b >> infos[i].cost;
  sort(infos.begin(), infos.end(), comp);

  G.resize(N+1, vector<pii>());
  int MST_sum = 0;
  for(int i=0; i<M; i++){
    int roota = find(infos[i].a);
    int rootb = find(infos[i].b);
    if(roota != rootb){
      unify(roota, rootb);
      MST_sum += infos[i].cost;
      G[infos[i].a].push_back({infos[i].b, infos[i].cost});
      G[infos[i].b].push_back({infos[i].a, infos[i].cost});
    }
  }

  // MST 내에서 DFS 탐색으로 최대 간선 찾아서 정답 출력
  visited.resize(N+1);
  int Q;
  cin >> Q;
  while(Q--){
    int x, y;
    cin >> x >> y;

    fill(visited.begin(), visited.end(), false);
    max_edge = -1;
    done = false;
    
    DFS(x, y);

    cout << MST_sum - max_edge << '\n';
  }
}

/*
연결 그래프로 주어졌기 때문에 모든 정점이 연결되어 있으므로
일단 최소 연결의 기반을 제공하기 위해서 MST를 구성해주어야 함
그리고 MSt 구성한 이후에 팀장 입력 받아서
팀장 사이에 있는 팀원들 중 가장 연락 cost가 비싼 간선을 찾아서 MST에서 제외하면
그 cost로 묶여있던 팀원을 경계로 각 팀이 나눠지고 MST안에서 가장 최소 연락 비용으로 구성됨
*/ 
