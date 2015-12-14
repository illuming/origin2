#ifndef Screen_h
#define Screen_h

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

#endif
