#include <algorithm>
#include <iostream>
#include <list>
#include <ncurses.h>

int main(int argc, char** argv) {
  std::list<int> registers({59, 108, 107, 106});
  int RESET = 39;
  int SUBMIT = 32;

  initscr();
  clear();
  noecho();
  cbreak();

  int result = 0;
  int state = 1;
  while(true) {
    int ch = getch();

    auto it = std::find(registers.begin(), registers.end(), ch);
    if(it != registers.end()) {
      result |= 1 << (std::distance(registers.begin(), it) + state * 4);
    }
    if(ch == RESET) {
      state = 1;
      result = 0;
    }
    if(ch == SUBMIT) {
      if(state == 1) { state = 0; }
      else if(state == 0) {
        addch(char(result));
        state = 1;
        result = 0;
      }
    }
  }

  return(0);
}
