/**
 * @param {Array} arr
 * @return {Matrix}
 */
const helper = (ele, path, object, columns) => {
  if (ele != null && typeof ele == "object") {
    Object.entries(ele).forEach(([key, value]) =>
     helper(value, path + (path ? "." : "") + key, object, columns)
    )
  } else {
    object[path] = ele
    columns.add(path)
  }
  return object
}
var jsonToMatrix = function(arr) {
     const matrix = []
  const columns = new Set()

  arr = arr.map((ele) => helper(ele, "", {}, columns))
  matrix.push([...columns].sort())

  const columnsIdx = matrix[0].reduce(
    (acc, cur, idx) => ((acc[cur] = idx), acc),
    {}
  )

  arr.forEach((ele) => {
    matrix.push(Array(columns.size).fill(""))
    Object.entries(ele).forEach(([key, value]) => (matrix.at(-1)[columnsIdx[key]] = value))
  })

  return matrix
};