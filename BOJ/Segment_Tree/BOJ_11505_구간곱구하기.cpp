// https://www.acmicpc.net/problem/11505

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

#define mod 1000000007

vector<ll> tree;
ll arr[1000004];

// 세그먼트 트리 형성해주기
// 전체구간에서부터 이분적으로 구간을 분할해가면서
// 이용하고자 하는 구간의 정보를 저장해놓기
void init(ll idx, ll left, ll right){
  
  // 구간의 크기가 1인 경우 해당하는 위치의 배열 값 넣어주기
  if(left==right){
    tree[idx] = arr[left];
    return;
  }

  // 구간 분할해나가기
  ll mid = (left+right)/2;
  init(idx*2, left, mid);
  init(idx*2+1, mid+1, right);
  
  // 필요한 정보(구간곱) 저장하기
  tree[idx] = (tree[idx*2] * tree[idx*2+1]) % mod;
}

// 트리 노드들에 값이 변경된 사항을 반영해주기
void update(ll idx, ll left, ll right, ll target, ll value){
  
  // 목표가 현재 구간내에 있지 않음
  if(target < left || right < target) return;
  
  // 해당 목표 찾으면 값 변경해주기
  if(target == left && target == right) {
    tree[idx] = value;
    return;
  }

  // 값이 변경되었으므로 재귀 빠져나오면서 구간곱 정보들 또한 업데이트해줘야 함
  ll mid = (left+right)/2;
  update(idx*2, left, mid, target, value);
  update(idx*2+1, mid+1, right, target, value);
  tree[idx] = (tree[idx*2] * tree[idx*2+1]) % mod;
}

// 원하는 구간의 정보 가져오기
ll query(ll idx, ll left, ll right, ll target_L, ll target_R){
  
  // 현재 구간이 찾는 구간과 전혀 겹치지 않는 경우
  if(target_R < left || right < target_L) return 1;
  
  // 현재 구간이 찾는 구간보다 작거나 같은 범위인 경우
  // 현재 구간합의 정보 챙겨가기
  if(target_L <= left && right <= target_R) return tree[idx];

  // 구간들의 곱 종합해서 최종적으로 원하는 구간의 전체 곱 구성하기
  ll mid = (left+right)/2;
  return (query(idx*2, left, mid, target_L, target_R) 
          * query(idx*2+1, mid+1, right, target_L, target_R)) % mod;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  ll N, M, K;
  cin >> N >> M >> K; 
  tree.resize(1 << 21, 1); 
  for(ll i=1; i<=N; i++)
    cin >> arr[i];

  init(1, 1, N);

  ll q = M+K;
  ll type, temp1, temp2;
  while(q--){
    cin >> type;
    if(type == 1){
      cin >> temp1 >> temp2;
      update(1, 1, N, temp1, temp2);
    }
    else{
      cin >> temp1 >> temp2;
      cout << query(1, 1, N, temp1, temp2) << '\n';
    }
  }
}

/*
Segment Tree 구간합 변용
0이 기본값인거 1로 바꾸는 것만 신경써주기
*/