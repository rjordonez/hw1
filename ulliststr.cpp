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
    tail_->val[tail_->last++] = val;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val) {
  if (head_ != NULL && head_->first > 0) {
    head_->val[--head_->first] = val;
  } else {
    Item* newItem = new Item();
    newItem->val[ARRSIZE - 1] = val; 
    newItem->first = ARRSIZE - 1;
    newItem->last = ARRSIZE; 

    if (head_ != NULL) {
      newItem->next = head_;
      head_->prev = newItem;
    }

    head_ = newItem;
    if (tail_ == NULL) {
      tail_ = newItem;
    }
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
      head_ = NULL; 
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
      tail_ = NULL; 
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
  size_t indexInCurrentItem = 0;

  while (current != NULL) {
    size_t itemCount = current->last - current->first;
    if (loc < indexInCurrentItem + itemCount) {
      
      size_t actualIndex = loc - indexInCurrentItem + current->first;
      return &current->val[actualIndex];
    }
    indexInCurrentItem += itemCount;
    current = current->next;
  }

  return NULL;
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
