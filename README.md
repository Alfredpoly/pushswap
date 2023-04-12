# push-swap

push-swap is a project that consists in sorting data on a stack, with a limited set of instructions, using the lowest
possible number of actions. To make this happen, you will have at your disposal a set of int values, 2 stacks and a set
of instructions to manipulate both stacks.

**Here is the set of instructions:**

* sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
* sa: swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* sb: swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* ss: sa and sb at the same time.
* pa: push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb: push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra: rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* rb: rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr: ra and rb at the same time.
* rra: reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* rrb: reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* rrr: rra and rrb at the same time.

**The goal is to sort in ascending order numbers into stack a.**

## How to use it

### Compilation

To compile the project, run `make` in the root directory. This will create the following binary file:

* push_swap: sorts the stack

### Usage

To use the program, run `./push_swap [numbers]` in the root directory. The program will output the list of instructions
to sort the stack.

## Example

### Input

`./push_swap 2 1 3 6 5 8`

### Output

`sa pb ra pb ra ra pb pa pa pa pa`

# What I learned

* How to use the stack data structure
* How to use the queue data structure
* Create my own algorithm to sort the stack





