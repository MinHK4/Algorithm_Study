// https://school.programmers.co.kr/learn/courses/30/lessons/12924

function solution(n) {
  let answer = 0;

  for (let i = 1; i <= n; i++) {
    let temp = (i * (i - 1)) / 2;
    if (temp >= n) continue;
    if ((n - temp) % i === 0) answer++;
  }

  return answer;
}
