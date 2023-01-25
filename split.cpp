/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{

  // base case: check to make sure linked list is not empty

  if (in == NULL)
  {
    return; // work is done if it is empty
  }

  // let's check if the value is even

  if (in->value % 2 == 0) // if it is even we will add it to evens list
  {
    // lets handle base case: evens list is empty
    if (evens == NULL)
    {
      evens = in; // evens ptr points at even node in OG LL 
      in = in->next; // drop of the node in the original LL
      evens->next = NULL; // update the evens node's next w/ nullptr
    }
    else // if evens is not empty
    {
      Node* temp = evens; // create temporary ptr to even node
      evens = in; // evens LL takes even node
      in = in->next; // drop the even value node from original LL
      evens->next = temp; // add the even node to the front of evens LL

    }
  }
  else // if not even, it must be odd
  {
    // lets handle base case: odds list is empty
    if (odds == NULL)
    {
      odds = in; // giving odds LL pointer to node
      in = in->next; // drop of the node in the original LL
      odds->next = NULL; // update the odd node's next w/ nullptr
    }
    else // if evens is not empty
    {
      Node* temp = odds; 
      odds = in; 
      in = in->next;
      odds->next = temp;

    }
  }

  split(in, odds, evens); //recursive call
}

/* If you needed a helper function, write it here */
