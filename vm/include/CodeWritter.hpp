#ifndef __CODE_WRITTER__

#define __CODE_WRITTER__
#include "Utilities.hpp"
#include <fstream>
#include <iostream>
using std::ofstream;
using std::string;
class CodeWritter {
private:
  ofstream writeFile;

public:
  CodeWritter();
  void setFileName(string fileName);
  void writeArithmetic(string command);
  void writePushPop(COMMAND_TYPE commandType, string segment, int index);
  // closing the output file
  // void close
  ~CodeWritter();
};
#endif
