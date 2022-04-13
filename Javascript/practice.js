const bestsum = (targetsum,  numbers) => {
    const table = Array(targetsum +1).fill(null);
    table[0] = [];
    //j = 0;
    for (let i = 0; i <= targetsum  ; i++) {
        if (table[i] !== null) {
            for (let num of numbers) {
                const combination = [...table[i], num];
                if (!table[i + num] || table[i + num].length > combination.length)
                 table[i + num] = combination;
                //  if (table[targetsum] !== targetsum ) {
                //      j++;
                //  }
                //  if (table[targetsum + j] === targetsum + j )
                //  return table[targetsum + j];
            }
        }
    }
    return table[targetsum];
}

console.log(bestsum(8, [2]));