*Este proyecto ha sido creado como parte del currículo de 42 por acanadil, raqroca-.*

# push_swap

## Contributors

- **raqroca-**: Algorithm implementation (simple, medium, complex sorts)
- **acanadil**: Benchmark mode, movements, parser, bonus, makefile

---

## Description

push_swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using only two stacks (A and B) and a restricted set of operations, while minimizing the total number of operations used.

The project requires implementing three sorting algorithms of different complexity classes (O(n²), O(n√n), O(n√n) optimized), a disorder index to measure how unsorted the input is, and an adaptive mode that selects the best strategy automatically based on that index.

The available stack operations are:

| Operation | Description |
|-----------|-------------|
| `sa` / `sb` | Swap the first two elements of stack A / B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` / `pb` | Push top of B to A / top of A to B |
| `ra` / `rb` | Rotate A / B upward (top goes to bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate A / B (bottom goes to top) |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Instructions

### Compilation

```bash
make
```

This produces the `push_swap` binary and, if bonus is enabled, the `checker` binary.

```bash
make bonus   # builds checker
make clean   # removes object files
make fclean  # removes objects and binaries
make re      # fclean + make
```

### Execution

```bash
# Basic usage — prints the move sequence to stdout
./push_swap 4 2 7 1 5

# Select strategy explicitly
./push_swap --simple  4 2 7 1 5
./push_swap --medium  4 2 7 1 5
./push_swap --complex 4 2 7 1 5
./push_swap --adaptive 4 2 7 1 5

# Benchmark mode — prints stats to stderr
./push_swap --bench --complex 4 2 7 1 5

# Checker (bonus) — validates that a move sequence sorts the stack
./push_swap 4 2 7 1 5 | ./checker 4 2 7 1 5
```

### Generating random test inputs

```bash
# Test with 100 random numbers
ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' ')
./push_swap --bench --complex $ARG

# Benchmark all strategies for 50, 100 and 500 numbers
rm -f bench.txt && for n in 50 100 500; do
    shuf -i 1-10000 -n $n > args.txt
    echo "=== $n NUMBERS ===" >> bench.txt
    ./push_swap --simple   $(cat args.txt) --bench 2>>bench.txt >/dev/null
    ./push_swap --medium   $(cat args.txt) --bench 2>>bench.txt >/dev/null
    ./push_swap --complex  $(cat args.txt) --bench 2>>bench.txt >/dev/null
done && cat bench.txt
```

---

## Algorithms

### Disorder index

Before sorting, the program calculates a **disorder index** between 0.0 and 1.0 by counting the number of inversions (pairs of elements that are out of order) divided by the total number of possible pairs. A fully sorted stack has disorder 0.0; a fully reversed stack has disorder ~1.0. This index drives the `--adaptive` strategy selection.

---

### Simple — O(n²) — Selection Sort adaptation

**How it works:** repeatedly finds the minimum element in Stack A, rotates it to the top using the shortest path (ra if it is in the first half, rra if it is in the second half), and pushes it to B. Once only 3 elements remain in A, a dedicated tiny sort handles them. Finally, all elements are pushed back from B to A in order.

**Justification:** this is a direct adaptation of selection sort to the two-stack model. Each extraction of the minimum costs O(n) rotations and is repeated n times, giving O(n²) total. It is simple to implement and understand, making it suitable as the baseline algorithm and for very small inputs (≤ 20 numbers) where the overhead of more complex strategies is not justified.

---

### Medium — O(n√n) — Basic Chunk Sort

**How it works:** normalizes all values to positions 0..n-1 with `assign_pos`. Divides the range into chunks of size √n. In a single pass over A, pushes any element whose position falls within the current chunk to B (pb), otherwise rotates A forward (ra). After every √n pushes, the chunk window advances. Once A is empty, repeatedly finds the maximum in B, rotates B by the shortest path (rb or rrb) to bring it to the top, and pushes it back to A (pa).
, such as chunk-based sorting, may perform better than alternatives like radix sort for input sizes typically evaluated in the project (n = 100–500)
**Justification:** dividing into √n chunks means each element is found within at most O(√n) rotations on average during the push phase, and the retrieval phase also costs O(n) total for all maximums. This gives O(n × √n) = O(n√n) overall. No rb optimization is applied during the push phase, so B is unordered within each chunk — this is intentional to keep this version as a clean O(n√n) baseline that is clearly less efficient than the complex version.

---

### Complex — O(n long n) optimized — Chunk Sort with rb trick

**How it works:** same chunk-based structure as Medium, with two key optimizations:

1. **rb trick**: when pushing an element to B, if it belongs to the lower half of the current chunk, it is immediately sent to the bottom of B with `rb`. This keeps B semi-sorted in descending order within each chunk, drastically reducing the rotations needed during retrieval.
2. **Doubled chunk size**: for inputs ≥ 50 elements, the chunk size is set to `√n × 2` instead of `√n`. This reduces the number of ra passes in the push phase by grouping more elements per chunk window.

**Justification:** both optimizations target the constant factor of the O(n√n) complexity. The rb trick reduces the average retrieval cost per element from O(n/2) to much less, because B stays partially ordered. The doubled chunk size reduces the number of ra passes by approximately half for large inputs. The result is that this version empirically outperforms a standard O(n log n) radix sort for the input sizes evaluated (100–500 numbers). This is a well-known phenomenon in algorithmics: an algorithm of a lower complexity class with small constants can outperform a theoretically superior one in practical ranges of n.

---

### Adaptive — disorder-based auto-selection

Selects the strategy automatically based on the disorder index:

| Disorder | Strategy selected |
|----------|------------------|
| < 0.2 | Simple O(n²) |
| 0.2 – 0.5 | Medium O(n√n) |
| ≥ 0.5 | Complex O(n long n) optimized |

The rationale is that for nearly sorted inputs (low disorder) the overhead of chunk sort is not justified and simple extraction is sufficient. For highly disordered inputs the optimized chunk sort is always the best choice.

---

## Resources

- [Algorithm Complexity Analysis - Big O Notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [algoritmos de ordenacion](https://www.freecodecamp.org/espanol/news/algoritmos-de-ordenacion-explicados-con-ejemplos-en-javascript-python-java-y-c/)
- [Push swap visualizer](https://push-swap42-visualizer.vercel.app/)

### AI usage

AI was used as a support tool during the development of this project. It assisted in discussing algorithmic approaches, analyzing time complexity (e.g., O(n²), O(n log n)), and exploring possible optimizations for sorting strategies within the constraints of the push_swap project. The AI was also used to clarify theoretical concepts related to algorithm efficiency and to help reason about why certain implementations.


---

**42 School**:  Madrid