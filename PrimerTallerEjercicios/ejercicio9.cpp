/*
Realizar un programa que calcule el importe a pagar por un vehículo al circular
por una autopista. El vehículo puede ser una bicicleta, una moto, un coche o un
camión. Para definir el conjunto vehículos utilizaremos un tipo enumerado (vea en
el capítulo 2 los tipos enumerados). El importe se calculará según los siguientes
datos:

• Un importe fijo de 100 unidades para las bicicletas.
• Las motos y los coches pagarán 30 unidades por Km.
• Los camiones pagarán 30 unidades por Km más 25 unidades por Tm.

La presentación en pantalla de la solución, será de la forma siguiente:

1 - Bicicleta
2 - Moto
3 - Coche
4 - Camión
5 - Salir
Seleccione la opción deseada: 4
Kilómetros y toneladas? 100 50
Importe = 4250
*/


/**
 * @file ejercicio9.cpp
 * @author Daniel Olarte
 * @brief Programa Vehiculos en autopista (Ejercicio 9)
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

void camionOp(){
	int importe, km, tn;
	//system("cls");
	std::cout<<"\n\t\t\tCAMION\n\n"<<std::endl;
	
	std::cout<<"\tDigite los km recorridos: ";
	std::cin>>km;
	
	std::cout<<"\n\tDigite las Tn del camion: ";
	std::cin>>tn;
	
	importe = (km*30) + (tn * 25);
	
	std::cout<<"\n\tIMPORTE: "<<importe;
	//system("pause");
	//system("cls");
}

void cocheOp(){
	int importe, km;
	//system("cls");
	std::cout<<"\n\t\t\tCOCHE\n\n"<<std::endl;
	
	std::cout<<"\tDigite los km recorridos: ";
	std::cin>>km;
	
	importe = km*30;
	
	std::cout<<"\n\tIMPORTE: "<<importe;
	//system("pause");
	//system("cls");
}

void motoOp(){
	int importe, km;
	//system("cls");
	std::cout<<"\n\t\t\tMOTO\n\n"<<std::endl;
	
	std::cout<<"\tDigite los km recorridos: ";
	std::cin>>km;
	
	importe = km*30;
	
	std::cout<<"\n\tIMPORTE: "<<importe;
	//system("pause");
	//system("cls");
}

void bicicletasOp(){
	int importe = 100;
	//system("cls");
	std::cout<<"\n\t\t\tBICICLETA\n\n"<<std::endl;
	std::cout<<"\n\tIMPORTE: "<<importe;
	//system("pause");
	//system("cls");
}

void menu(){
	int men;
	std::cout<<"\t\t\tMENU:\n"<<std::endl;
	std::cout<<"\t1) Bicicleta"<<std::endl;
	std::cout<<"\t2) Moto"<<std::endl;
	std::cout<<"\t3) Coche"<<std::endl;
	std::cout<<"\t4) Camion"<<std::endl;
	std::cout<<"\t0) Salir\n"<<std::endl;
	std::cout<<"\tSeleccione la opcion deseada: ";
	std::cin>>men;
	
	switch(men){
		case 1:
			bicicletasOp();
		break;
		
		case 2:
			motoOp();
		break;
		
		case 3:
			cocheOp();
		break;
		
		case 4:
			camionOp();
		break;
		
		case 0:
			exit(0);
		break;
		
		default:
			std::cout<<"\n\n\t\t\tDIGITO UN VALOR INCORRECTO, VUELVA A INTENTARLO\n"<<std::endl;
		break;	
	}
	menu();
}

int main(){
	menu();
	//system("pause");
}