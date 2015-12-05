#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;

char screen [80];

void draw(double position, char symbol){

  for (int i = 0; i < position; i++) {
    screen[i] = ' ';
  }
  screen[(int) position]= symbol;

  for (int i = 0; i <= position; i++) {
    std::cout << screen[i] ;
  }
  std::cout<<"\n";
}


double move (double position, double &speed){ 
  position += speed;
  if (position >= maxColumn) {
    position = maxColumn;
    speed = -speed;
  } else if (position < minColumn) {
    position = minColumn;
    speed = -speed;
  }
  return position;
}

int main() {
  char particleSymbol = 'x';
  double particlePosition = 0;
  double particleSpeed = 6.3;

  int timeStep = 0;
  int stopTime = 60;

  char particleSymbol2 = 'y';
  double particlePosition2 = 0;
  double particleSpeed2 = 6.3;

  while (timeStep < stopTime) {
  
    draw (particlePosition, particleSymbol);
    particlePosition = move (particlePosition, particleSpeed);

    draw (particlePosition2, particleSymbol2);
    particlePosition2 = move (particlePosition2, particleSpeed2);

    timeStep++;

  }

}
