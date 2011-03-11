/*
  - Ethan Mart�nez Carratal�
  - Aitor Salgado Molina
  - Andr�s Marotta
  - Raquel Llor�ns Gamb�n
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
  string notas[maxContactos];
  int siguienteNota;
};

// Funci�n para agregar un contacto
void InsertarContacto(int numContactos, tipoContacto contactos[])
{
  string auxText;
  int dia;
  int mes;
  bool ok = false;

  //Asignamos la id
  contactos[numContactos].id = numContactos + 1;

  // Pedimos el nombre
  cout << "Introduzca su nombre: ";
  cin >> contactos[numContactos].nombre;

  // Pedimos el apellido
  cout << "Introduzca su apellido: ";
  cin >> contactos[numContactos].apellido;

  // Pedimos el tel�fono mientras tenga m�s de 15 d�gitos
  do
  {
     if (auxText.length() > 15)
      cout << "N�mero excesivamente largo." << endl;

    cout << "Introduzca su tel�fono: ";
    cin >> auxText;
  }
  while(auxText.length() > 15);

  contactos[numContactos].telefono = auxText;

  // Pedimos el e-mail
  cout << "Introduzca su e-mail: ";
  cin >> contactos[numContactos].email;

  // Pedimos el d�a de cumplea�os y comprobamos el formato y la fecha
  try 
  {
        do
        {
            cout << "Introduzca el d�a de su cumplea�os (DD-MM): ";
            cin >> auxText;

            if ( auxText == "" )
                cout << "La fecha no puede estar vac�a" << endl;

            else
            {
                if ( auxText.length() != 5 )
                    cout << "El formato de fecha no es correcto: DD-MM" << endl;

                else
                {
                    if ( auxText[2] != '-' )
                    {
                        cout << "El formato de fecha no es correcto: DD-MM" << endl;
                    }

                    else
                    {
                        try
                        {
                            mes = atoi(auxText.substr(3).c_str());

                            // Comprobaci�n de mes
                            if ( mes < 1 )
                                cout << "El mes no puede ser inferior a 01 (Enero)" << endl;

                            else
                            {
                                if ( mes > 12 )
                                    cout << "El mes no puede ser superior a 12 (Diciembre)" << endl;

                                else
                                {
                                    dia = atoi(auxText.substr(0,2).c_str());

                                    // Comprobaci�n de d�a, por mes
                                    switch ( mes )
                                    {
                                        // Enero
                                        case 1:
									        if ( (dia >= 1) && (dia <= 31 ) )
                                                ok = true;

                                            else
                                                cout << "El dia tiene que estar entre 01 y 31" << endl;
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
                                            if ( (dia >= 1) && (dia <= 31 ) )
                                                ok = true;

                                            else
                                                cout << "El dia tiene que estar entre 01 y 31" << endl;
                                        break;

                                        // Abril
                                        case 4:
                                            if ( (dia >= 1) && (dia <= 30 ) )
                                                ok = true;

                                            else
                                                cout << "El dia tiene que estar entre 01 y 30" << endl;
                                        break;

                                        // Mayo
                                        case 5:
                                            if ( (dia >= 1) && (dia <= 31 ) )
                                                ok = true;

                                            else
                                                cout << "El dia tiene que estar entre 01 y 31" << endl;
                                        break;

                                        // Junio
                                        case 6:
                                            if ( (dia >= 1) && (dia <= 30 ) )
                                                ok = true;

                                            else
                                                cout << "El dia tiene que estar entre 01 y 30" << endl;
                                        break;

                                        // Julio
                                        case 7:
                                            if ( (dia >= 1) && (dia <= 31 ) )
                                                ok = true;

                                            else
                                                cout << "El dia tiene que estar entre 01 y 31" << endl;
                                        break;

                                        // Agosto
                                        case 8:
                                            if ( (dia >= 1) && (dia <= 31 ) )
                                                ok = true;

                                            else
                                                cout << "El dia tiene que estar entre 01 y 31" << endl;
                                        break;

                                        // Septiembre
                                        case 9:
                                            if ( (dia >= 1) && (dia <= 30 ) )
                                                ok = true;

                                            else
                                                cout << "El dia tiene que estar entre 01 y 30" << endl;
                                        break;

                                        // Octubre
                                        case 10:
                                            if ( (dia >= 1) && (dia <= 31 ) )
                                                ok = true;

                                            else
                                                cout << "El dia tiene que estar entre 01 y 31" << endl;
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
        }
        while ( ok != true );
  
    contactos[numContactos].cumpleanyos = auxText;
  }

  catch( exception )
  {
    cout << "Los valores introducidos no son correctos";
  }
  // Pedimos el edad
  cout << "Introduzca su edad: ";
  cin >> contactos[numContactos].edad;
  
  contactos[numContactos].siguienteNota = 0;
}

// Funci�n para modificar un contacto
void ModificarContacto(int numContactos, tipoContacto contactos[])
{
  int contactoModificar = 0;//Variale para seleccionar que contacto modificar
  string nombreAuxiliar;
  int edadAuxiliar;
  
  do
  {
     cout << "Introduce el contacto a modificar " <<endl;
     cin >> contactoModificar;
     cin.ignore();
  }while( contactoModificar <= 0 || contactoModificar > numContactos);
  contactoModificar-=1;

  cout << "Este es el antiguo nombre: " << contactos[contactoModificar].nombre <<endl;
  cout << "Dime el nuevo nombre (Pulsa intro si on quieres introducir nada)" <<endl;
  getline(cin,nombreAuxiliar);
  if ( nombreAuxiliar != "")
    contactos[contactoModificar].nombre = nombreAuxiliar;
  
  cout << "Este es el antiguo apellido: " << contactos[contactoModificar].apellido <<endl;
  cout << "Dime el nuevo apellido (Pulsa intro si on quieres introducir nada)" <<endl;
  getline(cin,nombreAuxiliar);
  if ( nombreAuxiliar != "")
    contactos[contactoModificar].apellido = nombreAuxiliar;

  cout << "Este es el antiguo telefono: " << contactos[contactoModificar].telefono <<endl;
  cout << "Dime el nuevo telefono (Pulsa intro si on quieres introducir nada)" <<endl;
  getline(cin,nombreAuxiliar);
  if ( nombreAuxiliar != "")
    contactos[contactoModificar].telefono = nombreAuxiliar;

  cout << "Este es el antiguo email: " << contactos[contactoModificar].email <<endl;
  cout << "Dime el nuevo email (Pulsa intro si on quieres introducir nada)" <<endl;
  getline(cin,nombreAuxiliar);
  if ( nombreAuxiliar != "")
    contactos[contactoModificar].email = nombreAuxiliar;

  cout << "Este es el antiguo cumplea�os: " << contactos[contactoModificar].cumpleanyos <<endl;
  cout << "Dime el nuevo cumplea�os (Pulsa intro si on quieres introducir nada)" <<endl;
  getline(cin,nombreAuxiliar);
  if ( nombreAuxiliar != "")
    contactos[contactoModificar].cumpleanyos = nombreAuxiliar;
  
  cout << "Este es el antiguo edad: " << contactos[contactoModificar].cumpleanyos <<endl;
  cout << "Dime el nuevo edad (Pulsa intro si on quieres introducir nada)" <<endl;
  getline(cin,nombreAuxiliar);
  if ( nombreAuxiliar != "")
  {
    edadAuxiliar = atoi(nombreAuxiliar.c_str());
    contactos[contactoModificar].edad = edadAuxiliar;
  }

  cout << "Los datos han quedado as�:" << contactos[contactoModificar].id << "-" << contactos                   [contactoModificar].nombre << "-" << contactos[contactoModificar].apellido << "-" << contactos[contactoModificar].telefono << "-" << contactos[contactoModificar].email << "-" << contactos[contactoModificar].cumpleanyos << "-" << contactos[contactoModificar].cumpleanyos << "-" << contactos[contactoModificar].edad << endl;
}


// Funci�n para ver la lista de contactos
void VerContactosOpcion03(int numContactos, tipoContacto contactos[])
{
	int i;
	
	for ( i = 0 ; i < numContactos ; i++ )
	{
		cout << "Id: " << contactos[i].id << endl;
		cout << "Nombre: " << contactos[i].nombre << endl;
		cout << "Apellidos: " << contactos[i].apellido << endl;
		cout << "Tel�fono: " << contactos[i].telefono << endl;
		cout << "Correo: " << contactos[i].email << endl;
		cout << "Fecha de cumplea�os: " << contactos[i].cumpleanyos
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
    int cont = 1;
    string var;
	tipoContacto fichaTemporal;
	
	for ( i = 0 ; i < numContactos-1 ; i++ )
	{
		for ( j = i+1 ; j < numContactos ; j++ )
		{
			// Comparo los nombres
			if ( contactosAux[i].nombre > contactosAux[j].nombre )
			{
				fichaTemporal = contactosAux[i];
				contactosAux[i] = contactosAux[j];
				contactosAux[j] = fichaTemporal;
			}
		}
	}

	// Muestro los contactos ya ordenados
	for ( i = 0 ; i < numContactos ; i++ )
	{
		cout << "Id: " << contactosAux[i].id << endl;
		cout << "Nombre: " << contactosAux[i].nombre << endl;
		cout << "Apellidos: " << contactosAux[i].apellido << endl;
		cout << "Tel�fono: " << contactosAux[i].telefono << endl;
		cout << "Correo: " << contactosAux[i].email << endl;
		cout << "Fecha de cumplea�os: " << contactosAux[i].cumpleanyos
			<< endl;
		cout << "Edad: " << contactosAux[i].edad << endl;
		cout << "--------------------" << endl;
		cout << endl;
		
		// Mostrar de 10 en 10
		if (cont == 10)
		{
			// Si no quedan contactos
			if (i == maxContactos - 1)
			{
				cout << "Pulse una tecla para volver al men�..." << endl;
				cin >> var;
				cont = 0;
				system("cls");
			}
			// Al llegar a los diez
			else 
			{
				cout << "Pulse una tecla para continuar..." << endl;
				cin >> var;
				cont = 0;
				system("cls");
			}
		}

	cont++;
	}
}


// Ordenar por edad
void OrdenarEdad(int numContactos, tipoContacto contactosAux[])
{
	int i, j;
	int cont = 1;
    string var;
	tipoContacto fichaTemporal;
	
	for ( i = 0 ; i < numContactos-1 ; i++ )
	{
		for ( j = i+1 ; j < numContactos ; j++ )
		{
			// Comparo las edades
			if ( contactosAux[i].edad > contactosAux[j].edad )
			{
				fichaTemporal = contactosAux[i];
				contactosAux[i] = contactosAux[j];
				contactosAux[j] = fichaTemporal;
			}
		}
	}
	
	// Muestro los contactos ya ordenados
	for ( i = 0 ; i < numContactos ; i++ )
	{
		cout << "Id: " << contactosAux[i].id << endl;
		cout << "Nombre: " << contactosAux[i].nombre << endl;
		cout << "Apellidos: " << contactosAux[i].apellido << endl;
		cout << "Tel�fono: " << contactosAux[i].telefono << endl;
		cout << "Correo: " << contactosAux[i].email << endl;
		cout << "Fecha de cumplea�os: " << contactosAux[i].cumpleanyos
			<< endl;
		cout << "Edad: " << contactosAux[i].edad << endl;
		cout << "--------------------" << endl;
		cout << endl;
		
		// Mostrar de 10 en 10
		if (cont == 10)
		{
			// Si no quedan contactos
			if (i == maxContactos - 1)
			{
				cout << "Pulse una tecla para volver al men�..." << endl;
				cin >> var;
				cont = 0;
				system("cls");
			}
			// Al llegar a los diez
			else 
			{
				cout << "Pulse una tecla para continuar..." << endl;
				cin >> var;
				cont = 0;
				system("cls");
			}
		}

	cont++;
	}
}

// Funci�n para calcular los d�as faltantes hasta el cumplea�os de un contacto
void CalcularCumpleanyos( int dia, int mes, int numContactos, tipoContacto contactos[] )
{
    int id;
    int diaBuscar;
    int mesBuscar;
    int diasFaltantes;
    int mesesFaltantes;

    VerContactosOpcion03( numContactos, contactos );

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
					diasFaltantes = (31 - dia) + diaBuscar;
                break;

                // Febrero
                case 2:
                    diasFaltantes = (28 - dia) + diaBuscar;
                break;

                // Marzo
                case 3:
                    diasFaltantes = (31 - dia) + diaBuscar;
                break;

                // Abril
                case 4:
                    diasFaltantes = (30 - dia) + diaBuscar;
                break;

                // Mayo
                case 5:
                    diasFaltantes = (31 - dia) + diaBuscar;
                break;

                // Junio
                case 6:
                    diasFaltantes = (30 - dia) + diaBuscar;
                break;

                // Julio
                case 7:
                    diasFaltantes = (31 - dia) + diaBuscar;
                break;

                // Agosto
                case 8:
                    diasFaltantes = (31 - dia) + diaBuscar;
                break;

                // Septiembre
                case 9:
                    diasFaltantes = (30 - dia) + diaBuscar;
                break;

                // Octubre
                case 10:
                    diasFaltantes = (31 - dia) + diaBuscar;
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

            mesesFaltantes --;
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

void MostrarContactosOpcion2(int numContactos,tipoContacto contactos[])
{
  for (int i=0 ; i < numContactos ; i++)
  {
    cout << contactos[i].id << "-" << contactos[i].nombre <<endl;
  }
}

void AgregarAnotacion(int numContactos, tipoContacto contactos[])
{
	string nombreContacto;
	int numContacto;
	string nota;
	
	cout << "Nombre del contacto: ";
	cin >> nombreContacto;
	numContacto = BusquedaPorNombre(nombreContacto, numContactos, contactos) - 1;
	
	if (numContacto == 0)
		cout << "El contacto no existe." << endl;
	else
	{
		cout << "Escribe la nota: " << endl;
		cin >> nota;
		
		if (nota == null)
			cout << "No se ha introducido ninguna nota." << endl;
		else
		{
			contactos[numContacto].notas[contactos[numContacto].siguienteNota] = nota;
			contactos[numContacto].siguienteNota += 1;
		}	 
	}
}

int BusquedaPorNombre()
{
	return 0;
}

void VerAnotaciones()
{
}

int main()
{
    // Variables
    int opcion = 0;
    int numContactos = 0;
    int dia;
    int mes;
    bool ok;
    string fechaActual;
    tipoContacto contactos[maxContactos];
    tipoContacto contactosAux[maxContactos];

    cout << "Agenda de Contactos" << endl;
    cout << endl;
    
    // B�cle del programa
    do
    {
        // Men� de opciones
		cout << endl;
        cout << "----- Opciones -----" << endl;
        cout << endl;
        cout << "1.- Agregar nuevo contacto" << endl;
        cout << "2.- Modificar un contacto" << endl;
        cout << "3.- Ver contactos" << endl;
        cout << "4.- Calcular cumplea�os" << endl;
		cout << "5.- Anotaciones" << endl;
        cout << "0.- Salir" << endl;
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
              //if(numContactos < maxContactos)
                InsertarContacto(numContactos, contactos);
                numContactos++;
            break;

            // Modificar un contacto
            case 2:
              if ( numContactos <= 0)
                cout << "No hay datos para modificar "<<endl;
              else
              {
                MostrarContactosOpcion2(numContactos, contactos);
                ModificarContacto(numContactos,contactos);
              }
            break;

            // Ver lista de contactos
            case 3:
                system("cls");
                cout << "1. Ver todos" << endl;
                cout << "2. Ordenar" << endl;
                cout << "3. Salir al men�." << endl;
                cout << "Introduzca una opci�n: ";
                cin >> opcion;
                cout << "--------------------" << endl;
                cout << endl;
				
                switch (opcion)
                {
                    case 1:
                        // Muestro los contactos sin cambiar el orden
                        VerContactosOpcion03(numContactos, contactos);
                        cout << endl;
                    break;
					
                    case 2:
                        cout << "1. Ordenar alfabeticamente." << endl;
                        cout << "2. Ordenar por edad." << endl;
                        cout << "3. Salir al men�." << endl;
                        cout << "Introduzca una opci�n: ";
                        cin >> opcion;
                        cout << "--------------------" << endl;
                        cout << endl;
						
                        switch (opcion)
                        {
                            case 1:
                                OrdenarAlfabeticamente(numContactos, contactos);
                                cout << endl;
                            break;

                            case 2:
                                OrdenarEdad(numContactos, contactos);
                                cout << endl;
                            break;
                        }
                    break;
				}
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
                        if ( fechaActual.length() != 5 )
                            cout << "El formato de fecha no es correcto: DD-MM" << endl;

                        else
                        {
                            if ( fechaActual[2] != '-' )
                            {
                                cout << "El formato de fecha no es correcto: DD-MM" << endl;
                            }

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
												    if ( (dia >= 1) && (dia <= 31 ) )
                                                        ok = true;

                                                    else
                                                        cout << "El dia tiene que estar entre 01 y 31" << endl;
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
                                                    if ( (dia >= 1) && (dia <= 31 ) )
                                                        ok = true;

                                                    else
                                                        cout << "El dia tiene que estar entre 01 y 31" << endl;
                                                break;

                                                // Abril
                                                case 4:
                                                    if ( (dia >= 1) && (dia <= 30 ) )
                                                        ok = true;

                                                    else
                                                        cout << "El dia tiene que estar entre 01 y 30" << endl;
                                                break;

                                                // Mayo
                                                case 5:
                                                    if ( (dia >= 1) && (dia <= 31 ) )
                                                        ok = true;

                                                    else
                                                        cout << "El dia tiene que estar entre 01 y 31" << endl;
                                                break;

                                                // Junio
                                                case 6:
                                                    if ( (dia >= 1) && (dia <= 30 ) )
                                                        ok = true;

                                                    else
                                                        cout << "El dia tiene que estar entre 01 y 30" << endl;
                                                break;

                                                // Julio
                                                case 7:
                                                    if ( (dia >= 1) && (dia <= 31 ) )
                                                        ok = true;

                                                    else
                                                        cout << "El dia tiene que estar entre 01 y 31" << endl;
                                                break;

                                                // Agosto
                                                case 8:
                                                    if ( (dia >= 1) && (dia <= 31 ) )
                                                        ok = true;

                                                    else
                                                        cout << "El dia tiene que estar entre 01 y 31" << endl;
                                                break;

                                                // Septiembre
                                                case 9:
                                                    if ( (dia >= 1) && (dia <= 30 ) )
                                                        ok = true;

                                                    else
                                                        cout << "El dia tiene que estar entre 01 y 30" << endl;
                                                break;

                                                // Octubre
                                                case 10:
                                                    if ( (dia >= 1) && (dia <= 31 ) )
                                                        ok = true;

                                                    else
                                                        cout << "El dia tiene que estar entre 01 y 31" << endl;
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
                }
                while ( ok != true );

                CalcularCumpleanyos( dia, mes, numContactos, contactos );
            break;

			// Anotaciones
			case 5:
				system("cls");
                cout << "1. Agregar anotaci�n" << endl;
                cout << "2. Ver anotaciones por contacto" << endl;
                cout << "3. Salir al men�." << endl;
                cout << "Introduzca una opci�n: ";
                cin >> opcion;
                cout << "--------------------" << endl;
                cout << endl;

				switch (opcion)
				{
					case 1:
						system("cls");
						AgregarAnotacion(numContactos, contactos);
						break;
					case 2:
						system("cls");
						VerAnotaciones();
						break;
				}
				break;

            // Salir
            case 0:
				system("cls");
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
    while ( opcion != 0 );

    return 0;
}
