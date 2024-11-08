#include <iostream>
#include <string>
#include "windows.h"
#include <conio.h>
#include "Funciones.h"
#include "ClassDetalleVenta.h"

using namespace std;


//MENU
void menu(){
int opcion;
while(true){
 LH(); cout<<endl;
 cout<<"  BIENVENIDO AL SISTEMA GESTOR DE LA CONSESIONARIA"<<endl;
 LH();
 cout << R"(
                ______
              //  ||\ \
         ____//___||_\ \___
         )  _          _    \
         |_/ \________/ \___|
        ___\_/________\_/______
    )"; cout<<endl;

LH2();cout<<endl;
cout<<"1-)INICIAR SESION"<<endl;
LH2();cout<<endl;
cout<<"2-)REGISTRARSE"<<endl;
LH2();cout<<endl;
cout<<"3-)RECUPERAR CLAVE"<<endl;
LH2();cout<<endl;
cout<<"4-)SALIR DEL SISTEMA"<<endl;
LH2();cout<<endl;
cout<<"INGRESE LA OPCION QUE DESEE:";
cin>>opcion;
switch(opcion){
case 1:
    system("cls");
    iniciarSesion();
    break;
case 2:
    system("cls");
    registrarse();
    break;
case 3:
    system("cls");
    recuperarClave();
    break;
case 4:
    return;
default:
    cout<<"Opcion invalida...";
}
}
}
//INICIAR SESION
void iniciarSesion(){
FILE *registro;
registro=fopen("registros.dat","rb");
if(registro==NULL){
cout<< "ERROR AL INTENTAR ABRIR EL ARCHIVO DE REGISTROS"<<endl;
return ;
}
Vendedores obj;
char correo[35];
char clave[20];

cout<<"Ingrese su correo:";
cin.ignore();
cin.getline(correo,35,'\n');
cout<<"Ingrese su clave:";
cin.ignore();
cin.getline(clave,20,'\n');


bool inicio=false;

while(fread(&obj, sizeof(Vendedores), 1, registro)!=0){
if(strcmp(obj.getCorreo(),correo)==0){
if(strcmp(obj.getClave(),clave)==0){
cout<<"EL INICIO DE SESION SE REALIZO CORRECTAMENTE"<<endl;
inicio=true;
break;
}
}
}
if(!inicio){
cout<<"UNO DE LOS DATOS INGRESADOS NO ES CORRECTO"<<endl;
system("pause");
system("cls");
}
fclose(registro);
system("pause");
system("cls");
if(inicio){
menuVendedores();
}
}
//REGISTRARSE EN EL SISTEMA
void registrarse(){
FILE *registro;
registro=fopen("C:\\Users\\Lauty\\OneDrive\\Escritorio\\ProyectoGestor\\registros.dat","ab");
if(registro==NULL){
    cout<<"ERROR AL CREAR UN ARCHIVO DE REGISTROS"<<endl;
}
Vendedores obj;
  char nombre[30];
  int dni;
  char correo[35];
  char clave[20];
  int IdVendedor;
cout<<"Ingrese su nombre:";
cin.ignore();
cin.getline(nombre,30,'\n');
obj.setNombre(nombre);
cout<<"Ingrese su dni:";
cin>>dni;
obj.setDni(dni);
cout<<"Ingrese su correo:";
cin.ignore();
cin.getline(correo,35,'\n');
obj.setCorreo(correo);
cout<<"Ingrese su clave:";
cin.ignore();
cin.getline(clave,20,'\n');
obj.setClave(clave);
IdVendedor=nuevoId();
obj.setId(IdVendedor);
fwrite(&obj,sizeof(Vendedores),1,registro);
system("cls");
cout<<"Usuario dado de alta..."<<endl;
cout<<"El numero de id asignado es:"<<IdVendedor<<endl;
system("pause");
system("cls");
fclose(registro);
}

