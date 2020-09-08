/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
    const str_arr = str.split(' ');
    var dict = {}, dict2 = {};
    if(str_arr.length !== pattern.length) return false
    for(let i = 0; i<str_arr.length; i++){
        if(dict[pattern[i]] == undefined && dict2[str_arr[i]] == undefined) {
            dict[pattern[i]] = str_arr[i]; 
            dict2[str_arr[i]] = pattern[i];
        }
        else if(dict[pattern[i]] === str_arr[i] && dict2[str_arr[i]] === pattern[i]) continue;
        else return false;        
    }
    return true;
};