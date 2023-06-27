// INTEGRANTES:
// - Valentino Maffeis
// - Ivan Apanowicz
// - Nicolas Abramovich
// - Ramiro Muñoz
// - Kevin Rodrigo Kener

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cantClientes = 10;
int indiceClienteActual; // Indice del cliente que inicio sesión.

void cargarClientes(int nroCuentaCliente[], char contraseniaCliente[][20], char nombreCliente[][20], float saldoCliente[], char estadoCliente[][10]);
int iniciarSesion(int nroCuentaCliente[], char contraseniaCliente[][20], char estadoCliente[][10], int intentos);
void depositarSaldo(float saldoCliente[]);
void retirarSaldo(float saldoCliente[]);

void main()
{
    // DATOS CLIENTE

    int nroCuentaCliente[cantClientes];
    char contraseniaCliente[cantClientes][20];
    char nombreCliente[cantClientes][20];
    float saldoCliente[cantClientes];
    char estadoCliente[cantClientes][10]; // [ACTIVO/BLOQUEADO]

    // OTRAS VARIABLES:
    int sesionIniciada;
    int intentosLogin;
    int opcionMenu;
    int intentosOperaciones;
    int cajeroEstado = 1; // Para que el cajero se reinicie al cerrar sesion

    cargarClientes(nroCuentaCliente, contraseniaCliente, nombreCliente, saldoCliente, estadoCliente);

    while (cajeroEstado = 1)
    {
        sesionIniciada = 0;
        intentosOperaciones = 0;
        intentosLogin = 1;

        // ----------- LOGIN -----------
        do
        {
            sesionIniciada = iniciarSesion(nroCuentaCliente, contraseniaCliente, estadoCliente, intentosLogin);

            if (sesionIniciada == 0)
            {
                printf("N%cmero de cuenta o contrase%ca incorrecta\n" ,163, 164);
                intentosLogin++;
            }
            else if (sesionIniciada == -1)
            {
                printf("\nSu cuenta se encuentra bloqueada, comun%cquese con la entidad bancaria para su restablecimiento\n" , 161);
            }

        } while (sesionIniciada == 0 && intentosLogin <= 3);
        if (intentosLogin > 3)
        {
            printf("\nNo se permiten m%cs intentos. Su cuenta ha sido bloqueada, comun%cquese con la entidad bancaria para su restablecimiento.\n" ,160, 161);
            // FALTA BLOQUEAR CUENTA POR LIMITE DE INTENTOS
        }

        // ----------- MENU -----------

        if (sesionIniciada == 1) // al confirmar login, muestro el menu.
        {
            system("cls");

            do
            {
                printf("\n------ Bienvenido/a %s ------\n", nombreCliente[indiceClienteActual]);
                printf("1)  Dep%csito.\n2)  Extracci%cn.\n3)  Consultar saldo.\n4)  Mostrar saldo y la cantidad de operaciones realizadas.\n5)  Cerrar Sesi%cn.\n" , 162, 162, 162);
                printf("Ingrese una opci%cn del men%c: " ,162 ,163);
                scanf("%i", &opcionMenu);
                printf("\n");
                switch (opcionMenu)
                {
                case 1:
                    // Depositar Saldo
                    depositarSaldo(saldoCliente);
                    intentosOperaciones = intentosOperaciones + 1;
                    break;
                case 2:
                    // Extraer Saldo
                    retirarSaldo(saldoCliente);
                    intentosOperaciones = intentosOperaciones + 1;
                    break;
                case 3:
                    // Mostrar Saldo
                    printf("Saldo: $%0.2f\n", saldoCliente[indiceClienteActual]);
                    intentosOperaciones = intentosOperaciones + 1;
                    break;
                case 4:
                    // Mostrar saldo y la cantidad de operaciones
                    printf("Saldo: $%0.2f\n", saldoCliente[indiceClienteActual]);
                    printf("Cantidad de operaciones: %i\n", intentosOperaciones);
                    break;
                case 5:
                    // Salir
                    break;
                default:
                    printf("Opci%cn inv%clida.\n" , 162, 160);
                    break;
                }

            } while (opcionMenu != 5 && intentosOperaciones < 10);
        }
        if (intentosOperaciones >= 10)
        {
            printf("Lleg%c al limite de operaciones. Fin. Gracias!\n" , 162);
        }
    }

    printf("\n");
    system("pause");
}

