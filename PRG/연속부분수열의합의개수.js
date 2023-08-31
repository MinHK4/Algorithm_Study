// https://school.programmers.co.kr/learn/courses/30/lessons/131701

function solution1(elements) {
  const circular = elements.concat(elements);
  const set = new Set();

  // i는 원형 수열의 시작점
  for (let i = 0; i < elements.length; i++) {
    let sum = 0;
    // j는 원형 수열의 길이-1
    for (let j = 0; j < elements.length; j++) {
      sum += circular[i + j];
      set.add(sum);
    }
  }
  return set.size;
}

function solution2(elements) {
  let answer = [];
  // 배열 2배 확장
  const extendElements = [...elements, ...elements];

  elements.forEach((element, idx) => {
    if (idx < elements.length) {
      for (let i = 0; i < elements.length; i++) {
        // 각각의 순회마다 i부터 idx만큼 잘라서 slice 배열을 반환한 값을 push
        // i는 시작점,
        const slice = extendElements.slice(i, i + 1 + idx);
        answer.push(slice.reduce((a, b) => a + b));
      }
    }
  });

  // 중복 제거
  const set = new Set(answer);
  return [...set].length;
}
