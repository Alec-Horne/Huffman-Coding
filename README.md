# Data Structures - Project 3 - Huffman Coding Trees
## Due 12/11/15 at 11:59 pm

With this project you will be using Huffman Coding trees to encode strings!

I have provided the header file for the Huffman class, and you MUST implement all neccesary functions.


## Files

I will supply you with these files:

 * README.md - This file contains these instructions
 * makefile - Use 'make' on the linux system to compile the project using this makefile.  The binary file will be named 'huffman.out'.
 * Huffman.hpp - This contains the header file for a Huffman object as well as the Encoded struct.
   * There are three functions you need to implement in this file
   * The encode function is already implemented, you need to make Heap.hpp reflects all the calls used within it
 * Heap.hpp - Implement a min heap that stores HNode*
   * This will be very similar to the one we did in the class examples with changes to handle HNode* instead of int
   * You must implement enqueue, dequeue, fix_up, fix_down, and clear functions
   * You must correctly update the count variable
 * Hnode.hpp - The struct for the nodes you will use inside your heap
   * You must implement the two constructors
   * The value member is the character
   * The weight member is the frequency count for characters in leaf nodes, and combined count for internal nodes
   * There are two constructors, one creates a character/frequency node
   * The other combines two existing nodes to make an internal node
 * test_huffman.hpp
   * There are no test cases for this program
   * instead, it will output the tree serialization and encoded string
   * you can draw the tree and manually check that the encoded string matches

## TO-DO CHECKLIST

  * Finish HNode.hpp
    * creating a leaf node
    * creating an internal node
  * Finish the Heap.hpp
    * enqueue
    * dequeue
    * fix_up
    * fix_down
    * clear
  * implement the three unfinished functions in Huffman.hpp
    * create_codes
    * serialize_tree
    * encode_string

## General Information

  * Our heap is going to function as a priority queue without the overhead of creating a class around the heap
  * The serialized huffman tree should use "*" for inner node characters
  * The serialized huffman tree should only have the character portion of each node, not the value portion.
  * When encoding, use "0" for a left branch and "1" for a right
  * You ARE alowed to modify the heap code we did in class to implement your heap, I recommend this
  * You are NOT allowed to use std::priority_queue
  * You ARE allowed to use std::vector(but I see no need) and std::map(You have to use it)

## OUTPUT

The output I get for the finished project follows:

```
$ ./huffman.out
Input: MISSISSIPPI
100011110111101011010
*I//**M//P//S//
Input: A man a plan, a canal, Panama!
010110010111110000110001101011111100101000110001010111001101111010000100111001110111101100
** //**P//*c//A//**!//p//l//**n//*,//m//a//

```
 * Your output may be slightly different depending on how you implement your heap

## Rubric

 * [20%] Your program must compile and run on our knuth linux server. TEST THIS! IF IT DOESNT COMPILE YOU LOSE 20% OFF THE TOP!

 * [10%] Your Heap must work correctly with HNode pointers

 * [20%] Thee huffman tree output must be correct

 * [20%] The encoded string output must match the given string and huffman tree

 * [10%] You must document all functions in your code (you don't need to go crazy, just document what you are doing)

 * [10%] You must properly handle memory, memory leaks will cost you points
