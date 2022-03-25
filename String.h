#include "StringInfo.h"

struct String {
  StringInfo* Info;
  int len;
  void* ptr;
} typedef String;

String* initialise();
void* keyboardInput(void* Str);
void* concatenate(void* Str);
void* getSubString(void* Str);
void* splitIntoWords(void* Str);
void* print(void* Str);
void* selfRemove(void* Str);


