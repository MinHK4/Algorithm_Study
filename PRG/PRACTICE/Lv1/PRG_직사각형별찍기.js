// https://school.programmers.co.kr/learn/courses/30/lessons/12969

process.stdin.setEncoding('utf8');
process.stdin.on('data', (data) => {
  let [a, b] = data.split(' ');

  while (b--) {
    console.log('*'.repeat(a));
  }
});
