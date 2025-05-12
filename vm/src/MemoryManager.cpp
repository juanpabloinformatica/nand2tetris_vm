#include "MemoryManager.hpp"
#include <cassert>
#include <iostream>

MemoryManager::MemoryManager() {
  this->setTempMemorySegment();
  this->setPointerMemorySegment();
  this->setRamMemorySegment();
}
MemoryManager::~MemoryManager() {}
void MemoryManager::setPointerMemorySegment(void) {
  for (int i = 0; i < POINTER_MEMORY_LENGTH - 1; i++) {
    this->pointerMemorySegment[i] = 0;
  }
}
void MemoryManager::setTempMemorySegment(void) {
  for (int i = 0; i < TEMP_MEMORY_LENGTH - 1; i++) {
    this->tempMemorySegment[i] = 0;
  }
}
void MemoryManager::setRamMemorySegment(void) {
  // if size() giving the top
  // using defautl stack or vector???
  this->ramMemory.at(0) = stackMemory.size();
  this->ramMemory.at(1) = this->localMemorySegment.pointer;
  this->ramMemory.at(2) = this->argumentMemorySegment.pointer;
  this->ramMemory.at(3) = this->thisMemorySegment.pointer;
  this->ramMemory.at(4) = this->thatMemorySegment.pointer;
  this->ramMemory.at(5) = this->tempMemorySegment.at(0);
  this->ramMemory.at(6) = this->tempMemorySegment.at(1);
  this->ramMemory.at(7) = this->tempMemorySegment.at(2);
  this->ramMemory.at(8) = this->tempMemorySegment.at(3);
  this->ramMemory.at(9) = this->tempMemorySegment.at(4);
  this->ramMemory.at(10) = this->tempMemorySegment.at(5);
  this->ramMemory.at(11) = this->tempMemorySegment.at(6);
  this->ramMemory.at(12) = this->tempMemorySegment.at(7);
  // this->ramMemory.at(13) = 0;
  // this->ramMemory.at(14) = 0;
  // this->ramMemory.at(15) = 0;
}
void MemoryManager::updateStackMemory(int value) {
  this->stackMemory.push(value);
}
int MemoryManager::popStack(void) {
  int result = this->stackMemory.top();
  this->stackMemory.pop();
  result += this->stackMemory.top();
  this->stackMemory.pop();
  return result;
}
