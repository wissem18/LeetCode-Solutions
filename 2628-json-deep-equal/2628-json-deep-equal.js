/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
function helper(key, value) {
    if (value && typeof value === "object" && !Array.isArray(value))
        return Object.fromEntries(Object.entries(value).sort());
    else
        return value;
}
var areDeeplyEqual = function(o1, o2) {
      const O1 = JSON.stringify(o1, helper);
    const O2 = JSON.stringify(o2, helper);

    return O1 === O2;
};