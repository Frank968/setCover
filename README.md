# setCover

# Problem
Given a list of robot names, find the list of robot names with the least number of characters that covers all characters int the original list.


# Background
This problem is a set cover proplem with NP-hardnes. Using greedy algorithm can find a solution closing to optimal solution.

The greedy algorithm for polynomial time approximation of set covering that chooses sets according to one rule: 
at each stage, choose the set that contains the largest number of uncovered elements.

Source:
https://en.wikipedia.org/wiki/Set_cover_problem
https://en.wikipedia.org/wiki/Greedy_algorithm

#Greedy Algorithm Solution
1.A candidate set, output list
2.A selection function, which chooses the best candidate to be added to the solution


# Note
compile successful under g++ (Ubuntu 4.8.4-2ubuntu1~14.04.4) 4.8.4

g++ --version

g++ -Wall -o TestSetCover main.cpp; ./TestSetCover




