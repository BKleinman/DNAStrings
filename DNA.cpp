#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char** argv){
  if(argc < 2){
    cout << "Invalid amount of command line arguments" << endl;
    return 1;
  }

  ifstream inFS;
  ifstream inFS2;
  ofstream outFS;
  string dnaInput = "";
  string fileName = argv[1];

  int iterations = 0;
  int countA = 0;
  int countT = 0;
  int countC = 0;
  int countG = 0;
  int countAA = 0;
  int countAC = 0;
  int countAT = 0;
  int countAG = 0;
  int countCA = 0;
  int countCC = 0;
  int countCT = 0;
  int countCG = 0;
  int countTA = 0;
  int countTC = 0;
  int countTT = 0;
  int countTG = 0;
  int countGA = 0;
  int countGC = 0;
  int countGT = 0;
  int countGG = 0;
  int totalLength = 0;
  int meanLength = 0;

  float std = 0.0;
  float var = 0.0;
  float varNumerator = 0.0;
  int length = 0;

  cout << "Opening file " << fileName << endl;
  inFS.open(fileName);
  cout << "Reading in DNA strings" << endl;

  while(!inFS.eof()){
    inFS >> dnaInput;
    if (!inFS.fail()){
      string dnaUpper = "";
      for(int i = 0; i < dnaInput.size(); ++i){
        dnaUpper += toupper(dnaInput[i]);
      }
      for(int i = 0; i < dnaUpper.size(); ++i){
        char c = dnaUpper[i];
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
      if(dnaUpper.find("AA") != std::string::npos){
        countAA++;
      }if(dnaUpper.find("AC") != std::string::npos){
        countAC++;
      }if(dnaUpper.find("AT") != std::string::npos){
        countAT++;
      }if(dnaUpper.find("AG") != std::string::npos){
        countAG++;
      }if(dnaUpper.find("CA") != std::string::npos){
        countCA++;
      }if(dnaUpper.find("CC") != std::string::npos){
        countCC++;
      }if(dnaUpper.find("CT") != std::string::npos){
        countCT++;
      }if(dnaUpper.find("CG") != std::string::npos){
        countCG++;
      }if(dnaUpper.find("TA") != std::string::npos){
        countTA++;
      }if(dnaUpper.find("TC") != std::string::npos){
        countTC++;
      }if(dnaUpper.find("TT") != std::string::npos){
        countTT++;
      }if(dnaUpper.find("TG") != std::string::npos){
        countTG++;
      }if(dnaUpper.find("GA") != std::string::npos){
        countGA++;
      }if(dnaUpper.find("GC") != std::string::npos){
        countGC++;
      }if(dnaUpper.find("GT") != std::string::npos){
        countGT++;
      }if(dnaUpper.find("GG") != std::string::npos){
        countGG++;
      }
      totalLength += dnaInput.size();
      iterations += 1;
    }
  }
  meanLength = totalLength/iterations;

  inFS2.open(fileName);

  while(!inFS2.eof()){
    inFS2 >> dnaInput;
    if (!inFS2.fail()){
      length = dnaInput.size();
      varNumerator += pow((length - meanLength), 2);
    }
  }

  var = varNumerator/iterations;
  std = sqrt(var);

  float probabilityA = (float)countA/totalLength;
  float probabilityC = (float)countC/totalLength;
  float probabilityT = (float)countT/totalLength;
  float probabilityG = (float)countG/totalLength;
  float probabilityAA = (float)countAA/totalLength;
  float probabilityAC = (float)countAC/totalLength;
  float probabilityAT = (float)countAT/totalLength;
  float probabilityAG = (float)countAG/totalLength;
  float probabilityCA = (float)countCA/totalLength;
  float probabilityCC = (float)countCC/totalLength;
  float probabilityCT = (float)countCT/totalLength;
  float probabilityCG = (float)countCG/totalLength;
  float probabilityTA = (float)countTA/totalLength;
  float probabilityTC = (float)countTC/totalLength;
  float probabilityTT = (float)countTT/totalLength;
  float probabilityTG = (float)countTG/totalLength;
  float probabilityGA = (float)countGA/totalLength;
  float probabilityGC = (float)countGC/totalLength;
  float probabilityGT = (float)countGT/totalLength;
  float probabilityGG = (float)countGG/totalLength;

  outFS.open("BrandonKleinman.out", ios::app);

  outFS << "Mean " << meanLength << endl;
  outFS << "Variance " << var << endl;
  outFS << "Standard Deviation " << std << endl;
  outFS << "Probability of nucleotide 'A' " << probabilityA << endl;
  outFS << "Probability of nucleotide 'C' " << probabilityC << endl;
  outFS << "Probability of nucleotide 'T' " << probabilityT << endl;
  outFS << "Probability of nucleotide 'G' " << probabilityG << endl;
  outFS << "Probability of nucleotide bigram 'AA' " << probabilityAA << endl;
  outFS << "Probability of nucleotide bigram 'AC' " << probabilityAC << endl;
  outFS << "Probability of nucleotide bigram 'AT' " << probabilityAT << endl;
  outFS << "Probability of nucleotide bigram 'AG' " << probabilityAG << endl;
  outFS << "Probability of nucleotide bigram 'CA' " << probabilityCA << endl;
  outFS << "Probability of nucleotide bigram 'CC' " << probabilityCC << endl;
  outFS << "Probability of nucleotide bigram 'CT' " << probabilityCT << endl;
  outFS << "Probability of nucleotide bigram 'CG' " << probabilityCG << endl;
  outFS << "Probability of nucleotide bigram 'TA' " << probabilityTA << endl;
  outFS << "Probability of nucleotide bigram 'TC' " << probabilityTC << endl;
  outFS << "Probability of nucleotide bigram 'TT' " << probabilityTT << endl;
  outFS << "Probability of nucleotide bigram 'TG' " << probabilityTG << endl;
  outFS << "Probability of nucleotide bigram 'GA' " << probabilityGA << endl;
  outFS << "Probability of nucleotide bigram 'GC' " << probabilityGC << endl;
  outFS << "Probability of nucleotide bigram 'GT' " << probabilityGT << endl;
  outFS << "Probability of nucleotide bigram 'GG' " << probabilityGG << endl;



  return 0;
}
