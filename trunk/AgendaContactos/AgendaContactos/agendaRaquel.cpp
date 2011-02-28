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
};

// Funci�n para agregar un contacto
void InsertarContacto(int numContactos, tipoContacto contactos[])
{
  string auxText;

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
  do
  {
    if (auxText[2] != '-')
      cout << "Formato incorrecto. Por favor introduzca DD-MM" << endl;

    cout << "Introduzca el d�a de su cumplea�os (DD-MM): ";
    cin >> auxText;

    
    //contactos[numContactos].cumpleanyos

  }
  while( auxText[2] != '-');

  // Pedimos el edad
  cout << "Introduzca su edad: ";
  cin >> contactos[numContactos].edad;
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
  if ( nombreAuxiliar != "");
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
  
  /*cout << "Este es el antiguo edad: " << contactos[contactoModificar].cumpleanyos <<endl;
  cout << "Dime el nuevo edad (Pulsa intro si on quieres introducir nada)" <<endl;
  getline(cin,nombreAuxiliar);
  if ( edadAuxiliar != "")
  {
    edadAuxiliar = atoi(nombreAuxiliar.c_str());
    contactos[contactoModificar].edad = nombreAuxiliar;
  }
  */
  cout << "Los datos han quedado as�:" << contactos[contactoModificar].id << "-" << contactos[contactoModificar].nombre << "-" << contactos[contactoModificar].apellido << "-" << contactos[contactoModificar].telefono << "-" << contactos[contactoModificar].email << "-" << contactos[contactoModificar].cumpleanyos << "-" << contactos[contactoModificar].cumpleanyos << "-" << contactos[contactoModificar].edad << endl;
}


// Funci�n para ver la lista de contactos
void VerContactos()
{
}

// Funci�n para calcular los d�as faltantes hasta el cumplea�os de un contacto
void CalcularCumpleanyos()
{
}

void MostrarContactosOpcion2(int numContactos,tipoContacto contactos[])
{
  for (int i=0 ; i < numContactos ; i++)
  {
    cout << contactos[i].id + 1<< "-" << contactos[i].nombre <<endl;
  }
}

int main()
{
    // Variables
    int opcion = 0;
    int numContactos = 0;
    tipoContacto contactos[maxContactos];

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
                //MostrarContactosOpcion2(numContactos, contactos);
                ModificarContacto(numContactos,contactos);
              }
            break;

            // Ver lista de contactos
            case 3:
            break;

            // Calcular cumplea�os
            case 4:
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