//RECUPERAR CLAVE
void recuperarClave(){
FILE *clave;
clave=fopen("registros.dat","rb+");
if(clave==nullptr){
cout<<"ERROR AL INTENTAR ABRIR EL ARCHIVO DE REGISTROS"<<endl;
return;
}
Vendedores objC;
int dni;
char correo[30];
char nuevaClave[30];
bool encontrado=false;
cout<<"Ingrese los siguientes datos para recuperar su clave: "<<endl;
LH();cout<<endl;
cout<<"D.N.I: ";
cin>>dni;
cout<<"Correo: ";
cin.ignore();
cin.getline(correo,30,'\n');
while(fread(&objC, sizeof(Vendedores),1,clave)!=0){
if(strcmp(objC.getCorreo(),correo)==0 && objC.getDni()==dni){
cout<<"Ingrese su nueva Clave:";
cin.ignore();
cin.getline(nuevaClave,30,'\n');
objC.setClave(nuevaClave);
long pos=ftell(clave)-sizeof(Vendedores);
fseek(clave,pos,SEEK_CUR);
fwrite(&objC, sizeof(Vendedores), 1, clave);
cout << "Su nueva clave fue guardada con exito" << endl;
encontrado=true;
break;

}
}
if(!encontrado){
cout<<"LOS DATOS INGRESADOS NO ESTAN EN LA BASE DE DATOS"<<endl;
}
fclose(clave);
system("pause");
system("cls");
}

//MENU VENDEDORES
void menuVendedores(){
int opcion;
while(true){
cout<<"BIEVENIDO AL SISTEMA DE LA CONSECIONARIA"<<endl;
LH(); cout<<endl;
cout<<"1-)DAR DE ALTA VEHICULO NUEVO"<<endl;
LH(); cout<<endl;
cout<<"2-)REALIZAR VENTA DE VEHICULO"<<endl;
LH(); cout<<endl;
cout<<"3-)DAR DE BAJA VENDEDOR DEL SISTEMA"<<endl;
LH(); cout<<endl;
cout<<"4-)LISTAR VEHICULOS DISPONIBLES"<<endl;
LH(); cout<<endl;
cout<<"5-)LISTAR VENDEDORES"<<endl;
LH(); cout<<endl;
cout<<"6-)MODIFICAR VEHICULOS"<<endl;
LH(); cout<<endl;
cout<<"7-)MODIFICAR VENDEDORES"<<endl;
LH(); cout<<endl;
cout<<"8-)INFORMACION SOBRE CLIENTES"<<endl;
LH(); cout<<endl;
cout<<"9-)INFORMACION SOBRE FACTURAS"<<endl;
LH(); cout<<endl;
cout<<"0-)CERRAR SESION"<<endl;
LH(); cout<<endl;
cout<<"ELIGA LA OPCION QUE DESEE:";
cin>>opcion;

switch(opcion){

case 0:
    system("cls");
    menu();
case 1:
    system("cls");
    Alta obj;
    obj.NuevoAuto();
    break;
case 2:
    system("cls");
    ventaVehiculo();
    break;
case 3:
    system("cls");
    BajaVendedor objB;
    objB.bajaVendedor();
    break;
case 4:
    system("cls");
    AutosList objLista;
    objLista.stockAutos();
    break;
case 5:
    system("cls");
    Lista empleados;
    empleados.ListarEmpleados();
    break;
case 6:
    system("cls");
   AutosList objModificar;
   objModificar.realizarCambiosAutos();
    break;
case 7:
    system("cls");
    Lista objModificarV;
    objModificarV.ModificarEmpleados();
    break;
case 8:
    system("cls");
    informacionClientes();
    break;
case 9:system("cls");
informacionFacturas();
    break;
default:
    cout<<"La opcion elegida no es correcta..."<<endl;
}
}
}

