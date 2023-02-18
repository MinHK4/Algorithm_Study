// https://school.programmers.co.kr/learn/courses/30/lessons/87389

function solution(n) {
  let answer = 2;

  while (n % answer !== 1) answer++;

  return answer;
}
