#include "StringInfo.h"
#include <stdlib.h>

StringInfo* Create(void* (*keyboardInput)(void *), void* (*concatenate)(void *), void* (*getSubString)(void*), void* (*splitIntoWords)(void *), void* (*print)(void*), void* (*selfRemove)(void*)) {
  StringInfo* sI      = (StringInfo*) malloc(sizeof(StringInfo));
  sI->keyboardInput   = keyboardInput;
  sI->concatenate     = concatenate;
  sI->getSubString    = getSubString;
  sI->splitIntoWords  = splitIntoWords;
  sI->print           = print;
  sI->selfRemove      = selfRemove;
  return sI;
}