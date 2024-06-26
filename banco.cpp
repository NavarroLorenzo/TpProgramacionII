#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <limits>
#include "banco.h"
using namespace std;

persona::persona(){

};

persona::persona(string _nombre, string _apellido, int _dni)
{

    nombre = _nombre;
    apellido = _apellido;
    dni = _dni;
};

void persona::set_nombre(string _nombre)
{
    nombre = _nombre;
}
void persona::set_apellido(string _apellido)
{
    apellido = _apellido;
}
void persona::set_dni(int _dni)
{
    dni = _dni;
}
string persona::get_nombre()
{
    return nombre;
}
string persona::get_apellido()
{
    return apellido;
}
int persona::get_dni()
{
    return dni;
}
// constructores y metodos transacciones//

transaccion::transaccion(){

};
transaccion::transaccion(float _numero_transaccion, float _monto, int _numero_cliente_transaccion, string _tipo_moneda, string _tipo_transaccion, int _dia, int _mes, int _anio)
{
    numero_transaccion = _numero_transaccion;
    monto = _monto;
    numero_cliente_transaccion = _numero_cliente_transaccion;
    tipo_moneda = _tipo_moneda;
    tipo_transaccion = _tipo_transaccion;
    dia = _dia;
    mes = _mes;
    anio = _anio;
};

void transaccion::set_numero_transaccion(float _numero_transaccion)
{
    numero_transaccion = _numero_transaccion;
}
void transaccion::set_monto(float _monto)
{
    monto = _monto;
}
void transaccion::set_numero_cliente_transaccion(int _numero_cliente_transaccion)
{
    numero_cliente_transaccion = _numero_cliente_transaccion;
}
void transaccion::set_tipo_moneda(string _tipo_moneda)
{
    tipo_moneda = _tipo_moneda;
}
void transaccion::set_tipo_transaccion(string _tipo_transaccion)
{
    tipo_transaccion = _tipo_transaccion;
}
void transaccion::set_dia(int _dia)
{
    dia = _dia;
}
void transaccion::set_mes(int _mes)
{
    mes = _mes;
}
void transaccion::set_anio(int _anio)
{
    anio = _anio;
}
float transaccion::get_numero_transaccion()
{
    return numero_transaccion;
}
float transaccion::get_monto()
{
    return monto;
}
int transaccion::get_numero_cliente_transaccion()
{
    return numero_cliente_transaccion;
}
string transaccion::get_tipo_moneda()
{
    return tipo_moneda;
}
string transaccion::get_tipo_transaccion()
{
    return tipo_transaccion;
}
int transaccion::get_dia()
{
    return dia;
}
int transaccion::get_mes()
{
    return mes;
}

int transaccion::get_anio()
{
    return anio;
}

cliente::cliente(){};
cliente::cliente(string _nombre, string _apellido, int _dni, string _tipo_cliente, int _anio_ingreso, bool _estado, string _tarjeta) : persona(_nombre, _apellido, _dni)
{
    tipo_cliente = _tipo_cliente;
    anio_ingreso = _anio_ingreso;
    estado = _estado;
    tarjeta = _tarjeta;
};

void cliente::set_tipo_cliente(string _tipo_cliente)
{
    tipo_cliente = _tipo_cliente;
}
void cliente::set_anio_ingreso(int _anio_ingreso)
{
    anio_ingreso = _anio_ingreso;
}
void cliente::set_estado(bool _estado)
{
    estado = _estado;
}
void cliente::set_tarjeta(string _tarjeta)
{
    tarjeta = _tarjeta;
}
string cliente::get_tipo_clente()
{
    return tipo_cliente;
}
int cliente::get_anio_ingreso()
{
    return anio_ingreso;
}
bool cliente::get_estado()
{
    return estado;
}
string cliente::get_tarjeta()
{
    return tarjeta;
}
empleado::empleado(){};

banco::banco()
{
    num_clientes = 0;
    num_transacciones = 0;
}

banco::banco(cliente _clientes[], empleado _empleados[], transaccion _transacciones[], int _num_clientes, int _num_transacciones)
{
    num_clientes = _num_clientes;
    num_transacciones = _num_transacciones;

    // Only copy as many elements as specified by _num_clientes and _num_transacciones
    for (int i = 0; i < num_clientes; i++)
    {
        clientes[i] = _clientes[i];
    }
    for (int i = 0; i < num_transacciones; i++)
    {
        transacciones[i] = _transacciones[i];
    }
    for (int i = 0; i < num_clientes; i++)
    {
        empleados[i] = _empleados[i];
    }
}

