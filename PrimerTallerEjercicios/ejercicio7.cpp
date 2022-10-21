/*Si quiere averiguar su número de Tarot, sume los números de su fecha de naci-
miento y a continuación redúzcalos a un único dígito; por ejemplo si su fecha de

nacimiento fuera 17 de octubre de 1992, los cálculos a realizar serían: 

17 + 10 + 1992 = 2019 => 2 + 0 + 1 + 9 = 12 => 1 + 2 = 3
lo que quiere decir que su número de Tarot es el 3.*/

/**
 * @file ejercicio7.cpp
 * @author Daniel Olarte
 * @brief Numero del Tarot (Ejercicio 7)
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>


int main(){
    
    // Declaración de variables
    int dia, mes, anio, suma = 0;
    
    // Entrada de datos
    std::cout << "Introduce un valor para dia: ";
    std::cin >> dia;
    std::cout << "Introduce un valor para mes: ";
    std::cin >> mes;
    std::cout << "Introduce un valor para anio: ";
    std::cin >> anio;
    
    //condicional que no acepte valores negativos  para dia y mes y anio y que verifique que mes y dia esten entre 1 y 12
    if (dia < 0 || mes < 0 || anio < 0 || dia > 31 || mes > 12){
        std::cout << "No se aceptan valores negativos" << std::endl;
    }else{

        //suma los valores de dia, mes y anio 
        suma = dia + mes + anio;

        //ciclo que suma los digitos de la suma
       while (suma > 9){
            suma = suma/10 + suma%10;
        }
        
        //imprime los resultados
        std::cout<<"\n\nRESULTADOS"<<std::endl;
        std::cout << "\nEl numero de Tarot de " << dia << "/" << mes << "/" << anio << " es: " << suma << "\n\n" << std::endl;
    
    }
    return 0;
}














 
        