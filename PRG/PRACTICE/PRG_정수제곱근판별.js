// https://school.programmers.co.kr/learn/courses/30/lessons/12934

function solution(n) {
  var answer = 0;

  let flag = false;
  for (let i = 1; i * i <= n; i++) {
    if (i * i === n) {
      answer = (i + 1) * (i + 1);
      flag = true;
      break;
    }
  }

  return flag ? answer : -1;
}
