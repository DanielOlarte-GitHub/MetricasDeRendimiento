/**
 * @file ejercicio4.cpp
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
    int x = 0, y = 0;

    //condiciones
    for (x = 6; x > 0; x -= 2){
        for (y = 0; y < 2; y++){
            std::cout << x-y << std::endl;
        }
    }
}