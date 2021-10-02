# Usage
```
$> make
$> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```
# Description
There are 2 stacks named a and b and the goal is to sort in ascending order numbers into stack a.  

- To start with:  
    - a contains a random number of either positive or negative numbers without any duplicates.  
    - is empty  
  
- To do this push_swap program has the following operations:  
    - sa : swap a - swap the first 2 elements at the top of stack a.  
    - sb : swap b - swap the first 2 elements at the top of stack b.  
    - ss : sa and sb at the same time.  
    - pa : push a - take the first element at the top of b and put it at the top of a.  
    - pb : push b - take the first element at the top of a and put it at the top of b.  
    - ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.  
    - rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.  
    - rr : ra and rb at the same time.  
    - rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.  
    - rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.  
    - rrr : rra and rrb at the same time.

## bonus part  
If after executing those instructions, stack a is actually sorted and b is empty, then checker program must display "OK".
```
$> make bonus
$> ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
```
