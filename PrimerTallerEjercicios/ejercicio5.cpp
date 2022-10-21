/**
 * @file ejercicio5.cpp
 * @author Daniel Olarte
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

//metodo para imprimir la variable x
void fnx(int x){
    if (x){ //si x es distinto de 0
        std::cout << x << std::endl;
    }
}


int main() {
    //creacion de variables
    int i, a = 1234;
    //condiciones
    for (i = 0; i < 4; i++){
        fnx(a = a/10);

    }
}