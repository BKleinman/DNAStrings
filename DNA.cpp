#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <random>

using namespace std;

int main(int argc, char** argv){
  if(argc < 2){
    cout << "Invalid number of command line arguments" << endl;
    return 1;
  }

  int loops = 0;
  bool passGo = true;

  while(passGo){
    ifstream inFS;
    ifstream inFS2;
    ofstream outFS;

    string dnaInput = "";
    string fileName = argv[1];

    //only entering this portion of code if we already finished the first iteration of the while loop
    if(loops != 0){
      cout << "Would you like to enter another DNA file for processing? Enter 'Y' for yes and 'N' for no." << endl;
      string check = "";
      cin >> check;
      if(check == "N" || check == "n"){
        passGo = false;
        break;
      }else if(check == "Y" || check == "y"){
        cout << "Enter the name of the file you would like to process?" << endl;
        cin >> fileName;
      }else{
        cout << "Invalid input. Terminating Program." << endl;
        passGo = false;
        break;
      }
    }


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
    float stdev = 0.0;
    float var = 0.0;
    float varNumerator = 0.0;
    int length = 0;
    int iterations = 0;

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
        } // accounting for every possible nucleotide bigram
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

    //adding all of the probabilities of the nucleotide bigrams so that I have a denominator to divide each individual probability by
    int totalBigrams = countAA + countAC + countAT + countAG +
    countCA + countCC + countCT + countCG +
    countTA + countTC + countTT + countTG +
    countGA + countGC + countGT + countGG;

    inFS2.open(fileName);

    while(!inFS2.eof()){
      inFS2 >> dnaInput;
      if (!inFS2.fail()){
        length = dnaInput.size();
        varNumerator += pow((length - meanLength), 2);
      }
    }

    var = varNumerator/iterations;
    stdev = sqrt(var);

    float probabilityA = (float)countA/totalLength;
    float probabilityC = (float)countC/totalLength;
    float probabilityT = (float)countT/totalLength;
    float probabilityG = (float)countG/totalLength;
    float probabilityAA = (float)countAA/totalBigrams;
    float probabilityAC = (float)countAC/totalBigrams;
    float probabilityAT = (float)countAT/totalBigrams;
    float probabilityAG = (float)countAG/totalBigrams;
    float probabilityCA = (float)countCA/totalBigrams;
    float probabilityCC = (float)countCC/totalBigrams;
    float probabilityCT = (float)countCT/totalBigrams;
    float probabilityCG = (float)countCG/totalBigrams;
    float probabilityTA = (float)countTA/totalBigrams;
    float probabilityTC = (float)countTC/totalBigrams;
    float probabilityTT = (float)countTT/totalBigrams;
    float probabilityTG = (float)countTG/totalBigrams;
    float probabilityGA = (float)countGA/totalBigrams;
    float probabilityGC = (float)countGC/totalBigrams;
    float probabilityGT = (float)countGT/totalBigrams;
    float probabilityGG = (float)countGG/totalBigrams;

    outFS.open("BrandonKleinman.out", ios::app);
    cout << "Printing Summary Statistics to 'BrandonKleinman.out'" << endl;

    outFS << "Name: Brandon Kleinman" << endl;
    outFS << "Student ID: 2291703" << endl;
    outFS << "Mean: " << meanLength << endl;
    outFS << "Variance: " << var << endl;
    outFS << "Standard Deviation: " << stdev << endl;
    outFS << "Probability of nucleotide 'A' : " << probabilityA << endl;
    outFS << "Probability of nucleotide 'C' : " << probabilityC << endl;
    outFS << "Probability of nucleotide 'T' : " << probabilityT << endl;
    outFS << "Probability of nucleotide 'G' : " << probabilityG << endl;
    outFS << "Probability of nucleotide bigram 'AA' : " << probabilityAA << endl;
    outFS << "Probability of nucleotide bigram 'AC' : " << probabilityAC << endl;
    outFS << "Probability of nucleotide bigram 'AT' : " << probabilityAT << endl;
    outFS << "Probability of nucleotide bigram 'AG' : " << probabilityAG << endl;
    outFS << "Probability of nucleotide bigram 'CA' : " << probabilityCA << endl;
    outFS << "Probability of nucleotide bigram 'CC' : " << probabilityCC << endl;
    outFS << "Probability of nucleotide bigram 'CT' : " << probabilityCT << endl;
    outFS << "Probability of nucleotide bigram 'CG' : " << probabilityCG << endl;
    outFS << "Probability of nucleotide bigram 'TA' : " << probabilityTA << endl;
    outFS << "Probability of nucleotide bigram 'TC' : " << probabilityTC << endl;
    outFS << "Probability of nucleotide bigram 'TT' : " << probabilityTT << endl;
    outFS << "Probability of nucleotide bigram 'TG' : " << probabilityTG << endl;
    outFS << "Probability of nucleotide bigram 'GA' : " << probabilityGA << endl;
    outFS << "Probability of nucleotide bigram 'GC' : " << probabilityGC << endl;
    outFS << "Probability of nucleotide bigram 'GT' : " << probabilityGT << endl;
    outFS << "Probability of nucleotide bigram 'GG' : " << probabilityGG << endl;

    inFS.close();
    inFS2.close();

    float a;
    float b;
    float c;
    float d;
    float e;
    string newDNA = "";
    float chance;
    //now we must generate the length of the string following the gaussian distribution
    for(int i = 0; i < 1000; ++i){
      a = rand() / (float)RAND_MAX;
      b = rand() / (float)RAND_MAX;
      c = sqrt((-2) * log(a)) * cos(M_PI * b);
      d = stdev * c + meanLength;
      e = round(d);
      newDNA = "";
      for(int i = 0; i < e; ++i){
        chance = rand() / (float)RAND_MAX;
        if(chance <= probabilityA){
          newDNA += "A";
        }else if(chance <= probabilityA + probabilityC){
          newDNA += "C";
        }else if(chance <= probabilityA + probabilityC + probabilityT){
          newDNA += "T";
        }else if(chance <= probabilityA + probabilityC + probabilityT + probabilityG){
          newDNA += "G";
        }
      }
      outFS << newDNA << endl;
    }
    loops++;
  }

  return 0;
}
