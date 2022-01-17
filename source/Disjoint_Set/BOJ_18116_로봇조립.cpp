#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

vector <int> parent (1000001, 0);
vector <int> level (1000001, 0);
vector <int> cnt (1000001, 1);

int Find(int key){
  while(parent[key] != key){
    key = parent[key];
  }
  return key;
}

void Union(int a, int b){
  if(level[a] > level[b]){
    parent[b] = a;
    cnt[a] += cnt[b];
  }
  else if(level[a] < level[b]){
    int root = Find(b);
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
  
  for(int i=0; i<1000000; i++)
    parent[i] = i;

  int N;
  cin >> N;
  while(N--){
    char c;
    cin >> c;
    if(c == 'I'){
      int a, b;
      cin >> a >> b;
      int roota = Find(a);
      int rootb = Find(b);
      if(roota != rootb)
        Union(roota, rootb);
    }
    if(c == 'Q'){
      int a;
      cin >> a;
      cout << cnt[Find(a)] << '\n';
    }
  }
}