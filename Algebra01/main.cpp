/**
 * @file main.cpp
 * @author Daniel Olarte
 * @brief Introducción al Algebra lineal con Eigen
 * @version 0.1
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * Materia: Métricas de Rendimiento para HPC
 */

#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>

/*
    Se crean nuevos tipos de datos :
        *Matriz de flotantes 3x3
        *Vector de flotantes 3x1
        *Matriz de flotantes dinamica
*/

typedef Eigen::Matrix<float, 3, 3> MiMatrix33f;
typedef Eigen::Matrix<float, 3, 1> MiVector3f;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MiMatrixDDd;


int main()
{

  /* Se ingresan los valores iniciales a las matrices de forma manual */

    p << 1,2,3,
         4,5,6,
         7,8,9;

    q << 10,11,12,
         13,14,15,
         16,17,18;

    /* Operaciones aritmeticas con las matrices */
    std::cout << "\n\np+q = \n" << p+q << std::endl;
    std::cout << "\n\np-q = \n" << p-q << std::endl;

    /* Operaciones aritmeticas con los vectores */
    std::cout << "\n\nr+s = \n" << r+s << std::endl;
    std::cout << "\n\nr-s = \n" << r-s << std::endl;

    /* Producto de matriz por escalar */
    std::cout << "\n\np*pi = \n" << p*3.141592 << std::endl;
    std::cout << "\n\nq*e = \n" << q*2.71828 << std::endl;

    /* matriz p y q */
    std::cout << "\n\np = \n" << p << std::endl;
    std::cout << "\n\nq = \n" << q << std::endl;

    /* Se requiere la matriz transpuesta de p y q */
    std::cout << "\n\np transpuesta = \n" << p.transpose() << std::endl;
    std::cout << "\n\nq transpuesta = \n" << q.transpose() << std::endl;

    /* Cambio p y q a transpuestas */
    std::cout << "\n\nCAMBIO DE MATRIZ: " << std::endl;
    p.transposeInPlace();
    q.transposeInPlace();
    std::cout << "p = \n" << p << std::endl;
    std::cout << "\n\nq = \n" << q << std::endl;

    /* Producto de matriz por matriz */
    std::cout << "\n\np*p = \n" << p*p << std::endl;
    std::cout << "\n\nq*q = \n" << q*q << std::endl;

    /* Producto de matriz por vector */
    std::cout << "\n\np*r = \n" << p*r << std::endl;
    std::cout << "\n\nq*s = \n" << q*s << std::endl;

   std::cout << "\n\n\n****************************" << std::endl;
    std::cout << "****************************\n" << std::endl;

    /* Se declaran las variables segun los nuevos tiṕos de datos definidos */
    MiMatrix33f mA;
    MiVector3f vB;
    MiMatrixDDd m(10, 15);

    /* Se inicializa la matriz mA con Ceros */
    mA = MiMatrix33f::Zero();
    std::cout << "\n\nmA = \n" << mA << std::endl;

    /* Se inicializa Identidad la mA*/
    mA = MiMatrix33f::Identity();
    std::cout << "\n\nmA Identidad = \n" << mA << std::endl;

    /* Se inicializa el vector vB con valores aleatorios */
    vB = MiVector3f::Random();
    std::cout << "\n\nvB = \n" << vB << std::endl;

    /* Crear un vector de enteros: datos */
    int datos[] = {1, 2, 3, 4};

    /* Se mapea (Map) El vector datos, en un vector Eigen, usando la función Map */
    Eigen::Map<Eigen::RowVectorXi> v_map(datos, 4);
    std::cout << "Vector mapeado a Vector por Filas enteros \n" << std::endl;
    std::cout << v_map << std::endl;



    /*
         Se requiere un vector de datos flotantes propio de iostream y mapearlo en una variable de tipo MiMatrix33f
    */

    /* Crear un vector de enteros: datos */
    std::vector<float> datos2 = {1,2,3,4,5,6,7,8,9};

    /* Se mapea (Map) El vector datos, en un vector Eigen, usando la función Map */

    Eigen::Map<MiMatrix33f> v_map2(datos2.data());
    std::cout << "Datos del vector mapeado a MiMatrix33f \n" << std::endl;
    std::cout << v_map2 << std::endl;

    std::cout << "\n\n\n****************************" << std::endl;
    std::cout << "****************************\n" << std::endl;



    std::cout << "\n\nOPERACIONES ARITMETICAS= \n" << std::endl;
    std::cout << "Element Wise: " << std::endl;

    Eigen::Matrix2d a;
    Eigen::Matrix2d b;
    Eigen::Matrix2d resultado;

    a << 1, 2,
         3, 4;

    b << 3, 3,
         2, 2;

    /* matriz p y q */
    std::cout << "\n\na = \n" << a << std::endl;
    std::cout << "\n\nb = \n" << b << std::endl;


    /* Element Wise operaciones */

    resultado = a.array() * b.array();
    std::cout<<"\nProducto Element Wise\n" << std::endl;
    std::cout<< resultado << std::endl;

    std::cout << "\n\n\n****************************" << std::endl;
    std::cout << "****************************\n" << std::endl;

    /* Operaciones con Escalar */
    int k = 15;
    std::cout << "\n\n\nEscalar k = " << k << std::endl;
    std::cout << "\nMatriz a*k = \n\n" << a*k << std::endl;




    std::cout << "\n\n\n****************************" << std::endl;
    std::cout << "****************************\n" << std::endl;


    /* La posicion fila[1] columna[1] cambiar el valor a -5*/
    mA(1,1) = -5;
    std::cout << "\n\nmA nuevo valor central = \n" << mA << std::endl;


/*Se crean 2 matrices "double" 3x3 */
    Eigen::Matrix3d p;
    Eigen::Matrix3d q;

    /*Se crean 2 vectores "double" 3D*/
    Eigen::Vector3d r(1,2,3);
    Eigen::Vector3d s(4,5,6);


  

    /*
        Acceso parcial a las matrices
    */

    /* Se crea una matriz aleatoria */
    Eigen::MatrixXf matriz_aleatoria = Eigen::MatrixXf::Random(6,6);
    std::cout<<"\n\nMatriz 6x6 \n" << matriz_aleatoria << std::endl;

    /* Se crea una matriz con submatriz de matriz_aleatoria */
    Eigen::Matrix2f b_bloque; /*EL BLOQUE SERA DEFINIDO POR INDICES DE FILAS Y COLUMNAS*/
    b_bloque = matriz_aleatoria.block(2, 2, 2, 2);
    std::cout<<"\n\nMatriz bloque central: \n" << b_bloque << std::endl;
    /* Se modifica la matriz aleatoria la cual a la fila escogida se le suma el valor escogido*/
    matriz_aleatoria.row(1).array() += 3;
    std::cout<<"\n\nMatriz aleatoria sumada en 3 la fila 1 \n" << matriz_aleatoria << std::endl;

    /*Se requiere que a la fila 5 se le reste 1*/
    matriz_aleatoria.row(5).array() -= 1;

    /*Se requiere que a la fila 4 se le divida entre 3*/
    matriz_aleatoria.row(4).array() /= 3;

    std::cout<<"\n\nMatriz aleatoria sumada en 3 la fila 1 \n" << matriz_aleatoria << std::endl;


    /*
        Broadcasting: Transmision
    */
    Eigen::MatrixXf mat_broad = Eigen::MatrixXf::Random(2,4);
    std::cout<<"\n\nMatriz 2x4 \n" << mat_broad << std::endl;

    Eigen::VectorXf vector_broad(2);
    vector_broad << 100, 100;
    std::cout<<"\n\nVector columna 2: \n" << vector_broad << std::endl;

    /* Se suma sobre cada columna el vector */
    mat_broad.colwise() += vector_broad;
    std::cout<<"\n\nMatriz sumada cada valor por el vector: \n" << mat_broad << std::endl;


    /* Crear 2 vectores doubles de 3 valores (vector A y vector B) */
    Eigen::Vector3d vectorA(100,200,300);
    Eigen::Vector3d vectorB(500,500,300);

    /* Aplicar la funcion dot (producto punto) a los vectores */
    std::cout<<"\n\nvectorA . vectorB: \n" << vectorA.dot(vectorB) << std::endl;

    /* Aplicar la funcion cross (producto cross) a los vectores */
    std::cout<<"\n\nvectorA x vectorB: \n" << vectorA.cross(vectorB) << std::endl;


    /*
        OPERACIONES DE REDUCCION DE MATRICES O VECTORES
    */

    /* Se crea matriz double 3X3*/
    Eigen::Matrix3d matriz_reduccion;
    matriz_reduccion <<
         15,25,35,
         45,55,65,
         75,85,95;

    std::cout << "\n\nMatriz: \n" << matriz_reduccion << std::endl;
    /* 1-> Suma: calcula la suma de todos los elementos del vector o de la matriz*/
    std::cout << "\n\nOperacion Reduccion: Suma\n" << matriz_reduccion.sum() << std::endl;

    /* 2-> Prod: calcula el producto de todos los elementos del vector o de la matriz*/
    std::cout << "\n\nOperacion Reduccion: Producto\n" << matriz_reduccion.prod() << std::endl;

    /* 3-> mean: calcula el promedio de todos los elementos del vector o de la matriz*/
    std::cout << "\n\nOperacion Reduccion: Mean\n:      " << matriz_reduccion.mean() << std::endl;

    /* 4-> minCoeff: calcula el coeficiente minimo de la matriz*/
    std::cout << "\n\nOperacion Reduccion: Coeficiente Minimo\n:  " << matriz_reduccion.minCoeff()  << std::endl;

    /* 5-> maxCoeff: calcula el coeficiente maximo de la matriz*/
    std::cout << "\n\nOperacion Reduccion: Coeficiente Maximo\n:  " << matriz_reduccion.maxCoeff()  << std::endl;

    /* 6-> trace: calcula la traza_de la matriz*/
    std::cout << "\n\nOperacion Reduccion: Trace\n:  " << matriz_reduccion.trace()  << std::endl;
    return 0;
}
