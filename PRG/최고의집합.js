// https://school.programmers.co.kr/learn/courses/30/lessons/12938
// 15 min

function solution(n, s) {
  if (n > s) return [-1];

  const def = Math.floor(s / n);
  const ans = new Array(n).fill(def);

  let left = s - def * n;
  let i = 0;
  while (left) {
    ans[i]++;
    left--;
    i++;
  }

  return ans.sort((a, b) => a - b);
}
