/**
 * 문제 - https://school.programmers.co.kr/learn/courses/30/lessons/92341
 * 
 * 조금 더 js 스럽게
 */

const records = ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"];
const fees = [180, 5000, 10, 600];


function solution(fees, records) {
	const answer = [];
	const totalTime = {};
	const pay = {};

	records.map((it) => {
		const [clock, car, entrance] = it.split(' ');
		const [h, m] = clock.split(':');

		const time = +h * 60 + +m;

		if (!pay[car]) pay[car] = 0;

		if (entrance === 'IN') {
			totalTime[car] = time;
		} else if (entrance === 'OUT') {
			pay[car] += time - totalTime[car];
			delete totalTime[car];
		}
	});

	// 출차하지 않은 차량들 정리
	Object.keys(totalTime).map((it) => {
		pay[it] += 1439 - totalTime[it];
	});

	Object.entries(pay).map(([c, t]) => {
		answer.push([c, t <= fees[0] ? fees[1] : Math.ceil((t - fees[0]) / fees[2]) * fees[3] + fees[1]]);
	});

	return answer.sort((a, b) => a[0] - b[0]).map(it => it[1]);
}

console.log(solution(fees, records))
