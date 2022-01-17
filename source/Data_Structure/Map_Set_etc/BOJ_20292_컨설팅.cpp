#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair <int, int>;

// 하나의 키에 대해서 복수의 value 값이 지정된 상태를 유지할 수 있어야 하기 때문에 multimap
multimap<string, string> write_from_to;
multimap<string, string> write_to_from;

// 단일 변수 문장으로 들어오기 때문에 중복 허용하지 않고 key값을 관리할 수 있어야 하기 때문에 set
set<string> read;

vector<string> ans;

void CLEAR()
{
	write_from_to.clear();
	write_to_from.clear();
	read.clear();
}

int main() {
  
  cin.tie(NULL);
	ios_base::sync_with_stdio(false);

  //freopen("inp.txt", "r", stdin);

  map <string, int> M;
  vector <string> ans;

  string str;
  while (getline(cin, str)) {
      if (strncmp(str.c_str(), "WRITE", 5) == 0) {
          string name1 = "", name2="";
          int i = 6;
          for(;str[i]!=' '; i++)
            name1 += str[i];
          for(i++;str[i]!=' '; i++);
          for(i++;str[i]!='\0'; i++)
            name2 += str[i];
          
          // Read with Write 1
          if(read.count(name2)!=0){
            CLEAR();
            ans.push_back("WAIT");
          }
          
          // Read with Write 2 + 교착상태
          // 양쪽이 교차해서 중복되는 경우
          else if(write_to_from.count(name1)!= 0 || write_from_to.count(name2)!=0){
            CLEAR();
            ans.push_back("WAIT");
          }

          // Write with Write 1 + 2
          // 같은 쪽이 동일하게 중복되는 경우
          else if(write_to_from.count(name2)!= 0 || write_to_from.count(name1)!=0){
            CLEAR();
            ans.push_back("WAIT");
          }
          ans.push_back(str);
          write_from_to.insert({name1, name2});
          write_to_from.insert({name2, name1});
      }
      else if (strncmp(str.c_str(), "READ", 4) == 0){
          string name = &str[5];
          if(write_to_from.count(name)!= 0){
            CLEAR();
            ans.push_back("WAIT");
          }
          ans.push_back(str);
          read.insert(name);
      }
      else if (strncmp(str.c_str(), "EXIT", 4) == 0) {
          ans.push_back(str);
          break;
      }
  }

  for (string x : ans)
      cout << x << '\n';
}