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
float depositarSaldo(float saldoCliente);
float retirarSaldo(float saldoCliente);
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
    float saldoDepositado;
    int intentosLogin = 1;
    int intentosOperaciones = 1;
    int opcionesMenu;
    float depositoPlata, extraccionPlata;

    // ----------- LOGIN -----------
    do
    {
        sesionIniciada = iniciarSesion(nroCuentaCliente, contraseniaCliente, estadoCliente, intentosLogin);
        if (sesionIniciada == 0)
        {
            printf("Numero de cuenta o contraseña incorrecta\n");
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
        // al confirmar login, muestro el menu.
        do
        {
            printf("\n1)  Deposito.\n 2)  Extraccion.\n 3)  Consultar saldo.\n 4)  Mostrar la cantidad de operaciones realizadas y el saldo actual.\n 5)  Salir.\n ");
            scanf("%i", &opcionesMenu);
            switch (opcionesMenu)
            {
            case 1:
                saldoDepositado = depositarSaldo(saldoCliente);
                saldoCliente = saldoCliente + saldoDepositado;
                intentosOperaciones = intentosOperaciones + 1;

                break;
            case 2:

                extraccionPlata = retirarSaldo(saldoCliente);
                saldoCliente = saldoCliente - extraccionPlata;
                intentosOperaciones = intentosOperaciones + 1;

                break;
            case 3:
                printf("Saldo: $%0.2f\n", saldoCliente);
                intentosOperaciones = intentosOperaciones + 1;
                break;
            case 4:
                printf("Cantidad de operaciones: %i\n", intentosOperaciones);
                break;

            default:
                break;
            }
            if (intentosOperaciones > 10)
            {
                printf("Llego al limite de operaciones Fin Gracias!\n");
            }

        } while (opcionesMenu != 5 && intentosOperaciones <= 10);
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

float depositarSaldo(float saldoCliente)
{
    float saldoADepositar = 0;
    float saldoDepositado = 0;
    do
    {
        printf("Ingrese la cantidad de saldo a depositar.\n");
        scanf("%f", &saldoADepositar);
        if (saldoADepositar < 0)
        {
            printf("Deposito incorrecto.\n");
        }

    } while (saldoADepositar < 0);
    printf("Saldo aprobado.\n");
    saldoDepositado = saldoADepositar + saldoDepositado;
    return saldoDepositado;
}

float retirarSaldo(float saldoCliente)
{
    float saldoARetirar = 0;
    float saldoRetirado = 0;

    do
    {
        printf("ingrese la cantidad de dinero a retirar.\n");
        scanf("%f", &saldoARetirar);
        if (saldoARetirar > saldoCliente)
        {
            printf("Saldo en la cuenta Insuficiente.\n");
        }
        if (saldoARetirar < 0)
        {
            printf("Saldo a retirar ingresado incorrecto.\n");
        }

    } while (saldoARetirar < 0 || saldoARetirar > saldoCliente);
    printf("Extraccion exitosa.\n");
    saldoRetirado = saldoRetirado + saldoARetirar;
    return saldoRetirado;
}

void consultarSaldo() {}

void mostrarOperacionesYSaldo() {}

void cerrarSesion() {}
