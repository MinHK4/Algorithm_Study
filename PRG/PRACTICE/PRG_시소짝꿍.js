// https://school.programmers.co.kr/learn/courses/30/lessons/152996?language=javascript

function solution(weights) {
  var answer = 0;

  const weightTable = {};
  weights.forEach((weight) => {
    if (!weightTable.hasOwnProperty(weight)) weightTable[weight] = 0;
    weightTable[weight]++;
  });

  const newWeightTable = {};
  for (const key in weightTable) {
    const count = weightTable[key];

    // 같은 무게끼리의 짝꿍 찾아주기
    answer += (count * (count - 1)) / 2;

    // 다른 무게끼리의 짝꿍 찾아주기
    for (let i = 2; i <= 4; i++) {
      if (newWeightTable.hasOwnProperty(key * i)) {
        answer += count * newWeightTable[key * i];
        newWeightTable[key * i] += count;
      } else newWeightTable[key * i] = count;
    }
  }

  return answer;
}
