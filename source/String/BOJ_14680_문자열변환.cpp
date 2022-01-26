#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

#define mod 1000000007

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  ll N;
  cin >> N;
  
  vector<vector<vector<ll>>> arr(N, vector<vector<ll>>(51, vector<ll>(51)));
  vector<pii> v;
  for(ll i=0; i<N; i++){
    ll row, col;
    cin >> row >> col;
    v.push_back({row, col});

    for(ll j=1; j<=row; j++){
      for(ll k=1; k<=col; k++)
        cin >> arr[i][j][k];
    }
  }

  vector<vector<ll>> temp(51, vector<ll>(51, 0));
  for(ll j=0; j<51; j++){
    for(ll k=0; k<51; k++)
      temp[j][k] = arr[0][j][k];
  }

  for(ll i=0; i<N-1; i++){

    if(v[i].second != v[i+1].first){
      cout << -1;
      return 0;
    }

    vector<vector<ll>> temp2(51, vector<ll>(51, 0));
    for (ll j=1; j<=v[i].first; j++){
      for(ll k=1; k<=v[i+1].second; k++){
        for(ll l=1; l<=v[i].second; l++)
          temp2[j][k] = (temp2[j][k] + ((temp[j][l] * arr[i+1][l][k]) % mod)) % mod;
      }
    }

    for(ll j=0; j<51; j++){
      for(ll k=0; k<51; k++)
        temp[j][k] = temp2[j][k];
    }
  }

  ll ans = 0;
  for(ll i=1; i<=v[0].first; i++){
    for(ll j=1; j<=v[N-1].second; j++)
      ans = (ans + temp[i][j]) % mod;
  }
  cout << ans;
}