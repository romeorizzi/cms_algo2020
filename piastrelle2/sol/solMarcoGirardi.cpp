#include <fstream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
using namespace std;

ofstream out("output.txt");
/*
void piastrelle (int N, string history) {
  assert (N>=0);
  if (N==1) out<< history << "[O]"<< endl;
  else if (N==0) out << history << endl;
  else{
    piastrelle(N-1, history + "[O]");
    piastrelle (N-2, history + "[OOOO]");
  }
}
*/

int countPiastrelle (int i, int j){
  //cout << "called with input (" << i << "," << j << ")"<<endl;
  if (i<0 || j < 0){
    return 0;
  }   
  else if (i==0 && j==0){
    return 1;
  }
  else if (i > j){
    return (countPiastrelle(i-1, j) + countPiastrelle(i-2, j));
  }
  else if (j > i){
    return (countPiastrelle(i, j-1) + countPiastrelle(i, j-2));
  }
  else if (j==i){
    return (countPiastrelle(i-1, j) + countPiastrelle (i-2, j) + countPiastrelle (i-1, j-1));
  }
  else{
    cout << "whoops!" << endl;
    return -42;
  }
}

void drawPiastrelle (int i, int j, string firstLine, string secondLine, int nextPiastrella){
  //nextPiastrella = (nextPiastrella % 5) +1;
  //cout << "called with input (" << i << "," << j << ")"<<endl;
  if (i<0 || j < 0){
    //cout << "DO NOTHING" << endl;
  }   
  else if (i==0 && j==0){
    out << endl << firstLine << endl<< secondLine << endl;
  }
  else if (i > j){//put things in firstline
    firstLine = firstLine + to_string(nextPiastrella%5+1) + " ";
    drawPiastrelle(i-1, j, firstLine, secondLine, nextPiastrella+1);
    firstLine = firstLine + to_string(nextPiastrella%5+1)+ " ";
    drawPiastrelle(i-2, j, firstLine, secondLine, nextPiastrella+1);
  }
  else if (j > i){//put things in secondline
    //return (countPiastrelle(i, j-1) + countPiastrelle(i, j-2));
    secondLine = secondLine + to_string(nextPiastrella%5+1)+ " ";
    drawPiastrelle(i, j-1, firstLine, secondLine, nextPiastrella+1);
    secondLine = secondLine + to_string(nextPiastrella%5+1)+ " ";
    drawPiastrelle(i, j-2, firstLine, secondLine, nextPiastrella+1);
  }
  else if (j==i){
    //return (countPiastrelle(i-1, j) + countPiastrelle (i-2, j) + countPiastrelle (i-1, j-1));
    firstLine = firstLine + to_string(nextPiastrella%5+1)+ " ";
    drawPiastrelle(i-1, j, firstLine, secondLine, nextPiastrella+1);
    string temp = secondLine + to_string(nextPiastrella%5+1)+ " ";
    drawPiastrelle (i-1, j-1, firstLine, temp, nextPiastrella+1);
    firstLine = firstLine + to_string(nextPiastrella%5+1)+ " ";
    drawPiastrelle(i-2, j, firstLine, secondLine, nextPiastrella+1);
  }
  else{
    cout << "whoops!" << endl;
  }
}

/*
void drawPiastrelle (int i, int j, string firstLine, string secondLine, int nextPiastrella){
  nextPiastrella = (nextPiastrella % 5) +1;
  //cout << "called with input (" << i << "," << j << ")"<<endl;
  if (i<0 || j < 0){
    //cout << "DO NOTHING" << endl;
  }   
  else if (i==0 && j==0){
    out << endl << firstLine << endl<< secondLine << endl;
  }
  else if (i > j){//put things in firstline
    firstLine = firstLine + to_string(nextPiastrella) + " ";
    drawPiastrelle(i-1, j, firstLine, secondLine, nextPiastrella+1);
    firstLine = firstLine + to_string(nextPiastrella) + " ";
    drawPiastrelle(i-2, j, firstLine, secondLine, nextPiastrella+1);
  }
  else if (j > i){//put things in secondline
    //return (countPiastrelle(i, j-1) + countPiastrelle(i, j-2));
    secondLine = secondLine + to_string(nextPiastrella) + " ";
    drawPiastrelle(i, j-1, firstLine, secondLine, nextPiastrella+1);
    secondLine = secondLine + to_string(nextPiastrella) + " ";
    drawPiastrelle(i, j-2, firstLine, secondLine, nextPiastrella+1);
  }
  else if (j==i){
    //return (countPiastrelle(i-1, j) + countPiastrelle (i-2, j) + countPiastrelle (i-1, j-1));
    firstLine = firstLine + to_string(nextPiastrella) + " ";
    drawPiastrelle(i-1, j, firstLine, secondLine, nextPiastrella+1);
    string temp = secondLine + to_string(nextPiastrella) + " ";
    drawPiastrelle (i-1, j-1, firstLine, temp, nextPiastrella+1);
    firstLine = firstLine + to_string(nextPiastrella) + " ";
    drawPiastrelle(i-2, j, firstLine, secondLine, nextPiastrella+1);
  }
  else{
    cout << "whoops!" << endl;
  }
}
*/



int main(){
  ifstream in("input.txt");
  int N;
  in >> N;
 
  //piastrelle(N, "");
  int nPiast = countPiastrelle(N,N);
  out << nPiast;
  drawPiastrelle(N, N, "", "", 0);
  //string prova = "ciao";
  //prova = prova +" patata" + " culo" + to_string(1) + " uno" ;
  //cout << prova << endl;
  return 0;
}
