// https://school.programmers.co.kr/learn/courses/30/lessons/118666

function solution(survey, choices) {
  let answer = '';

  const score = {
    R: 0,
    T: 0,
    C: 0,
    F: 0,
    M: 0,
    J: 0,
    A: 0,
    N: 0,
  };

  survey.forEach((s, idx) => {
    score[s[0]] += 4 - choices[idx];
    score[s[1]] += choices[idx] - 4;
  });

  const temp = [
    ['R', 'T'],
    ['C', 'F'],
    ['J', 'M'],
    ['A', 'N'],
  ];
  temp.forEach((arr) => {
    answer += chooseOne(arr);
  });

  return answer;

  function chooseOne(arr) {
    if (score[arr[0]] >= score[arr[1]]) return arr[0];
    else if (score[arr[0]] < score[arr[1]]) return arr[1];
  }
}
