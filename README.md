# ascii
Big-Fingered Keyboard Input

### Installation
```
make
./ascii.app
```

### Usage
Output a character by ASCII number.

Keys:
* `J` position 1 / position 5
* `K` position 2 / position 6
* `L` position 3 / position 7
* `;` position 4 / position 8
* `SPACE` advance positions by 4 / submit char
* `'` reset current character to 0 (i.e. reset positions)

### Example
Input sequence: `K` `SPACE` `K` `;` `SPACE` --> `0100` `0101` --> `E`
