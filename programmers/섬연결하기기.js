// MST 알고리즘
// 가장 많이 사용하는 크루스칼 알고리즘 적용

function solution(n, costs) {
    const uf = Array(n).fill().map((val,idx)=>idx);
    function find(a){
        if(uf[a] === a) return a;
        return uf[a] = find(uf[a]);
    }
    function merge(_a,_b){
        const a = find(_a);
        const b = find(_b);
        if(a===b) return false;
        uf[b] = a;
        return true;
    }
    costs.sort((first,second) => second[2] - first[2]); //내림차순
    let cnt=0, result = 0;
    for(let i=0; ;i++){
        let cur = costs.pop(); //가장 뒤 = 가장 작음
        if(merge(cur[0],cur[1])){
            result+=cur[2];
            if(++cnt === n-1) break;
        }
    }
    //console.log(result);
    return result;
}
//solution(4,[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]);