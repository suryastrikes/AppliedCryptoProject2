#include <iostream>
#include <fstream>
#include <cstdlib>
#include <exception>

using namespace std;

void prompt();
void help();
void txtToBin(ifstream&,ofstream&);
void binToTxt(ifstream&,ofstream&);
int main(int argc, char** argv) {
  //To check if the user provides the required number of args
  if (argc != 4) {
    //calls the help function which provides documentation of the program usage
    if (argc == 2 && ((strcmp(argv[1],"-h")) == 0)) {
      help();
    }
    //if they haven't provided the required number of args the display a prompt message
    else {
      prompt();
    }
  } 
  else {
    char* inputFileName = new char[sizeof(argv[1])];
    char* conversion = new char[sizeof(argv[2])];
    char* outputFileName = new char[sizeof(argv[3])];
    strcpy(inputFileName,argv[1]);
    strcpy(conversion,argv[2]);
    strcpy(outputFileName,argv[3]);
    ifstream inFile;
    ofstream outFile;
    if (strcmp(conversion,"-b") == 0) {
      inFile.open(inputFileName);
      outFile.open(outputFileName,std::ios::binary);
      txtToBin(inFile,outFile);
    }
    else if(strcmp(conversion,"-t") == 0) {
      inFile.open(inputFileName,std::ios::binary);
      outFile.open(outputFileName);
      binToTxt(inFile,outFile);
    }
    else {
      cout << "Incorrect Usage\n For more info type ./FileConverter -h\n";
    }
    
    delete inputFileName;
    delete outputFileName;
    inputFileName = NULL;
    outputFileName = NULL;
    inFile.close();
    outFile.close();
  }
  return 0;
}

void help() {
  cout << "An application to convert text files to binary files and vice-versa\n";
  cout << "Usage:\n";
  cout << "./FileConverter <InputFileName> <options> <OutputFileName>\n";
  cout << "The input and output files can be of the formats .txt and .bin\n";
  cout << "The options are -b for .txt to .bin conversion and\n";
  cout << "-t for .bin to .txt conversion\n";
  cout << "Note: The input file must exist before however the output file need not";
}

void prompt() {
  cout << "Incorrect usage\n";
  cout << "For help on using FileConverter, Type:\t./FileConverter -h\n";
}

//A function to convert input txt file to an output binary file
//Constraints: Both file must exist beforehand
void txtToBin(ifstream& inFile, ofstream& outFile) {
  //cout << "Under Construction\n";
  try {
    char c;
    inFile >> std::noskipws;
    while (inFile >> c) {
      outFile.write(reinterpret_cast<char*>(&c), sizeof(c));
    }
  }
  catch (exception& e) {
    cerr << e.what() << endl;
  }
}

//A function to convert input binary file to an output txt file
//Constraints: Both file must exist beforehand
void binToTxt(ifstream& inFile, ofstream& outFile) {
  //cout << "Under Construction\n";
  try {
    char c;
    inFile >> std::noskipws;
    while (inFile >> c) {
      outFile.write(reinterpret_cast<char*>(&c), sizeof(c));
    }
  }
  catch (exception& e) {
    cerr << e.what() << endl;
  }
}
