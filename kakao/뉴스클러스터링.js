// 자카드 유사도
// 교집합크기 / 합집합크기
// 공집합의 경우 1
const _makeToken = (str, obj) => {
  for(let i=0; i<str.length-1; i++) {
      const token = str.substr(i,2).toUpperCase();
      const regexp = /[A-Z]{2}/;
      if(!regexp.test(token)) continue;
      if(obj[token]) obj[token]++;
      else obj[token] = 1;
  }
}
const _makeUnion = (A, B, Union) => {
  Object.keys(A).forEach((key) => {
      if(Union[key]) Union[key] = Math.max(A[key], Union[key]);
      else Union[key] = A[key];
  })
  Object.keys(B).forEach((key) => {
      if(Union[key]) Union[key] = Math.max(B[key], Union[key]);
      else Union[key] = B[key];
  })
}
const _makeIntersection = (A, B, Intersection) => {
  Object.keys(A).forEach((key) => {
      if(B[key]) Intersection[key] = Math.min(A[key], B[key]);
  })
}
function solution(str1, str2) {
  const A={}, B= {}, Intersection={}, Union={};    
  _makeToken(str1,A);
  _makeToken(str2,B);
  _makeUnion(A,B,Union);
  _makeIntersection(A,B,Intersection);
  const intersectionVal = Object.keys(Intersection).reduce((acc,cur) => acc + Intersection[cur], 0);
  const unionVal = Object.keys(Union).reduce((acc,cur) => acc+Union[cur],0);
  if(unionVal === 0) return 65536;
  return parseInt((intersectionVal/unionVal)*65536);
}