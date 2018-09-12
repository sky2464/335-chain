// Salem Saboori
// Salem.Saboori00@myhunter.cuny.edu
// Create and test a class called Chain. A chain is just a series of items, e.g. [2 7 -1 43] is a chain containing four integers.
// A Chain can have any size. An empty Chain has size 0.

#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_

#include <iostream>
#include <cstddef>
#include <fstream> // For File I/O
#include <cstring>
#include <sstream> // String stream

namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
//Template Object - Chain Class, matrix data container
template<typename Object>
class Chain {
public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor.
  // Chain() = default;
  Chain() {
    size_ = 0; // Creating an empty chain with size 0
    array_ = nullptr; // Initialization
  }



  // Copy-assignment
  Chain& operator=(const Chain &rhs) {
    // To prevent self assignment
    if (this != &rhs) {
      Chain copy = rhs;
      std::swap(*this, copy);
    }
    return *this;
  }
  // Copy-assignment. If you have already written
    // the copy-constructor and the move-constructor
    // you can just use:
    // {
    // Chain copy = rhs;
    // std::swap(*this, copy);
    // return *this;
    // }
  //  Chain& operator=(const Chain &rhs) = default;

  // Copy-constructor
  Chain(const Chain &rhs) {
    size_ = rhs.size();
    array_ = new Object[size_];
    for (unsigned int i = 0; i < size_; i++) {
      array_[i] = rhs.array_[i];
    }
  }


  //Move-constructor
  //Chain(Chain &&rhs) = default;
  // BIG 5: Reference to Reference of rhs chain
  Chain(Chain &&rhs) :
      size_ { rhs.size_ }, array_ { rhs.array_ } {
    rhs.size_ = 0;
    rhs.array_ = nullptr;
  }



  // Move-assignment.
  // Just use std::swap() for all variables.
  //Chain& operator=(Chain &&rhs) = default;

  Chain& operator=(Chain &&rhs) {
    std::swap(size_, rhs.size_);
    //rhs.size_ = 0;
    std::swap(array_, rhs.array_);
    //rhs.array_ = nullptr;
    return *this;
  }

  // Destructor
  virtual ~Chain() {
    delete[] array_;
    size_ = 0;
    array_ = nullptr;
  }
  // End of big-five.


  // One parameter constructor.
  Chain(const Object& item) {
    size_ = 1;
    array_ = new Object[size_];
    array_[0] = item;
  }

  // Read and use a chain from standard input.
  void ReadChain() {
    std::string input; // String of user input
    getline(std::cin, input); // Read user input
    if (input.empty() || input == "[]") {
      return;
    } // Empty or blank chain input

    if (input[0] == '[' && input[input.length() - 1] == ']') {
      Object* temp = array_; // Point the current dynamic object, array_
      input = (input.substr(1, input.length() - 2)); // Eliminate brackets
      char* c = new char[input.length() - 1]; // Temp char* for input string
      std::copy(input.begin(), input.end(), c);
      //Char -> Integer parsing function atoi from cstring library
      int len = atoi(strtok(c, ":")); // Returns part of string before : sign
      if (len > 0) {
        size_ = len;
        array_ = new Object[size_];
      }
      delete[] temp; // Remove previously loaded dynamic array_ object
      temp = nullptr;

      // Part to write to the Chain array_
      int i = 0;
      while (input[i] != ':') {
        i++;
      } // Iterate to the part until : sign
      input = (input.substr(i + 1, input.length() - 1)); // Eliminate : sign
      std::stringstream linestream(input); // To input to array_
      for (unsigned int j = 0; j < size_; j++) {
        linestream >> array_[j];
      }
      delete[] c;
    } else {
      return;
    }
  }

  size_t size() const {
    return size_;
  }

  // @location: an index to a location in the chain.
  // @returns the Object at @location.
  // const version.
  // abort() if out-of-range.
  const Object& operator[](size_t location) const { // @suppress("No return")
    // Write something

    if (location > size() - 1 || location < 0) {
      abort();
    } else
      return array_[location];
  }

  // @location: an index to a location in the range.
  // @returns the Object at @location.
  // non-const version.
  // abort() if out-of-range.

  // non-const version of the above for assigning/ L,R value operations
  Object& operator[](size_t location) { // @suppress("No return")
    // Write something (will be the same as above)
    if (location > size() - 1 || location < 0) {
      abort();
    } else
      return array_[location];
  }

  //  @c1: A chain.
  //  @c2: A second chain.
  //  @return the concatenation of the two chains.
  friend Chain operator+(const Chain &c1, const Chain &c2) {
    // Write something.
    Chain temp;
    temp.size_ = c1.size() + c2.size();
    temp.array_ = new Object[temp.size()];
    unsigned int i = 0, j = 0;
    while (i < c1.size()) {
      temp.array_[i] = c1.array_[i];
      i++; // Temp has an copied element from c1, increment i
    }
    while (i < temp.size()) { // Now adding second chain elements
      temp.array_[i] = c2.array_[j];
      i++;
      j++;
    }
    return temp;
  }

  // Overloading the << operator.
  friend std::ostream &operator<<(std::ostream &out, const Chain &a_chain) {
    // Print the chain.
    if (a_chain.size() == 0 || a_chain.array_ == nullptr) {
      out << "[]\n";
      return out;
    } else {
      out << "["; // Print the chain.
      for (unsigned int i = 0; i < a_chain.size(); i++) {
        if (i != a_chain.size() - 1)
          out << a_chain.array_[i] << " ";
        else
          out << a_chain.array_[i]; // Last element, eliminate space
      }
      out << "]\n";
      return out;
    }
  }

private:
  size_t size_;
  Object *array_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_CHAIN_
