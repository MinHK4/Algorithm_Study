#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  ll N, Q;
  cin >> N >> Q;
  vector<ll> cost(N);
  for(ll i=0; i<N; i++ ){
    ll fan, time, add;
    cin >> fan >> time >> add;
    ll temp;
    if(Q%time)
      temp = Q/time;
    else
      temp = Q/time - 1;
    cost[i] = fan + add*temp*(temp+1)/2;
  }

  ll min = *min_element(cost.begin(), cost.end()); 
  for(ll i=0; i<N; i++){
    if(cost[i] == min){
      cout << i+1 << ' ' << min;
      break;
    }
  }
}