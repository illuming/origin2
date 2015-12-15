#include <iostream>
#include <fstream>
#include <vector>
#include "Screen.h"
#include "Particle.h"
#include "Array.h"

/*
template <typename T>
class Array {
public:
  std::vector <T> m_particles_;

  Array();
  Array (int);
  ~Array();

  int Size();
  int Capacity();

};

template<typename T>
Array<T>::Array(){}
template<typename T>
Array<T>::Array(int a){m_particles_.reserve(a);}
template<typename T>
//Array<T>::Array(int a){m_particles_.resize(a);}
//template<typename T>
int Array<T>::Size(){return m_particles_.size();}
template<typename T>
int Array<T>::Capacity(){return m_particles_.capacity();}
template<typename T>
Array<T>::~Array(void){}
*/

int main() {
  
  int timeStep = 0;
  int stopTime = 60;

  Screen screen(maxColumn+1);

  int n_particles;
  std::ifstream in ("MyInputFile");
  if (!in) std::cerr<<"Could not open file"<<std::endl;
  else in>> n_particles;

  Array <Particle> particles(n_particles);

  for (int i=0; i<n_particles; i++){
    char symbol;
    double position;
    double speed;

    in>>symbol;
    in>>position;
    in>>speed;

    particles.m_particles_.push_back(Particle(symbol, position, speed)); //*   se il constructor di Array(int) contiene reserve(int) 
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
