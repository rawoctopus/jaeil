// 총 3번의 기회
// 각 기회마나 0~10까지 점수 획득 가능
// S=1제곱, D=2제곱, T=3제곱 
// *=점수2배&전점수2배, #=마이너스
// *=첫번째인 경우, 첫번째 스타상 점수만 2배

//
const Bonus = {S:1, D:2, T:3};
const Option = {'*':2, '#':-1};

const action = (arr, score, bonus, option) => {
    score = parseInt(score);
    if(!(/[\*\#]/.test(option)))
        return [...arr, Math.pow(score,Bonus[bonus])]        
    const cur = Math.pow(score,Bonus[bonus]) * Option[option];
    if(option === '*') arr[arr.length-1] = arr[arr.length-1]*2;
    return [...arr, cur];    
}

function solution(dartResult) {    
    const re = /([0-9]+[SDT][#*]?)([0-9]+[SDT][#*]?)([0-9]+[SDT][#*]?)/;
    const arr = dartResult.replace(re, '$1,$2,$3');
    const result = arr.split(',').reduce((acc,cur) => {
        const tmpre = /([0-9]+)([SDT])([*#])?/
        const [score, bonus, option] = cur.replace(tmpre, '$1,$2,$3').split(',');
        return action(acc, score, bonus, option);
    },[])
    //console.log(result);
    return result.reduce((acc,cur)=>acc+cur);
}
solution('1S2D*3T');