// https://school.programmers.co.kr/learn/courses/30/lessons/77884

function solution(left, right) {
  let sum = 0;

  for (let i = left; i <= right; i++) {
    let cnt = 0;
    for (let j = 1; j * j <= i; j++) {
      if (i % j === 0) cnt += j === i / j ? 1 : 2;
    }
    sum += cnt % 2 ? -i : i;
  }

  return sum;
}

// 약수의 개수가 홀수인 경우는 제곱근인 경우!
function solution(left, right) {
  var answer = 0;
  for (let i = left; i <= right; i++) {
    if (Number.isInteger(Math.sqrt(i))) {
      answer -= i;
    } else {
      answer += i;
    }
  }
  return answer;
}
