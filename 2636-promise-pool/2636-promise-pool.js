/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    async function exnext(){
        if(functions.length===0)
            return ;
        const cur=functions.shift();
        await cur();
        await exnext();
    }
    const ppool=Array(n).fill().map(exnext);
    await Promise.all(ppool);
};
 
/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */