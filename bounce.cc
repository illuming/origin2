#include <iostream>
#include "Screen.h"
#include "Particle.h"

const int n_particles = 3;

int main() {

  int timeStep = 0;
  int stopTime = 60;

  Screen screen(maxColumn+1);

  Particle particles [n_particles] = {
    Particle('x', 0, 6.3),   Particle('y', 0, 6.3) ,  Particle('z', 0, 6.3)};

  while (timeStep < stopTime) {
  
    for (int i=0; i<n_particles; i++){
      particles[i].m_draw (screen);
      screen.m_display_screen ((particles[i].m_position()));
      screen.m_clear_screen ((particles[i].m_position()));
      particles[i].m_move ();
    }

    timeStep++;
  }

}
