// https://school.programmers.co.kr/learn/courses/30/lessons/138476

function solution(k, tangerine) {
  const countMap = new Map();
  tangerine.forEach((t) => {
    if (!countMap.has(t)) {
      countMap.set(t, 0);
    }
    countMap.set(t, countMap.get(t) + 1);
  });

  const countList = [...countMap.values()].sort((a, b) => b - a);
  let sum = 0;
  let ans = 0;
  for (let i = 0; i < countList.length; i++) {
    ans++;
    sum += countList[i];
    if (sum >= k) break;
  }
  console.log(countList);

  return ans;
}

function solution1(k, tangerine) {
  const tDict = {};
  tangerine.forEach((t) => (tDict[t] = (tDict[t] || 0) + 1));

  const tArr = Object.values(tDict).sort((a, b) => b - a);
  let answer = 0;
  for (const t of tArr) {
    answer++;
    if (k > t) k -= t;
    else break;
  }
  return answer;
}
