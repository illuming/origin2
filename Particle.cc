#include <iostream>
#include "Particle.h"


Particle::Particle(){}

Particle::Particle (char sy, double po, double sp)
  :m_symbol_(sy), m_position_(po), m_speed_(sp){}

char Particle::m_symbol (){return m_symbol_;}
  
double Particle::m_position (){return m_position_;}
  
double Particle::m_speed (){return m_speed_;}
  
void Particle::m_draw (Screen &screen) const {
  screen.m_put(m_position_, m_symbol_);  
}

void Particle::m_move (){ 
    m_position_ += m_speed_;
    if (m_position_ >= maxColumn) {
      m_position_ = maxColumn;
      m_speed_ = -m_speed_;
    } else if (m_position_ < minColumn) {
      m_position_ = minColumn;
      m_speed_ = -m_speed_;
    }
}



MagicParticle::MagicParticle(){}

MagicParticle::MagicParticle (char sy, double po, double sp){
  m_symbol_=sy;
  m_position_=po;
  m_speed_=sp;
}

void MagicParticle::m_move(){
    m_position_ += m_speed_;
    if (m_position_ >= maxColumn) {
      m_position_ = minColumn;
      m_speed_ = m_speed_;
    } else if (m_position_ < minColumn) {
      m_position_ = maxColumn;
      m_speed_ = m_speed_;
    }
}
