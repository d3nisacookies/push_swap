*This projected was made by akaung*

# Push_swap

## Overview

Push_swap is a sorting algorithm project from 42 School.  
The goal is to sort a list of integers using two stacks and a limited set of operations while minimizing the number of moves.

The program receives a sequence of integers as arguments and outputs the operations required to sort them in ascending order.

---

## Rules

You have two stacks:

* **Stack A** – initially contains all numbers.
* **Stack B** – initially empty.

Your objective is to sort **Stack A** using only the allowed operations.

---

## Allowed Operations

* `sa` — Swap the first two elements of stack A
* `sb` — Swap the first two elements of stack B
* `ss` — Perform `sa` and `sb` simultaneously
* `pa` — Push the top element of B onto A
* `pb` — Push the top element of A onto B
* `ra` — Rotate stack A (first element becomes last)
* `rb` — Rotate stack B
* `rr` — Perform `ra` and `rb` simultaneously
* `rra` — Reverse rotate stack A
* `rrb` — Reverse rotate stack B
* `rrr` — Perform `rra` and `rrb` simultaneously

---

## Project Structure
push_swap/ \
│ \
├── Makefile \
├── push_swap.h \
├── main.c \
│ \
├── parsing/ \
│ ├── parse.c \
│ ├── check_errors.c \
│ └── index.c \
│ \
├── stack/ \
│ ├── stack_init.c \
│ └── stack_utils.c \
│ \
├── operations/ \
│ ├── swap.c \
│ ├── push.c \
│ ├── rotate.c \
│ └── reverse_rotate.c \
│ \
├── sorting/ \
│ ├── small_sort.c \
│ └── radix_sort.c \
│ \
└── utils/ \
├── ft_split.c \
└── ft_atoi.c 


---

## Algorithms

### Small Sort (2–5 numbers)

For small inputs, specialized sorting logic is used:

* **2 numbers** → swap if necessary  
* **3 numbers** → minimal swaps and rotations  
* **4–5 numbers** → push the smallest numbers to stack B, sort the remaining numbers, then push them back

### Radix Sort (Large Inputs)

For larger inputs, the program uses **binary radix sort**:

1. Each number is assigned an index based on sorted order.
2. Numbers are processed bit by bit.
3. Elements are moved between stacks based on bit values.

This allows efficient sorting of large lists.

---

## Compilation

Compile the program using:
```bash
make
```

## Usage

Run the program with a list of integers:
```bash
./push_swap 5 4 3 2 1
```

Example output:
```bash
pa
pb
sb
sa
rra
```

Each line represents an operation performed to sort the stack.

---

## Error Handling

The program prints:
```bash
Error
```

when:

* Arguments are not valid integers
* Duplicate numbers are detected
* Memory allocation fails

---

## Testing

Example test:
```bash
ARG="4 67 3 87 23"
./push_swap $ARG
```

Count operations:
```bash
./push_swap $ARG | wc -l
```

---

## Resources

The following resources were helpful for understanding the algorithms and concepts used in this project:

### Algorithms

* Radix Sort explanation  
  https://www.geeksforgeeks.org/radix-sort/

* Sorting algorithms overview  
  https://visualgo.net/en/sorting

* Bitwise operations in C  
  https://www.learn-c.org/en/Bitwise_Operators

### Push_swap Visualizers

* Push_swap visualizer (helps debug and visualize stack operations)  
  https://github.com/o-reo/push_swap_visualizer

* Push_swap tester  
  https://github.com/louisabricot/push_swap_tester

### Stack and Data Structures

* Stack data structure explanation  
  https://www.geeksforgeeks.org/stack-data-structure/

### C Programming References

* C reference documentation  
  https://en.cppreference.com/w/c

* Memory management in C  
  https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
