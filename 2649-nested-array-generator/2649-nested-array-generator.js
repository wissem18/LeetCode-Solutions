/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function*(arr) {
    if(!Array.isArray(arr)){//if the element is a number yield the number 
        yield arr;
        return;
    }
    //if it's an array traverse it's content 
    for(let i=0;i<arr.length;i++){
        yield* inorderTraversal(arr[i]);
    }
};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */