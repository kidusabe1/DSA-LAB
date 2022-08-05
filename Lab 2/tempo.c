#include <stdio.h>
typedef struct complex {
    float real;
    float imag;
} complex;
complex add(complex firstno, complex secondno);

int main() {
    complex firstno, secondno, result;

    printf("The first complex numbers \n");
    printf("Enter the real and imaginary numbers: ");
    scanf("%f %f", &firstno.real, &firstno.imag);
    printf("\nFor 2nd complex numbers \n");
    printf("Enter the real and imaginary parts: ");
    scanf("%f %f", &secondno.real, &secondno.imag);

    result = add(firstno, secondno);

    printf("Sum = %.1f + %.1fi", result.real, result.imag);
    return 0;
}
complex add(complex firstno, complex secondno) {
    complex temp;
    temp.real = firstno.real + secondno.real;
    temp.imag = firstno.imag + secondno.imag;
    return (temp);
}