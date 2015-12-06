#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;

const int n_particles = 3;


struct Particle {
  char symbol;
  double position;
  double speed;
  
  void initialize (char sy, double po, double sp){
    symbol = sy;
    position = po;
    speed = sp;  
  }

  void draw (char screen[]){
    for (int i = 0; i < position; i++) {
      screen[i] = ' ';
    }
    screen[(int) position]= symbol; 
  }

  void move (){ 
    position += speed;
    if (position >= maxColumn) {
      position = maxColumn;
      speed = -speed;
    } else if (position < minColumn) {
      position = minColumn;
      speed = -speed;
    }
  }
};

void display_screen (Particle const * const p, char *screen){
  for (int j = 0; j <= p->position; j++) {
    std::cout << screen[j];
  }
  std::cout<<"\n";
}

void clear_screen (Particle const * const p, char *screen) {
  for (int j = 0; j <= p->position; j++) {
    screen[j] = ' ';
  }
}

int main() {
  int timeStep = 0;
  int stopTime = 60;

  char *screen = new char[maxColumn+1];

  Particle particles [n_particles];

  particles[0].initialize ('x', 0, 6.3);
  particles[1].initialize ('y', 0, 6.3);
  particles[2].initialize ('z', 0, 6.3);

  while (timeStep < stopTime) {
  
    for (int i=0; i<n_particles; i++){
      particles[i].draw (screen);
      display_screen (&particles[i], screen);
      clear_screen (&particles[i], screen);
      particles[i].move ();
    }

    timeStep++;
  }

  delete [] screen;
}
