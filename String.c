#include "String.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

String* initialise() {
  String* Str = malloc(sizeof(String));
  StringInfo* Info = Create(&keyboardInput, &concatenate, &getSubString, &splitIntoWords, &print, &selfRemove);
  Str->len = 0;
  Str->ptr = NULL;
  Str->Info = Info;
  return Str;
}

char *myreadline(const char *prompt) {
    scanf("%*c");
    printf("%s", prompt);
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;

    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        }
        else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        }
        else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    }
    else {
        res = calloc(1, sizeof(char));
    }
    return res;
}

char *mystrchr(const char *str, int smb) {
  if(!str) return NULL;
  while (*str != '\0') {
    if(*str == (char) smb) return (char *) str;
    str++;
  }
  return NULL;
}

char *mystrtok(char *str, const char *delim) {
        static char *ptr = NULL;
        if (str) ptr = str;
        if (ptr == NULL || *ptr == '\0' || !ptr) {
                //free(ptr);
                return NULL;
        }

        while (*ptr && mystrchr(delim, *ptr)) ptr++;
        char* start = ptr;
        while (*ptr && !mystrchr(delim, *ptr)) ptr++;

        if (*ptr == '\0') {
                ptr = NULL;
                return start;
        }
        *ptr = '\0';
        ptr++;
        while (*ptr && mystrchr(delim, *ptr)) ptr++;
        return start;
}

void *keyboardInput(void* Str) {
  String* StrCasted = (String*) Str;
  printf("%d\n", StrCasted->len);
  if(StrCasted->len) free(StrCasted->ptr);
  char* ptr = myreadline("Enter you string: \n");
  StrCasted->len = strlen(ptr);
  StrCasted->ptr = ptr;
}


void* concatenate(void *Str) {
  String* StrCasted = (String*) Str;
  char* ptrCasted = (char*) StrCasted->ptr;
  char* ptr = myreadline("Enter string to concatenate: \n");
  size_t len = strlen(ptr);
  StrCasted->ptr = (StrCasted->ptr != NULL ? realloc(StrCasted->ptr, (StrCasted->len + len + 1) * sizeof(char)) : malloc((len + 1) * sizeof(char)));
  memcpy(StrCasted->ptr + StrCasted->len, ptr, len + 1);
  StrCasted->len += len;
  free(ptr);
}

void* getSubString(void *Str) {
  String* StrCasted = (String*) Str;
  if(!StrCasted->len) {
    printf("No string given.\n");
    return;
  }
  int i = -1, j = -1;
  char* msg = "";
  while(i < 0 || i >=StrCasted->len || j < 0 || j >= StrCasted->len || i > j) {
    printf("%s", msg);
    printf("Enter i j: \n");
    scanf("%d %d", &i, &j);
    msg = "Wrong input\n";
  }
  int sslen = j - i;
  char* substr = malloc(sizeof(char) * (sslen + 1));
  memcpy(substr, StrCasted->ptr + i, sslen);
  memcpy(substr + sslen, StrCasted->ptr + StrCasted->len, 1);

  String* Substr = initialise();
  Substr->ptr = substr;
  Substr->len = sslen;
  Substr->Info->print(Substr);
  Substr->Info->selfRemove(Substr);
}


void* splitIntoWords(void* Str) {
  String* StrCasted = (String*) Str;
    if(!StrCasted->len) {
    printf("Nothing to slit\n");
    return;
  }
  char *ptrCstd = (char*) StrCasted->ptr;
  char* ptrcpy = malloc(sizeof(char) * (strlen(ptrCstd) + 1));
  memcpy(ptrcpy, ptrCstd, (strlen(ptrCstd) + 1) * sizeof(char));
  char* word = mystrtok(ptrcpy, " \t");

  String** Words = malloc(sizeof(String*));
  int i = 0;
  while(word != NULL) {
    int wordLen   = strlen(word);
    Words         = realloc(Words, (i + 1) * sizeof(String*));
    Words[i]      = initialise();
    Words[i]->ptr = malloc((wordLen + 1) * sizeof(char));
    Words[i]->len = wordLen;

    memcpy(Words[i]->ptr, word, wordLen + 1);
    word = mystrtok(NULL, " \t");
    i++;
  }
  for(int k = 0; k < i; k++) {
    printf("%s\n", Words[k]->ptr);
    Words[k]->Info->selfRemove(Words[k]);
  }
  free(Words);
  free(ptrcpy);
}

void* print(void* Str) {
  String* StrCasted = (String*) Str;
  if(!StrCasted->len) {
    printf("Nothing to print\n");
    return;
  }
  printf("%s\n", ((String*) StrCasted)->ptr);
}

void* selfRemove(void *Str) {
  String* StrCasted = (String*) Str;
  if(StrCasted != NULL) free(StrCasted->ptr);
  free(StrCasted->Info);
  free(Str);
} 