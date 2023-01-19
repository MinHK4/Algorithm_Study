// https://www.acmicpc.net/problem/10090

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;

ll tree[1<<21];
vector<pll> arr;
ll N;

ll query(ll idx, ll l, ll r, ll tl, ll tr){
  if(tr < l || r < tl) return 0;
  if(tl <= l && r <= tr) return tree[idx];

  ll mid = (l+r)/2;
  return query(idx*2, l, mid, tl, tr)+query(idx*2+1, mid+1, r, tl ,tr);
}

void update(ll idx, ll l, ll r, ll t, ll v){

  if(t < l || r < t) return;
  if(l==t && r ==t){
    tree[idx] = v;
    return;
  }

  ll mid = (l+r)/2;
  update(idx*2, l, mid, t, v);
  update(idx*2+1, mid+1, r, t, v);
  tree[idx] = tree[idx*2] + tree[idx*2+1];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> N;
  arr.resize(N);
  for(ll i=0; i<N; i++){
    cin >> arr[i].first;
    arr[i].second = i;
  }
  sort(arr.begin(), arr.end(), greater<>());

  ll ans = 0;
  for(ll i=0; i<N; i++){
    ans += query(1, 0, N-1, 0, arr[i].second);
    update(1, 0, N-1, arr[i].second, 1);
  }
  cout << ans;
}

/*
Segment Tree 방식
세그트리의 노드에 저장되어 있을 값은 현재 인덱스 위치에 수가 등장한 횟수
그리고 이를 의미있게 하기 위해서 (값, 인덱스) 형식으로 입력을 저장하고 정렬
자신보다 큰 값이 먼저 처리되기 때문에 처음부터 현재 값이 나올 인덱스까지의 구간합을
해주게 되면 현재 값과 발생하는 inversion을 세어주는 것이 된다
문제에서 숫자는 한번씩만 등장한다고 했으므로 같은 수의 경우 고려 X
*/ 
