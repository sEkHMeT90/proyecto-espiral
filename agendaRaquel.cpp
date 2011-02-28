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
void InsertarContacto(int numContactos, tipoContacto contactos[])
{
  string auxText;
  bool esCorrecto = false;

  //Asignamos la id
  contactos[numContactos].id = numContactos + 1;

  // Pedimos el nombre
  cout << "Introduzca su nombre: ";
  cin >> contactos[numContactos].nombre;

  // Pedimos el apellido
  cout << "Introduzca su apellido: ";
  cin >> contactos[numContactos].apellido;

  // Pedimos el teléfono mientras tenga más de 15 dígitos
  do
  {
     if (auxText.length() > 15)
      cout << "Número excesivamente largo." << endl;

    cout << "Introduzca su teléfono: ";
    cin >> auxText;
  }
  while(auxText.length() > 15);

  contactos[numContactos].telefono = auxText;

  // Pedimos el e-mail
  cout << "Introduzca su e-mail: ";
  cin >> contactos[numContactos].email;

  // Pedimos el día de cumpleaños y comprobamos el formato y la fecha
  try 
  {

    do
    {
      cout << "Introduzca el día de su cumpleaños (DD-MM): ";
      cin >> auxText;
    
      int mes = atoi(auxText.substr(3).c_str());
      int dia = atoi(auxText.substr(0,2).c_str());

      switch ( mes )
      {
        case 1: //Enero
          if ((dia > 00) && (dia < 31))
          {
            esCorrecto = true;
          }
        break;
        case 2: //Febrero
          if ((dia > 00) && (dia < 29))
          {
            esCorrecto = true;
          }
        break;
        case 3: //Marzo 
          if ((dia > 00) && (dia < 31))
          {
            esCorrecto = true;
          }
        break;
        case 4: //Abril
          if ((dia > 00) && (dia < 30))
          {
            esCorrecto = true;
          }
        break;
        case 5: //Mayo
          if ((dia > 00) && (dia < 31))
          {
            esCorrecto = true;
          }
        break;
        case 6: //Junio 
          if ((dia > 00) && (dia < 30))
          {
            esCorrecto = true;
          }
        break;
        case 7: //Julio 
          if ((dia > 00) && (dia < 31))
          {
            esCorrecto = true;
          }
        break;
        case 8: //Agosto
          if ((dia > 00) && (dia < 31))
          {
            esCorrecto = true;
          }
        break;
        case 9: //Septiembre
          if ((dia > 00) && (dia < 30))
          {
            esCorrecto = true;
          }
        break;
        case 10: //Octubre
          if ((dia > 00) && (dia < 31))
          {
            esCorrecto = true;
          }
        break;
        case 11: //Noviembre
          if ((dia > 00) && (dia < 30))
          {
            esCorrecto = true;
          }
        break;
        case 12: //Diciembre
          if ((dia > 00) && (dia < 31))
          {
            esCorrecto = true;
          }
        break;
      }

      if((auxText.length() != 5) || (auxText[2] != '-') || (auxText.substr(3) < "01") || (auxText.substr(3) > "12") || (esCorrecto != true))
        cout << "Formato incorrecto" << endl;

    }
    while ((auxText.length() != 5) || (auxText[2] != '-') || (auxText.substr(3) < "01") || (auxText.substr(3) > "12") || (esCorrecto != true));
  
    contactos[numContactos].cumpleanyos == auxText;
  }

  catch( exception )
  {
    cout << "Los valores introducidos no son correctos";
  }
  // Pedimos el edad
  cout << "Introduzca su edad: ";
  cin >> contactos[numContactos].edad;
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
void CalcularCumpleanyos()
{
}

int main()
{
    // Variables
    int opcion = 0;
    int numContactos = 0;
    tipoContacto contactos[maxContactos];

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
              //if(numContactos < maxContactos)
                InsertarContacto(numContactos, contactos);
              numContactos++;
            break;

            // Modificar un contacto
            case 2:
            break;

            // Ver lista de contactos
            case 3:
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
