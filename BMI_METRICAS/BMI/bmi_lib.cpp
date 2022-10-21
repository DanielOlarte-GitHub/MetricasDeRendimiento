#include <iostream>
#include "bmi_lib.h"
std::string nombre;
void procesos(){
    std::cout<<"PROGRAMA BMI"<<std::endl;

    std::cout<<"Ingrese su nombre: "<<std::endl;
    
    std::cin>>nombre;
    std::cout<<"CALCULEMOS TU BMI "<<nombre<<" !!"<<std::endl;
}

float calculoBMI(){
    float peso, altura, bmi;
    std::cout<<"Ingrese su peso: "<<std::endl;
    std::cin>>peso;
    std::cout<<"Ingrese su altura: "<<std::endl;
    std::cin>>altura;
    bmi=peso/(altura * altura);
    std::cout<<"Tu BMI es: "<<bmi<<std::endl;
    return bmi;
}

void clasificacion(float bmi){
    if(bmi < 18.5){
        std::cout<<nombre<<std::endl;
        std::cout<<"Tu bmi es: PESO BAJO"<<std::endl;
    }else if(bmi>=18.5 && bmi <= 24.9){
        std::cout<<nombre<<std::endl;
        std::cout<<"Tu bmi es: NORMAL"<<std::endl;
    }else if(bmi>=25 && bmi <=29.9){
        std::cout<<nombre<<std::endl;
        std::cout<<"Tu bmi es: SOBREPESO"<<std::endl;
    }else if(bmi>=30 && bmi <= 34.9){
        std::cout<<nombre<<std::endl;
        std::cout<<"Tu bmi es: OBESO"<<std::endl;
    }else if(bmi >= 35 && bmi <= 39.9){
        std::cout<<nombre<<std::endl;
        std::cout<<"Tu bmi es: OBESIDAD GRADO 2"<<std::endl;
    }else{
        std::cout<<nombre<<std::endl;
        std::cout<<"Tu bmi es: OBESIDAD GRADO 3"<<std::endl;
    }
}