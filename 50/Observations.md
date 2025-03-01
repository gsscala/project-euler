# Consecutive Prime Sum

### In order to find the primes, I used the algorithm [Sieve of Eratosthenes](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html).  

### Then I just decided to brute force through them, using a two-pointers technique, which nets me an O(n²) solution.  

### However, what is n here? It's actually the quantity of prime numbers in the considered interval. For something like 1e6, it's [78,498](https://t5k.org/howmany.html), whose square is about 6e9, which is fast enough.  
