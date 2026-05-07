*This project has been created as part of the 42 curriculum by abrandao.*

# ft_printf

## 📝 Description
The goal of this project is to recode the famous C library function `printf`. It is a fundamental exercise that teaches about **variadic functions** in C and how to handle different data types through a single entry point. The project involves parsing a format string and implementing various conversions such as characters, strings, integers, and hexadecimals.

**Supported conversions:**
* `%c` Prints a single character.
* `%s` Prints a string.
* `%p` Prints a void * pointer in hexadecimal format.
* `%d` Prints a decimal (base 10) number.
* `%i` Prints an integer in base 10.
* `%u` Prints an unsigned decimal (base 10) number.
* `%x` Prints a number in hexadecimal (base 16) lowercase format.
* `%X` Prints a number in hexadecimal (base 16) uppercase format.
* `%%` Prints a percent sign.

## 🛠️ Instructions

### Compilation

To compile the library:

```bash
make
```

This generates the static library:

```bash
libftprintf.a
```
---
### Example Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "42");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```
---
## 🧠 Algorithm & Data Structure Choices

### Parsing Algorithm

`ft_printf` uses a linear parsing algorithm that scans the format string character
by character.

- Regular characters are printed directly
- When a `%` is found, the next character is interpreted as a format specifier
- The corresponding printing function is then called

This approach was chosen because it is simple, efficient, and closely reproduces
the behavior of the original `printf`.

---

### Variadic Arguments

The project uses variadic functions through the `<stdarg.h>` library.

The `va_list` type and its associated macros (`va_start`, `va_arg`, and `va_end`)
allow `ft_printf` to receive and process an unknown number of arguments depending
on the format string.

## 📚 Resources

- GNU C Library Documentation
- Manual pages:
  - `man printf`
  - `man stdarg`
- AI was used only for conceptual clarification and README formatting.