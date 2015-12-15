#ifndef Array_h
#define Array_h

#include "Particle.h"

template <typename T>
class Array {
public:
  T *m_particles_;

  Array();
  Array (int);
  ~Array();
  T m_particles();
};

template<typename T>
Array<T>::Array(){}
template<typename T>
Array<T>::Array(int a) : m_particles_(new Particle [a]){};
template<typename T>
Array<T>::~Array(void){delete [] m_particles_;}
template<typename T>
T Array<T>::m_particles (){ return *m_particles_;}

/*
class Array {
public:
  Particle *m_particles_;

  Array();
  Array (int);
  ~Array();
  Particle m_particles();

};
*/

#endif
