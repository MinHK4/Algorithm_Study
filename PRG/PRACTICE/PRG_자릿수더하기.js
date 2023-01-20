// https://school.programmers.co.kr/learn/courses/30/lessons/12931

function solution(n) {
  var answer = 0;

  while (n) {
    answer += n % 10;
    n = Math.floor(n / 10);
  }

  return answer;
}
