// https://www.acmicpc.net/problem/2357

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<pii> tree;
vector<int> arr;

void init(int idx, int left, int right){
  if(left==right){
    tree[idx].first= arr[left];
    tree[idx].second= arr[left];
    return;
  }
  int mid = (left+right)/2;
  init(idx*2, left, mid);
  init(idx*2+1, mid+1, right);
  
  tree[idx].first = min(tree[idx*2].first, tree[idx*2+1].first);
  tree[idx].second = max(tree[idx*2].second, tree[idx*2+1].second);
}

int min_query(int idx, int left, int right, int target_L, int target_R){
  if(target_R < left || right < target_L) return INT_MAX;
  if(target_L <= left && right <= target_R) return tree[idx].first;

  int mid = (left+right)/2;
  return min(min_query(idx*2, left, mid, target_L, target_R),
              min_query(idx*2+1, mid+1, right, target_L, target_R));
}

int max_query(int idx, int left, int right, int target_L, int target_R){
  if(target_R < left || right < target_L) return INT_MIN;
  if(target_L <= left && right <= target_R) return tree[idx].second;

  int mid = (left+right)/2;
  return max(max_query(idx*2, left, mid, target_L, target_R),
              max_query(idx*2+1, mid+1, right, target_L, target_R));
}

int main() {

  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N, M;
  cin >> N >> M;
  tree.resize(1<<19, {INT_MAX, INT_MIN});
  arr.resize(N+1);
  for(int i=1; i<=N; i++)
    cin >> arr[i];

  init(1, 1, N);
  
  int l, r;
  while(M--){
    cin >> l >> r;
    cout << min_query(1, 1, N, l, r) << ' ' << max_query(1, 1, N, l, r)<< '\n';
  }
}

/*
Segment Tree 기본 구조에서 pair로만 바꿔서
first에 최솟값, second에 최댓값 찾기로 변용
*/