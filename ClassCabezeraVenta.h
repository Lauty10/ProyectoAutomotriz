#ifndef CLASSCABEZERAVENTA_H_INCLUDED
#define CLASSCABEZERAVENTA_H_INCLUDED
#include <iostream>
#include <string.h>
#include "Funciones.h"
#include "ClassVendedores.h"
#include "ClassFecha.h"

using namespace std;

class Cabezera:public Fecha{
private:
    int IdVendedor;
    char nombreVendedor[20];
    int idCliente;
    int dniCliente;
    char nombreCliente[20];
    int numVenta;
    int dia;
    int mes;
    int anio;
public:
    Cabezera(int id=0, const char* nombreV="XXX",int idC=0, int dniC=0, const char* nombreC="XXX", int numV=0,int d=0,int m=0,int a=0):Fecha(d,m,a){
    this->IdVendedor=id;
    strcpy(nombreVendedor,nombreV);
    strcpy(nombreCliente,nombreC);
    this->idCliente=idC;
    this->dniCliente=dniC;
    this->numVenta=numV;
    }

    void setIdVendedor(int id){
    this->IdVendedor=id;
    }
    void setNombreVendedor(char nombreV[20]){
    strcpy(nombreVendedor,nombreV);
    }
    void setIdCliente(int idC){
    this->idCliente=idC;
    }
    void setDniCliente(int dniC){
    this->dniCliente=dniC;
    }
    void setNombreCliente(char nombreC[20]){
    strcpy(nombreCliente,nombreC);
    }
    void setNumVenta(int numV){
    this->numVenta=numV;
    }
    int getIdVendedor(){
    return IdVendedor;
    }
    const char* getNombreVendedor(){
    return nombreVendedor;
    }
    int getIdCliente(){
    return idCliente;
    }
    int getDniCliente(){
    return dniCliente;
    }
    const char* getNombreCliente(){
    return nombreCliente;
    }
    int getNumVenta(){
    return numVenta;
    }

    void cabezeraDatos(int idV, int idC){
    FILE *dato1,*dato2,*datos3;
    dato1=fopen("registros.dat","rb");
    if(dato1==NULL){
        cout<<"Error al abrir archivo de registros"<<endl;
    }
    Vendedores objV;
    char nombreV[20];
    bool encontrado=false;
    while(fread(&objV,sizeof(Vendedores),1,dato1)!=0){
        if(idV==objV.getIdVendedor()){
         encontrado=true;
         strcpy(nombreV,objV.getNombre());
         break;
        }
    }
    if(!encontrado){
        cout<<"No se encontro el vendedor correspondiente"<<endl;
    }

    fclose(dato1);
    dato2=fopen("cliente.dat","rb");
    if(dato2==NULL){
        cout<<"Error al abrir archivo de clientes"<<endl;
    }
    Clientes objC;
    int dniC;
    char nombreC[20];

    bool encontrado2=false;
    while(fread(&objC,sizeof(Clientes),1,dato2)!=0){
        if(idC==objC.getIdCliente()){
            encontrado2=true;
            dniC=objC.getDni();
            strcpy(nombreC,objC.getNombreCliente());
            break;
        }
    }
    if(!encontrado2){
        cout<<"Cliente no encontrado"<<endl;
    }
    fclose(dato2);
    datos3=fopen("C:/Users/Lauty/OneDrive/Escritorio/Proyecto/cabezera.dat","wb");
    if(datos3==NULL){
        cout<<"Error al generar la cabezera..."<<endl;
    }
    int numV=nuevoId();
    Cabezera objCabezera;
    objCabezera.setIdCliente(idC);
    objCabezera.setIdVendedor(idV);
    objCabezera.setNombreCliente(nombreC);
    objCabezera.setNombreVendedor(nombreV);
    objCabezera.setDniCliente(dniC);
    objCabezera.setNumVenta(numV);
    objCabezera.agregarFecha();
    fwrite(&objCabezera,sizeof(Cabezera),1,datos3);
    fclose(datos3);
    cout<<"Cabezera creada con exito...."<<endl;
    }

int nuevoId(){
int nuevoIdentificador=0;
FILE *nuevo;
nuevo=fopen("cabezera.dat","rb");
if(nuevo==NULL){
    cout<<"Error al crear nuevo ID";
}
Cabezera obj;
while(fread(&obj,sizeof(Cabezera),1,nuevo)!=0){
    nuevoIdentificador++;
}
fclose(nuevo);
return nuevoIdentificador+1;
}



void listarCabezera(){
FILE *cabezera;
cabezera=fopen("cabezera.dat","rb");
if(cabezera==NULL){
cout<<"EEROR AL INTENTAR LISTAR CABEZERAS"<<endl;
return;
}
Cabezera objCA;

while(fread(&objCA,sizeof(Cabezera),1,cabezera)!=0){
objCA.mostrarFecha();
cout<<"ID vendedor: "<<objCA.getIdVendedor()<<endl;
cout<<"Nombre vendedor: "<<objCA.getNombreVendedor()<<endl;
cout<<"ID cliente: "<<objCA.getIdCliente()<<endl;
cout<<"Nombre cliente: "<<objCA.getNombreCliente()<<endl;
cout<<"D.N.I cliente: "<<objCA.getDniCliente()<<endl;
cout<<"Numero de venta: "<<objCA.getNumVenta()<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
}

fclose(cabezera);
cout<<endl;
cout<<"Estos son todas las cabezeras..."<<endl;
system("pause");
system("cls");

}


void buscarCabezera(int id){
FILE *cabezera2;
cabezera2=fopen("cabezera.dat", "rb");
if(cabezera2==NULL){
cout<<"NO SE PUDO ABIR ESTE ARCHIVO"<<endl;
return;
}
Cabezera obj;
bool encontrado= false;
while(fread(&obj,sizeof(Cabezera),1,cabezera2)!=0){
if(obj.getNumVenta()==id){
cout<<"ID vendedor: "<<obj.getIdVendedor()<<endl;
cout<<"Nombre vendedor: "<<obj.getNombreVendedor()<<endl;
cout<<"ID cliente: "<<obj.getIdCliente()<<endl;
cout<<"Nombre cliente: "<<obj.getNombreCliente()<<endl;
cout<<"D.N.I cliente: "<<obj.getDniCliente()<<endl;
cout<<"Nº de cabezera: "<<obj.getNumVenta()<<endl;
encontrado=true;
}
}

if(!encontrado){
cout<<"EL ID INGRESADO NO FUE ENCONTRADO"<<endl;
}
fclose(cabezera2);

}
};

#endif // CLASSCABEZERAVENTA_H_INCLUDED
