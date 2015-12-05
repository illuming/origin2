#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;

const int n_particles = 3;

double Positions [n_particles]={0, 0, 0};
double Speeds [n_particles]={6.3, 6.3, 6.3};
char Symbols [n_particles] = {'x', 'y', 'z'};

void draw(double position, char symbol, char screen[]){
  for (int i = 0; i < position; i++) {
    screen[i] = ' ';
  }
  screen[(int) position]= symbol; 
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

void display_screen (double position, char *screen){
  for (int j = 0; j <= position; j++) {
    std::cout << screen[j];
  }
  std::cout<<"\n";
}

void clear_screen (double position, char *screen) {
  for (int j = 0; j <= position; j++) {
    screen[j] = ' ';
  }
}

int main() {
  int timeStep = 0;
  int stopTime = 60;

  char *screen = new char[maxColumn+1];

  while (timeStep < stopTime) {
  
    for (int i=0; i<n_particles; i++){
      draw (Positions[i], Symbols[i], screen);
      display_screen (Positions[i], screen);
      clear_screen (Positions[i], screen);
      Positions[i] = move (Positions[i], Speeds[i]);
    }

    timeStep++;
  }

  delete [] screen;

}
