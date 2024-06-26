#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <limits>
#include "banco.cpp"
using namespace std;

int main()
{
    bool bandmenu = 0;
    string eleccion;
    int eleccionentera;
    string nombre1, apellido1, tipo_cliente1, tarjeta1;

    banco banco1;

    do
    {
        menu();
        cin >> eleccion;
        if (!esnumero(eleccion))
        {
            cout << "No Ingreso un numero valido" << endl;
        }
        else
        {
            eleccionentera = stoi(eleccion);
            if (eleccionentera == 0)
            {
                cout << "Gracias por usar el programa" << endl;
                bandmenu = 1;
            }
            else
            {
                switch (eleccionentera)
                {
                case 1:
                    banco1.agregar_cliente();
                    break;
                case 2:
                    banco1.cambiar_estado_cliente();
                    break;
                case 3:
                    banco1.listar_clientes();
                    break;
                case 4:
                    banco1.detallar_clientes();
                    break;
                case 5:
                    banco1.realizar_transaccion();
                    break;
                case 6:
                    banco1.listar_transacciones();
                    break;
                case 7:
                    banco1.informes_transacciones_mes();
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
                }
            }
        }
    } while (!bandmenu);
}