// https://programmers.co.kr/learn/courses/30/lessons/42747#

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(), greater<>());

	int i = 0;
	for (; i != citations.size(); ++i){
		if (i + 1 > citations[i])
			break;
	}
	answer = i;
  
	return answer;
}