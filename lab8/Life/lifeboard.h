// Taylor Murray Lab 8 Part 2: lifeboard.h
// PLEASE READ!!!!!!! This program was made under the assumption that
// we were to DISPLAY a 40 by 40 array. 
#define SIZE 40
#define SIZE2 41
class Life {
  public:
    Life();
    ~Life();
    void addCell(int, int);
    void removeCell(int, int);
    void displayBoard();
    void setBoard();
    void play();

    //void play();
  private:
    char Board[SIZE][SIZE2];
};
