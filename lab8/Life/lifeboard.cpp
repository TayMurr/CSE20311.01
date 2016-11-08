// Lab 8 Part 2 Implementation file
#include<iostream>
#include"lifeboard.h"
#include<unistd.h>
using namespace std;
#define SIZE 40

Life::Life(){
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++) {
      Board[i][j] = ' ';

    }
  }
}

Life::~Life(){
}

void Life::addCell(int a, int b) {

  Board[a][b] = 'X'; // x denotes populated or live cell
}

void Life::removeCell(int a, int b){
  Board[a][b] = ' '; // blank space denotes unpopulated or dead cell
}



void Life::displayBoard(){

  for(int k = 0; k < SIZE; k++){
    if(k == 0){
      cout << "+";
    }
    cout << "-";
    if(k == SIZE - 1){
      cout << "+";
    }
  }
  cout << endl; //formatting purposes for the border

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++) {
      if(j == 0){
          cout << "|"; // formatting for border
      }
      cout << Board[i][j];

      if(j == SIZE - 1){
          cout << "|";
      }
    }
    cout << endl;
  }

  for(int k = 0; k < SIZE; k++){
    if(k == 0){
      cout << "+";
    }
    cout << "-";
    if(k == SIZE - 1){
      cout << "+";
    }
  }
  cout << endl;
  usleep(200000);
  system("clear");
}

void Life::setBoard(){
  Life tempBoard;
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++) {
      int numAlive = 0; // used to count up number of lives neighbors for game of life rules
      //these conditionals look to see if the indices in contained in the bounds of the array
        if((j-1 >= 0) && (i - 1 >= 0) && Board[i-1][j-1] == 'X'){
          numAlive++;
        }
        if((i - 1 >= 0) && Board[i-1][j] == 'X'){
          numAlive++;
        }
        if((i - 1 >= 0) && (j + 1 < SIZE) && Board[i-1][j+1] == 'X'){
          numAlive++;
        }
        if((j-1 >= 0) && Board[i][j-1] == 'X'){
          numAlive++;
        }
        if((j + 1 < SIZE) && Board[i][j+1] == 'X'){
          numAlive++;
        }

        if((i + 1 < SIZE) && (j-1 >= 0) && Board[i+1][j-1] == 'X'){
        numAlive++;
        }
        if((i + 1 < SIZE) && Board[i+1][j] == 'X'){
        numAlive++;
        }
        if((i + 1 < SIZE) && (j + 1 < SIZE) && Board[i+1][j+1] == 'X'){
          numAlive++;
        }

      if(Board[i][j] == 'X'){
        if(numAlive < 2){
          tempBoard.Board[i][j] = ' ';
        }
        if(numAlive == 2 || numAlive == 3){
          tempBoard.Board[i][j] = 'X';
        }
        if(numAlive > 3){
          tempBoard.Board[i][j] = ' ';
        }
      }

      if(Board[i][j] == ' '){
        if(numAlive == 3){
          tempBoard.Board[i][j] = 'X';
        }
      }
    }
  }

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++) {
      Board[i][j] = tempBoard.Board[i][j];
    }
  }

}

void Life::play(){
  // play game of life forever as specified in class assignment
  while(1){
    setBoard();
    displayBoard();
  }
}
