/**
 * 문제 - https://school.programmers.co.kr/learn/courses/30/lessons/92335
 * 
 * 쉬운 문제였으나, js 이점을 많이 살리지 못함.
 * 
 * 
 * 
테스트 1 〉	통과 (64.00ms, 37.8MB)
테스트 2 〉	통과 (0.12ms, 33.5MB)
테스트 3 〉	통과 (0.13ms, 33.5MB)
테스트 4 〉	통과 (0.20ms, 33.5MB)
테스트 5 〉	통과 (0.13ms, 33.5MB)
테스트 6 〉	통과 (0.30ms, 33.6MB)
테스트 7 〉	통과 (0.34ms, 33.5MB)
테스트 8 〉	통과 (0.26ms, 33.5MB)
테스트 9 〉	통과 (0.20ms, 33.5MB)
테스트 10 〉	통과 (0.12ms, 33.6MB)
테스트 11 〉	통과 (0.27ms, 33.5MB)
테스트 12 〉	통과 (0.19ms, 33.1MB)
테스트 13 〉	통과 (0.23ms, 33.5MB)
테스트 14 〉	통과 (0.17ms, 33.5MB)
테스트 15 〉	통과 (0.18ms, 33.5MB)
테스트 16 〉	통과 (0.16ms, 33.5MB)
 */



function isPrime(num) {
  // 소수는 1이상의 자연수. 1은 아님
  if (num <= 1) return false;

  // 짝수일 경우 소수가 아님. but, 2는 소수
  if (num & 2 === 0) {
    return num === 2 ? true : false;
  }

  // 아리스토테네스의 체
  const sqrt = parseInt(Math.sqrt(num));
  for (let i = 3; i <= sqrt; i += 2) {
    if (num % i === 0) return false;
  }

  return true;
}

const divmod = (x, y) => [Number.isNaN(x / y) ? 0 : Math.floor(x / y), x % y];

const makeFour = (base, n = 4) => {
  const str = '0123456789ABCDEF';
  const [q, r] = divmod(base, n);
  if (q === 0) return str[r];
  else return makeFour(+q, n) + str[r];
}

const solution = (n, k) => {
  let answer = 0;

  makeFour(n, k).split('0').map(it => {
    if (isPrime(it)) answer++;
  });

  return answer;
}

const inputN = 437674, inputK = 3;

solution(inputN, inputK);