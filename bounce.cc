#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;

const int n_particles = 3;

char screen [80];
double Positions [n_particles]={0, 0, 0};
double Speeds [n_particles]={6.3, 6.3, 6.3};
char Symbols [n_particles] = {'x', 'y', 'z'};

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
  int timeStep = 0;
  int stopTime = 60;

  while (timeStep < stopTime) {
  
    for (int i=0; i<n_particles; i++){
    draw (Positions[i], Symbols[i]);
    Positions[i] = move (Positions[i], Speeds[i]);
    }

    timeStep++;

  }

}
