07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Add and Remove work as shown by the testing file given. Grow should work by making a new array with double the size of the previous array 
and it should also transfer all data into the new array.
2. The program shouldnt leak memory through use of the deconstructor.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.1
				3
------------------------------------------------------------------
		9				4		
------------------------------------------------------------------
	17		26		6		7
------------------------------------------------------------------
19	     69    32	     93    55        50    16	    8


10.2
				9
-----------------------------------------------------------------
		17				50
-----------------------------------------------------------------
	19		26		55		16
-----------------------------------------------------------------
93	     69    32

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
parent = (i-1)/3 (using interger division
child = di+1, di+2 ... till di+d
#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
My biggest confusion with this was how it can be stored in an array but it seems to be just like a BST. However the more i work with it
the more it makes sense.