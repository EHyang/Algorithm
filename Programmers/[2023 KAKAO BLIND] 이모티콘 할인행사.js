/**
 * 문제 - https://school.programmers.co.kr/learn/courses/30/lessons/150368
 * 
 * Level 2인데..
 * 
 * 풀이가 너무 더러운듯 하다.
 * 안하려던거 하려니까 풀이 방법이 기억이 나지 않는다.
 * 다른 사람들 풀이를 보니 dfs 방식으로 많이 사용하는거 같은데, 다른 풀이 방법도 생각해봐야겠다.
 * 
 */

/**
 * 몫, 나머지를 리턴해주는 함수
 * 
 * @param {number} x 
 * @param {number} y 
 * @returns {Array<number,number>} [몫, 나머지]
 */
const divmod = (x, y) => [Number.isNaN(x / y) ? 0 : Math.floor(x / y), x % y];

/**
 * n 진수를 만들어주는 function
 * 
 * @param {number} base
 * @param {number} n default 4
 * @returns {string} ' ' 로 구분되는 n진수 리턴
 */
const makeFour = (base, n = 4) => {
	const str = '0123456789ABCDEF';
	const [q, r] = divmod(base, n);
	if (q === 0) return str[r];
	else return makeFour(+q, n) + ' ' + str[r];
}

/**
 * 순서에 맞게 할인가격을 리턴해줌.
 * 
 * @param {string} nx n진수, makeFour 리턴값
 * @param {Array<number>} price 기존 가격 
 * @returns {Array<number, number>} [할인가격, 할인율]
 */
function discountPrice(nx, price) {
	const percent = [10, 20, 30, 40];

	return nx.split(' ').map((v, i) => [price[i] * (100 - percent[v]) / 100, percent[v]]);
}

function solution(users, emoticons) {
	let maxPlus = 0, maxVal = 0;

	const Max = Math.pow(4, emoticons.length);

	for (let i = 0; i < Max; i++) {
		let plus = 0, total = 0;
		const val = discountPrice(makeFour(i), emoticons);

		for (let j = 0; j < users.length; j++) {
			let personalTotal = 0;
			const [d, v] = users[j];

			val.map(([dc, p]) => {
				if (p >= d) personalTotal += dc;
			});

			if (personalTotal >= v) {
				plus++;
				continue;
			} else {
				total += personalTotal;
			}
		}

		if (plus > maxPlus) {
			maxPlus = plus;
			maxVal = total;
		} else if (plus == maxPlus) {
			maxVal = maxVal > total ? maxVal : total
		}
	}

	return [maxPlus, maxVal];
}

const us = [[40, 2900], [23, 10000], [11, 5200], [5, 5900], [40, 3100], [27, 9200], [32, 6900]];
const emt = [1300, 1500, 1600, 4900];

solution(us, emt)