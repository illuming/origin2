#include <iostream>
#include "Screen.h"

Screen::Screen (int screenWidth){
  m_screen_ = new char[screenWidth];
}

Screen::Screen (const Screen &obj){
  m_screen_ = obj.m_screen_; 
}

Screen::~Screen (){
  delete [] m_screen_;
}

void Screen::m_display_screen (double p){
    for (int j = 0; j <= p; j++) {
      std::cout << m_screen_[j];
    }
    std::cout<<"\n";
  }

void Screen::m_clear_screen (double p) {
    for (int j = 0; j <= p; j++) {
      m_screen_[j] = ' ';
    }
  }

char Screen::m_screen(){
    return *m_screen_;
  }

void Screen::m_put (double p, char s){
    for (int i = 0; i < p; i++) {
      m_screen_[i] = ' ';
    }
    m_screen_[(int) p]= s;
  }

