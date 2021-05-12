# push_swap
<img width="1925" alt="push_swap" src="https://user-images.githubusercontent.com/74931024/117972740-c8dfae00-b32b-11eb-80c7-b4ba871217b4.png"><br>

This project is simply a good way to get involved in the **_world of algorithms_** and everything related to their optimization. Due to the limitations imposed on us, we have to find, among many algorithms, the best one to sort an unordered list of numbers stored in a stack.<br>
<img width="256" align="right" alt="unsorted stack" src="https://user-images.githubusercontent.com/74931024/117662329-b89ac800-b19f-11eb-8812-983cdd1089da.png">

### A brief introduction to algorithms
I am currently working on another repository where I want to explain in more detail [what algorithm analysis consists of](https://github.com/pgomez-a/algorithms) and what are the different types of algorithms that we can use depending on the objective we want to achieve. All the information you will find here is a combination of the things I studied before starting my **push_swap** and the things I came across while reading different algorithm books.
<img width="256" align="right" alt="sorted stack" src="https://user-images.githubusercontent.com/74931024/117662466-e1bb5880-b19f-11eb-98db-e7e63aebd496.png">

### Instructions
In this project, we have to **sort a list of numbers**. We have at our disposal **two stacks** to manipulate the numbers for the sort operation and a set of instructions to manipulate both stacks. With this, we have to write two programs:
* **Checker:** takes integer arguments and reads instructions on standard input. Once read, it executes them and shows OK if the integers are sorted or KO if not.
* **Push_swap:** calculates and displays on standard output the instructions needed to sort the given stack. Our algorithm should use the fewest number of rules necessary to sort the stack. Our grade will totally depend on this (depending on the optimization topic).

### General Rules
We can only use two stacks to manipulate the elements. This means that when it comes to getting information from a stack, we can do whatever we want if we don't manipulate the elements. But when we want to stack, unstack, rotate, etc., we can only use these two stacks and the rules explained below. This is very important because otherwise we could just use a quick sort to sort all the items and that would be the whole project. But [since we want to expand our knowledge](https://www.goodreads.com/book/show/22847284-grokking-algorithms-an-illustrated-guide-for-programmers-and-other-curio), we have to make an effort to read the different ways of implementing algorithms and how to use the least amount of resources.<br>
When one of the programs starts, stack a contains a random list of numbers and stack b is empty. After the program ends, stack a must contain all sorted items and stack b must be empty. Remember that the goal is to sort the numbers in ascending order on stack a.

### Handling Rules
* **sa:** swap a --> swap the first two elements at the top of stack a.
* **sb:** swap b --> swap the first two elements at the top of stack b.
* **ss:** sa & sb at the same time.
* **pa:** push a --> unstack the first element of stack b and put it in stack a.
* **pb:** push b --> unstack the first element of stack a and put it in stack b.
* **ra:** rotate a --> shift up all elements of stack a by 1.
* **rb:** rotate b --> shift up all elements of stack b by 1.
* **rr:** ra & rb at the same time.
* **rra:** reverse rotate a --> shift down all elements of stack a by 1.
* **rrb:** reverse rotate b --> shift down all elements of stack b by 1.
* **rrr:** rra & rrb at the same time.

### ./push_swap
<img width="254" alt="push_swap test" src="https://user-images.githubusercontent.com/74931024/117660046-f64a2180-b19c-11eb-875d-4bb07717742a.png"> <img width="141" alt="push_swap test" src="https://user-images.githubusercontent.com/74931024/117659565-64daaf80-b19c-11eb-9a49-9f704ba2fefd.png"> <img width="145" alt="push_swap test" src="https://user-images.githubusercontent.com/74931024/117659652-80de5100-b19c-11eb-867e-e622a653e3b4.png"> <img width="133" alt="push_swap test" src="https://user-images.githubusercontent.com/74931024/117660346-5a6ce580-b19d-11eb-84bc-70177a1e96e4.png">

### ./checker
<img width="170" alt="checker test" src="https://user-images.githubusercontent.com/74931024/117661163-4ecdee80-b19e-11eb-835e-6dd38b6f7cd2.png"> <img width="170" alt="checker test" src="https://user-images.githubusercontent.com/74931024/117660773-debf6880-b19d-11eb-8152-459b10b29faf.png"> <img width="170" alt="checker test" src="https://user-images.githubusercontent.com/74931024/117660951-0c0c1680-b19e-11eb-9916-ffe0dda9dce8.png"> <img width="170" alt="checker test" src="https://user-images.githubusercontent.com/74931024/117661044-28a84e80-b19e-11eb-875d-965d39632874.png">

### ./checker | ./push_swap
<img width="465" alt="push_swap & checker test" src="https://user-images.githubusercontent.com/74931024/117661820-24c8fc00-b19f-11eb-870d-f142f7b2b380.png"> <img width="465" alt="push_swap & checker test" src="https://user-images.githubusercontent.com/74931024/117661885-39a58f80-b19f-11eb-8c2f-f513036d7414.png">
