#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;

const int n_particles = 3;

class Screen {

  char *m_screen_;

public:
  Screen (int);
  Screen (const Screen &obj);
  ~Screen ();

  void m_display_screen (double);
  void m_clear_screen (double);
  char m_screen ();
  void m_put (double, char);
};

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


class Particle {
 
  char mutable m_symbol_;
  double mutable m_position_;
  double mutable m_speed_;
 
public:

  Particle (char, double, double);

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

Particle::Particle (char sy, double po, double sp)
  :m_symbol_(sy), m_position_(po), m_speed_(sp){
}

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

int main() {

  int timeStep = 0;
  int stopTime = 60;

  Screen screen(maxColumn+1);

  Particle particles [n_particles] = {
    Particle('x', 0, 6.3),   Particle('y', 0, 6.3) ,  Particle('z', 0, 6.3)};

  /*
  particles[0].m_initialize ('x', 0, 6.3);
  particles[1].m_initialize ('y', 0, 6.3);
  particles[2].m_initialize ('z', 0, 6.3);
  */
  while (timeStep < stopTime) {
  
    for (int i=0; i<n_particles; i++){
      particles[i].m_draw (screen);
      screen.m_display_screen ((particles[i].m_position()));
      screen.m_clear_screen ((particles[i].m_position()));
      particles[i].m_move ();
    }

    timeStep++;
  }

}
