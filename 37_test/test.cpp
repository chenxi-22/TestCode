#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

#define MAX 255

int main()
{
  char str[MAX] = {0};
  cin>>str;
  int i = 0;
  int start = 0;
  int end = 0;
  int _start;
  int _end;
  int max = 0;
  while (str[i] != '\0') {
    if (isdigit(str[i])) {
      _start = i;
      while (str[i] != '\0' && isdigit(str[i])) {
        i++;
      }
      _end = i;
      if (max < _end - _start) {
        max = _end - _start;
        start = _start;
        end = _end;
      }
      if (str[i] == '\0') {
        break;
      }
    }
    i++;
  }
  while (start < end) {
    cout<<str[start++];
  }
  return 0;
}
