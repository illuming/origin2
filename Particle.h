#ifndef Particle_h
#define Particle_h

#include "Screen.h"

const int maxColumn = 80;
const int minColumn = 0;

class Particle {
 
  char mutable m_symbol_;
  double mutable m_position_;
  double mutable m_speed_;
 
public:

  Particle (char, double, double);

  Particle ();

  Particle & operator= (const Particle& other){
    m_symbol_ = other.m_symbol_;
    m_position_ = other.m_position_;
    m_speed_ = other.m_speed_;
    return *this;
  }

  char m_symbol();
  double m_position();
  double m_speed();
  void m_draw(Screen &screen) const;
  void m_move();
};

#endif
