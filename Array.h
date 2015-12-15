#ifndef Array_h
#define Array_h

#include <vector>

#include "Particle.h"

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

#endif
