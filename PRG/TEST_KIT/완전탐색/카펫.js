// https://school.programmers.co.kr/learn/courses/30/lessons/42842?language=javascript

function solution(brown, yellow) {
  for (let i = 1; i * i <= yellow; i++) {
    if (yellow % i === 0) {
      if ((i + yellow / i + 2) * 2 === brown)
        return [i + 2, yellow / i + 2].sort((a, b) => b - a);
    }
  }
}
