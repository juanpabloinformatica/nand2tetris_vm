#include "Control.hpp"
#include <iostream>
Control::Control(string filepath) {
  this->setReadFile(filepath);
  int indexDelimeter = filepath.find(".");
  string writeFilePath = filepath.substr(0, indexDelimeter) + ".hack";
  cout << writeFilePath << endl;
  this->setWriteFile(writeFilePath);
  this->parser = Parser();
  // learning about error of having the destructor
  this->codeWritter = CodeWritter();
  this->memoryManager = MemoryManager();
}
void Control::traverseFile() {
  string currentCommand;
  while (std::getline(this->readFile, currentCommand)) {
    currentCommand.erase(
        0, currentCommand.find_first_not_of(" \n\r\t")); // left trim
    currentCommand.erase(currentCommand.find_last_not_of("\t\n\v\f\r ") +
                         1); // right trim
    if (currentCommand.substr(0, 2) != "//" && currentCommand != "") {
      this->parser.operateCommand(currentCommand);
      switch (this->parser.getCommandType()) {
      case C_ARITHMETIC:
        if (this->parser.getArg1() == "add") {
          this->memoryManager.updateStackMemory(this->memoryManager.popStack());
        }
        this->writeFile << endl;
        this->parser.resetSplitCurrentCommand();
        break;
      case C_PUSH:
        this->memoryManager.updateStackMemory(this->parser.getArg2());
        this->writeFile << this->codeWritter.getPushAssembly(
            C_PUSH, this->parser.getArg1(), this->parser.getArg2());
        this->writeFile << endl;
        this->parser.resetSplitCurrentCommand();
        break;
      case C_POP:
        break;
      case C_LABEL:
        break;
      case C_GOTO:
        break;
      case C_IF:
        break;
      case C_FUNCTION:
        break;
      case C_RETURN:
        break;
      case C_CALL:
        break;
      default:
        break;
      }
    }
  }

  void Control::setReadFile(string filepath) {
    if (std::filesystem::exists(filepath)) {
      this->readFile = ifstream(filepath);
    } else {
      cout << "ERROR AT READING FILE" << endl;
      exit(1);
    }
  }
  void Control::setWriteFile(string filepath) {
    this->writeFile = ofstream(filepath);
  }
  ifstream &Control::getReadFile() { return this->readFile; }
  ofstream &Control::getWriteFile() { return this->writeFile; }
  Control::~Control() {
    this->readFile.close();
    this->writeFile.close();
  }
