// https://school.programmers.co.kr/learn/courses/30/lessons/12916

function solution(s) {
  let pCount = 0,
    yCount = 0;

  for (const c of s.toLowerCase()) {
    if (c === 'p') pCount++;
    if (c === 'y') yCount++;
  }

  return pCount === yCount;
}

// 정규표현식을 이용한 풀이
function numPY(s) {
  return s.match(/p/gi).length == s.match(/y/gi).length;
}
