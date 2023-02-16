function solution(places) {
  return places.map((place) => {
    let flag = true;
    for (let i = 0; i < 5 && flag; i++) {
      for (let j = 0; j < 5 && flag; j++) {
        if (place[i][j] === 'P') {
          if (isValid(i - 1, j) && place[i - 1][j] === 'P') flag = false;
          if (isValid(i + 1, j) && place[i + 1][j] === 'P') flag = false;
          if (isValid(i, j - 1) && place[i][j - 1] === 'P') flag = false;
          if (isValid(i, j + 1) && place[i][j + 1] === 'P') flag = false;

          if (
            isValid(i - 2, j) &&
            place[i - 1][j] === 'O' &&
            place[i - 2][j] === 'P'
          )
            flag = false;
          if (
            isValid(i + 2, j) &&
            place[i + 1][j] === 'O' &&
            place[i + 2][j] === 'P'
          )
            flag = false;
          if (
            isValid(i, j - 2) &&
            place[i][j - 1] === 'O' &&
            place[i][j - 2] === 'P'
          )
            flag = false;
          if (
            isValid(i, j + 2) &&
            place[i][j + 1] === 'O' &&
            place[i][j + 2] === 'P'
          )
            flag = false;

          if (
            isValid(i - 1, j - 1) &&
            (place[i - 1][j] === 'O' || place[i][j - 1] === 'O') &&
            place[i - 1][j - 1] === 'P'
          )
            flag = false;
          if (
            isValid(i - 1, j + 1) &&
            (place[i - 1][j] === 'O' || place[i][j + 1] === 'O') &&
            place[i - 1][j + 1] === 'P'
          )
            flag = false;
          if (
            isValid(i + 1, j - 1) &&
            (place[i + 1][j] === 'O' || place[i][j - 1] === 'O') &&
            place[i + 1][j - 1] === 'P'
          )
            flag = false;
          if (
            isValid(i + 1, j + 1) &&
            (place[i + 1][j] === 'O' || place[i][j + 1] === 'O') &&
            place[i + 1][j + 1] === 'P'
          )
            flag = false;
        }
      }
    }

    return flag ? 1 : 0;
  });

  function isValid(i, j) {
    return 0 <= i && i < 5 && 0 <= j && j < 5 ? true : false;
  }
}
