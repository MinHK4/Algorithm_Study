#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

pii tree[1<<8];
vector<int> arr;

void init(int idx, int left, int right){
  if(left==right){
    tree[idx].first = arr[left];
    tree[idx].second = left;
    return;
  }

  int mid = (left+right)/2;
  init(idx*2, left, mid);
  init(idx*2+1, mid+1, right);

  if(tree[idx*2] < tree[idx*2+1]){
    tree[idx].first = tree[idx*2+1].first;
    tree[idx].second = tree[idx*2+1].second;
  }
  else{
    tree[idx].first = tree[idx*2].first;
    tree[idx].second = tree[idx*2].second;
  }  
}

void update(ll idx, ll left, ll right, ll target, ll value){
  
  if(target < left || right < target) return;
  
  if(target == left && target == right) {
    tree[idx].first = value;
    return;
  }

  ll mid = (left+right)/2;
  update(idx*2, left, mid, target, value);
  update(idx*2+1, mid+1, right, target, value);

  if(tree[idx*2] < tree[idx*2+1]){
    tree[idx].first = tree[idx*2+1].first;
    tree[idx].second = tree[idx*2+1].second;
  }
  else{
    tree[idx].first = tree[idx*2].first;
    tree[idx].second = tree[idx*2].second;
  }  
}

pii query(int idx, int left, int right, int target_L, int target_R){
  if(target_R < left || right < target_L) return {INT_MIN, -1};
  if(target_L <= left && right <= target_R) return tree[idx];

  int mid = (left+right)/2;
  return max(query(idx*2, left, mid, target_L, target_R),
              query(idx*2+1, mid+1, right, target_L, target_R));
}


int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int TC;
  cin >> TC;
  while(TC--){
    int N, K;
    cin >> N >> K;

    string str;
    cin >> str;

    arr.resize(N+1, 0);
    for(int i=1; i<=N; i++)
      arr[i] = str[i] - '0';

    int max_dig = max(K, N-K);    
    int num1 = 0; 
    int last = 1;
    while(max_dig){
      pii temp = query(1, 1, 32, last, N-max_dig+1);
      num1 = num1*10 + temp.first;
      last = temp.second;
      max_dig--;
    }
  }
   
}