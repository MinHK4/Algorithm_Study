// 문자열 정렬하기
function sortAlphabets(text){
  return text.split('').sort().join('')
}

// 문자의 배열을 받아서 주어진 길이로 구성된 문자 조합 배열 돌려주기
function getCombi(arr, num){
  const results = []
  if(num === 1)
      return arr.map(el => [el])
  
  arr.forEach((fixed, idx, org)=> {
      const rest = org.slice(idx+1)
      const combi = getCombi(rest, num-1)
      const attached = combi.map(el => [fixed, ...el])
      results.push(...attached)
  })
  return results
}

function solution(orders, course) {
  var answer = [];
  
  // 문자 길이에 따라서 반복문 돌리면서
  for(num of course){
      
      // 해당 길이에 해당하는 문자 조합별 주문 횟수 카운트 해주고
      var cntTable = {}
      var max = 0
      for(const order of orders){
          const temp = sortAlphabets(order)
          const numStrList = getCombi(temp.split(''), num)
          
          for(const list of numStrList){
              const str = list.join('')
              if(!(str in cntTable))
                  cntTable[str] = 0
              cntTable[str]++
              max = Math.max(max, cntTable[str])
          }
      }
      
      // 그 중 2번 이상 나온 가장 많은 문자 조합들 쌓아주기
      for(key in cntTable){
          if(cntTable[key] === max && cntTable[key] >= 2)
              answer.push(key)
      }
  }
  answer.sort()
  
  return answer;
}