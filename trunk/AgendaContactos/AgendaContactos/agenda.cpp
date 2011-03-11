/*
  - Ethan Martínez Carratalá
  - Aitor Salgado Molina
  - Andrés Marotta
  - Raquel Lloréns Gambín
*/

#include <iostream>
#include <string>
#include <fstream>
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
  string notas[50];
  int siguienteNota;
};

// Función para agregar un contacto
void InsertarContacto(int numContactos, tipoContacto contactos[])
{
  string auxText;
  int dia;
  int mes;
  bool ok = false;
  bool emailValidado = false;

  //Asignamos la id
  contactos[numContactos].id = numContactos + 1;
  cin.ignore();

  // Pedimos el nombre
  cout << "Introduzca su nombre: ";
  getline(cin,auxText);

  while(auxText == ""){

	      cout << "No puede dejar el campo vacio" << endl;
        cout << "Introduzca su nombre: ";
        getline(cin,auxText);
  }

  contactos[numContactos].nombre = auxText;

  // Pedimos el apellido
  cout << "Introduzca su apellido: ";
  getline(cin,contactos[numContactos].apellido);
  // Pedimos el teléfono mientras tenga más de 15 dígitos
  

  cout << "Introduzca su teléfono: ";
  getline(cin,auxText);

  while((auxText.length() > 15) || (auxText == ""))
  {
     if (auxText.length() > 15)
      cout << "Número excesivamente largo." << endl;
	 if (auxText == "")
	  cout << "No puede dejar el campo vacio" << endl;

    cout << "Introduzca su teléfono: ";
    getline(cin,auxText);
  }

  contactos[numContactos].telefono = auxText;

  // Pedimos el e-mail
  do {
      cout << "Introduzca su e-mail: ";
      getline(cin,auxText);

      while(auxText == ""){

	      cout << "No puede dejar el campo vacio" << endl;
        cout << "Introduzca su e-mail: ";
        getline(cin,auxText);
      }

      // Comprobamos que el e-mail sea válido
      if (( auxText.find('.',0) != string::npos ) && ( auxText.find('@',0) != string::npos ) // Si tiene mínimo un punto y un arroba
         && (auxText.find_first_of('@') == auxText.find_last_of('@')) // Si solo contiene un @
         && (auxText.find_last_of('.') > auxText.find_first_of('@')) // Si el último punto está detras del @
         && (auxText.find_last_of('.') < auxText.length()-1)) // Si el último punto no es el último carácter
            emailValidado = true; // Suponemos que el e-mail es correcto
      else
          cout << "El e-mail introducido no tiene un formato válido" << endl;
  }
  while( !emailValidado );

  contactos[numContactos].email = auxText;

  // Pedimos el día de cumpleaños y comprobamos el formato y la fecha
  try 
  {
        do
        {
            cout << "Introduzca el día de su cumpleaños (DD-MM): ";
            getline(cin,auxText);

            if ( auxText == "" )
                cout << "La fecha no puede estar vacía" << endl;

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

                            // Comprobación de mes
                            if ( mes < 1 )
                                cout << "El mes no puede ser inferior a 01 (Enero)" << endl;

                            else
                            {
                                if ( mes > 12 )
                                    cout << "El mes no puede ser superior a 12 (Diciembre)" << endl;

                                else
                                {
                                    dia = atoi(auxText.substr(0,2).c_str());

                                    // Comprobación de día, por mes
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
  getline(cin,auxText);

  contactos[numContactos].edad = atoi(auxText.c_str());

  // Daremos la edad como no válida si no está comprendida entre 0 y 130 años.
  while ((contactos[numContactos].edad < 0) || (contactos[numContactos].edad > 130) )
  {
      cout << "Edad introducida no válida" << endl;
      cout << "Introduzca su edad: ";
      getline(cin,auxText);

      contactos[numContactos].edad = atoi(auxText.c_str());
  }
  contactos[numContactos].siguienteNota = 0;
}

// Función para modificar un contacto
void ModificarContacto(int numContactos, tipoContacto contactos[])
{
  int contactoModificar = 0;//Variale para seleccionar que contacto modificar
  string nombreAuxiliar;
  int edadAuxiliar;
  bool emailValidado = false;
  
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
  do
  {
      cout << "Dime el nuevo email (Pulsa intro si on quieres introducir nada)" <<endl;
      getline(cin,nombreAuxiliar);

      if (( nombreAuxiliar.find('.',0) != string::npos ) && ( nombreAuxiliar.find('@',0) != string::npos ) // Si tiene mínimo un punto y un arroba
         && (nombreAuxiliar.find_first_of('@') == nombreAuxiliar.find_last_of('@')) // Si solo contiene un @
         && (nombreAuxiliar.find_last_of('.') > nombreAuxiliar.find_first_of('@')) // Si el último punto está detras del @
         && (nombreAuxiliar.find_last_of('.') < nombreAuxiliar.length()-1)) // Si el último punto no es el último carácter
            emailValidado = true; // Suponemos que el e-mail es correcto
      else
            cout << "El e-mail introducido no tiene un formato válido" << endl;
  }
  while( !emailValidado );

  contactos[contactoModificar].email = nombreAuxiliar;

  cout << "Este es el antiguo cumpleaños: " << contactos[contactoModificar].cumpleanyos <<endl;
  cout << "Dime el nuevo cumpleaños (Pulsa intro si on quieres introducir nada)" <<endl;
  getline(cin,nombreAuxiliar);
  if ( nombreAuxiliar != "")
    contactos[contactoModificar].cumpleanyos = nombreAuxiliar;
  
  cout << "Este es el antiguo edad: " << contactos[contactoModificar].edad <<endl;
  cout << "Dime el nuevo edad (Pulsa intro si on quieres introducir nada)" <<endl;
  getline(cin,nombreAuxiliar);
  if ( nombreAuxiliar != "")
  {
    edadAuxiliar = atoi(nombreAuxiliar.c_str());
    contactos[contactoModificar].edad = edadAuxiliar;
  }

  cout << "Los datos han quedado así:" << endl;
  cout << contactos[contactoModificar].id << endl;
  cout << contactos[contactoModificar].nombre << endl;
  cout << contactos[contactoModificar].apellido << endl;
  cout << contactos[contactoModificar].telefono << endl;
  cout << contactos[contactoModificar].email << endl;
  cout << contactos[contactoModificar].cumpleanyos << endl;
  cout << contactos[contactoModificar].edad << endl;
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
		cout << "Teléfono: " << contactosAux[i].telefono << endl;
		cout << "Correo: " << contactosAux[i].email << endl;
		cout << "Fecha de cumpleaños: " << contactosAux[i].cumpleanyos
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
				cout << "Pulse una tecla para volver al menú..." << endl;
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
		cout << "Teléfono: " << contactosAux[i].telefono << endl;
		cout << "Correo: " << contactosAux[i].email << endl;
		cout << "Fecha de cumpleaños: " << contactosAux[i].cumpleanyos
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
				cout << "Pulse una tecla para volver al menú..." << endl;
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

// Función para calcular los días faltantes hasta el cumpleaños de un contacto
void CalcularCumpleanyos( int dia, int mes, int numContactos, tipoContacto contactos[] )
{
    int id;
    int diaBuscar;
    int mesBuscar;
    int diasFaltantes;
    int mesesFaltantes;

    VerContactosOpcion03( numContactos, contactos );

	cout << endl;
    cout << "Introduzca el ID del usuario para calcular fecha" << endl;
    cin >> id;
	cout << endl;

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

			if ( mesesFaltantes == -1 )
				mesesFaltantes += 12;
		}
	}

	// Muestro los días y los meses que faltan
	if ( (diasFaltantes == 0) && (mesesFaltantes == 0) )
		cout << "El cumpleaños es hoy" << endl;

	else
	{
		if ( (diasFaltantes > 0) && (mesesFaltantes == 0) )
		{
			if ( diasFaltantes == 1 )
				cout << "Falta " << diasFaltantes << " día" << endl;
			
			else
				cout << "Faltan " << diasFaltantes << " días" << endl;
		}

		else
		{
			if ( (diasFaltantes == 0) && (mesesFaltantes > 0) )
			{
				if ( mesesFaltantes == 1 )
					cout << "Falta " << mesesFaltantes << " mes" << endl;

				else
					cout << "Faltan " << mesesFaltantes << " meses" << endl;
			}

			else
			{
				cout << "Faltan " << diasFaltantes << " días";
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

int BusquedaPorNombre(string nombreBuscar,int numContactos,tipoContacto contactos[])
{
    bool encontrado = false;
    int id;

    for ( int i = 0 ; i < numContactos ; i ++ )
    {
		if ( contactos[i].nombre.find(nombreBuscar,0) != string::npos )
        {
            encontrado = true;
            cout << contactos[i].id << ".- " << contactos[i].nombre << " " << contactos[i].apellido << endl;
        }
    }

    if ( encontrado == true )
    {
        cout << "Introduzca el ID del contacto deseado" << endl;
        cin >> id;

        return id;
    }

    else
    {
        return 0;
    }
}

void AgregarAnotacion(int numContactos, tipoContacto contactos[])
{
	string nombreContacto;
	string nota;
    int numContacto;
    int numNotas;
	
	cout << "Nombre del contacto: ";
	cin >> nombreContacto;
	numContacto = BusquedaPorNombre(nombreContacto, numContactos, contactos);
	
	if (numContacto == 0)
		cout << "El contacto no existe." << endl;
	else
	{
        numNotas = contactos[numContacto-1].siguienteNota;
		
        cout << "Escribe la nota: " << endl;
		cin >> nota;
		
		if (nota == "")
			cout << "No se ha introducido ninguna nota." << endl;
		else
		{
			contactos[numContacto-1].notas[numNotas] = nota;
			contactos[numContacto-1].siguienteNota += 1;
		}	 
	}
}

void VerAnotaciones(int numContactos, tipoContacto contactos[])
{
    string nombreContacto;
    string nota;
    string letra;
	int numContacto;
    int numNotas;
    int j = 0;

    cout << "Nombre del contacto: ";
	cin >> nombreContacto;
	numContacto = BusquedaPorNombre(nombreContacto, numContactos, contactos);

    if (numContacto == 0)
		cout << "El contacto no existe." << endl;

	else
	{
        numNotas = contactos[numContacto-1].siguienteNota;
        if ( numNotas <= 0 )
            cout << "El contacto no tiene notas" << endl;

        else
        {
            cout << "Hay " << numNotas << " notas" << endl;
            cout << endl;

            for ( int i = 0; i < numNotas ; i ++ )
            {
                if ( j == 4 )
                {
                    cout << "Pulse una tecla para continuar..." << endl;
                    getline(cin,letra);
                    system("cls");
                    j = 0;
                }

                nota = contactos[numContacto-1].notas[i];
                cout << i + 1 << ".- " << nota << endl;
                j ++;
            }
        }
	}
}

void SobrecargarContactos(tipoContacto contactos[],int &numContactos)
{
  //---------------FICHERO----------------------------//
    //Sobrecargo los contactos desde fichero
    ifstream fichero_lectura;
    string linea;
    fichero_lectura.open("sobrecargar.txt");
    if (fichero_lectura.is_open())
    {
      cout << "Precaución: Se han sobrecargado contactos desde Fichero" << endl;
      while (!fichero_lectura.eof())
      {
        if (!fichero_lectura.eof()|| linea.length()!=0)
        {
          getline(fichero_lectura,linea);
          contactos[numContactos].id = numContactos+1;
          getline(fichero_lectura,contactos[numContactos].nombre);
          getline(fichero_lectura,contactos[numContactos].apellido);
          getline(fichero_lectura,contactos[numContactos].telefono);
          getline(fichero_lectura,contactos[numContactos].email);
          getline(fichero_lectura,contactos[numContactos].cumpleanyos);
          getline(fichero_lectura,linea);
          contactos[numContactos].edad = atoi(linea.c_str());
          contactos[numContactos].siguienteNota = 0;
          numContactos++;
        }
      }
    }
    else
    {
      cout << "No se han podido sobrecargar contactos desde fichero" << endl;
    }
    //---------------FICHERO----------------------------//
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

    SobrecargarContactos(contactos,numContactos);
    cout << endl;

    // Búcle del programa
    do
    {
        // Menú de opciones
		cout << endl;
        cout << "----- Opciones -----" << endl;
        cout << endl;
        cout << "1.- Agregar nuevo contacto" << endl;
        cout << "2.- Modificar un contacto" << endl;
        cout << "3.- Ver contactos" << endl;
        cout << "4.- Calcular cumpleaños" << endl;
		cout << "5.- Anotaciones" << endl;
        cout << "0.- Salir" << endl;
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
                cout << "3. Salir al menú." << endl;
                cout << "Introduzca una opción: ";
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
                        cout << "3. Salir al menú." << endl;
                        cout << "Introduzca una opción: ";
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

            // Calcular cumpleaños
            case 4:
                system("cls");

				if ( numContactos <= 0)
					cout << "No hay datos."<<endl;
				
				else
				{
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
				}
            break;

			// Anotaciones
			case 5:
				system("cls");
                cout << "1. Agregar anotación" << endl;
                cout << "2. Ver anotaciones por contacto" << endl;
                cout << "3. Salir al menú." << endl;
                cout << "Introduzca una opción: ";
                cin >> opcion;
                cout << "--------------------" << endl;
                cout << endl;

				switch (opcion)
				{
					case 1:
						system("cls");
						AgregarAnotacion(numContactos, contactos);
						break;
					break;
					
                    case 2:
						system("cls");
						VerAnotaciones(numContactos, contactos);
					break;
				}
				break;

            // Salir
            case 0:
				system("cls");
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
    while ( opcion != 0 );

    return 0;
}