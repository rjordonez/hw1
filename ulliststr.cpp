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
void ULListStr::push_back(const std::string& val) {
  // If the list is empty or the last node's array is full, create a new node
  if (tail_ == NULL || tail_->last == ARRSIZE) {
    Item* newItem = new Item();
    if (tail_ != NULL) {
      tail_->next = newItem;
      newItem->prev = tail_;
    }
    tail_ = newItem;
    if (head_ == NULL) {
      head_ = newItem;
    }
    tail_->last = 1;
    tail_->first = 0;
    tail_->val[0] = val;
  } else {
    // Otherwise, add the value to the current tail node's array
    tail_->val[tail_->last++] = val;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val) {
  // If the list is empty or the first node's array is full from the front, create a new node
  if (head_ == NULL || head_->first == 0) {
    Item* newItem = new Item();
    if (head_ != NULL) {
      head_->prev = newItem;
      newItem->next = head_;
    }
    head_ = newItem;
    if (tail_ == NULL) {
      tail_ = newItem;
    }
    head_->first = ARRSIZE - 1; // Start at the end of the array
    head_->last = ARRSIZE;
    head_->val[ARRSIZE - 1] = val;
  } else {
    // Otherwise, add the value to the current head node's array
    head_->val[--head_->first] = val;
  }
  size_++;
}

void ULListStr::pop_back() {
  if (empty()) {
    throw std::underflow_error("List is empty");
  }
  tail_->last--;
  size_--;
  if (tail_->last == tail_->first) {
    Item* temp = tail_;
    tail_ = tail_->prev;
    delete temp;
    if (tail_) {
      tail_->next = NULL;
    } else {
      head_ = NULL; // List is now empty
    }
  }
}

void ULListStr::pop_front() {
  if (empty()) {
    throw std::underflow_error("List is empty");
  }
  head_->first++;
  size_--;
  if (head_->first == head_->last) {
    Item* temp = head_;
    head_ = head_->next;
    delete temp;
    if (head_) {
      head_->prev = NULL;
    } else {
      tail_ = NULL; // List is now empty
    }
  }
}

std::string const & ULListStr::back() const {
  if (empty()) {
    throw std::underflow_error("List is empty");
  }
  return tail_->val[tail_->last - 1];
  return NULL;
}

std::string const & ULListStr::front() const {
  if (empty()) {
    throw std::underflow_error("List is empty");
  }
  return head_->val[head_->first];
  return NULL;
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) {
    return NULL;
  }
  Item* current = head_;
  while (current != NULL) {
    if (loc < (current->last - current->first)) {
      return &current->val[current->first + loc];
    }
    loc -= (current->last - current->first);
    current = current->next;
  }
  return NULL; // Should not reach here if loc is valid
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
