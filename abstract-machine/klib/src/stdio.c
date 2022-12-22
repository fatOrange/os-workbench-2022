#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>


#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap,fmt);
  int i = 1;
  int x = 0;
  char output = 0;
  // 去掉第一个
  va_arg(ap,char);
  while(fmt[i])
  {
    if(fmt[i] == '%')
    {
      // 跳过% 并对接下来的值进行分析
      i++;
      switch(fmt[i])
      {
        case 'd':
        {
          x =va_arg(ap,int);
          
          break;
        }
      }
      
    }
    else
    {
      output = fmt[i];
    }
    putch();
    i++;

  }
  va_end(ap);
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  panic("Not implemented");
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
