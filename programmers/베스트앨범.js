// 가장 많이 재생된 장르
// 많이 재생된 노래
// 오름차순

function solution(genres, plays) {
    const answer = [];
    const dict = {};
    [...(new Set(genres))].forEach(e => dict[e]=0);
    genres.forEach((elem,idx) => dict[elem]+=plays[idx]);

    const items = Object.keys(dict).sort((a,b) => dict[b] - dict[a]);
    items.forEach(cur => {
        const tmp = {};
        genres.foreach((genre,idx)=>{
            if(genre == cur)
                tmp[idx] = plays[idx];            
        });
        const arr = Object.keys(tmp).sort((a,b) => tmp[b]-tmp[a]);
        arr.filter((e,idx)=>idx<2).forEach(e => answer.push(parseInt(e)));    
    })
    return answer;
}

//console.log(solution(['classic', 'pop', 'classic', 'classic', 'pop'], [500, 600, 150, 800, 2500]))