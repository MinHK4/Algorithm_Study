// https://www.acmicpc.net/problem/4195

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> level;
vector<int> parent;
vector<int> cnt;

// 같은 집합의 최상위 부모 찾아주기
int find(int cur){
  if(cur != parent[cur])
    parent[cur] = find(parent[cur]);
  return parent[cur];
}

// 다른 집합 합쳐주기
// cnt 배열 추가해서 집합의 원소 개수도 업데이트
void unify(int a, int b){
  if(level[a] < level[b]){
    parent[a] = b;
    cnt[b] += cnt[a];
  }
  else{
    parent[b] = a;
    cnt[a] += cnt[b];
    if(level[a] == level[b])
      level[a]++;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int T;
  cin >> T;
  while(T--){
    
    int F;
    cin >> F;
    
    map<string, int> M;
    level.resize(F*2);
    parent.resize(F*2);
    cnt.resize(F*2);

    fill(level.begin(), level.end(), 0);
    for(int i=0; i<F*2; i++)
      parent[i] = i;
    fill(cnt.begin(),cnt.end(), 1);

    int idx = 0;
    while(F--){
      // Map 이용해서 이름별 ID 관리
      string name1, name2;
      cin >> name1 >> name2;
      if(M.find(name1) == M.end())
        M[name1] = idx++;
      if(M.find(name2) == M.end())
        M[name2] = idx++;

      int root1 = find(M[name1]);
      int root2 = find(M[name2]);
      if(root1 != root2)
        unify(root1, root2);
      
      cout << cnt[find(root1)] << '\n';
    }
  } 
}

/*
Map을 이용해서 각각의 이름별 id를 부여해서 관리해주기
그리고 각각의 id에 대해서 disjoint_set으로 친구관계 업데이트
추가로 cnt 배열 추가해서 unify할 때 집합의 원소 개수 같이 저장하기
*/ 