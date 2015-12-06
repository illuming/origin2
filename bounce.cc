#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;

const int n_particles = 3;


struct Particle {
  char m_symbol;
  double m_position;
  double m_speed;
  
  void m_initialize (char sy, double po, double sp){
    m_symbol = sy;
    m_position = po;
    m_speed = sp;  
  }

  void m_draw (char screen[]){
    for (int i = 0; i < m_position; i++) {
      screen[i] = ' ';
    }
    screen[(int) m_position]= m_symbol; 
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

void display_screen (Particle const * const p, char *screen){
  for (int j = 0; j <= p->m_position; j++) {
    std::cout << screen[j];
  }
  std::cout<<"\n";
}

void clear_screen (Particle const * const p, char *screen) {
  for (int j = 0; j <= p->m_position; j++) {
    screen[j] = ' ';
  }
}

int main() {
  int timeStep = 0;
  int stopTime = 60;

  char *screen = new char[maxColumn+1];

  Particle particles [n_particles];

  particles[0].m_initialize ('x', 0, 6.3);
  particles[1].m_initialize ('y', 0, 6.3);
  particles[2].m_initialize ('z', 0, 6.3);

  while (timeStep < stopTime) {
  
    for (int i=0; i<n_particles; i++){
      particles[i].m_draw (screen);
      display_screen (&particles[i], screen);
      clear_screen (&particles[i], screen);
      particles[i].m_move ();
    }

    timeStep++;
  }

  delete [] screen;
}
