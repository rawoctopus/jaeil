function solution(operations) {
    const arr = [];
    operations.forEach(op => {
        if(op[0] === 'I') arr.push(+op.split(' ')[1])
        else {
            if(!arr.length) return
            const target = (op[2] === '-'? Math.min : Math.max)(...arr)
            const idx = arr.findIndex(e => e === target)
            arr.splice(idx,1)
        }
    })
    return (arr.length) ? ([Math.max(...arr), Math.min(...arr)]) : ([0,0])
}