# 9.6 Recursion

A function is ***recursive*** if it calls itself.

The following function computes *n!* recursively, using the formula *n! = n x (n - 1)!*:

```c
int fact(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}
```

A function that computes *x^n*, using the formula *x^n = x * x^(n - 1)*.

```c
int power(int x, int n)
{
    if (n == 0)
        return 1;
    else
        return x * power(x, n - 1);
}
```

Condense `power` with a conditional epxression:

```c
int power(int x, int n)
{
    return n = 0 ? 1 : x * power(x, n - 1);
}
```

## The Quicksort Algorithm

Recursion is really only useful for sophisticated algorithms that require a function to call itself more than once.

***Divide-and-Conquer***

A large problem is divided into smaller pieces that are then tackled by the same algorithm.

A classic example is the ***Quicksort*** algorithm. (Assume the array being sorted is indexed from 1 to *n*):

1. Choose an array element *e* (the "partitioning element"), then rearrange the array so that elements `1, ..., i - 1` are less than or equal to *e*, element `i` contains *e*, and elements `i + 1, ..., n` are greater than or equal to *e*.

2. Sort elements `1, ..., i - 1` by using Quicksort recursively.

3. Sort elements `i + 1, ..., n` by using Quicksort recursively.

After step 1, the element *e* is sorted in it's proper location. Elements left of *e* will be in their proper places once they've been sorted in step 2, and elements right of *e* will be in their proper places once they've been sorted in step 3.

Step 1 is crucial. There are various methods for partitioning an array, but we will look at one that's easy to understand but not particularly efficient.

***Partitioning***

1. Uses a *low* marker pointing to the first element of the array and a *high* marker pointing to the last element of the array.

2. Copy the element that *low* points to into a temporary location to be the partitioning element.

3. Move *high* from right to left until it points to an element that's smaller than the partitioning element.

4. Copy that element from *high* into *low*, now leaving a hole where *high* points to.

5. Now move *low* from left to right until it finds an element that is greater than the partitioning element.

6. Copy that element into *high*, now leaving a hole where *low* points to.

7. Go back and forth moving *high* and *low* and moving elements (steps 3-6) until they point to the same element (a hole).

8. Copy the partition element into the hole. It is now sorted with everything to the left of it being less than it, and everything to the right being greater than it.

Now that the array is partitioned, we can call Quicksort on the left and right sides of the partitioned element.

---

### Ways to improve this version of Quicksort

***Improving the partitioning algorithm.*** Instead of choosing the first element in the array as the partitioning element, it's better to take the median of the first element, the middle element, and the last element. The partitioning process itself can be sped up. In particular, it's possible to avoid the `low < high` tests in the two `while` loops.

***Using a different method to sort small arrays.*** Instead of using Quicksort recursively all the way down to arrays with one element, it's better to use a simpler method for small arrays (those with fewer than, say, 25 elements).

***Making Quicksort nonrecursive.*** Although Quicksort is a recursive algorithm by nature--and it's easiest to understand in recursive form--it's actually more effecient if the recursion is removed.
