// https://school.programmers.co.kr/learn/courses/30/lessons/12928

function solution(n) {
  var answer = 0;

  for (let i = 1; i * i <= n; i++) {
    if (n % i === 0) {
      answer += i === n / i ? i : i + n / i;
    }
  }

  return answer;
}
