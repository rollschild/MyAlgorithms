/*
 * Nov 23, 2018
 * Tree sort in JavaScript
 */

let Node = function(val) {
  this.value = val;
  this.left = null;
  this.right = null;
};

let plant = function(key, node) {
  if (node === null) {
    node = new Node(key);
    return node;
  }
  if (key < node.value) node.left = plant(key, node.left);
  else node.right = plant(key, node.right);

  return node;
};

let harvest = function(node, sorted_arr = []) {
  if (node === null) return;
  harvest(node.left, sorted_arr);
  sorted_arr.push(node.value);
  harvest(node.right, sorted_arr);
};

let treeSort = function(arr) {
  if (arr.length === 0) return [];
  let seed = null;
  let root = plant(arr[0], seed);
  for (let i = 1; i < arr.length; i++) {
    plant(arr[i], root);
  }
  let sorted = []
  harvest(root, sorted);
  return sorted;
};

// let sorted = treeSort([2037, -1, 5, 4, 100, 4]);
// console.log(sorted);
console.log(treeSort([2037, -1, 5, 4, 100, 4]));
