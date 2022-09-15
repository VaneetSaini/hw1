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

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) //Adds a new value to the back of the list
{
  if (empty()){  //empty list
    Item* newHead = new Item();
    newHead->val[0] = val;
    newHead->first = 0;
    newHead->last = 1;
    head_ = newHead;
    tail_ = head_;
  }
  else if (tail_->last == ARRSIZE){
    //no free space
    Item* a = new Item();
    a->prev = tail_;
    a->next = NULL;
    tail_->next = a;  //inserts before head 
    a->val[0] = val;
    a->first = 0;
    a->last = 1;
    tail_ = a;
  }
  else{
    //free space
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  size_++;
}

void ULListStr::pop_back(){ //Removes a value from the back of the list
  if (empty()){
    return;
  }
  else if (tail_->last - tail_->first != 1){
    tail_->last--;  //not one item
  }
  else{   //one item left 
    Item* a = new Item();
    a = tail_;
    tail_ = tail_->prev;
    tail_->next = NULL;
    delete a;
  }
  size_--;
}

void ULListStr::push_front(const std::string& val){ //Adds a new value to the front of the list
  if (empty()){
    Item* newTail = new Item();
    newTail->val[0] = val;
    newTail->first = 0;
    newTail->last = 1;
    head_ = newTail;
    tail_ = head_;
  }
  else if (head_->first == 0){
    //no free space
    Item* a = new Item();
    a->prev = NULL;
    a->next = head_;
    head_->prev = a;   
    a->val[ARRSIZE-1] = val;
    a->first = ARRSIZE-1;
    a->last = ARRSIZE;
    head_ = a;
  }
  else{
    //free space
    head_->val[head_->first-1] = val;
    head_->first--;
  }
  size_++;
}

void ULListStr::pop_front(){
  if (empty()){
    return;   //nothing to pop_front
  }
  else if (head_->last - head_->first != 1){
    //more than 1 item
    head_->first++;  //increment pointer
  }
  else{
    //last item left, need to deallocate  
    Item* a = new Item();
    a = head_;
    head_ = head_->next;
    head_->prev = NULL;
    delete a;
  }
  size_--; //update 
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last - 1]; //exclusive index
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first]; //inclusive index
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  
  Item* a = head_;
  unsigned int asize = a->last - a->first;
  if (loc > size_){
    return NULL;
  }
  else if (size_ == 0){
    return NULL;
  }
  else{
    while (loc >= asize){
      loc -= asize;
      if (a->next == NULL){
        return NULL;
      }
      a = a->next;
    }
  }
  return &a->val[a->first + loc];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
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
