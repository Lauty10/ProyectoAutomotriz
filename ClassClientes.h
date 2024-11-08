#ifndef CLASSCLIENTES_H_INCLUDED
#define CLASSCLIENTES_H_INCLUDED
#include <string.h>
#include <iostream>
#include "windows.h"

using namespace std;

class Clientes {
private:
    int idCliente;
    char nombreCliente[30];
    int dni;
    char correoCliente[35];
    bool rol = false;

public:
    Clientes(int idC = 0, const char* nombreC = "XXX", int dniC = 1000000, const char* correoC = "cliente123@gmail.com", const char* claveC = "12345678", bool rol = false) {
        this->idCliente = idC;
        strcpy(this->nombreCliente, nombreC);
        this->dni = dniC;
        strcpy(this->correoCliente, correoC);
        this->rol = rol;
    }
    void setIdCliente(int idC) { this->idCliente = idC; }
    void setNombreCliente(const char nombreC[30]) { strcpy(this->nombreCliente, nombreC); }
    void setDni(int dniC) { this->dni = dniC; }
    void setCorreoCliente(const char correoC[35]) { strcpy(this->correoCliente, correoC); }
    void setRol(bool rol) { this->rol = rol; }

    int getIdCliente() { return idCliente; }
    const char* getNombreCliente() { return nombreCliente; }
    int getDni() { return dni; }
    const char* getCorreoCliente() { return correoCliente; }
    bool getRolCliente() { return rol; }

    ~Clientes() {}
};


class AltaCliente {
public:
    void registrarCliente() {
        FILE *cliente = fopen("C:\\Users\\Lauty\\OneDrive\\Escritorio\\ProyectoGestor\\cliente.dat", "ab");
        if (cliente == NULL) {
            cout<<"Error al intentar generar un nuevo cliente"<<endl;
            return;
        }

        Clientes obj;
        char nombreC[30];
        int dniC;
        char correoC[35];
        cout<<"INGRESE LOS DATOS DEL CLIENTE A REGISTRAR....."<<endl;
        cout<<"Ingrese el nombre del nuevo cliente: ";
        cin.ignore();
        cin.getline(nombreC, 30, '\n');
        obj.setNombreCliente(nombreC);
        cout<<"Ingrese el dni del nuevo cliente: ";
        cin>>dniC;
        obj.setDni(dniC);
        cout<<"Ingrese el correo del nuevo cliente: ";
        cin.ignore();
        cin.getline(correoC, 35, '\n');
        obj.setCorreoCliente(correoC);
        int idC = nuevoIdCliente();
        obj.setIdCliente(idC);
        obj.setRol(true);
        fwrite(&obj, sizeof(Clientes), 1, cliente);
        cout<<"EL nuevo cliente fue registrado en el sistema"<<endl;
        cout<<"EL ID DEL CLIENTE ES: "<<idC<<endl;
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        system("pause");

        fclose(cliente);
    }

    int nuevoIdCliente() {
        int nuevoIdentificador = 0;
        FILE *nuevo = fopen("cliente.dat", "rb");
        if (nuevo == NULL) {
            cout<<"Error al crear nuevo ID"<<endl;
            return 1;
        }

        Clientes obj;
        while (fread(&obj, sizeof(Clientes), 1, nuevo) != 0) {
            nuevoIdentificador++;
        }
        fclose(nuevo);
        return nuevoIdentificador + 1;
    }

void buscarCliente(int id) {
        FILE *cliente = fopen("cliente.dat", "rb");
        if (cliente == NULL) {
            cout<<"Error al intentar encontrar el cliente."<<endl;
            return;
        }

        Clientes obj;
        bool encuentro = false;
        while(fread(&obj, sizeof(Clientes), 1, cliente) != 0) {
            if(id == obj.getIdCliente()) {
                encuentro = true;
                cout<<"El cliente seleccionado es: "<<obj.getNombreCliente()<<endl;
                cout<<"El DNI del cliente es: "<<obj.getDni()<<endl;
                cout<<"El correo del cliente es: "<<obj.getCorreoCliente()<<endl;
                  cout<<"----------------------------------------------------------------------------------------"<<endl;
                break;
            }
        }
        if (!encuentro) {
            cout<<"No se encontró ningún cliente..."<<endl;
        }

        fclose(cliente);
        system("pause");
    }



void listarClientes(){
FILE *cliente;
cliente=fopen("cliente.dat","rb");
if(cliente==NULL){
cout<<"Error al intentar listar clientes"<<endl;
}
Clientes obj;
while(fread(&obj,sizeof(Clientes),1,cliente)!=0){
cout<<"ID DEL CLIENTE:"<<obj.getIdCliente()<<endl;
cout<<"NOMBRE CLIENTE:"<<obj.getNombreCliente()<<endl;
cout<<"DNI CLIENTE:"<<obj.getDni()<<endl;
cout<<"CORREO CLIENTE:"<<obj.getCorreoCliente()<<endl;
cout<<"-------------------------------------------------------------------"<<endl;
    }
fclose(cliente);
cout<<endl;
cout<<"Estos son todos los clientes..."<<endl;
system("pause");
system("cls");
}


};

#endif // CLASSCLIENTES_H_INCLUDED
