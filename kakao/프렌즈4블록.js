function solution(m, n, board) {
    board = board.map(e => e.split(""));
    while(true) {
        let founded = [];
        for(let i=1; i<m; i++)
            for(let j=1; j<n; j++){
                const tmp = board[i][j]
                if(tmp && tmp===board[i-1][j] && tmp===board[i][j-1] && tmp===board[i-1][j-1])
                    founded.push([i,j]);
            }
        if(!founded.length) return [].concat(...board).filter(v=>!v).length;                    
        founded.forEach(pos => {
            board[pos[0]][pos[1]] = 0;
            board[pos[0]-1][pos[1]] = 0;
            board[pos[0]][pos[1]-1] = 0;
            board[pos[0]-1][pos[1]-1] = 0;
        })
        for(let r=m-1; r>0; r--) {
            if(!board[r].some(v=>!v)) continue;
            for(let c=0; c<n; c++){
                if(board[r][c]) continue;
                for(let k=r-1; k>=0; k--) {
                    if(board[k][c]){
                        board[r][c] = board[k][c];
                        board[k][c] = 0;
                        break;
                    }                    
                }
            }                    
        }               
    }

}