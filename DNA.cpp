/**
Brandon Kleinman
2291703
kleinman@chapman.edu
CPSC-350-02
Assignment 1
The purpose of this assignment is to read in a .txt file containing DNA strings, calculate the mean, length,
and standard deviation of the length of all read DNA strings, calculate the probability of each nucleotide and
nucleotide bigram, and then generate 1000 new DNA strings based on a gaussian distribution built by the summary Statistics
of the file that we read and the nucleotide bigram probabilities
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <random>

using namespace std;

int main(int argc, char** argv){
  //checking for proper number of command line arguements
  if(argc < 2){
    cout << "Invalid number of command line arguments" << endl;
    return 1;
  }

  //intitializing variables that will control the while loop and if statement below
  int loops = 0;
  bool passGo = true;

  while(passGo){
    //initializing streams and strings that will help the streams for input and output
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
      if(check == "N" || check == "n"){ //break if user does not want to process another DNA sequence file
        passGo = false;
        break;
      }else if(check == "Y" || check == "y"){ //prompts the user for the name of the DNA sequence file that is to be processed
        cout << "Enter the name of the file you would like to process?" << endl;
        cin >> fileName;
      }else{
        cout << "Invalid input. Terminating program." << endl;
        return 1;
      }
    }

    //intitializing variables that I will use throughout the program
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

    //initializing variables that relate to statistics
    int totalLength = 0;
    int meanLength = 0;
    float stdev = 0.0;
    float var = 0.0;
    float varNumerator = 0.0;
    int length = 0;
    int iterations = 0;

    //opening the file using the inFS stream
    cout << "Opening file " << fileName << endl;
    inFS.open(fileName);

    cout << "Reading in DNA strings" << endl;
    //here we begin reading from the file
    while(!inFS.eof()){
      inFS >> dnaInput;
      if (!inFS.fail()){
        string dnaUpper = "";
        for(int i = 0; i < dnaInput.size(); ++i){
          dnaUpper += toupper(dnaInput[i]);
        }
        for(int i = 0; i < dnaUpper.size(); ++i){
          //iterating through each DNA sequence to get the count of each nucleotide
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
        }if(dnaUpper.find("AC") != std::string::npos){ //using if for all of the boolean expressions so that for example ACT will recognize bigram AC and CT
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
    meanLength = totalLength/iterations; //calculating the mean length of the DNA sequences

    //adding all of the probabilities of the nucleotide bigrams so that I have a denominator to divide each individual probability by
    int totalBigrams = countAA + countAC + countAT + countAG +
    countCA + countCC + countCT + countCG +
    countTA + countTC + countTT + countTG +
    countGA + countGC + countGT + countGG;

    //opening a new file in stream to avoid complications of reading a file twice
    inFS2.open(fileName);

    //reading through the file again to calculate variance and then derive standard deviation from variance
    while(!inFS2.eof()){
      inFS2 >> dnaInput;
      if (!inFS2.fail()){
        length = dnaInput.size();
        varNumerator += pow((length - meanLength), 2); //calculating the numerator of the variance equation
      }
    }

    //calcuating variance and standard deviation
    var = varNumerator/iterations;
    stdev = sqrt(var);

    //making calculations for the probabilities of the occurence of each nucleotide and nucleotide bigram
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

    //opening the out stream which I use to append to the BrandonKleinman.out file
    outFS.open("BrandonKleinman.out", ios::app);
    cout << "Printing Summary Statistics to 'BrandonKleinman.out'" << endl;

    //printing all of the summary statistics and probabilites using the outFS stream
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

    //closing the inFS and inFS2 streams
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
      a = rand() / (float)RAND_MAX; //creating a float between 0 and 1
      b = rand() / (float)RAND_MAX; // we divide by RAND_MAX so that the scale of rand() shrinks from [0, RAND_MAX) to [0,1)
      c = sqrt((-2) * log(a)) * cos(M_PI * b); //creating a gaussian distribtion with mean 0 and variance 1, box muller transform
      d = stdev * c + meanLength;
      e = round(d); //rounding to get an integer
      newDNA = "";
      for(int i = 0; i < e; ++i){
        chance = rand() / (float)RAND_MAX;
        if(chance <= probabilityA){ //using the probabilities to create the appropriate distrubtion of the number of each nucleotide
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
    loops++; //counting the number of loops to control whether the user wants to process another file

    outFS.close(); //closing the out stream
  }

  return 0;
}
