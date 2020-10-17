## Qn: Write a C program to find ε – closure of all states of any given NFA with ε transition.

### Algorithm

```
1. Start
2. Read NFA with epsilon moves
3. Repeat for all states
3.1 Push (state)
3.2 While stack not empty
3.2.1 U =pop()
3.2.2 For each epsilon move from u to v
a) If v is not visited
(i) Set v as visited
(ii) Push (v)
3.3 Epsilon closure (state) = visited edge
```
