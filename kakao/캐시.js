function solution(cacheSize, cities) {
    let cache = [];
    let sum = 0;
    //if(cacheSize===0) return 5*cities.length;
    cities.forEach(element => {
        const target = element.toLowerCase();
        if(cache.includes(target)){
            sum+=1;
            cache = cache.filter(e => e!==target);
            cache.push(target);
        } else if(cache.length < cacheSize) {
            sum+=5;
            cache.push(target);
        } else if(cacheSize > 0){
            sum+=5;
            cache.shift();
            cache.push(target);
        } else {
            sum+=5;
        }
    });
    return sum;
}