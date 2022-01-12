/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(base, power) {
      if (power < 0) {
    return 1 / powBinary(base, -power)
  }
  
  return powBinary(base, power)
};


function powBinary(base, power) {
  if (power === 0) return 1
  if (power === 1) return base
  
  const halfRes = myPow(base, Math.floor(power / 2))
  return power % 2 == 0 ? halfRes * halfRes : halfRes * halfRes * base
}