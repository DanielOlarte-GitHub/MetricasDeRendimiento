/*
Realizar un programa que genere la siguiente secuencia de dígitos:

                                    1
                                2   3   2
                            3   4   5  4   3
                        4   5   6   7   6   5   4
                    5   6   7   8   9   8   7   6   5
                6   7   8   9   0   1   0   9   8   7   6
            7   8   9   0   1   2   3   2   1   0   9   8   7
        8   9   0   1   2   3   4   5   4   3   2   1   0   9   8   
                            

• El número de filas estará comprendido entre 11 y 20 y el resultado aparecerá
centrado en la pantalla como se indica en la figura.
*/


/**
 * @file ejercicio8.cpp
 * @author Daniel Olarte
 * @brief Programa Piramide con secuencia (Ejercicio 8)
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int main(){

    //creacion de variables
    int cantF;

    //entrada de datos
    std::cout << "Digite la cantidad de filas: " << std::endl;
    std::cin >> cantF;


    //condiciones
    for (int x = 1; x <= cantF; x++){

        for (int k=10 ; k>=x; k--){
            std::cout << "   ";
        }

        if(x==1){
            std::cout << x << std::endl;
        }else{
            int z = ((x*2))-1;

            
            
            for (int y = 0; y <= ((x*2)-2); y++){
                
                if((x+y) >= x*2){
                    z-=1;
                    if(z>9){
                        std::cout << z%10 << "  ";
                    }else{
                        std::cout << z << "  ";
                    }
                    
                    
                }else{
                    if(x+y >9){
                        std::cout << (x+y)%10 << "  ";
                    }else{
                        std::cout << x+y << "  ";
                    }
                    
                }
            }
            std::cout << std::endl;
       }
    }
}
