CPP course summary exercise:
Operations:
The postal office has the option of performing several operations:
1. Receiving packages
2. package delivery
3. Making payments
4. purchase of products

Type of People in the postal office:
There can be 1-4 clerks handling operations, where each of them can handle 0 or more of the operations
There are two types of customers:
1. regular customers
2. Elderly customers (over 65 years old)

A priority queue must be implemented using linked lists, which performs the following operations:
1. Entry of a person into a queue
2. What is the action he wants to perform
3. what is his date of birth

As a result he gets a number
1. Canceling a turn - a user who gives up his turn
2. Selection of the next user when a clerk becomes vacant
   
For each clerk, the order is 1,2,3,4 (that is, receiving packages is the first if such an option exists with the clerk).
When a clerk selects a client, if the previous client he handled is normal, he checks to see if there is an elderly client in line. If not, a regular customer chooses.
As soon as a customer is treated, the treatment date is updated and the waiting time is calculated.

File:
Saving information in an external file.
Reading information from an external file.
