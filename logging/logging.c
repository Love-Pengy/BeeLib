#define LOG(s, data...) argFunc("%s (%d): %s", __FILE__, __LINE__, s, ##data)   
void argFunc(char *formatString, ...) {
  va_list list;
  int d;
  char c;
  /*char *s;*/
  /*long l;*/
  /*long long ll;*/
  /*float f; */
  va_start(list, formatString);
  char test;
  char buff[8192];
  vsnprintf(buff, 8192, formatString, list);
  /*printf("WRITTEN: %d\n",d); */
  printf("%s\n", buff);
  /*printf("%p\n", __builtin_return_address(0));*/
  va_end(list);
}

