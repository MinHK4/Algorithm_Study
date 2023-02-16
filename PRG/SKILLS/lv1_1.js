function solution(n, arr1, arr2) {
  var answer = [];

  const bin1 = arr1.map((el) => {
    let str = '';
    let cur = el;
    while (el) {
      str += el % 2 ? '1' : '0';
      el = Math.floor(el / 2);
    }
    while (str.length !== n) {
      str += '0';
    }

    return [...str].reverse().join('');
  });

  const bin2 = arr2.map((el) => {
    let str = '';
    let cur = el;
    while (el) {
      str += el % 2 ? '1' : '0';
      el = Math.floor(el / 2);
    }
    while (str.length !== n) {
      str += '0';
    }

    return [...str].reverse().join('');
  });

  return bin1.map((str, idx) => {
    let newStr = '';
    for (let i = 0; i < n; i++) {
      if (str[i] === '1' || bin2[idx][i] === '1') newStr += '#';
      else newStr += ' ';
    }
    return newStr;
  });
}
