#ifndef CLASSAUTO_H_INCLUDED
#define CLASSAUTO_H_INCLUDED
#include <string.h>
#include "ClassClientes.h"
#include"ClassCabezeraVenta.h"

using namespace std;

class Auto{
private:
    int idDelAuto;
    char nombreAuto[20];
    char modeloAuto[20];
    char marcaAuto[20];
    int anioAuto;
    float precioAuto;
public:
    Auto(int id=0, const char* nombreA="XXX", const char* modeloA="XXX", const char* marcaA="XXX", int anioA=0, float precioA=0.0){
    this->idDelAuto=id;
    strcpy(this->nombreAuto,nombreA);
    strcpy(this->modeloAuto,modeloA);
    strcpy(this->marcaAuto,marcaA);
    this->anioAuto=anioA;
    this->precioAuto=precioA;
    }
    void setIdAuto(int id){
    this->idDelAuto=id;
    }
    void setNombreAuto(char nombreA[20]){
    strcpy(this->nombreAuto,nombreA);
    }
    void setModeloAuto(char modeloA[20]){
    strcpy(this->modeloAuto,modeloA);
    }
    void setMarcaAuto(char marcaA[20]){
    strcpy(this->marcaAuto,marcaA);
    }
    void setAnio(int anioA){
    this->anioAuto=anioA;
    }
    void setPrecioAuto(float precioA){
    this->precioAuto=precioA;
    }
    int getId(){
    return idDelAuto;
    }
    const char* getNombreAuto(){
    return nombreAuto;
    }
    const char* getModeloAuto(){
    return modeloAuto;
    }
    const char* getMarcaAuto(){
    return marcaAuto;
    }
    int getAnioAuto(){
    return anioAuto;
    }
    float getPrecioAuto(){
    return precioAuto;
    }
};

class Alta{
public:
 void NuevoAuto(){
 FILE *vehiculo;
 vehiculo = fopen("C:/Users/Lauty/OneDrive/Escritorio/Proyecto/vehiculos.dat", "ab");
 if(vehiculo==NULL){
    cout<<"Error al intentar cargar vehiculo"<<endl;
 }
  Auto nuevoVehiculo;
  int idUnico;
  char nombreAuto[20];
  char modeloAuto[20];
  char marcaAuto[20];
  int anioAuto;
  float precioAuto;
  idUnico=generadorId();
  nuevoVehiculo.setIdAuto(idUnico);
  cout<<"Ingrese el nombre del auto:";
  cin.ignore();
  cin.getline(nombreAuto,20,'\n');
  nuevoVehiculo.setNombreAuto(nombreAuto);
  cout<<"Ingrese el modelo del auto:";
  cin.getline(modeloAuto,20,'\n');
  nuevoVehiculo.setModeloAuto(modeloAuto);
  cout<<"Ingrese la marca del auto:";
  cin.getline(marcaAuto,20,'\n');
  nuevoVehiculo.setMarcaAuto(marcaAuto);
  cout<<"Ingrese el anio de fabricacion del auto:";
  cin>>anioAuto;
  nuevoVehiculo.setAnio(anioAuto);
  cout<<"Ingrese el precio del auto:";
  cin>>precioAuto;
  nuevoVehiculo.setPrecioAuto(precioAuto);
  fwrite(&nuevoVehiculo,sizeof(Auto),1,vehiculo);
  cout<<"Vehiculo cargado en el sistema"<<endl;
  system("pause");
  system("cls");
  fclose(vehiculo);
 }

 int generadorId(){
 int nuevoDato=0;
 FILE *dato;
 dato=fopen("vehiculos.dat","rb");
 if(dato==NULL){
    cout<<"Error al generar nuevo id";
 }
 Auto objId;
 while(fread(&objId,sizeof(Auto),1,dato)!=0){
    nuevoDato++;
 }
 fclose(dato);
 return nuevoDato+1;
 }

};

