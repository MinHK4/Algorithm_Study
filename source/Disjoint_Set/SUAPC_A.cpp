#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

vector <ll> parent (200001, 0);
vector <ll> level (200001, 0);
vector <ll> cnt (200001, 1);


ll Find(ll cur){
  if(cur != parent[cur])
    parent[cur] = Find(parent[cur]);
  return parent[cur];
}

void Union(ll a, ll b){
  if(level[a] > level[b]){
    parent[b] = a;
    cnt[a] += cnt[b];
  }
  else if(level[a] < level[b]){
    ll root = Find(b);
    parent[a] = b;
    cnt[b] += cnt[a];
  }
  else{
    if(a<b) swap(a, b);
    level[b]++;
    parent[a] = b;
    cnt[b] += cnt[a];
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  ll N, M;
  cin >> N >> M;
  
  parent.resize(N+1, 0);
  level.resize(N+1, 0);
  cnt.resize(N+1, 1);
  for(ll i=0; i<=N; i++)
    parent[i] = i;

  while(M--){
    ll a, b;
    cin >> a >> b;
    ll roota = Find(a);
    ll rootb = Find(b);
    if(roota != rootb)
      Union(roota, rootb);
  }

  vector<bool> checked(N+1, false);
  vector<ll> v;
  for(ll i=1; i<=N; i++){
    ll rooti = Find(i);
    if(!checked[rooti]){
      v.push_back(cnt[rooti]);
      checked[rooti] = true;
    }
  }

  ll ans = 1;
  for(ll x : v)
    ans = (ans * x) % 1000000007;
  cout << ans; 
}