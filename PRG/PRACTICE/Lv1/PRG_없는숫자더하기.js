// https://school.programmers.co.kr/learn/courses/30/lessons/86051

function solution(numbers) {
  return 45 - numbers.reduce((a, b) => a + b);
}