class AutosList{
public:
    void stockAutos(){
    FILE *listaA;
    listaA=fopen("vehiculos.dat","rb");
    if(listaA==NULL){
        cout<<"Error al intentar listar los vehiculos";
    }
    Auto obj;
    while(fread(&obj,sizeof(Auto),1,listaA)!=0){
        cout<<"EL ID DEL AUTO ES:"<<obj.getId()<<endl;
        cout<<"EL NOMBRE DEL AUTO ES:"<<obj.getNombreAuto()<<endl;
        cout<<"LA MARCA DEL AUTO ES:"<<obj.getMarcaAuto()<<endl;
        cout<<"EL MODELO DEL AUTO ES:"<<obj.getModeloAuto()<<endl;
        cout<<"EL ANIO DE FABRICACION ES:"<<obj.getAnioAuto()<<endl;
        cout<<"EL PRECIO DEL AUTO ES:"<<obj.getPrecioAuto()<<endl;
       cout<<"----------------------------------------------------------------------------------------"<<endl;
    }
    fclose(listaA);
    cout<<"Estos son los autos disponibles actualmente"<<endl;
    system("pause");
    system("cls");
    }

    void realizarCambiosAutos(){
    FILE *cambios;
    cambios=fopen("vehiculos.dat","rb+");
    if(cambios==NULL){
        cout<<"Error al intentar realizar cambios...";
    }
    Auto obj;
    int autoBuscado;
    char nombreAuto[20];
    char modeloAuto[20];
    char marcaAuto[20];
    int anioAuto;
    float precioAuto;
    bool encontrado=false;
    cout<<"Ingrese el ID del auto buscado:";
    cin>>autoBuscado;
    while(fread(&obj,sizeof(Auto),1,cambios)!=0){
        if(autoBuscado==obj.getId()){
        encontrado=true;
        long posicion=ftell(cambios)-sizeof(Auto);
        cout<<"Ingrese los nuevos datos del vehiculo....."<<endl;
        cout<<"Ingrese el nombre del vehiculo:";
        cin.ignore();
        cin.getline(nombreAuto,20,'\n');
        obj.setNombreAuto(nombreAuto);
        cout<<"Ingrese el modelo del auto:";
        cin.getline(modeloAuto,20,'\n');
        obj.setModeloAuto(modeloAuto);
        cout<<"Ingrese la marca del auto:";
        cin.getline(marcaAuto,20,'\n');
        obj.setMarcaAuto(marcaAuto);
        cout<<"Ingrese el anio de fabricacion del auto:";
        cin>>anioAuto;
        obj.setAnio(anioAuto);
        cout<<"Ingrese el precio del auto:";
        cin>>precioAuto;
        obj.setPrecioAuto(precioAuto);
        fseek(cambios,posicion,SEEK_SET);
        fwrite(&obj,sizeof(Auto),1,cambios);
        cout<<endl;
        cout<<"Vehiculo actualizado..."<<endl;
        system("pause");
        break;
        }
    }
    if(!encontrado){
    system("cls");
    cout<<"Vehiculo no encontrado...."<<endl;
    system("pause");
    }
    fclose(cambios);
    system("cls");
    }

void encontrarAuto(int id){
        FILE *nave;
nave=fopen("vehiculos.dat","rb");
if(nave==NULL){
    cout<<"Error al encontrar el auto";
}
Auto obj;
bool encuentro=false;
while(fread(&obj,sizeof(Auto),1,nave)!=0){
    if(id==obj.getId()){
        encuentro=true;
        cout<<"El auto seleccionado es:"<<obj.getNombreAuto()<<endl;
        cout<<"La marca del auto es:"<<obj.getMarcaAuto()<<endl;
        cout<<"El modelo del auto es:"<<obj.getModeloAuto()<<endl;
        cout<<"El anio del auto es:"<<obj.getAnioAuto()<<endl;
        cout<<"El precio del auto es:"<<obj.getPrecioAuto()<<endl;
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        break;
    }
}
if(!encuentro){
    cout<<"No se encontro ningun auto..."<<endl;
}
fclose(nave);
system("pause");
    }
};


#endif // CLASSAUTO_H_INCLUDED
