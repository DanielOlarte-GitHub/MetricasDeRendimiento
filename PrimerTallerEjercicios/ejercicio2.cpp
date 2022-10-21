/**
 * @file ejercicio2.cpp
 * @author Daniel Olarte
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int main(){

    //creacion de variables
    int x = 1, y = 1;

    //condiciones
    if (x == 1){
        if (y == 0){
            x = 10;
        }
    }else{
        x = -1;
    }

    //salida
    std::cout << x << std::endl;
}