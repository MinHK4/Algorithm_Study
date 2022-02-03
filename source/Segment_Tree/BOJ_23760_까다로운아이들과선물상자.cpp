// https://www.acmicpc.net/problem/23760

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

#define MAX_SIZE 100000

ll tree[1<<21];
ll arr[MAX_SIZE+4];

void init(ll idx, ll l, ll r){
  if(l==r){
    tree[idx] = arr[l];
    return;
  }

  ll mid = (l+r)/2;
  init(idx*2, l, mid);
  init(idx*2+1, mid+1, r);

  tree[idx] = tree[idx*2] + tree[idx*2+1];
}

ll query(ll idx, ll l, ll r, ll tl, ll tr){
  if(tr < l || r < tl) return 0;
  if(tl <= l && r <= tr) return tree[idx];

  ll mid = (l+r)/2;
  return query(idx*2, l, mid, tl, tr) +
        query(idx*2+1, mid+1, r, tl, tr);
}

void update(ll idx, ll l, ll r, ll t, ll v){
  if(t < l || r < t)  return;
  if(l==t && r==t)  {
    tree[idx] += v;
    return;
  }
  ll mid = (l+r)/2;
  update(idx*2, l, mid, t, v);
  update(idx*2+1, mid+1, r, t, v);

  tree[idx] = tree[idx*2] + tree[idx*2+1];
}

// mid부터 MAX까지의 등장 횟수 총합을 구해서
// 원하는 값보다 많이 나왔으면 mid를 뒤로 땡겨서 더 줄이는 방향으로
// 원하는 값보다 적게 나왔으면 mid를 앞으로 땡겨서 더 늘리는 방향으로
// 아예 안 찾아지는 경우를 위해서 ret -1로 초기화해서 사용하기
ll bin_srch(ll l, ll r, ll key){
  ll ret = -1;
  ll s = l;
  ll e = r;
  while(s<=e){
    ll mid = (s+e)/2;
    ll cnt = query(1, 1, MAX_SIZE, mid, MAX_SIZE);
    if(cnt >= key){
      ret = mid;
      s = mid+1;
    }
    else
      e = mid-1;
  }
  return ret;
}


int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  ll N, M;
  cin >> N >> M;

  // 세그먼트 트리 노드에 저장되는 정보는 선물 개수의 등장 횟수
  for(ll i=1; i<=N; i++){
    ll c;
    cin >> c;
    arr[c]++;
  }
  init(1, 1, MAX_SIZE);

  vector<ll> w(M);
  vector<ll> b(M);
  for(ll i=0; i<M; i++)
    cin >> w[i];
  for(ll i=0; i<M; i++)
    cin >> b[i];

  // 각각의 b[i]번째 큰 수를 찾아서 변화 업데이트 해주기
  for(ll i=0; i<M; i++){
    ll cur = bin_srch(0, MAX_SIZE+1, b[i]);
    
    // 원하는 n번째 큰 상자가 남아있는 상자보다 많거나
    // 찾은 상자의 선물 개수가 원하는 개수보다 적은 경우 실패
    if(cur == -1 || cur - w[i] < 0){
      cout << 0;
      return 0;
    }

    // 선물 개수가 더 많아서 계속 진행되면 찾은 개수는 감소하고
    // 딱 맞아떨어지지 않은 경우 남은 개수는 증가해야 함
    update(1, 1, MAX_SIZE, cur, -1);
    if(cur-w[i])
      update(1, 1, MAX_SIZE, cur-w[i], 1);
  }

  cout << 1;
}

/*
Segment Tree에 무엇을 저장할지가 핵심
선물개수 자체를 등장 횟수로 카운트해서 저장해주고 이를 세그트리에 저장
이런 방식으로 하면 i번째 큰 것을 찾고 그와 관련된 정보를 업데이트 해줄 수 있음
*/