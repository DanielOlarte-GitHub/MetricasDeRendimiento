/**
 * @file main.cpp
 * @author Daniel Olarte
 * @brief Taller 15 ejercicios
 * @version 0.1
 * @date 2022-22-08
 *
 * @copyright Copyright (c) 2022
 *
 * Materia: Métricas de Rendimiento para HPC
 */

#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>

//IDENTIDAD
int main()
{
    Eigen::Matrix2d A;
    Eigen::Matrix2d B;

    Eigen::Matrix2d X;

    //Primer Ejercicio (A)

    A << 4, -2,
         1, -7;

    B << -1, 2,
         6, -5;

    X = (3*A-4*B);

    std::cout<<"\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"PRIMER EJERCICIO (A):\n"<<std::endl;
    std::cout<<"A =\n"<<A<<std::endl;
    std::cout<<"\nB =\n"<<B<<std::endl;

    std::cout<<"\n\nX = 3A - 4B = \n\n"<<X<<std::endl;



    //Segundo Ejercicio (B)
    A << 0, -1,
         2, 1;

    B << 1, 2,
         3, 4;

    X = ((3*B*A)-(4*A))/2;

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"SEGUNDO EJERCICIO (B):\n"<<std::endl;
    std::cout<<"A =\n"<<A<<std::endl;
    std::cout<<"\nB =\n"<<B<<std::endl;

    std::cout<<"\n\n2X + 4A = 3BA\n"<<std::endl;
    std::cout<<"\nX = (3BA - 4A)/2\n\nX = \n"<<X<<std::endl;


    //Tercer Ejercicio (C) $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    Eigen::Matrix2d C;
    Eigen::MatrixXd X2;

    A << -3, -2,
         3, 3;

    B << 5, 3,
         9, 4;

    C << 1, 1,
         0, 0;

    X = (C*A.transpose()*B);
    //X = C.array()/A.array()*B.transpose().array();

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"TERCER EJERCICIO: (C)\n"<<std::endl;
    std::cout<<"A =\n"<<A<<std::endl;
    std::cout<<"\nB =\n"<<B<<std::endl;
    std::cout<<"\nB^t =\n"<<B.transpose()<<std::endl;
    std::cout<<"\nC =\n"<<C<<std::endl;

    std::cout<<"\n\nAXB^t = C\n"<<std::endl;
    //std::cout<<"\nX = C/AB^t\n\nX = \n"<<X<<std::endl;
    std::cout<<"\nIa*X*Ib = C*A^t*B\n\nX = \n"<<X<<std::endl;


    //Cuarto Ejercicio (D) $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

    A << 2, 1,
         -4, -3;

    B << 2, 2,
         6, 4;

    //X = B*A.transpose();
    X = B.array()/A.array();

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"CUARTO EJERCICIO: (D)\n"<<std::endl;
    std::cout<<"A =\n"<<A<<std::endl;
    std::cout<<"\nB =\n"<<B<<std::endl;

    std::cout<<"\n\nXA = B\n"<<std::endl;
    std::cout<<"\nX = B/A\n\nX = \n"<<X<<std::endl;


    //Quinto Ejercicio (E)

    Eigen::MatrixXd Ad23(2, 3);
    Eigen::MatrixXd Bd32(3, 2);

    Ad23 << 3, 0, -1,
         0, 2, 1;

    Bd32 << 1, 2,
         1, 0,
         0, 6;

    C << -2, 0,
         -2, -5;

    X = 2*((Ad23*Bd32)+C);

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"QUINTO EJERCICIO: (E)\n"<<std::endl;
    std::cout<<"A =\n"<<Ad23<<std::endl;
    std::cout<<"\nB =\n"<<Bd32<<std::endl;
    std::cout<<"\nC =\n"<<C<<std::endl;

    std::cout<<"\n\nX = 2(AB + C)\n\nX = \n"<<X<<std::endl;


    //Sexto Ejercicio (F)
    Eigen::Matrix3d A3;
    Eigen::Matrix3d B3;

    Eigen::Matrix3d X3;

    A3 << 1, 5, -1,
         -1, 2, 2,
         0, -3, 3;

    B3 << -1, -4, 3,
         1, -2, -2,
         -3, 3, -5;

    X3 = (A3 + (3*B3));

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"SEXTO EJERCICIO: (F)\n"<<std::endl;
    std::cout<<"A =\n"<<A3<<std::endl;
    std::cout<<"\nB =\n"<<B3<<std::endl;

    std::cout<<"\n\nX = A + 3B\n\nX = \n"<<X3<<std::endl;


    //Septimo Ejercicio (G) $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    A3 << 2, 7, 3,
         3, 9, 4,
         1, 5, 3;

    B3 << 1, 0, 2,
         0, 1, 0,
         0,0, 1;

    //X3 = B3*A3.transpose();
    X3 = B3.array()/A3.array();

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"SEPTIMO EJERCICIO: (G)\n"<<std::endl;
    std::cout<<"A =\n"<<A3<<std::endl;
    std::cout<<"\nB =\n"<<B3<<std::endl;

    std::cout<<"\n\nXA = B\n"<<std::endl;
    std::cout<<"\nX = B/A\n\nX = \n"<<X3<<std::endl;


    //Octavo Ejercicio (H) $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    A3 << 1, 1, 1,
         6, 5, 4,
         13, 10, 8;

    B3 << 0, 1, 2,
         1, 0, 2,
         1, 2, 0;

    //X3 = B3*A3.transpose();
    X3 = B3.array()/A3.array();

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"OCTAVO EJERCICIO: (H)\n"<<std::endl;
    std::cout<<"A =\n"<<A3<<std::endl;
    std::cout<<"\nB =\n"<<B3<<std::endl;

    std::cout<<"\n\nAX = B\n"<<std::endl;
    std::cout<<"\nX = B/A\n\nX = \n"<<X3<<std::endl;


    //Noveno Ejercicio (I)
    A << 3, -1,
         0,  2;

    X = ((A.transpose()*A)-(2*A));

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"NOVENO EJERCICIO: (I)\n"<<std::endl;
    std::cout<<"A =\n"<<A<<std::endl;

    std::cout<<"\n\nAX = B\n"<<std::endl;
    std::cout<<"\nX = B/A\n\nX = \n"<<X<<std::endl;


    //Decimo Ejercicio (J)
    A << 4, 2,
         -1,  0;

    X = A*A*A;

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"DECIMO EJERCICIO: (J)\n"<<std::endl;
    std::cout<<"A =\n"<<A<<std::endl;

    std::cout<<"\n\nX = A³\n\nX = \n"<<X<<std::endl;


    //Onceavo Ejercicio (K) $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    A << 2, 4,
         3, 2;

    B << 1, 0,
         2, 1;

    C << 7, 5,
         6, 1;


    //X = C*A*B.transpose();
    X= C.array()/((A.transpose().array())*B.array());

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"ONCEAVO EJERCICIO: (K)\n"<<std::endl;
    std::cout<<"A =\n"<<A<<std::endl;
    std::cout<<"\nB =\n"<<B<<std::endl;
    std::cout<<"\nC =\n"<<C<<std::endl;

    std::cout<<"\n\nA^tXB = C\n"<<std::endl;
    std::cout<<"\nX = C/A^t*B\n\nX = \n"<<X<<std::endl;


    //Doceavo Ejercicio (L)
    Ad23 << 1, 0, -2,
            2, -1, 3;

    Bd32 << 2, -3,
            -2, 0,
            -1, -2;


    X= ((Ad23*Ad23.transpose())-(2*Ad23*Bd32));

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"DOCEAVO EJERCICIO: (L)\n"<<std::endl;
    std::cout<<"A =\n"<<Ad23<<std::endl;
    std::cout<<"\nB =\n"<<Bd32<<std::endl;

    std::cout<<"\n\nX = AA^t - 2AB\n\nX = \n"<<X<<std::endl;


    //Treceavo Ejercicio (M)


    //Eigen::Vector3d Av3(4, 8,12);
    Eigen::MatrixXd Av3(1,3);
    //Eigen::RowVector3d Cv(3,-1);
    Eigen::MatrixXd Cv(2, 1);

    Av3 << 4, 8, 12;

    Cv << 3,
          -1;

    Bd32 << 3, 2,
            0, 1,
            -1, 0;


    //X = (Av3*Bd32*Cv);

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"TRECEAVO EJERCICIO: (M)\n"<<std::endl;
    std::cout<<"A =\n"<<Av3<<std::endl;
    std::cout<<"\nB =\n"<<Bd32<<std::endl;
    std::cout<<"\nC =\n"<<Cv<<std::endl;


    std::cout<<"\n\nX = ABC\n\nX = \n"<<(Av3*Bd32*Cv)<<std::endl;


    //Catorceavo Ejercicio (N) $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    A3 << 3, 4, 1,
         -1, -3, 3,
          2, 3, 0;

    B3 << 3, 9, 7,
          1, 11, 7,
          7, 5, 7;

    //X3 = B3*A3;
    X3 = (B3.array()/(A3.transpose().array()));

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"CATORCEAVO EJERCICIO: (N)\n"<<std::endl;
    std::cout<<"A =\n"<<A3<<std::endl;
    std::cout<<"\nB =\n"<<B3<<std::endl;

    std::cout<<"\n\nA^tX = B\n"<<std::endl;
    std::cout<<"\nX = B/A^t\n\nX = \n"<<X3<<std::endl;


    //Quinceavo Ejercicio (O) $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    A3 << 2, 5, 7,
          6, 3, 4,
          5, -2, -3;

    B3 << -1, 1, 0,
          0, 1, 1,
          1, 0, -1;

    //X3 = B3*A3.transpose();
    X3 = (B3.array()/(A3.array()));

    std::cout<<"\n\n-----------------------------------------------------------------\n"<<std::endl;
    std::cout<<"QUINCEAVO EJERCICIO: (O)\n"<<std::endl;
    std::cout<<"A =\n"<<A3<<std::endl;
    std::cout<<"\nB =\n"<<B3<<std::endl;

    std::cout<<"\n\nXA = B\n"<<std::endl;
    std::cout<<"\nX = B/A\n\nX = \n"<<X3<<std::endl;

}
