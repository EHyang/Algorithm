/**
 * 문제 - https://school.programmers.co.kr/learn/courses/30/lessons/84512
 * 
 * 그냥.. 완탐... 별로다..
 * 
테스트 1 〉	통과 (8.51ms, 37.1MB)
테스트 2 〉	통과 (6.20ms, 37.2MB)
테스트 3 〉	통과 (7.04ms, 37.2MB)
테스트 4 〉	통과 (8.98ms, 37.1MB)
테스트 5 〉	통과 (7.75ms, 37.2MB)
테스트 6 〉	통과 (8.48ms, 37.1MB)
테스트 7 〉	통과 (6.55ms, 37.3MB)
테스트 8 〉	통과 (6.96ms, 37.1MB)
테스트 9 〉	통과 (9.50ms, 37.2MB)
테스트 10 〉	통과 (7.52ms, 37.3MB)
테스트 11 〉	통과 (9.05ms, 37.2MB)
테스트 12 〉	통과 (8.02ms, 37.2MB)
테스트 13 〉	통과 (6.45ms, 37.3MB)
테스트 14 〉	통과 (6.37ms, 37.1MB)
테스트 15 〉	통과 (9.51ms, 37.2MB)
테스트 16 〉	통과 (8.46ms, 37.2MB)
테스트 17 〉	통과 (8.92ms, 37.2MB)
테스트 18 〉	통과 (7.52ms, 37.2MB)
테스트 19 〉	통과 (6.50ms, 37.1MB)
테스트 20 〉	통과 (10.55ms, 37.2MB)
테스트 21 〉	통과 (9.13ms, 37.3MB)
테스트 22 〉	통과 (10.50ms, 37.2MB)
테스트 23 〉	통과 (6.72ms, 37.2MB)
테스트 24 〉	통과 (6.83ms, 37.1MB)
테스트 25 〉	통과 (10.08ms, 37.2MB)
테스트 26 〉	통과 (7.06ms, 37.2MB)
테스트 27 〉	통과 (12.04ms, 37.2MB)
테스트 28 〉	통과 (7.84ms, 37.1MB)
테스트 29 〉	통과 (6.54ms, 37.2MB)
테스트 30 〉	통과 (7.41ms, 37.1MB)
테스트 31 〉	통과 (12.41ms, 37MB)
테스트 32 〉	통과 (6.79ms, 37.2MB)
테스트 33 〉	통과 (6.54ms, 37.2MB)
테스트 34 〉	통과 (7.13ms, 37.1MB)
테스트 35 〉	통과 (6.67ms, 37.2MB)
테스트 36 〉	통과 (6.37ms, 37.2MB)
테스트 37 〉	통과 (9.24ms, 37.2MB)
테스트 38 〉	통과 (6.99ms, 37.2MB)
테스트 39 〉	통과 (7.36ms, 37.2MB)
테스트 40 〉	통과 (6.40ms, 37.3MB)
 */
const w = ['', 'A', 'E', 'I', 'O', 'U'];

const makeWord = (str) => {
  let res = '';
  str.split('').map(it => {
    res += w[it];
  })

  return res;
}

const solution = (word) => {
  const dic = [];

  let idx = 1;

  while (1) {
    const t = idx.toString(6);

    const str = makeWord(t.padStart(5, '0'));

    dic.push(str);

    if (str === 'UUUUU') break;
    idx++;
  }

  return [... new Set(dic)].sort().indexOf(word) + 1
}


console.log(solution("I"));