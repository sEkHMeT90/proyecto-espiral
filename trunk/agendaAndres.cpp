/*
  - Ethan Martínez Carratalá
  - Aitor Salgado Molina
  - Andrés Marotta
  - Raquel Lloréns Gambín
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

// Función para agregar un contacto
void InsertarContacto()
{
}

// Función para modificar un contacto
void ModificarContacto()
{
}

// Función para ver la lista de contactos
void VerContactos()
{
}

// Función para calcular los días faltantes hasta el cumpleaños de un contacto
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

	// Calculo del día
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

	// Muestro los días y los meses que faltan
	if ( (diasFaltantes == 0) && (mesesFaltantes == 0) )
		cout << "El cumpleaños es hoy" << endl;

	else
	{
		if ( (diasFaltantes > 0) && (mesesFaltantes == 0) )
			cout << "Faltan " << diasFaltantes << " días" << endl;

		else
		{
			if ( (diasFaltantes == 0) && (mesesFaltantes > 0) )
				cout << "Faltan " << mesesFaltantes << " meses" << endl;

			else
			{
				cout << "Faltan " << diasFaltantes << " días";
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

    // ### Variables para la opción 4 ###
    string fechaActual;
    int dia;
    int mes;
    bool ok;

    cout << "Agenda de Contactos" << endl;
    cout << endl;
    
    // Búcle del programa
    do
    {
        // Menú de opciones
        cout << "----- Opciones -----" << endl;
        cout << endl;
        cout << "1.- Agregar nuevo contacto" << endl;
        cout << "2.- Modificar un contacto" << endl;
        cout << "3.- Ver contactos" << endl;
        cout << "4.- Calcular cumpleaños" << endl;
        cout << "5.- Salir" << endl;
        cout << endl;
        cout << "Introduzca una opción: ";
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

            // Calcular cumpleaños
            case 4:
                system("cls");
                ok = false;

                cout << endl;
                cout << "Calcular cumpleaños" << endl;
                cout << endl;

                do
                {
                    cout << "Introduzca la fecha de hoy (DD-MM): ";
                    cin >> fechaActual;

                    if ( fechaActual == "" )
                        cout << "La fecha no puede estar vacía" << endl;

                    else
                    {
                        if ( fechaActual.length() > 5)
                            cout << "El formato de fecha no es correcto: DD-MM" << endl;

                        else
                        {
                            try
                            {
                                mes = atoi(fechaActual.substr(3).c_str());

                                // Comprobación de mes
                                if ( mes < 1 )
                                    cout << "El mes no puede ser inferior a 01 (Enero)" << endl;

                                else
                                {
                                    if ( mes > 12 )
                                        cout << "El mes no puede ser superior a 12 (Diciembre)" << endl;

                                    else
                                    {
                                        dia = atoi(fechaActual.substr(0,2).c_str());

                                        // Comprobación de día, por mes
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
                cout << "Que tengas un buen día ;)" << endl;
                cout << endl;
            break;

            // Opción por defecto
            default:
                system("cls");
                cout << "Por favor, introduzca una opción válida." << endl;
                cout << endl;
            break;
        }
    }
    while ( opcion != 5 );

    return 0;
}
