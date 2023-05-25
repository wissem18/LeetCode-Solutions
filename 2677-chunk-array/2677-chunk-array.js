/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    const ans=[];
    let cur=[];
    for (const e of arr) {
        if(cur.length===size){
            ans.push(cur);
            cur=[];
        }
        cur.push(e);
    }
    if(cur.length>0)
        ans.push(cur);
    return ans;
};
