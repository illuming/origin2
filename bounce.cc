#include <iostream>
#include <fstream>
#include "Screen.h"
#include "Particle.h"

int main() {

  int timeStep = 0;
  int stopTime = 60;

  Screen screen(maxColumn+1);

  int n_particles;
  std::ifstream in ("MyInputFile");
  if (!in) std::cerr<<"Could not open file"<<std::endl;
  else in>> n_particles;

  Particle *particles = new Particle [n_particles];

  for (int i=0; i<n_particles; i++){
    char symbol;
    double position;
    double speed;

    in>>symbol;
    in>>position;
    in>>speed;

    particles[i] = Particle(symbol, position, speed);
  }

  while (timeStep < stopTime) {
    
    for (int i=0; i<n_particles; i++){
      particles[i].m_draw (screen);
      screen.m_display_screen ((particles[i].m_position()));
      screen.m_clear_screen ((particles[i].m_position()));
      particles[i].m_move ();
    }
    
    timeStep++;
  }

  delete [] particles;

}
