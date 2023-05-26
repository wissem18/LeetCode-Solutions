/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    let ans=[];
    const rec=(a,l)=>{
        for(const element of a){
            if(Array.isArray(element)&&l>0)
                rec(element,l-1);
            else
                ans.push(element);
        }
    }
    rec(arr,n);
    return ans;
};