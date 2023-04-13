function solution(s) {
  const arr = [
    'zero',
    'one',
    'two',
    'three',
    'four',
    'five',
    'six',
    'seven',
    'eight',
    'nine',
  ];

  let temp = '';
  const str = s
    .split('')
    .reduce((acc, val) => {
      if (Number.parseInt(val) >= 0) return [...acc, val];

      temp += val;
      if (arr.includes(temp)) {
        const num = arr.indexOf(temp);
        temp = '';
        return [...acc, num.toString()];
      }

      return acc;
    }, [])
    .join('');

  return Number.parseInt(str);
}

// split, join 활용한 깔끔한 풀이
function solution(s) {
  let numbers = [
    'zero',
    'one',
    'two',
    'three',
    'four',
    'five',
    'six',
    'seven',
    'eight',
    'nine',
  ];
  var answer = s;

  for (let i = 0; i < numbers.length; i++) {
    let arr = answer.split(numbers[i]);
    answer = arr.join(i);
  }

  return Number(answer);
}
