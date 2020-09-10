/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function (version1, version2) {
  const v1 = version1.split(".").map((str) => parseInt(str));
  const v2 = version2.split(".").map((str) => parseInt(str));

  for (let i = 0; i < Math.max(v1.length, v2.length); i++) {
    const currV1 = v1[i] || 0;
    const currV2 = v2[i] || 0;

    console.log(currV1, currV2);

    if (currV1 > currV2) return 1;
    if (currV1 < currV2) return -1;
  }

  return 0;
};
