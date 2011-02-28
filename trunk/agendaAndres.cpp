/*
  - Ethan Mart�nez Carratal�
  - Aitor Salgado Molina
  - Andr�s Marotta
  - Raquel Llor�ns Gamb�n
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#define maxContactos 50

using namespace std;

struct tipoContacto
{
  int id;
  string nombre;
  string apellido;
  string telefono;
  string email;
  string cumpleanyos;
  int edad;
};

// Funci�n para agregar un contacto
void InsertarContacto()
{
}

// Funci�n para modificar un contacto
void ModificarContacto()
{
}

// Funci�n para ver la lista de contactos
void VerContactos()
{
}

// Funci�n para calcular los d�as faltantes hasta el cumplea�os de un contacto
void CalcularCumpleanyos( int dia, int mes )
{
    int id;
    int diaBuscar;
    int mesBuscar;
    int diasFaltantes;
    int mesesFaltantes;

    // ### FALTA AGREGAR LA FUNCION DE ETHAN ###
    // VerContactosOpcion03( numContactos, contactos );

    cout << "Introduzca el ID del usuario para calcular fecha" << endl;
    cin >> id;

    diaBuscar = atoi(contactos[id-1].cumpleanyos.substr(0,2).c_str());
    mesBuscar = atoi(contactos[id-1].cumpleanyos.substr(3).c_str());

	// Calculo del mes
	if ( mes == mesBuscar )
		mesesFaltantes = 0;

	else
	{
		if ( mes < mesBuscar )
			mesesFaltantes = mesBuscar - mes;

		else
			mesesFaltantes = (12 - mes) + mesBuscar;
	}

	// Calculo del d�a
	if ( dia == diaBuscar )
		diasFaltantes = 0;

	else
	{
		if ( dia < diaBuscar )
			diasFaltantes = diaBuscar - dia;

		else
		{
			switch ( mes )
			{
				// Enero
                case 1:
					goto case 12;
                break;

                // Febrero
                case 2:
                    diasFaltantes = (28 - dia) + diaBuscar;
                break;

                // Marzo
                case 3:
                    goto case 12;
                break;

                // Abril
                case 4:
                    goto case 11;
                break;

                // Mayo
                case 5:
                    goto case 12;
                break;

                // Junio
                case 6:
                    goto case 11;
                break;

                // Julio
                case 7:
                    goto case 12;
                break;

                // Agosto
                case 8:
                    goto case 12;
                break;

                // Septiembre
                case 9:
                    goto case 11;
                break;

                // Octubre
                case 10:
                    goto case 12;
                break;

                // Noviembre
                case 11:
                    diasFaltantes = (30 - dia) + diaBuscar;
                break;

                // Diciembre
                case 12:
                    diasFaltantes = (31 - dia) + diaBuscar;
                break;
			}
		}
	}

	// Muestro los d�as y los meses que faltan
	if ( (diasFaltantes == 0) && (mesesFaltantes == 0) )
		cout << "El cumplea�os es hoy" << endl;

	else
	{
		if ( (diasFaltantes > 0) && (mesesFaltantes == 0) )
			cout << "Faltan " << diasFaltantes << " d�as" << endl;

		else
		{
			if ( (diasFaltantes == 0) && (mesesFaltantes > 0) )
				cout << "Faltan " << mesesFaltantes << " meses" << endl;

			else
			{
				cout << "Faltan " << diasFaltantes << " d�as";
				cout << " y " << mesesFaltantes << " meses" << endl;
			}
		}
	}
}

int main()
{
    // Variables
    int opcion = 0;
    int numContactos = 0;
    tipoContacto contactos[maxContactos];

    // ### Variables para la opci�n 4 ###
    string fechaActual;
    int dia;
    int mes;
    bool ok;

    cout << "Agenda de Contactos" << endl;
    cout << endl;
    
    // B�cle del programa
    do
    {
        // Men� de opciones
        cout << "----- Opciones -----" << endl;
        cout << endl;
        cout << "1.- Agregar nuevo contacto" << endl;
        cout << "2.- Modificar un contacto" << endl;
        cout << "3.- Ver contactos" << endl;
        cout << "4.- Calcular cumplea�os" << endl;
        cout << "5.- Salir" << endl;
        cout << endl;
        cout << "Introduzca una opci�n: ";
        cin >> opcion;
        cout << endl;
        cout << "--------------------" << endl;
        cout << endl;

        switch ( opcion )
        {
            // Agregar nuevo contacto
            case 1:
            break;

            // Modificar un contacto
            case 2:
            break;

            // Ver lista de contactos
            case 3:
            break;

            // Calcular cumplea�os
            case 4:
                system("cls");
                ok = false;

                cout << endl;
                cout << "Calcular cumplea�os" << endl;
                cout << endl;

                do
                {
                    cout << "Introduzca la fecha de hoy (DD-MM): ";
                    cin >> fechaActual;

                    if ( fechaActual == "" )
                        cout << "La fecha no puede estar vac�a" << endl;

                    else
                    {
                        if ( fechaActual.length() > 5)
                            cout << "El formato de fecha no es correcto: DD-MM" << endl;

                        else
                        {
                            try
                            {
                                mes = atoi(fechaActual.substr(3).c_str());

                                // Comprobaci�n de mes
                                if ( mes < 1 )
                                    cout << "El mes no puede ser inferior a 01 (Enero)" << endl;

                                else
                                {
                                    if ( mes > 12 )
                                        cout << "El mes no puede ser superior a 12 (Diciembre)" << endl;

                                    else
                                    {
                                        dia = atoi(fechaActual.substr(0,2).c_str());

                                        // Comprobaci�n de d�a, por mes
                                        switch ( mes )
                                        {
                                            // Enero
                                            case 1:
												goto case 12;
                                            break;

                                            // Febrero
                                            case 2:
                                                if ( (dia >= 1) && (dia <= 28 ) )
                                                    ok = true;

                                                else
                                                    cout << "El dia tiene que estar entre 01 y 28" << endl;
                                            break;

                                            // Marzo
                                            case 3:
                                                goto case 12;
                                            break;

                                            // Abril
                                            case 4:
                                                goto case 11;
                                            break;

                                            // Mayo
                                            case 5:
                                                goto case 12;
                                            break;

                                            // Junio
                                            case 6:
                                                goto case 11;
                                            break;

                                            // Julio
                                            case 7:
                                                goto case 12;
                                            break;

                                            // Agosto
                                            case 8:
                                                goto case 12;
                                            break;

                                            // Septiembre
                                            case 9:
                                                goto case 11;
                                            break;

                                            // Octubre
                                            case 10:
                                                goto case 12;
                                            break;

                                            // Noviembre
                                            case 11:
                                                if ( (dia >= 1) && (dia <= 30 ) )
                                                    ok = true;

                                                else
                                                    cout << "El dia tiene que estar entre 01 y 30" << endl;
                                            break;

                                            // Diciembre
                                            case 12:
                                                if ( (dia >= 1) && (dia <= 31 ) )
                                                    ok = true;

                                                else
                                                    cout << "El dia tiene que estar entre 01 y 31" << endl;
                                            break;
                                        }
                                    }
                                }
                            }

                            catch ( exception )
                            {
                                cout << "Los valores introducidos no son incorrectos" << endl;
                            }
                        }
                    }
                }
                while ( ok != true );

                CalcularCumpleanyos( dia, mes );
            break;

            // Salir
            case 5:
                cout << "Que tengas un buen d�a ;)" << endl;
                cout << endl;
            break;

            // Opci�n por defecto
            default:
                system("cls");
                cout << "Por favor, introduzca una opci�n v�lida." << endl;
                cout << endl;
            break;
        }
    }
    while ( opcion != 5 );

    return 0;
}
