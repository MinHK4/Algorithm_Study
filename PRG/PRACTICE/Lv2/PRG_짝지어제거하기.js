// https://school.programmers.co.kr/learn/courses/30/lessons/12973

function solution(s) {
  let stck = [];

  for (let i = 0; i < s.length; i++) {
    if (stck.length && stck[stck.length - 1] === s[i]) {
      stck.pop();
      continue;
    }
    stck.push(s[i]);
  }

  return stck.length ? 0 : 1;
}
