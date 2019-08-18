//비트연산자 활용
//유일성 + 최소성 검사
function solution(relation) {
  const COL = relation[0].length;
  const ROW = relation.length;
  const set = new Set();

  //최소성 검사
  for(let i=1; i< 1<<COL; i++) {
      const tmp = new Set();
      for(let row=0; row<ROW; row++) {
          let key = [];
          for(let pick=0; pick<COL; pick++)
              if(i & (1<<pick)) key.push(relation[row][pick]);
          tmp.add(String(key));
      }
      if(tmp.size === ROW) set.add(i);
  }

  //유효성 검사
  for(let i of set) {
      for(let j of set) {
          if(i>=j) continue;
          if((i&j) === i) set.delete(j);
      }
  }
  return set.size;
}