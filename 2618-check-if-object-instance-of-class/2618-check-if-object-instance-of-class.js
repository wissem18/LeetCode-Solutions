/**
 * @param {any} object
 * @param {any} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if(obj===null || obj === undefined || typeof classFunction!=="function")
        return false;
    let x=obj;
    if(typeof obj!=="object")
        x=Object(obj);
    return x instanceof classFunction;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */