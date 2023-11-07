#include <iostream>
#include<Windows.h>
//Дано два масиви: А[M] і B[N] (M і N вводяться з клавіатури). Необхідно створити третій масив мінімально можливого розміру, в якому потрібно зібрати спільні елементи двох масивів без повторень.
int main() {
    system("chcp 1251");
    system("cls");
    int M, N;
    std::cout << "Введіть розмір масиву A (M): ";
    std::cin >> M;
    std::cout << "Введіть розмір масиву B (N): ";
    std::cin >> N;

    int A[100], B[100], C[200]; 

    std::cout << "Введіть елементи масиву A:" << std::endl;
    for (int i = 0; i < M; i++) {
        std::cout << "A[" << i << "]: ";
        std::cin >> A[i];
    }

    std::cout << "Введіть елементи масиву B:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << "B[" << i << "]: ";
        std::cin >> B[i];
    }

    int* ptrA = A;
    int* ptrB = B;
    int* ptrC = C;
    int sizeC = 0; 

    
    for (int i = 0; i < M; i++) {
        bool isDuplicate = false;

        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            *ptrC = A[i];
            ptrC++;
            sizeC++;
        }
    }

    
    for (int i = 0; i < N; i++) {
        bool isDuplicate = false;

        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            *ptrC = B[i];
            ptrC++;
            sizeC++;
        }
    }

    
    std::cout << "Масив C зі спільними елементами без повторень:" << std::endl;
    for (int i = 0; i < sizeC; i++) {
        std::cout << "C[" << i << "]: " << C[i] << std::endl;
    }

    return 0;
}
