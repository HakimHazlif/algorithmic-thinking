#define hashsize(n) ((unsigned long)1 << (n))
// This operator expresses 2^n
#define hashmask(n) (hashsize(n) - 1)
// Whatever the output of hashsize, subtract 1 from it.


unsigned long oaat(char *key, unsigned long len, unsigned long bits) {
    unsigned long hash, i;

    for (hash = 0, i = 0; i < len; i++) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash & hashmask(bits);
}

// Let's consider this input "abc"
// The ASCII values are: 'a' = 97, 'b' = 98, and 'c' = 99.
//
// The initial value of hash is 0.
//
// Since the length of the key is 3, the loop executes three times (once for each character).
//
// 1. Add the ASCII value of the current character to hash.
//
// 2. Shift the binary representation of hash 10 bits to the left.
//    This is equivalent to multiplying hash by 2^10 (1024), assuming no overflow.
//
//    Examples:
//    1    = 1            -> 10000000000      = 1024
//    3    = 11           -> 110000000000     = 3072
//    5    = 101          -> 1010000000000    = 5120
//
// 3. Shift the current hash value 6 bits to the right.
//    This is approximately equivalent to integer division by 2^6 (64).
//
//    Examples:
//    1024 = 10000000000  -> 10000            = 16
//    1280 = 10100000000  -> 10100            = 20
//
// 4. XOR the current hash with its shifted version:
//
//        hash ^= (hash >> 6);
//
//    This is equivalent to:
//
//        hash = hash ^ (hash >> 6);
//
//    XOR compares each pair of bits:
//      0 ^ 0 = 0
//      1 ^ 1 = 0
//      1 ^ 0 = 1
//      0 ^ 1 = 1
//
//    Examples:
//    17 ^ 12
//      10001
//    ^ 01100
//    -------
//      11101 = 29
//
//    17 ^ 13
//      10001
//    ^ 01101
//    -------
//      11100 = 28
// After all characters have been processed, perform three final mixing steps.
//
// 5. Shift hash 3 bits to the left.
//    This is equivalent to multiplying by 2^3 (8).
//
//    Examples:
//    1 = 1    -> 1000   = 8
//    5 = 101  -> 101000 = 40
//
// 6. Shift hash 11 bits to the right.
//    This is approximately equivalent to integer division by 2^11 (2048).
//
//    Examples:
//    1024  = 10000000000      -> 0    = 0
//    3000  = 101110111000     -> 1    = 1
//    8000  = 1111101000000    -> 11   = 3
//    20200 = 100111011101000  -> 1001 = 9
//
// 7. Shift hash 15 bits to the left.
//    This is equivalent to multiplying by 2^15 (32768).
//
//    Examples:
//    3 = 11
//    -> 11000000000000000 = 98304
//
//    9 = 1001
//    -> 1001000000000000000 = 294912
//
// Finally, return:
//
//      hash & hashmask(bits);
//
// The '&' operator is the bitwise AND operator.
//
// Unlike XOR, a bit is 1 only if both corresponding bits are 1:
//
//      1 & 1 = 1
//      1 & 0 = 0
//      0 & 1 = 0
//      0 & 0 = 0
//
// Examples:
//
//    17 & 12
//      10001
//    & 01100
//    -------
//      00000 = 0
//
//    17 & 13
//      10001
//    & 01101
//    -------
//      00001 = 1
//
// This final AND operation applies the hash mask, ensuring the returned
// value is in the range [0, 2^bits - 1], making it a valid index into
// a hash table with 2^bits buckets.





