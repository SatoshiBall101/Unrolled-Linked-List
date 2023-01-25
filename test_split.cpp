/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <cassert>
#include <ostream>

int main(int argc, char* argv[])
{
  
  Node* in1 = new Node(1, NULL);
  Node* in2 = new Node(2, NULL);
  Node* in3 = new Node(3, NULL);
  Node* in4 = new Node(4, NULL);
  Node* in5 = new Node(5, NULL);
  Node* in6 = new Node(6, NULL);
  Node* in7 = new Node(7, NULL);
  Node* in8 = new Node(8, NULL);

  in1->next = in2;
  in2->next = in3;
  in3->next = in4;
  in4->next = in5;
  in5->next = in6;
  in6->next = in7;
  in7->next = in8;

  Node* evens = NULL;
  Node* odds = NULL;

  split(in1, evens, odds);

  Node* temp = evens;

  while (temp != NULL)
  {
    assert(temp->value % 2 == 0);
    temp = temp->next;
  }

  temp = odds;

  while (temp != NULL)
  {
    assert(temp->value % 2 == 0);
    temp = temp->next;
  }

  delete in1;
  delete in2; 
  delete in3; 
  delete in4; 
  delete in5; 
  delete in6; 
  delete in7; 
  delete in8; 

}
