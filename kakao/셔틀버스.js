//9:00 n회 t분 간격 최대 m명 승객
//9:00도착 셔틀에 자리 있으면 9:00에 줄은 선 크루도 탑승 가능
//23:59에 집에 돌아간다
//사무실로 갈 수 있는 제일 늦은 도착시간
//같은 시각 제일 뒤에 선다
function solution(n, t, m, timetable) {
    let table = timetable.map(e => e.split(':').reduce((acc,cur) => acc*60 + cur*1),0);
    table.sort((a,b) => a-b);
    let testarr = [];
    let targetTime = 60*9 + (n-1)*t;
    for(let i=0; i<n-1; i++)
        testarr.push(60*9 + i*t);    
    testarr.forEach(time => {
        for(let i=0; i<m; i++)
            if(table[0] <= time) table.shift();
    })
    let newArr = table.filter(e => e<=targetTime)
    if(newArr.length >= m) {
        targetTime = newArr[m-1] -1;
    }
    const hour = parseInt(targetTime/60)<10? '0'+parseInt(targetTime/60) : ''+parseInt(targetTime/60);
    const min = targetTime%60<10? '0'+targetTime%60 : ''+targetTime%60;
    return `${hour}:${min}`;
}