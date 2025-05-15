#ifndef __CONTROL__
#define __CONTROL__
#include "CodeWritter.hpp"
#include "MemoryManager.hpp"
#include "Parser.hpp"
#include <fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
class Control {
private:
  ifstream readFile;
  ofstream writeFile;
  Parser parser;
  CodeWritter codeWritter;
  MemoryManager memoryManager;

public:
  Control(string filepath);
  ~Control();
  void setReadFile(string filepath);
  ifstream &getReadFile();
  void setWriteFile(string filepath);
  ofstream &getWriteFile();
  void traverseFile();
};
#endif