void banco::set_num_clientes(int _num_clientes)
{
    num_clientes = _num_clientes;
}
int banco::get_num_clientes()
{
    return num_clientes;
}
void banco::set_num_transacciones(int _num_transacciones)
{
    num_transacciones = _num_transacciones;
}
int banco::get_num_transacciones()
{
    return num_transacciones;
}

void menu()
{
    cout << "******************************************************" << endl;
    cout << "1. Agregar cliente" << endl;
    cout << "2. Cambiar estado de cliente" << endl;
    cout << "3. Listar clientes" << endl;
    cout << "4. Detallar cliente" << endl;
    cout << "5. Realizar transaccion" << endl;
    cout << "6. Listar transacciones" << endl;
    cout << "7. Informe de extracciones y depositos por mes y anio" << endl;
    cout << "****************************************************" << endl;
    cout << "0. Terminar programa" << endl;
}

bool esnumero(string numero)
{
    int i;
    for (i = 0; i < numero.length(); i++)
    {
        if (isdigit(numero[i]) == false)
        {
            return false;
        }
    }
    return true;
}

bool banco::dni_existe(int dni)
{
    for (int i = 0; i < num_clientes; i++)
    {
        if (clientes[i].get_dni() == dni)
        {
            return true;
        }
    }
    return false;
}

bool esNombreValido(const string &nombre1)
{
    for (char c : nombre1)
    {
        if (!isalpha(c) && !isspace(c))
        {
            return false;
        }
    }
    return true;
}

string obtenerNombreCliente()
{
    string nombre1;
    bool nombreValido = false;

    while (!nombreValido)
    {
        cout << "Ingrese el nombre del cliente: ";
        cin >> nombre1;

        nombreValido = esNombreValido(nombre1);

        if (!nombreValido)
        {
            cout << "Nombre no válido. Ingrese solo caracteres letras y espacios." << endl;
        }
    }

    return nombre1;
}

string obtenerApellidoCliente()
{
    string apellido1;
    bool nombreValido = false;

    while (!nombreValido)
    {
        cout << "Ingrese el Apellido del cliente: ";
        cin >> apellido1;

        nombreValido = esNombreValido(apellido1);

        if (!nombreValido)
        {
            cout << "Apellido no válido. Ingrese solo caracteres letras y espacios." << endl;
        }
    }

    return apellido1;
}

bool esDniValido(int dni1)
{
    // Verificar que el número esté dentro del rango y tenga máximo 8 dígitos, tambien que sea coherente
    return (dni1 >= 9999999 && dni1 <= 99999999);
};

int obtenerDniCliente()
{
    int dni1;
    bool numeroValido = false;

    while (!numeroValido)
    {
        cout << "Ingrese el DNI del cliente: ";
        if (!(cin >> dni1))
        {
            cin.clear();                                         // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida
            cout << "Entrada inválida. Por favor, ingrese un DNI valido" << endl;
        }
        else
        {
            if (esDniValido(dni1))
            {
                numeroValido = true;
            }
            else
            {
                cout << "DNI no válido. Ingrese un número entero con máximo 8 dígitos." << endl;
            }
        }
    }

    return dni1;
}

bool esAnioValido(int anio)
{
    return (anio >= 1990 && anio <= 2025);
}

string obtenerTipoCliente(){
    string tipo_cliente1;
    bool tipoValido = false;

    while (!tipoValido)
    {
        cout << "Ingrese el tipo de cliente (Plata, Oro, Platino): ";
        cin >> tipo_cliente1;

        if (tipo_cliente1 == "Plata" || tipo_cliente1 == "Oro" || tipo_cliente1 == "Platino")
        {
            tipoValido = true;
        }
        else
        {
            cout << "Tipo de cliente no válido" << endl;
        }
    }

    return tipo_cliente1;

}

int obtenerAnioCliente()
{
    string anioStr;
    int anioingreso1;
    bool anioValido = false;

    while (!anioValido)
    {
        cout << "Ingrese el año del cliente (entre 1990 y 2025): ";
        cin >> anioStr;

        if (esnumero(anioStr))
        {
            anioingreso1 = stoi(anioStr);
            if (esAnioValido(anioingreso1))
            {
                anioValido = true;
            }
            else
            {
                cout << "Año no válido. Ingrese un año entre 1990 y 2025." << endl;
            }
        }
        else
        {
            cout << "Entrada inválida. Por favor, ingrese un número válido." << endl;
        }
    }

    return anioingreso1;
}


