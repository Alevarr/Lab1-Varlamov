struct StringInfo {
  void* (*keyboardInput)(void*);
  void* (*concatenate)(void*);
  void* (*getSubString)(void*);
  void* (*splitIntoWords)(void*);
  void* (*print)(void*);
  void* (*selfRemove)(void*);
} typedef StringInfo;

StringInfo* Create(void* (*keyboardInput)(void*), void* (*concatenate)(void *), void* (*getSubString)(void*), void* (*splitIntoWords)(void *), void* (*print)(void*), void* (*selfRemove)(void*));