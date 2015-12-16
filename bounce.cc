#include <iostream>
#include <fstream>
#include <vector>
#include "Screen.h"
#include "Particle.h"
#include "Array.h"
  
int main() {
  
  int timeStep = 0;
  int stopTime = 60;

  Screen screen(maxColumn+1);

  int n_particles;
  std::ifstream in ("MyInputFile");
  if (!in) std::cerr<<"Could not open file"<<std::endl;
  else in>> n_particles;

  Array <MagicParticle> particles(n_particles);

  for (int i=0; i<n_particles; i++){
    char symbol;
    double position;
    double speed;

    in>>symbol;
    in>>position;
    in>>speed;

    particles.m_particles_.push_back(MagicParticle(symbol, position, speed)); //*   se il constructor di Array(int) contiene reserve(int) 
    //particles.m_particles_[i]=Particle(symbol, position, speed);   *se il constructor di Array(int) contiene resize(int)
  }

  while (timeStep < stopTime) {
        
    for (int i=0; i<n_particles; i++){
      particles.m_particles_[i].m_draw (screen);
      screen.m_display_screen (particles.m_particles_[i].m_position());
      screen.m_clear_screen ((particles.m_particles_[i].m_position()));
      particles.m_particles_[i].m_move ();
    }
    
    timeStep++;
  }

  
}
