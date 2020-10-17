## Q - Write a C program to convert NFA to DFA.

### Algorithm

```
An NFA can have zero, one or more than one move from a given state on a given input symbol. An NFA canalso have NULL moves (moves without input symbol). On the other hand, DFA has one and only one move
from a given state on a given input symbol.
```

### Conversion from NFA to DFA

```
Suppose there is an NFA N < Q, ∑, q0, δ, F > which recognizes a language L. Then the DFA D < Q’, ∑, q0, δ’,
F’ > can be constructed for language L as:
Step 1: Initially Q’ = ɸ.
Step 2: Add q0 to Q’.
Step 3: For each state in Q’, find the possible set of states for each input symbol using transition function
of NFA. If this set of states is not in Q’, add it to Q’.
Step 4: Final state of DFA will be all states with contain F (final states of NFA)
```
