#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val)
{
	if(head_ == NULL && tail_ == NULL) // if the list is empty
	{
		Item* item1 = new Item; // dynamically allocate a new Item
		head_ = tail_ = item1; // head and tail now point at the new Item
		head_->val[0] = val; // place the value in the array
		size_ = 1; // just created an item and placed a value, so size is 1
		head_->last = 1; // move up last pointer 
	}
	else if(tail_->last < 10) // there is room to push_back value to last node
	{
		tail_->val[tail_->last] = val; // place the value in the array
		size_++;
		tail_->last++; //increment last index
	}
	else if (tail_->last == 10) // there is no room thus new item needed
	{
		Item* nextItem = new Item; // DA next Item 
		Item* temp = tail_; // save previous last item's address
		tail_ = nextItem; // tail is now pointing at next Item
		tail_->prev = temp; // update nextItem's previous
		tail_->prev->next = nextItem; // update the old tail's next to the next Item
		tail_->val[0] = val; // store string
		size_++; 
		tail_->last++; // move up last index
	}
}

void ULListStr::pop_back()
{
	if (size_ == 0)
	{
		return; // bc nothing to "pop" due to empty list
	}

	if (size_ == 1) // only 1 element in list so we can delete list
	{
		delete head_;
		head_ = tail_ = NULL;
		size_--;
		
	}
	else
	{
		if (tail_->last == 1) // Item/node has single element  
		{
			tail_ = tail_->prev; // tail points at last non empty node
			delete tail_->next; // delete the node with 1 item for popback
			tail_->next = NULL; // drop off the empty Item from the LL
			size_--;
		}
		else
		{
			tail_->last--;
			size_--;
		}
	}
}


void ULListStr::push_front(const std::string& val)
{
	if(head_ == NULL && tail_ == NULL) // if the list is empty
	{
		Item* item2 = new Item; // dynamically allocate a new Item
		head_ = tail_ = item2; // head and tail now point at the new Item
		head_->val[9] = val; // place the value in the array
		size_ = 1; // just created an item and placed a value, so size is 1
		head_->first = 9; // first value at index 9 
		head_->last = 10; // last value at index 10 (non inclusive)
		return;
	}

	if(head_->first > 0) // there is room to push_front value to first node
	{
		head_->val[head_->first-1] = val; // place the value in the array
		size_++;
		head_->first--; //decrement first index 
		return;
	}
	else if (head_->first == 0) // there is no room thus new item needed
	{
		Item* prevItem = new Item; // DA next Item 
		Item* temp1 = head_; // save previous first item's address
		head_ = prevItem; // head is now pointing at prevItem
		head_->next = temp1; // update prevItem's next
		head_->next->prev = prevItem; // update the old head's prev to the prevItem
		head_->val[9] = val; // store string
		size_++; 
		head_->first = 9; // move up last index
		head_->last = 10; // move up last index
		return;
	}

}

void ULListStr::pop_front()
{
	if (size_ == 0)
	{
		return; // bc nothing to "pop" due to empty list
	}

	if (size_ == 1) // only 1 element in list so we can delete list
	{
		delete head_;
		head_ = tail_ = NULL;
		size_--;
	}
	else
	{
		if (head_->first == 9) // Item/node has single element  
		{
			head_ = head_->next; // head points at first non empty node
			delete head_->prev; // delete the old head node with 1 item for popfront
			head_->prev = NULL; // drop off the empty Item from the LL
			size_--;
		}
		else
		{
			head_->first++;
			size_--;
		}
	}
}

std::string const & ULListStr::back() const
{
	return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
	return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}


std::string* ULListStr::getValAtLoc(size_t loc) const
{
	if (loc > size_)
	{
		return NULL;
	}
	else
	{
		Item* currNode = head_;
		size_t currLoc = 0;
		size_t currIdx = head_->first;
		
		while (currLoc != loc)
		{
			currLoc++;
			currIdx++;
			if (currIdx >= currNode->last)
			{
				currNode = currNode->next;
				currIdx = currNode->first; // reset first 
			}
			
		}

		return &(currNode->val[currIdx]);
	}
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
