#ifndef Array_h
#define Array_h

#include "Particle.h"

class Array {
public:
  Particle *m_particles_;

  Array();
  Array (int);
  ~Array();
  Particle m_particles();

};

#endif
