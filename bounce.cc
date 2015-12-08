#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;

const int n_particles = 3;

struct Screen {

  char *m_screen;

  void m_initialize (){
    m_screen = new char[maxColumn+1];
  }

  void m_display_screen (double *p){
    for (int j = 0; j <= *p; j++) {
      std::cout << m_screen[j];
    }
    std::cout<<"\n";
  }

  void m_clear_screen (double *p) {
    for (int j = 0; j <= *p; j++) {
      m_screen[j] = ' ';
    }
  }

  void m_delete (){
  delete [] m_screen;
  }

};


struct Particle {
  char mutable m_symbol;
  double mutable m_position;
  double mutable m_speed;
  
  void m_initialize (char sy, double po, double sp){
    m_symbol = sy;
    m_position = po;
    m_speed = sp;  
  }

  void m_draw (Screen screen) const {
    for (int i = 0; i < m_position; i++) {
      screen.m_screen[i] = ' ';
    }
    screen.m_screen[(int) m_position]= m_symbol;
  }

  void m_move (){ 
    m_position += m_speed;
    if (m_position >= maxColumn) {
      m_position = maxColumn;
      m_speed = -m_speed;
    } else if (m_position < minColumn) {
      m_position = minColumn;
      m_speed = -m_speed;
    }
  }
};

int main() {
  int timeStep = 0;
  int stopTime = 60;

  Screen screen;

  Particle particles [n_particles];

  particles[0].m_initialize ('x', 0, 6.3);
  particles[1].m_initialize ('y', 0, 6.3);
  particles[2].m_initialize ('z', 0, 6.3);

  while (timeStep < stopTime) {
  
    for (int i=0; i<n_particles; i++){
      screen.m_initialize();
      particles[i].m_draw (screen);
      screen.m_display_screen (&(particles[i].m_position));
      screen.m_clear_screen (&(particles[i].m_position));
      particles[i].m_move ();
    }

    timeStep++;
  }

  screen.m_delete();
}

    
