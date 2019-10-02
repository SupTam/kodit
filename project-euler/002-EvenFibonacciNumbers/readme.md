# Even Fibonacci Numbers

### Question

*   https://projecteuler.net/problem=002
*   https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem

do, the question is we would like to find the sum of even Fibonacci numbers at the last value X which is less than N.

For example, let's N = 10 and the fibonacci list is 1,(2),3,5,(8),13, ... where number in () is the even fibonacci.
Hence, X is 8, where 8 < N.

#### First try

So, I approached this method by listing Fibonacci numbers directly as we know that.

> Fn = Fn-1 + Fn-3
* Fn is current fibonacci number
* Fn-1 is a fibonacci before current for 1 step.
* Fn-2 is ta fibonacci before current for 2 steps.
therefore, I directly calculate each fibonacci.

**in solution-1.cpp**
```cpp
    int f1 = 1; int f2 = 2;
    int fn = 3;
    int sum = 2;
    while (fn < N ){
        if (fn%2 == 0){
            sum += fn;
        }
        int temp = f2;
        f2 = fn;
        f1 = temp;
        fn = f1 + f2;
    }
```
voilà, It worked. But, It is not very efficient at all. It need to calculate fibonacci one by one. Well, There's another way to do that if we studied this topic in Math class in high school.

#### Second try
So, we know that Fn = Fn-1 + Fn-2. We also know that Fn-1 = Fn-2 + Fn-3. Therefore, We won't need to calculate one by one. But, Skip to calculate even Fibonacci only by using its property. How?
``` 
    1, (2), 3, 5, (8), 13, 21, (34) , 55, 89, (144), ....
```
We noticed that even Fibonacci happens in every three steps after each. Why? because property of odd + odd = even. And even + odd = odd, this makes the Fibonacci has even Fibonacci in every three steps. Which means, we can refer even Fibonacci by each its even number for three steps. Therefore, we can try to make a new formula.
```
    Fn = [ Fn-1 ] + Fn-2
    Fn = [ Fn-2 + Fn-3 ] + Fn-2
    Fn = Fn-3 + 2 ( Fn-2 )
    Fn = Fn-3 + 2 ( Fn-3 + Fn-4 )
    Fn = 3Fn-3 + 2 Fn-4
    Fn = 3Fn-3 + Fn-4 + Fn-5 + Fn-6
    Fn = 3Fn-3 + Fn-3 + Fn-6
    Fn = 4Fn-3 + Fn-6
```
therefore, we could see that the even fibonacci is equal to its previous 3 step fibonacci times 4 plus its previous 6 step fibonacci.
Here, we could calculate only even Fibonacci. Therefore, we could skip and conclude the formula that 
```
Fen = 4 * Fen-1 + Fen-2
```
so it finalizes the efficient in code as

***solution-2.cpp***
```cpp
    int fn1 = 2; fn2 = 8; // first two even fibonacci numbers.
    int sum = 10;
    int fn = 34; // next even fibonacci number
    while (fn < n){
        sum += fn;
        int temp = f2;
        f2 = fn;
        f1 = f2;
        fn = 4*f2 + f1;
    }
```
