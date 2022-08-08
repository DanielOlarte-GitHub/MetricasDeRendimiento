/*Realizar un programa que calcule e imprima la suma de los múltiplos de 5
comprendidos entre dos valores a y b. El programa no permitirá introducir valores
negativos para a y b, y verificará que a es menor que b. Si a es mayor que b,
intercambiará estos valores.*/

/**
 * @file ejercicio6.cpp
 * @author Daniel Olarte
 * @brief Multiplos de 5 en un rango (Ejercicio 6)
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>


int main(){
    
    // Declaración de variables
    int a, b, suma = 0;
    
    // Entrada de datos
    std::cout << "Introduce un valor para a: ";
    std::cin >> a;
    std::cout << "Introduce un valor para b: ";
    std::cin >> b;

    //condicional que no acepte valores negativos para a y b
    if (a < 0 || b < 0){
        std::cout << "No se aceptan valores negativos" << std::endl;
    }else{
        //condicional que verifique que a es menor que b
        if (a > b){
            int aux = a;
            a = b;
            b = aux;
        }
        //ciclo que recorre los valores de a y b 
        for (int i = a; i <= b; i++){
            if (i % 5 == 0){ //condicional que verifique que el valor de i sea múltiplo de 5
                suma += i;
            }
        }
        
        //imprime los resultados 
        std::cout<<"\n\nRESULTADOS"<<std::endl;
        std::cout << "\nLa suma de los múltiplos de 5 de los numeros entre " << a << " y " << b << " es: " << suma << "\n\n" << std::endl;
    }
    
    

    
    return 0;
}


