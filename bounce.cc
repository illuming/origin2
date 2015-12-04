#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;

void draw(double position, char symbol){
  for (int i = 0; i < position; i++) {
    std::cout << " ";
  }
  std::cout << symbol << std::endl;
}


void move (double *position, double *speed){ 
  *position += *speed;
  if (*position >= maxColumn) {
    *position = maxColumn;
    *speed = -*speed;
  } else if (*position < minColumn) {
    *position = minColumn;
    *speed = -*speed;
  }
}


int main() {
  char particleSymbol = 'x';
  double particlePosition = 0;
  double particleSpeed = 6.3;

  int timeStep = 0;
  int stopTime = 60;


  while (timeStep < stopTime) {

  
    draw (particlePosition, particleSymbol);
    move (&particlePosition, &particleSpeed);

    timeStep++;

  }

}
