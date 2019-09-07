//N개의 stage개수, 각 도달한 위치가 적힌 stages배열
//정렬 문제

function solution(N, stages) {
    let fail = Array(N+2).fill(0);
    let total = Array(N+2).fill(0);
    stages.forEach((stage,idx) => {
        fail[stage]++;
        for(let i=1; i<=stage; i++) total[i]++;
    });
    const result = fail.map((e,idx) => {
        if(total[idx]) return [e/total[idx], idx];
        else return [0, idx];
    }).slice(1,N+1);
    result.sort((a,b) => {
        if(a[0]===b[0]) return a[1]-b[1];
        return b[0]-a[0];
    });
    return result.map(e => e[1]);
}