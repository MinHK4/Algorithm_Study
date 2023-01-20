// https://school.programmers.co.kr/learn/courses/30/lessons/12944

function solution(arr) {
  var answer = 0;

  const sum = arr.reduce((acc, cur) => acc + cur);
  answer = sum / arr.length;

  return answer;
}
