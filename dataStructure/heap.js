class Heap {
  constructor() {
     this.arr = [];
  }
  reheapUp(idx) {
    if (!idx) return;
    const parent = parseInt((idx - 1) / 2);
    if (this.arr[idx] <= this.arr[parent]) return;
    this._swap(idx, parent);
    this.reheapUp(parent);        
  }
  reheapDown(idx) {
    let left = 0, right = 0, large;
    if (idx * 2 + 1 >= this.arr.length) return
    left = this.arr[idx * 2 + 1];
    if (idx * 2 + 2 < this.arr.length - 1) 
      right = this.arr[idx * 2 + 2];      
    large = (left > right)? (idx*2+1) : (idx*2+2)    
    if (this.arr[idx] < this.arr[large]) {
      this._swap(idx,large)
      this.reheapDown(large);
    }    
  }
  insert(number) {    
    this.arr.push(number)
    this.reheapUp(this.arr.length-1);
    return true;
  }
  delete() {
    if (!this.arr.length) return false;  
    const del = this.arr[0];
    this.arr[0] = this.arr.pop();
    this.reheapDown(0);    
    return del;
  }
  _swap(a, b) {
    let temp = this.arr[a];
    this.arr[a] = this.arr[b];
    this.arr[b] = temp;
  }
}