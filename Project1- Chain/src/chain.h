// Salem Saboori
// Salem.Saboori00@myhunter.cuny.edu
// Place comments describing the class Chain (two lines).

#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_

#include <iostream>
#include <cstddef>

namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Chain {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor.
  Chain() = default;

  // Copy-constructor.
  Chain(const Chain &rhs) = default;

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Chain copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  Chain& operator=(const Chain &rhs) = default;

  // Move-constructor. 
  Chain(Chain &&rhs) = default;

  // Move-assignment.
  // Just use std::swap() for all variables.
  Chain& operator=(Chain &&rhs) = default;

  ~Chain() {
    // Provide destructor.
  }

  // End of big-five.

  // One parameter constructor.
  Chain(const Object& item) {
    // Write something.
  }

  // Read a chain from standard input.
  void ReadChain() {
    // Write something.
  }

  size_t size() const { // Write something
  }

  // @location: an index to a location in the chain.
  // @returns the Object at @location.
  // const version.
  // abort() if out-of-range.
  const Object& operator[](size_t location) const { 
    // Write something
  }

 // @location: an index to a location in the range.
 // @returns the Object at @location.
 // non-const version.
 // abort() if out-of-range.
 Object& operator[](size_t location) { 
   // Write something (will be the same as above)
 }

 //  @c1: A chain.
 //  @c2: A second chain.
 //  @return the concatenation of the two chains.
 friend Chain operator+(const Chain &c1, const Chain &c2) {
  // Write something.
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Chain &a_chain) {
   // Print the chain.
   return out;
 }
 
 private:
  size_t size_;
  Object *array_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_CHAIN_
