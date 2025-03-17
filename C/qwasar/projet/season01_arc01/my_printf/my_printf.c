#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_func{

    char comm;
    int (*func)(va_list);
} t_func;

char* my_bzero(char* buffer){

    for(size_t i = 0; i < strlen(buffer); i++){
        buffer[i] = 0;
    }
    return buffer;
}

long convert(long n, int base, char *result){

    const char *digits = "0123456789abcdef";
    int index = 0;
    int negative = 0;

    if(n < 0){

        negative = 1;
        n = -n;
    }
    if (n == 0){

        result[0] = '0';
        result[1] = '\0';
        return 1;
    }

    while (n > 0){

        result[index++] = digits[n % base];
        n /= base;
    }
    result[index] = '\0';

    // Reverse the string to get the correct order
    for (int i = 0; i < index / 2; ++i){

        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }

    if (negative) {

        for (int i = index; i >= 0; --i) {
            
            result[i + 1] = result[i];
        }
        result[0] = '-';
        index++;
    }

    return index;
}

int print_d(va_list argv){

    int num = va_arg(argv, int);
    char buffer[50];
    int len = convert(num, 10, buffer);

    write(1, buffer, len);
    
    return len;
}

int print_o(va_list argv){

    int num = va_arg(argv, int);
    char buffer[50];
    int len = convert(num, 8, buffer);
    write(1, buffer, len);
    return len;
}

int print_u(va_list argv){

    unsigned int num = va_arg(argv, unsigned int);
    char buffer[50];
    int len = convert(num, 10, buffer);
    write(1, buffer, len);
    return len;
}

int print_x(va_list argv){

    unsigned int num = va_arg(argv, unsigned int);
    char buffer[50];
    int len = convert(num, 16, buffer);

    for(int i = 0; i < len; i++){

        if (buffer[i] > 'a' && buffer[i] < 'z'){

            buffer[i] -= 32;
        }
    }

    write(1, buffer, len);
    return len;
}

int print_c(va_list argv){

    char c = va_arg(argv, int);
    write(1, &c, 1);
    return 1;
}

int print_s(va_list argv){

    char *str = va_arg(argv, char*);
    if (str){

        write(1, str, strlen(str));
    } else{

        write(1, "(null)", 6);
        return 6;
    }
    return strlen(str);
}

int print_p(va_list argv){

    void *ptr = va_arg(argv, void*);
    char tmp; 
    // char buffer[50];
    unsigned long ptr_val = (unsigned long)ptr;

    char* buffer = malloc(sizeof(char) * convert(ptr_val, 16, &tmp));
    my_bzero(buffer);

    int len = convert(ptr_val, 16, buffer);

    write(1, "0x", 2);
    write(1, buffer, len);

    free(buffer);

    return len + 2;
}

int get_flag( char flag, va_list argv){
t_func comm[] ={
        {'d', print_d},
        {'o', print_o},
        {'u', print_u},
        {'x', print_x},
        {'c', print_c},
        {'s', print_s},
        {'p', print_p},
        {0, NULL}
    };
    t_func *tmp = comm;

    while(tmp->comm != 0){

        if (flag == tmp->comm){

            return tmp->func(argv);
        }
        tmp++;
    }

    return 0;
}

int my_printf(char * restrict format, ...){
    va_list argv;
    va_start(argv, format);

    int index = 0;
    int length = strlen(format);
    int size = 0;
    while(index < length) {
        if ( format[index] == '%' ){

            index += 1;
            size += get_flag(format[index], argv);

        } else{
            
            char temp = format[index];
            write(1, &temp, 1);
            size +=1;

        }
        index++;
    }

    va_end(argv);
    
    return size;
}

//  int main( int ac, char** av){

//     //  my_printf("%d test %o %x %u %c %s %p\n", 95, 255, 1234, 1234U, 'A', "Hello, world!", (void*)av);

//     my_printf(" toto = %d\n", 0);
//      printf("\n\n\n%s%d\n", *av, ac);
//      return 0;
//  }