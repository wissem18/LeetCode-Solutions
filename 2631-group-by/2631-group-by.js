/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    let res=new Object();
    for(let e of this){
        const x=fn(e);
      if( Object.keys(res).includes(x))
          res[x].push(e);
      else
          res[x]=[e];
    }
    return res;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */