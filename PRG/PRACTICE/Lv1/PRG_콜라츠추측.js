// https://school.programmers.co.kr/learn/courses/30/lessons/12943

function solution(num) {
  let tryCount = 0;
  while (num !== 1 && tryCount <= 500) {
    num = num % 2 ? num * 3 + 1 : num / 2;
    tryCount++;
  }

  return tryCount > 500 ? -1 : tryCount;
}
