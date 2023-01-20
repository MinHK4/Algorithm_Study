// https://school.programmers.co.kr/learn/courses/30/lessons/12932

function solution(n) {
  var answer = [];

  while (n) {
    answer.push(n % 10);
    n = Math.floor(n / 10);
  }

  return answer;
}
