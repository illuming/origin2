#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;

const int n_particles = 3;


struct Particle {
  char symbol;
  double position;
  double speed;
};

void draw(Particle const * const p, char screen[]){
  for (int i = 0; i < (*p).position; i++) {
    screen[i] = ' ';
  }
  screen[(int) (*p).position]= (*p).symbol; 
}

void move (Particle * const p){ 
  (*p).position += (*p).speed;
  if ((*p).position >= maxColumn) {
    (*p).position = maxColumn;
    (*p).speed = -(*p).speed;
  } else if ((*p).position < minColumn) {
    (*p).position = minColumn;
    (*p).speed = -(*p).speed;
  }
}

void display_screen (Particle const * const p, char *screen){
  for (int j = 0; j <= (*p).position; j++) {
    std::cout << screen[j];
  }
  std::cout<<"\n";
}

void clear_screen (Particle const * const p, char *screen) {
  for (int j = 0; j <= (*p).position; j++) {
    screen[j] = ' ';
  }
}

int main() {
  int timeStep = 0;
  int stopTime = 60;

  char *screen = new char[maxColumn+1];

  Particle particles [n_particles];

  particles[0].symbol = 'x';
  particles[1].symbol = 'y';
  particles[2].symbol = 'z'; 
  particles[0].position = particles[1].position = particles[2].position = 0;
  particles[0].speed = particles[1].speed = particles[2].speed = 6.3;

  while (timeStep < stopTime) {
  
    for (int i=0; i<n_particles; i++){
      draw (&(particles[i]), screen);
      display_screen (&(particles[i]), screen);
      clear_screen (&(particles[i]), screen);
      move (&(particles[i]));
    }

    timeStep++;
  }

  delete [] screen;
}
