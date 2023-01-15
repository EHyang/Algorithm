/**
 * 문제 - https://school.programmers.co.kr/learn/courses/30/lessons/92335
 * 
 * 조금만 JS 스럽게..
 * 
 * num.toString(n) => n진수로 바꿔줌.. 이걸 왜 생각...안해?
 * 
 * 
테스트 1 〉	통과 (105.73ms, 37.9MB)
테스트 2 〉	통과 (0.14ms, 33.5MB)
테스트 3 〉	통과 (0.07ms, 33.5MB)
테스트 4 〉	통과 (0.14ms, 33.6MB)
테스트 5 〉	통과 (0.11ms, 33.4MB)
테스트 6 〉	통과 (0.11ms, 33.4MB)
테스트 7 〉	통과 (0.07ms, 33.5MB)
테스트 8 〉	통과 (0.06ms, 33.5MB)
테스트 9 〉	통과 (0.08ms, 33.5MB)
테스트 10 〉	통과 (0.07ms, 33.6MB)
테스트 11 〉	통과 (0.15ms, 33.5MB)
테스트 12 〉	통과 (0.07ms, 33.6MB)
테스트 13 〉	통과 (0.07ms, 33.6MB)
테스트 14 〉	통과 (0.12ms, 33.6MB)
테스트 15 〉	통과 (0.07ms, 33.6MB)
테스트 16 〉	통과 (0.07ms, 33.5MB)
 */

function isPrime(num) {
  if (num <= 1) return false;

  if (num & 2 === 0) {
    return num === 2 ? true : false;
  }

  for (let i = 3; i <= parseInt(Math.sqrt(num)); i += 2) {
    if (num % i === 0) return false;
  }

  return true;
}

const solution = (n, k) => n.toString(k).split('0').filter(it => isPrime(it)).length;

const inputN = 437674, inputK = 3;

solution(inputN, inputK);