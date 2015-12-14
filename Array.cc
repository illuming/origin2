#include <iostream>
#include "Array.h"

Array::Array(){}
Array::Array(int a) : m_particles_(new Particle [a]){};
Array::~Array(void){delete [] m_particles_;}
Particle Array::m_particles (){ return *m_particles_;}

