#include <iostream>
#include <fstream>
#include "Screen.h"
#include "Particle.h"
//#include "Array.h"

template <typename T>
class Array2 {
public:
  T *m_particles_;

  Array2();
  Array2 (int);
  ~Array2();
  T m_particles();
};

template<typename T>
Array2<T>::Array2(){}
template<typename T>
Array2<T>::Array2(int a) : m_particles_(new Particle [a]){};
template<typename T>
Array2<T>::~Array2(void){delete [] m_particles_;}
template<typename T>
T Array2<T>::m_particles (){ return *m_particles_;}


int main() {

  int timeStep = 0;
  int stopTime = 60;

  Screen screen(maxColumn+1);

  int n_particles;
  std::ifstream in ("MyInputFile");
  if (!in) std::cerr<<"Could not open file"<<std::endl;
  else in>> n_particles;

  Array2 <Particle> particles(n_particles);

  for (int i=0; i<n_particles; i++){
    char symbol;
    double position;
    double speed;

    in>>symbol;
    in>>position;
    in>>speed;
    
    particles.m_particles_[i]=Particle(symbol, position, speed);
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
