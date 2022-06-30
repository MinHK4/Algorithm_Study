//https://programmers.co.kr/learn/courses/30/lessons/72410?language=javascript

function solution(new_id) {
  var answer = '';
  
  answer = new_id
  
  // 1단계 소문자로 바꾸기
  answer = answer.toLowerCase()
  
  // 2단계 특수 문자 제거
  var temp = ''
  for(var i=0; i<answer.length; i++){
      var cn = answer.charCodeAt(i)
      if((97 <= cn && cn <= 122) || (48 <= cn && cn <= 57) ||
         answer[i] === '-' || answer[i] === '_' || answer[i] === '.')
          temp += answer[i]
  }
  answer = temp
  
  // 3단계 연속 마침표 하나로 변환
  while(answer.includes('..')){
      answer = answer.replace(/\.\./gi, '.')
  }
  
  // 4단계 마침표 처음과 끝에 없애기
  if(answer[0] === '.')
      answer = answer.substring(1)
  if(answer[answer.length-1] == '.')
      answer = answer.slice(0, -1)
  
  // 5단계 빈 문자열 시 a 대입
  if(answer === '')
      answer = 'a'
  
  // 6단계 길이 15개로 맞추기 + 마지막 마침표 다시 한번 제거
  if(answer.length > 15){
      console.log(answer.length)
      answer = answer.substring(0, 15)
      if(answer[answer.length-1] === '.')
          answer = answer.slice(0, -1)
  }
  
  // 7단계
  while(answer.length <= 2)
      answer += answer[answer.length-1]
  
  // console.log(answer)
  return answer;
}

/*
정규표현식을 이용한 풀이... 지림...

function solution(new_id) {
  const answer = new_id
      .toLowerCase() // 1
      .replace(/[^\w-_.]/g, '') // 2
      .replace(/\.+/g, '.') // 3
      .replace(/^\.|\.$/g, '') // 4
      .replace(/^$/, 'a') // 5
      .slice(0, 15).replace(/\.$/, ''); // 6
  const len = answer.length;
  return len > 2 ? answer : answer + answer.charAt(len - 1).repeat(3 - len);
}
*/