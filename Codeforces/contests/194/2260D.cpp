//Signs of Predix Sums

/*
for an aarray of a integers
n

no element is equal to 0 (IMPORTANT)

define the prefix sums as array
p1, p2, ... pn
where p is sum of first i elements of array a

from prefix sums, a string of length n is constructedd

i char is if p1 > 0 , - if pi < 0, 0 if p1 = 0

cost of array a is max |a|

given a string sm, find the min cost of array a
which this string cld be obtained, all elements must be non zero

if impossible -1

t cases
n length
s of length n

sum of n <= 3 * 10^5

we can d a o(n) or O(nlogn) soln
*/