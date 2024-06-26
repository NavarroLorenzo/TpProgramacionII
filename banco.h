#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// clase persona//
class persona
{

private:
    string nombre;
    string apellido;
    int dni;

public:
    persona();
    persona(string, string, int);
    void set_nombre(string);
    void set_apellido(string);
    void set_dni(int);
    string get_nombre();
    string get_apellido();
    int get_dni();
};
// clase transaccion//
class transaccion
{
private:
    float numero_transaccion;
    float monto;
    int numero_cliente_transaccion;
    string tipo_moneda;
    string tipo_transaccion;
    int dia;
    int mes;
    int anio;

public:
    transaccion();
    transaccion(float, float, int, string, string, int, int, int);

    void set_numero_transaccion(float);
    void set_monto(float);
    void set_numero_cliente_transaccion(int);
    void set_tipo_moneda(string);
    void set_tipo_transaccion(string);
    void set_dia(int);
    void set_mes(int);
    void set_anio(int);

    float get_numero_transaccion();
    float get_monto();
    int get_numero_cliente_transaccion();
    string get_tipo_moneda();
    string get_tipo_transaccion();
    int get_dia();
    int get_mes();
    int get_anio();
};

// clase cliente, hereda de persona//
class cliente : public persona
{

private:
    string tipo_cliente;
    int anio_ingreso;
    bool estado;
    string tarjeta;

public:
    cliente();
    cliente(string, string, int, string, int, bool, string);
    void realizar_transaccion();
    void cambiar_estado();

    void set_tipo_cliente(string);
    void set_anio_ingreso(int);
    void set_estado(bool);
    void set_tarjeta(string);

    string get_tipo_clente();
    int get_anio_ingreso();
    bool get_estado();
    string get_tarjeta();
};

class empleado : public persona
{
private:
public:
    empleado();
};

class banco
{
private:
    cliente clientes[100];
    empleado empleados[100];
    transaccion transacciones[100];
    int num_clientes;
    int num_transacciones;

public:
    banco();
    banco(cliente[], empleado[], transaccion[], int, int);
    void set_num_clientes(int);
    int get_num_clientes();
    void set_num_transacciones(int);
    int get_num_transacciones();
    void cambiar_estado_cliente();

    void agregar_cliente();
    void listar_clientes();
    void detallar_clientes();
    void realizar_transaccion();
    void listar_transacciones();
    void informes_transacciones_mes();
    bool dni_existe(int);
};