bool esEstadoValido(int estado1)
{
    return (estado1 == 0 || estado1 == 1);
}
int obtenerEstadoCliente()
{
    int estado1;
    bool estadoValido = false;

    while (!estadoValido)
    {
        cout << "Ingrese el estado del cliente (0 si es baja, 1 si es alta): "<<endl;
        if (!(cin >> estado1))
        {
            cin.clear();                                         // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida
            cout << "Entrada inválida. Por favor, ingrese un estado valido" << endl;
        }
        else
        {
            if (esEstadoValido(estado1))
            {
                estadoValido = true;
            }
            else
            {
                cout << "Estado no válido,(0 si es baja, 1 si es alta) " << endl;
            }
        }
    }

    return estado1;
}

bool esNumeroTarjetaValido(const string &tarjeta)
{
    // Verificar que todos los caracteres sean dígitos y la longitud esté entre 13 y 18
    if (tarjeta.length() >= 13 && tarjeta.length() <= 18)
    {
        for (char c : tarjeta)
        {
            if (!isdigit(c))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

string obtenerNumeroTarjeta(string tipo_cliente)
{
    bool band = 1;
    string tarjeta;


        if(tipo_cliente == "Plata"){
            cout << "No tiene acceso a una tarjeta de credito"<<endl;;
            tarjeta = "No tiene tarjeta";
        }
        else if(tipo_cliente == "Oro"){
            while(band == 1){
            cout << "Ingrese el numero de tarjeta (13-18 digitos): "<<endl;
            cin >> tarjeta;
            if(esNumeroTarjetaValido(tarjeta)){
                break;
            }
            }
        }
        else if(tipo_cliente == "Platino"){
            while(band == 1){
            cout << "Ingrese el numero de tarjeta (13-18 digitos): "<<endl;
            cin>>tarjeta;
            if(esNumeroTarjetaValido(tarjeta)){
                break;
            }
            }
        }else {
            tarjeta = "Error en la tarjeta";
        }

    return tarjeta;
}

void banco::agregar_cliente()
{
    if (num_clientes >= 100)
    {
        cout << "No se pueden agregar más clientes." << endl;
        return;
    }

    string nombre1, apellido1, tipo_cliente1, tarjeta1;
    int dni1, anioingreso1, estado1;
    nombre1 = obtenerNombreCliente();
    apellido1 = obtenerApellidoCliente();
    dni1 = obtenerDniCliente();

    if (dni_existe(dni1))
    {
        cout << "El cliente ya existe." << endl;
        return;
    }

    tipo_cliente1 = obtenerTipoCliente();

    anioingreso1 = obtenerAnioCliente();

    estado1 = obtenerEstadoCliente();

    tarjeta1 = obtenerNumeroTarjeta(tipo_cliente1);

    cliente nuevo_cliente(nombre1, apellido1, dni1, tipo_cliente1, anioingreso1, estado1, tarjeta1);
    clientes[num_clientes] = nuevo_cliente;
    num_clientes++;

    cout << "Cliente agregado correctamente." << endl;
}

void banco::cambiar_estado_cliente(){
    int dni1;
    bool band = 1;
    cout << "Ingrese el DNI del cliente a cambiar el estado: " << endl;
    cin >> dni1;
    if(num_clientes == 0){
        cout << "No hay clientes registrados" << endl;
        return;
    }

    for (int i = 0; i < num_clientes; i++)
    {
        if (clientes[i].get_dni() == dni1)
        {
            band = 0;
            if (clientes[i].get_estado() == 1)
            {
                clientes[i].set_estado(0);
                cout << "El cliente ha sido dado de baja" << endl;
            }
            else
            {
                clientes[i].set_estado(1);
                cout << "El cliente ha sido dado de alta" << endl;
            }
        }
    }
    if (band == 1)
    {
        cout << "No existe el cliente" << endl;
    }

}

void banco::listar_clientes()
{

    if (num_clientes == 0)
    {
        cout << "No hay clientes registrados" << endl;
        return;
    }
    cout << "------------------------------------" << endl;
    for (int i = 0; i < num_clientes; i++)
    {
        cout << "Cliente Numero " << i + 1 << " con DNI: " << clientes[i].get_dni() << endl;
        cout << "------------------------------------" << endl;
    }
    ofstream archivo("clientes.txt"); // Abre el archivo clientes.txt para escritura
    if (archivo.is_open())
    {
        for (int i = 0; i < num_clientes; ++i)
        {
            // Escribir los datos del cliente en el archivo en el formato deseado
            archivo << "Nombre: " << clientes[i].get_nombre() << endl;
            archivo << "Apellido: " << clientes[i].get_apellido() << endl;
            archivo << "DNI: " << clientes[i].get_dni() << endl;
            archivo << "Tipo de Cliente: " << clientes[i].get_tipo_clente() << endl;
            archivo << "Año de Ingreso: " << clientes[i].get_anio_ingreso() << endl;
            archivo << "Estado: " << (clientes[i].get_estado() ? "Activo" : "Baja") << endl;
            archivo << "Tarjeta: " << clientes[i].get_tarjeta() << endl;
            archivo << "------------------------------------" << endl;
        }
        archivo.close(); // Cierra el archivo después de escribir todos los clientes
        cout << "Clientes guardados en clientes.txt correctamente." << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo clientes.txt." << endl;
    }
};

void banco::detallar_clientes()
{
    int numdetallar;
    cout << "Ingrese el numero del cliente a detallar: " << endl;
    cin >> numdetallar;
    numdetallar--;

    if (numdetallar > num_clientes)
    {
        cout << "No existe el cliente" << endl;
        return;
    }
    cout << "Nombre: " << clientes[numdetallar].get_nombre() << endl;
    cout << "Apellido: " << clientes[numdetallar].get_apellido() << endl;
    cout << "DNI: " << clientes[numdetallar].get_dni() << endl;
    cout << "Tipo de Cliente: " << clientes[numdetallar].get_tipo_clente() << endl;
    cout << "Año de Ingreso: " << clientes[numdetallar].get_anio_ingreso() << endl;
    cout << "Estado: " << (clientes[numdetallar].get_estado() ? "Activo" : "Baja") << endl;
    cout << "Tarjeta: " << clientes[numdetallar].get_tarjeta() << endl;
    cout << "----------------------------------------------------" << endl;
}

void banco::realizar_transaccion()
{
    int numero_cliente;
    bool band = 1;
    string tipo1, moneda1;
    string monto1, dia1, mes1, anio1;
    float monto2;
    int dia2, mes2, anio2;
    cout << "Ingrese el numero del cliente de la transaccion: " << endl;
    cin >> numero_cliente;
    if (numero_cliente > num_clientes)
    {
        cout << "No existe el cliente" << endl;
        return;
    }
    do
    {
        cout << "Tipo de transaccion (Deposito o Extraccion): " << endl;
        cin >> tipo1;
        if (tipo1 == "Deposito" || tipo1 == "Extraccion")
        {
            band = 0;
        }
    } while (band == 1);
    band = 1;
    do
    {
        cout << "Moneda de transaccion (Pesos o Dolares): " << endl;
        cin >> moneda1;
        if (moneda1 == "Pesos" || moneda1 == "Dolares")
        {
            band = 0;
        }
    } while (band == 1);
    band = 1;
    do
    {
        cout << "Monto de la transaccion: " << endl;
        cin >> monto1;
        if (esnumero(monto1))
        {
            monto2 = stof(monto1);
            band = 0;
        }
    } while (band == 1);
    band = 1;
    do
    {
        cout << "Dia de la transaccion: " << endl;
        cin >> dia1;
        if (esnumero(dia1))
        {
            if (stoi(dia1) > 0 && stoi(dia1) < 32)
            {
                dia2 = stoi(dia1);
                band = 0;
            }
        }
    } while (band == 1);
    band = 1;
    do
    {
        cout << "Mes de la transaccion: " << endl;
        cin >> mes1;
        if (esnumero(mes1))
        {
            if (stoi(mes1) > 0 && stoi(mes1) < 13)
            {
                mes2 = stoi(mes1);
                band = 0;
            }
        }
    } while (band == 1);
    band = 1;
    do
    {
        cout << "Año de la transaccion: " << endl;
        cin >> anio1;
        if (esnumero(anio1))
        {
            if (stoi(anio1) > 1990 && stoi(anio1) < 2025)
            {
                anio2 = stoi(anio1);
                band = 0;
            }
        }
    } while (band == 1);
    transaccion nueva_transaccion(num_transacciones, monto2, numero_cliente, moneda1, tipo1, dia2, mes2, anio2);
    transacciones[num_transacciones] = nueva_transaccion;
    cout << "Transaccion realizada correctamente" << endl;
    num_transacciones++;

    ofstream archivo("transacciones.txt");
    if (archivo.is_open())
    {
        archivo << "Numero de transaccion: " << num_transacciones << "\n";
        archivo << "Nombre del cliente: " << clientes[numero_cliente - 1].get_nombre() << "\n";
        archivo << "Numero de cliente: " << numero_cliente << "\n";
        archivo << "Tipo de transaccion: " << tipo1 << "\n";
        archivo << "Moneda: " << moneda1 << "\n";
        archivo << "Monto: " << monto2 << "\n";
        archivo << "Fecha: " << dia2 << "/" << mes2 << "/" << anio2 << "\n";
        archivo << "-------------------------------\n";
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo para guardar la transaccion." << endl;
    }
}

void banco::listar_transacciones()
{
    int numero_cliente, verificador = num_transacciones;

    // Solicitar número de cliente
    cout << "Ingrese el número del cliente para listar transacciones: ";
    cin >> numero_cliente;

    // Validar si el número de cliente es válido
    if (numero_cliente > num_clientes || numero_cliente <= 0)
    {
        cout << "Número de cliente inválido." << endl;
        return;
    }

    // Mostrar las transacciones del cliente
    cout << "Transacciones del cliente: " << clientes[numero_cliente - 1].get_nombre() << endl;
    cout << "------------------------------------------" << endl;
    for (int i = 0; i < num_transacciones; i++)
    {
        if (transacciones[i].get_numero_cliente_transaccion() == numero_cliente)
        {
            verificador--;
            cout << "Número de transacción: " << transacciones[i].get_numero_transaccion() + 1 << endl;
            cout << "Tipo de transacción: " << transacciones[i].get_tipo_transaccion() << endl;
            cout << "Tipo de moneda: " << transacciones[i].get_tipo_moneda() << endl;
            cout << "Monto: " << transacciones[i].get_monto() << endl;
            cout << "Fecha: " << transacciones[i].get_dia() << "/" << transacciones[i].get_mes() << "/" << transacciones[i].get_anio() << endl;
            cout << "------------------------------------------" << endl;
        }
    }
    if(verificador == num_transacciones){
        cout << "No hay transacciones para el cliente seleccionado" << endl;
    }
}

void banco::informes_transacciones_mes()
{
    if (num_transacciones == 0)
    {
        cout << "No hay transacciones registradas" << endl;
        return;
    }
    string mes1, anio1;
    int mes, anio, verificador = num_transacciones;
    bool band = false;

    cout << "Ingrese el mes a informar: "<<endl;
    cin >> mes1;
    cout << "Ingrese el año a informar: "<<endl;
    cin >> anio1;
    do
    {
        if (esnumero(mes1))
        {
            mes = stoi(mes1);
            if (mes < 1 || mes > 12)
            {
                cout << "Mes inválido. Ingrese un número entre 1 y 12." << endl;
                band = true;
            }
            else
            {
                band = false;
            }
        }
        else
        {
            cout << "Mes inválido. Ingrese un número entre 1 y 12." << endl;
            band = true;
        }
    } while (band);
    band = false;
        do
    {
        if (esnumero(anio1))
        {
            anio = stoi(anio1);
            if (anio < 1990 || anio > 2025)
            {
                cout << "Anio inválido. Ingrese un número entre 1990 y 2025." << endl;
                band = true;
            }
            else
            {
                band = false;
            }
        }
        else
        {
            cout << "Anio inválido. Ingrese un número entre 1990 y 2025." << endl;
            band = true;
        }
    } while (band);

    for (int i = 0; i < num_transacciones; i++)
    {
        if (transacciones[i].get_mes() == mes || transacciones[i].get_anio() == anio)
        {
            verificador --;
            cout << "Número de transacción: " << transacciones[i].get_numero_transaccion() + 1 << endl;
            cout << "Tipo de transacción: " << transacciones[i].get_tipo_transaccion() << endl;
            cout << "Tipo de moneda: " << transacciones[i].get_tipo_moneda() << endl;
            cout << "Monto: " << transacciones[i].get_monto() << endl;
            cout << "Fecha: " << transacciones[i].get_dia() << "/" << transacciones[i].get_mes() << "/" << transacciones[i].get_anio() << endl;
            cout << "------------------------------------------" << endl;
        }
    }
    if(verificador == num_transacciones){
        cout << "No hay transacciones en el mes y año seleccionado" << endl;
    }
}