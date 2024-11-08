#ifndef CLASSDETALLEVENTA_H_INCLUDED
#define CLASSDETALLEVENTA_H_INCLUDED
#include "Funciones.h"
#include "ClassAuto.h"

class Detalle{
private:
    int idVenta;
    int idAuto;
    float importeVenta;
    char modeloAuto[20];
    char marcaAuto[20];
    char nombreAuto[20];
public:
    Detalle(int id=0,int idA=0, float importeV=0, const char* modeloA="XXX", const char* marcaA="XXX", const char* nombreA="XXX"){
    this->idVenta=id;
    this->idAuto=idA;
    this->importeVenta=importeV;
    strcpy(modeloAuto,modeloA);
    strcpy(marcaAuto,marcaA);
    strcpy(nombreAuto,nombreA);
    }
    void setIdVenta(int id){
    this->idVenta=id;
    }
    void setIdAuto(int idA){
    this->idAuto=idA;
    }
    void setImporteVenta(float importeV){
    this->importeVenta=importeV;
    }
    void setModeloAuto(char modeloA[20]){
    strcpy(modeloAuto,modeloA);
    }
    void setMarcaAuto(char marcaA[20]){
    strcpy(marcaAuto,marcaA);
    }
    void setNombreAuto(char nombreA[20]){
    strcpy(nombreAuto,nombreA);
    }
    int getId(){
    return idVenta;
    }
    int getIdAuto(){
    return idAuto;
    }
    float getImporteVenta(){
    return importeVenta;
    }
    const char* getModeloAuto(){
    return modeloAuto;
    }
    const char* getMarcaAuto(){
    return marcaAuto;
    }
    const char* getNombreAuto(){
    return nombreAuto;
    }

    void generarDetalle(int idAuto){
    FILE *detalle1,*detalle2;
    detalle1=fopen("vehiculos.dat","rb");
    if(detalle1==NULL){
        cout<<"Error al abrir el detalle de vehiculos"<<endl;
    }
    Auto objA;
    float importeV;
    char modeloA[20];
    char marcaA[20];
    char nombreA[20];
    bool encontrado=false;
    while(fread(&objA,sizeof(Auto),1,detalle1)!=0){
        if(idAuto==objA.getId()){
            encontrado=true;
            importeV=objA.getPrecioAuto();
            strcpy(modeloA,objA.getModeloAuto());
            strcpy(marcaA,objA.getMarcaAuto());
            strcpy(nombreA,objA.getNombreAuto());
            break;
        }
    }
    if(!encontrado){
        cout<<"No se pudo encontrar el auto solicitado..."<<endl;
    }
    fclose(detalle1);
    detalle2=fopen("C:/Users/Lauty/OneDrive/Escritorio/Proyecto/detalle.dat","wb");
    if(detalle2==NULL){
        cout<<"Error al generar el detalle..."<<endl;
    }
    Detalle objD;
    int idDetalle=nuevoIdDetalle();
    objD.setIdVenta(idDetalle);
    objD.setIdAuto(idAuto);
    objD.setImporteVenta(importeV);
    objD.setMarcaAuto(marcaA);
    objD.setModeloAuto(modeloA);
    objD.setNombreAuto(nombreA);
    fwrite(&objD,sizeof(Detalle),1,detalle2);
    fclose(detalle2);
    cout<<"Detalle generado con exito..."<<endl;
    }

int nuevoIdDetalle(){
int nuevoIdentificador=0;
FILE *nuevo;
nuevo=fopen("detalle.dat","rb");
if(nuevo==NULL){
    cout<<"Error al crear nuevo ID";
}
Detalle obj;
while(fread(&obj,sizeof(Detalle),1,nuevo)!=0){
    nuevoIdentificador++;
}
fclose(nuevo);
return nuevoIdentificador+1;
}



void buscarDetalle(int id){
FILE *detalle1;
detalle1=fopen("detalle.dat", "rb");
if(detalle1==NULL){
cout<<"NO SE PUDO ABIR ESTE ARCHIVO"<<endl;
return;
}
Detalle obj;
bool encontrado= false;
while(fread(&obj,sizeof(Detalle),1,detalle1)!=0){
if(obj.getId()==id){
cout<<"Nº de factura: "<<obj.getId()<<endl;
cout<<"ID auto: "<<obj.getIdAuto()<<endl;
cout<<"Marca auto: "<<obj.getMarcaAuto()<<endl;
cout<<"Modelo auto: "<<obj.getModeloAuto()<<endl;
cout<<"Nombre auto: "<<obj.getNombreAuto()<<endl;
cout<<"Precio auto: "<<obj.getImporteVenta()<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
encontrado=true;
}
}

if(!encontrado){
cout<<"EL ID INGRESADO NO FUE ENCONTRADO"<<endl;
}
fclose(detalle1);
system("pause");
system("cls");
}

};


#endif // CLASSDETALLEVENTA_H_INCLUDED
