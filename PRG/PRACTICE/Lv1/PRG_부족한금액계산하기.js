// https://school.programmers.co.kr/learn/courses/30/lessons/82612
function solution(price, money, count) {
  const cost = Array(count)
    .fill()
    .map((_, idx) => (idx + 1) * price)
    .reduce((a, b) => a + b);
  return cost >= money ? cost - money : 0;
}

// 수의 합 공식 이용한 풀이
function solution(price, money, count) {
  const tmp = (price * count * (count + 1)) / 2 - money;
  return tmp > 0 ? tmp : 0;
}
