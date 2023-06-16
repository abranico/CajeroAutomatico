// INTEGRANTES:
// - Valentino Maffeis
// - Ivan Apanowicz
// - Nicolas Abramovich
// - Ramiro Muñoz
// - Kevin Rodrigo Kener

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int iniciarSesion(int nroCuentaCliente, char *contraseniaCliente, char *estadoCliente, int intentos);
void depositarSaldo();
void retirarSaldo();
void consultarSaldo();
void mostrarOperacionesYSaldo();
void cerrarSesion();

void main()
{
    // DATOS CLIENTE
    int const cantClientes = 10;
    int nroCuentaCliente = 123456789;
    char contraseniaCliente[20] = "martin123";
    char nombreCliente[20] = "MARTIN";
    float saldoCliente = 0;
    char estadoCliente[10] = "ACTIVO"; // [ACTIVO/BLOQUEADO]
    int sesionIniciada = 0;            // [0/1]
    // OTRAS VARIABLES:
    int intentosLogin = 1;

    // ----------- LOGIN -----------
    do
    {
        sesionIniciada = iniciarSesion(nroCuentaCliente, contraseniaCliente, estadoCliente, intentosLogin);
        if (sesionIniciada == 0)
        {
            printf("Número de cuenta o contraseña incorrecta\n");
            intentosLogin++;
        }
        else if (sesionIniciada == -1)
        {
            printf("Su cuenta se encuentra bloqueada, comuníquese con la entidad bancaria para su restablecimiento\n");
        }

    } while (sesionIniciada == 0 && intentosLogin <= 3);

    if (sesionIniciada == 1)
    {
        system("cls");
    }
    else
    {
        printf("Limite de intentos alcanzado.\n");
    }

    system("pause");
}

int iniciarSesion(int nroCuentaCliente, char *contraseniaCliente, char *estadoCliente, int intentos)
{

    int login;
    int nroCuenta;
    char contrasenia[20];
    printf("INTENTO %i/3\n", intentos);
    printf("Ingrese su número de cuenta: ");
    scanf("%i", &nroCuenta);
    printf("Ingrese contraseña: ");
    scanf("%s", &contrasenia);

    if (nroCuenta == nroCuentaCliente && strcmp(contrasenia, contraseniaCliente) == 0)
    {
        if (strcmp(estadoCliente, "ACTIVO") == 0)
        {
            login = 1;
        }
        else
        {
            login = -1;
        }
    }
    else
    {
        login = 0;
    }

    return login;
}

void depositarSaldo() {}

void retirarSaldo() {}

void consultarSaldo() {}

void mostrarOperacionesYSaldo() {}

void cerrarSesion() {}
