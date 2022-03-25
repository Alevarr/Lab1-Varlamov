#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  String* Str = initialise();
  menu(Str);
  Str->Info->selfRemove(Str);
}
