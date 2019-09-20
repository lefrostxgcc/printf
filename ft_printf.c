#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf(const char *format, ...)
{
  if (!format)
    return -1;
  else if (*format == '\0')
    return 0;
  va_list ap;
  va_start(ap, format);
  if (format[0] == '%')
    {
      if (format[1] == 'c')
	{
	  char ch = va_arg(ap, int);
	  return rz_write(0, &ch, 1);
	}
      else
	{
	  const char *p = va_arg(ap, const char *);
	  if (*p == '\0')
	      return 0;
	  return rz_write(0, p, ft_strlen(p));
	}
    }
  va_end(ap);
  return rz_write(0, format, ft_strlen(format));
}
