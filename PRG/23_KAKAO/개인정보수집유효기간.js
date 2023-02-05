// https://school.programmers.co.kr/learn/courses/30/lessons/150368

function solution(today, terms, privacies) {
  var answer = [];

  const termMap = new Map();
  terms.forEach((term) => {
    const [type, month] = term.split(' ');
    termMap.set(type, Number(month));
  });

  const [y, m, d] = today.split('.').map((val) => Number(val));
  const todayNum = y * 10000 + m * 100 + d;

  privacies.forEach((privacy, idx) => {
    const [startDate, type] = privacy.split(' ');
    const expireDate = addDate(startDate, termMap.get(type));

    if (expireDate <= todayNum) {
      answer.push(idx + 1);
    }
  });

  return answer;
}

const addDate = (dateStr, term) => {
  const [year, month, day] = dateStr.split('.').map((val) => Number(val));

  const newMonth = (month + term) % 12;
  const newYear =
    year + (newMonth === 0 ? -1 : 0) + Math.floor((month + term) / 12);

  return newYear * 10000 + (newMonth === 0 ? 12 : newMonth) * 100 + day;
};
