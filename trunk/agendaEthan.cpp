/*
  - Ethan Martínez Carratalá
  - Aitor Salgado Molina
  - Andrés Marotta
  - Raquel Lloréns Gambín
*/

#include <iostream>
#include <string>
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
void VerContactosOpcion03(int numContactos, tipoContacto contactos[])
{
	int i;
	
	for ( i = 0 ; i < numContactos ; i++ )
	{
		cout << "Id: " << contactos[i].id << endl;
		cout << "Nombre: " << contactos[i].nombre << endl;
		cout << "Apellidos: " << contactos[i].apellido << endl;
		cout << "Teléfono: " << contactos[i].telefono << endl;
		cout << "Correo: " << contactos[i].email << endl;
		cout << "Fecha de cumpleaños: " << contactos[i].cumpleanyos
			<< endl;
		cout << "Edad: " << contactos[i].edad << endl;
		cout << "--------------------" << endl;
		cout << endl;
	}
}

// Ordenar la lista de contactos alfabeticamente
void OrdenarAlfabeticamente(int numContactos, tipoContacto contactosAux[])
{
	int i, j;
	tipoContacto fichaTemporal;
	
	for ( i = 0 ; i < numContactos-1 ; i++ )
	{
		for ( j = i+1 ; j < numContactos ; j++ )
		{
			if ( contactosAux[i].nombre > contactosAux[j].nombre )
			{
				fichaTemporal = contactosAux[i];
				contactosAux[i] = contactosAux[j];
				contactosAux[j] = fichaTemporal;
			}
		}
	}

	for ( i = 0 ; i < numContactos ; i++ )
	{
		cout << "Id: " << contactosAux[i].id << endl;
		cout << "Nombre: " << contactosAux[i].nombre << endl;
		cout << "Apellidos: " << contactosAux[i].apellido << endl;
		cout << "Teléfono: " << contactosAux[i].telefono << endl;
		cout << "Correo: " << contactosAux[i].email << endl;
		cout << "Fecha de cumpleaños: " << contactosAux[i].cumpleanyos
			<< endl;
		cout << "Edad: " << contactosAux[i].edad << endl;
		cout << "--------------------" << endl;
		cout << endl;
	}
}

// Ordenar por edad
void OrdenarEdad(int numContactos, tipoContacto contactosAux[])
{
	int i, j;
	tipoContacto fichaTemporal;
	
	for ( i = 0 ; i < numContactos-1 ; i++ )
	{
		for ( j = i+1 ; j < numContactos ; j++ )
		{
			if ( contactosAux[i].edad > contactosAux[j].edad )
			{
				fichaTemporal = contactosAux[i];
				contactosAux[i] = contactosAux[j];
				contactosAux[j] = fichaTemporal;
			}
		}
	}

	for ( i = 0 ; i < numContactos ; i++ )
	{
		cout << "Id: " << contactosAux[i].id << endl;
		cout << "Nombre: " << contactosAux[i].nombre << endl;
		cout << "Apellidos: " << contactosAux[i].apellido << endl;
		cout << "Teléfono: " << contactosAux[i].telefono << endl;
		cout << "Correo: " << contactosAux[i].email << endl;
		cout << "Fecha de cumpleaños: " << contactosAux[i].cumpleanyos
			<< endl;
		cout << "Edad: " << contactosAux[i].edad << endl;
		cout << "--------------------" << endl;
		cout << endl;
	}
}

// Función para calcular los días faltantes hasta el cumpleaños de un contacto
void CalcularCumpleanyos()
{
}

int main()
{
    // Variables
    int opcion = 0;
    int numContactos = 0;
    tipoContacto contactos[maxContactos];
	tipoContacto contactosAux[maxContactos];

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
                system("cls");
				cout << "1. Ver todos" << endl;
				cout << "2. Ordenar" << endl;
				cout << "Introduzca una opción: ";
				cin >> opcion;
				cout << "--------------------" << endl;
				cout << endl;
				
				switch (opcion)
				{
					case 1:
						VerContactosOpcion03(numContactos, contactos);
						break;
					
					case 2:
						cout << "1. Ordenar alfabeticamente." << endl;
						cout << "2. Ordenar por edad." << endl;
						cout << "Introduzca una opción: ";
						cin >> opcion;
						cout << "--------------------" << endl;
						cout << endl;
						
						switch (opcion)
						{
							case 1:
								OrdenarAlfabeticamente(numContactos, contactos);
								break;
							case 2:
								OrdenarEdad(numContactos, contactos);
								break;
						}
						
						break;
				}
				break;

            // Calcular cumpleaños
            case 4:
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