int iniciarSesion(int nroCuentaCliente[], char contraseniaCliente[][20], char estadoCliente[][10], int intentos)
{
    int i = 0;

    int login = 0;
    int nroCuenta;
    char contrasenia[20];

    printf("\n------ INTENTO [%i/3] ------\n", intentos);
    printf("Ingrese su n%cmero de cuenta: " , 163);
    scanf("%i", &nroCuenta);
    printf("Ingrese contrase%ca: " , 164);
    scanf("%s", &contrasenia);

    while (i < cantClientes)
    {
        if (nroCuenta == nroCuentaCliente[i] && strcmp(contraseniaCliente[i], contrasenia) == 0)
        {
            if (strcmp(estadoCliente[i], "ACTIVO") == 0)
            {
                login = 1;
                indiceClienteActual = i;
            }
            else
            {
                login = -1;
            }
            break;
        }
        i++;
    }

    return login;
}

void depositarSaldo(float saldoCliente[])
{
    float saldoADepositar;

    do
    {
        printf("Ingrese la cantidad de saldo a depositar: ");
        scanf("%f", &saldoADepositar);
        if (saldoADepositar <= 0)
        {
            printf("Dep%csito incorrecto.\n" , 162);
        }
    } while (saldoADepositar <= 0);
    saldoCliente[indiceClienteActual] += saldoADepositar;
    printf("Dep%csito realizado con exito.\n" , 162);
}

void retirarSaldo(float saldoCliente[])
{
    float saldoARetirar;

    do
    {
        printf("Ingrese la cantidad de dinero a retirar: ");
        scanf("%f", &saldoARetirar);
        if (saldoARetirar > saldoCliente[indiceClienteActual])
        {
            printf("El saldo en la cuenta es insuficiente.\n");
        }
        if (saldoARetirar < 0)
        {
            printf("El saldo ingresado a retirar es incorrecto.\n");
        }
    } while (saldoARetirar < 0 || saldoARetirar > saldoCliente[indiceClienteActual]);

    saldoCliente[indiceClienteActual] -= saldoARetirar;
    printf("Extracci%cn exitosa.\n" , 162);
}

void cargarClientes(int nroCuentaCliente[], char contraseniaCliente[][20], char nombreCliente[][20], float saldoCliente[], char estadoCliente[][10])
{
    // Cliente 1
    nroCuentaCliente[0] = 123456789;
    strcpy(contraseniaCliente[0], "martin123");
    strcpy(nombreCliente[0], "Martin");
    saldoCliente[0] = 500;
    strcpy(estadoCliente[0], "ACTIVO");

    // Cliente 2
    nroCuentaCliente[1] = 987654321;
    strcpy(contraseniaCliente[1], "ana456");
    strcpy(nombreCliente[1], "Ana");
    saldoCliente[1] = 1000;
    strcpy(estadoCliente[1], "BLOQUEADO");

    // Cliente 3
    nroCuentaCliente[2] = 246813579;
    strcpy(contraseniaCliente[2], "pedro789");
    strcpy(nombreCliente[2], "Pedro");
    saldoCliente[2] = 750;
    strcpy(estadoCliente[2], "ACTIVO");

    // Cliente 4
    nroCuentaCliente[3] = 135792468;
    strcpy(contraseniaCliente[3], "maria321");
    strcpy(nombreCliente[3], "Maria");
    saldoCliente[3] = 1200;
    strcpy(estadoCliente[3], "ACTIVO");

    // Cliente 5
    nroCuentaCliente[4] = 864209753;
    strcpy(contraseniaCliente[4], "carlos987");
    strcpy(nombreCliente[4], "Carlos");
    saldoCliente[4] = 250;
    strcpy(estadoCliente[4], "BLOQUEADO");

    // Cliente 6
    nroCuentaCliente[5] = 567890123;
    strcpy(contraseniaCliente[5], "laura555");
    strcpy(nombreCliente[5], "Laura");
    saldoCliente[5] = 1500;
    strcpy(estadoCliente[5], "ACTIVO");

    // Cliente 7
    nroCuentaCliente[6] = 321654987;
    strcpy(contraseniaCliente[6], "javier789");
    strcpy(nombreCliente[6], "Javier");
    saldoCliente[6] = 900;
    strcpy(estadoCliente[6], "BLOQUEADO");

    // Cliente 8
    nroCuentaCliente[7] = 654987321;
    strcpy(contraseniaCliente[7], "lucia222");
    strcpy(nombreCliente[7], "Lucia");
    saldoCliente[7] = 600;
    strcpy(estadoCliente[7], "ACTIVO");

    // Cliente 9
    nroCuentaCliente[8] = 789654123;
    strcpy(contraseniaCliente[8], "roberto777");
    strcpy(nombreCliente[8], "Roberto");
    saldoCliente[8] = 350;
    strcpy(estadoCliente[8], "BLOQUEADO");

    // Cliente 10
    nroCuentaCliente[9] = 456321987;
    strcpy(contraseniaCliente[9], "mariana888");
    strcpy(nombreCliente[9], "Mariana");
    saldoCliente[9] = 2000;
    strcpy(estadoCliente[9], "ACTIVO");
}