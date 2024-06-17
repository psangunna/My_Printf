# ft_printf
**ft_printf** is a reimplementation of the **printf()** function from the standard C library (**libc**). This implementation includes support for various format specifiers, allowing the printing of different types of data.   

### Prototype  
``` int ft_printf(char const *, ...);```  

### Description
The **ft_printf** function allows formatted text output similar to the standard **printf** function. This version supports the following format specifiers:  

* **%c**: Prints a single character.
* **%s**: Prints a string.
* **%p**: Prints a **void** __*__ pointer in hexadecimal format.
* **%d**: Prints a decimal number (base 10).
* **%i**: Prints an integer in base 10.
* **%u**: Prints an unsigned decimal number (base 10).
* **%x**: Prints a hexadecimal number (base 16) in lowercase.
* **%X**: Prints a hexadecimal number (base 16) in uppercase.
* **%%**: Prints the percentage symbol.

### Project Requirements  
* Do not implement the buffer management of the original **printf()**.
* The **ft_printf** function will be compared to the original **printf** implementation.
* Use the **ar** command to create your library. Using **libtool** is prohibited.
* The **libftprintf.a** file must be created in the root of your repository.

### Compilation
To compile and create the **libftprintf.a** library, a **make** file have to be created. It will generate the **libftprintf.a** file in the root of the repository.

### Usage  
To use the **ft_printf** function, include the **ft_printf.h** header and compile the project with the **libftprintf.a** library. Below is an example:  
``` 
#include "ft_printf.h"

int main()
{
  ft_printf("Hello, %s!\n", "world");
  return 0;
}
```
### Conversion Examples
Below are some examples of how to use the different conversions:  
``` 
ft_printf("Character: %c\n", 'A');
ft_printf("String: %s\n", "Hello world");
ft_printf("Pointer: %p\n", &ft_printf);
ft_printf("Decimal number: %d\n", 123);
ft_printf("Integer: %i\n", -456);
ft_printf("Unsigned number: %u\n", 789);
ft_printf("Hexadecimal (lowercase): %x\n", 255);
ft_printf("Hexadecimal (uppercase): %X\n", 255);
ft_printf("Percentage: %%\n");
```