//FUNCION PARA LA VENTA DE VEHICULOS
void ventaVehiculo(){
int opcion;
while(true){
cout<<"BIENVENIDO AL MENU DE VENTAS..."<<endl;
LH(); cout<<endl;
cout<<"1-)Realizar venta a un nuevo cliente"<<endl;
LH(); cout<<endl;
cout<<"2-)Realizar venta a un cliente existente en el sistema"<<endl;
LH(); cout<<endl;
cout<<"3-)Salir"<<endl;
LH(); cout<<endl;
cout<<"Ingrese la opcion que desee:";
cin>>opcion;
switch(opcion){
case 1:{
system("cls");
AltaCliente objC;
objC.registrarCliente();
generarFactura();
break;
}
case 2:{
system("cls");
generarFactura();
}
break;

case 3:{
system("cls");
menuVendedores();
break;
}
}
}
}
//FUNCION PARA CREAR ID UNICOS
int nuevoId(){
int nuevoIdentificador=0;
FILE *nuevo;
nuevo=fopen("registros.dat","rb");
if(nuevo==NULL){
    cout<<"Error al crear nuevo ID";
}
Vendedores obj;
while(fread(&obj,sizeof(Vendedores),1,nuevo)!=0){
    nuevoIdentificador++;
}
fclose(nuevo);
return nuevoIdentificador+1;
}

void LH(){ /// linea horizontal
    int i, tam;
    for (i = 0;i < 52;i++ )
        cout<<char(196);
}
void LH2(){
    int i, tam;
    for (i = 0;i < 61;i++ )
        cout<<char(196);
}
void LV(){ /// linea vertical
    int i, tam;
    for (i = 0;i < 1 ;i++ )
        cout<<char(179)<<endl;
}

void generarFactura(){
AltaCliente objC;
Lista objV;
AutosList objA;
Cabezera objCabezera;
Detalle objD;
int idCliente,idAuto,idVendedor;
cout<<"Ingrese su id de vendedor:";
cin>>idVendedor;
objV.buscarEmpleado(idVendedor);
cout<<"Ingrese el id del cliente que realizara la compra:";
cin>>idCliente;
objC.buscarCliente(idCliente);
cout<<"Ingrese el id del auto a comprar:";
cin>>idAuto;
objA.encontrarAuto(idAuto);
objCabezera.cabezeraDatos(idVendedor,idCliente);
objD.generarDetalle(idAuto);
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"Factura generada...Proceso de venta finalizado..."<<endl;
system("pause");
system("cls");
}


//OPCION 8 (INFORMACION CLIENTES)
void informacionClientes(){
int opcion;
while(true){
cout<<"INFORMACION CLIENTES..."<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"1)Buscar cliente"<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"2)Listar clientes"<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"3)Salir..."<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"Eliga la opcion que desee:";
cin>>opcion;

switch(opcion){
case 1:
system("cls");
AltaCliente obj;
int id;
cout<<"Ingrese el ID del cliente: ";
cin>>id;
obj.buscarCliente(id);
system("cls");
    break;
case 2:
system("cls");
AltaCliente obj1;
obj1.listarClientes();
    break;
case 3:
system("cls");
menuVendedores();
    break;
}
}

}


//OPCION 9 (INFORMACION FACTURAS)
void informacionFacturas(){
int opcion;
while(true){
cout<<"INFORMACION FACTURAS"<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"1)Listar cabezera"<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"2)Buscar facturas"<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"3)Salir..."<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"Ingrese la opcion que desee:";
cin>>opcion;
switch(opcion){

{case 1:
    system("cls");
    cout<<"INFORMACION CABEZERA"<<endl;
   cout<<"----------------------------------------------------------------------------------------"<<endl;
    Cabezera obj;
    obj.listarCabezera();
    break ;}

case 2:
    system("cls");
    cout<<"INFORMACION FACTURA"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    buscarFacturas();
    break;

case 3:
    system("cls");
menuVendedores();
break;
}

}
}


void buscarFacturas(){
int idV;
cout<<"Ingrese el id de la venta:";
cin.ignore();
cin>>idV;
cout<<"----------------------------------------------------------------------------------------"<<endl;

FILE *cabezera1;
cabezera1=fopen("cabezera.dat","rb");
if(cabezera1==NULL){
cout<<"ERROR AL INTENTAR ABRIR EL ARCHIVO"<<endl;
return;
}

Cabezera objC;
objC.buscarCabezera(idV);
fclose(cabezera1);
FILE *detalle2;
detalle2=fopen("detalle.dat","rb");
if(detalle2==NULL){
cout<<"ERROR AL INTENTAR ABRIR UN ARCHIVO"<<endl;
return;
}
Detalle objD;
objD.buscarDetalle(idV);

fclose(detalle2);
system("pause");
system("cls");
return informacionFacturas();
}

