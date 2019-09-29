# Multiples of 3 and 5

### Question

* https://www.projecteuler.net/problem=1
* https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem

if we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3 5 6 9. the sum of these number is 23. 

write the program that finds the sum of N number.

#### First try
So, I created the for loop that iterates from 1 to N to
find the number which is dividable by 3 or 5. then add to the sum.

**in solution-1.cpp**
```cpp
    int N, sum = 0;
    cin >> N;
    for (int i=0; i<N ; i++) {
        if (i%3 == 0 || i%5 == 0){
             sum += i;
        }
    }
    cout << sum << endl;
```


It worked! But, It is not efficient at all because I tried to run with hackerrank and I was stuck with the test that limits the runtime.

Therefore, It might be some faster solution? So, I tried again.

#### Second try

so, the number which is divisible by 3 to N could be as
```
    value:       3, 6, 9, 12, 15, 16, ... , x
    position:    1, 2, 3, 4, 5, 6, ... , n
    < for the question n = N/3(floor) >
```
which means, we can find the relation of these number, then I found out, we can pull 2 out from the sequence if
```asm
    sum of 3s:  3 + 6 + 9 + 12 + 15 + ... + x
    pull 3 out: 3 (1 + 2 + 3 + 4 + 5 + ... + x/3)
    position:  1  2  3 4 5 6 7 8 9 10 ... n
    // x is the largest dividible below N
```
back to high school (or forward), there is the formula for this arithmetic series which is
```
    Sn = 1 + 2 + 3 + .. + n
    Sn = n*(n+1)/2
    where n is the position of the last number
```
[read more here]( https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF )

so, this should apply that 
the sum of multiples of 3, 5 is **3Sn + 5Sn**

but there is a point that
```
    Sn of 3 = 3 + 6 + 9 + 12 + 15 + 18 + ... 
    Sn of 5 = 5 + 10 + 15 + 20  + ...
```
which means 
```asm
    15 + 30 + 45 + ...
```
It repeats inside the sum. therefore, we need to take them out but including
> 3*Sn + 5*Sn - 15*Sn

but where is the last dividable position before it exceed N?

we can find out easily by seeing that
before for 3 at last number < 10
> 3 + 6 + 9 

Its last position is 3 one, which is 10/3(round down) same as 5 and 15.
therefore we can conclude that
the sum of multiples of 3 or 5 from beginning to the last number that < N is
```
    sum = 3*Sn3 + 5*Sn5 - 15*Sn15
    Sn3 = (N/3)(N/3+1)/2;  //according to Sn
    Sn5 = (N/5)(N/5+1)/2;
    Sn15 = (N/15)(N/15+1)/2;
```
which results a very shot code in solution-2.cpp

**solution-2.cpp**
``` cpp
    cin >> N;
    cout << 3*Sn(N/3) + 5*Sn(N/5) - 15*Sn(N/15)
```

where Sn is
``` cpp
    int Sn (int n)   {
        return n*(n+1)/2;
    }
```
