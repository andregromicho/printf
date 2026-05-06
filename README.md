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
To compile the library, run `make` in the root of the repository. This will generate the `libftprintf.a` file.
```bash
make