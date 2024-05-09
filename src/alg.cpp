// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Tree;
  std::ifstream file(filename);
  std::string strfile = "";
  if (!file) {
    std::cout << "Ошибка файла!" << std::endl;
    return Tree;
  }
  while (!file.eof()) {
    char ch = file.get();
    strfile += ch;
  }
  for (char& c : strfile) {
    c = std::tolower(c);
  }
  int length = strfile.length();
  bool inWord = false;
  std::string temp = "";
  for (int i = 0; i < length; i++) {
    if (strfile[i] >= 'a' && strfile[i] <= 'z') {
      inWord = true;
    } else {
      inWord = false;
    }
    if (inWord) {
      temp += strfile[i];
    } else {
      Tree.add(temp);
      temp = "";
    }
  }
  file.close();
  return Tree;
}
