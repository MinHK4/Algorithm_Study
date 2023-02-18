// https://school.programmers.co.kr/learn/courses/30/lessons/12935

function solution(arr) {
  if (arr.length === 1) return [-1];

  const min = Math.min(...arr);

  return arr.filter((val) => val !== min);
}

// splice는 원본 데이터 변경 시킴
