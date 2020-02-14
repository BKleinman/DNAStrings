#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
  if(argc < 2){
    cout << "Invalid amount of command line arguments" << endl;
    return 1;
  }

  ifstream inFS;
  ofstream outFS;
  string dnaInput;
  string fileName = argv[1];
  string sizes = ""

  int iterations = 0;
  int countA = 0;
  int countT = 0;
  int countC = 0;
  int countG = 0;
  int lineCount = 0;
  int totalLength = 0;

  cout << "Opening file " << fileName << endl;
  inFS.open(fileName);
  outFS.open("BrandonKleinman.out", ios::app);

  cout << "Reading in DNA strings" << endl;

  while(!inFS.eof()){
    inFS >> dnaInput;
    if (!inFS.fail()){
      dnaInput = toUpper(dnaInput);
      for(int i = 0; i < dnaInput.size(); ++i){
        char c = dnaInput[i];
        if(c == 'A'){
          countA++;
        }else if(c == 'C'){
          countC++;
        }else if(c == 'T'){
          countT++;
        }else if(c == 'G'){
          countG++;
        }
      }
      totalLength += dnaInput.size();
      sizes.append(itoa(dnaInput.size()));



    }
    iterations++;
  }

  int meanLength = totalLength/iterations;




  return 0;
}
