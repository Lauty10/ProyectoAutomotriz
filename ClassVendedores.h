#ifndef CLASSVENDEDORES_H_INCLUDED
#define CLASSVENDEDORES_H_INCLUDED
#include <string.h>

using namespace std;

class Vendedores{
private:
    int idVendedor;
    char nombre[30];
    int dni;
    char correo[35];
    char clave[20];
    char rol[6];
    bool estado;
public:
    Vendedores(int i=0, const char* n="XXX", int d=1000000,const char * c="usuariox@gmail.com",const char* claveV="123456789",const char* r="seller",bool estado=true){
    this->idVendedor=i;
    strcpy(this->nombre,n);
    this->dni=d;
    strcpy(this->correo,c);
    strcpy(this->clave,claveV);
    strcpy(this->rol,r);
    this->estado=estado;

    }
    void setId(int idV){
    this->idVendedor=idV;
    };
    void setNombre(char nombre[30]){
    strcpy(this->nombre,nombre);
    };
    void setDni(int dni){
    this->dni=dni;
    };
    void setCorreo(char correo[35]){
    strcpy(this->correo,correo);
    };
    void setClave(char clave[20]){
    strcpy(this->clave,clave);
    };
    void setRol(char rol[6]){
    strcpy(this->rol,rol);
    };
    void setEstado(bool est=false){
    this->estado=est;
    };
    int getIdVendedor(){
    return idVendedor;
    }
    const char* getNombre(){
    return nombre;
    }
    int getDni(){
    return dni;
    }
    const char* getCorreo(){
    return correo;
    }
    const char* getClave(){
    return clave;
    }
    const char* getRol(){
    return rol;
    }
    bool getEstado(){
    return estado;
    }
};

class Lista{
public:
    void ListarEmpleados(){
    FILE *empleados;
    empleados=fopen("registros.dat","rb");
    if(empleados==NULL){
        cout<<"Error al intentar listar empleados"<<endl;
    }
    Vendedores obj;
    while(fread(&obj,sizeof(Vendedores),1,empleados)!=0){
     if(obj.getEstado()==true){
        cout<<"EL ID DEL VENDEDOR ES:"<<obj.getIdVendedor()<<endl;
        cout<<"EL NOMBRE DEL VENDEDOR ES:"<<obj.getNombre()<<endl;
        cout<<"EL DNI DEL EMPLEADO ES:"<<obj.getDni()<<endl;
        cout<<"EL CORREO DEL VENDEDOR ES:"<<obj.getCorreo()<<endl;
        cout<<"EL ROL DEL EMPLEADO ES:"<<obj.getRol()<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;
    }
    }
    fclose(empleados);
    cout<<endl;
    cout<<"Estos son todos los vendedores..."<<endl;
    system("pause");
    system("cls");
    }

void buscarEmpleado(int id){
        FILE *vendedor = fopen("registros.dat", "rb");
        if (vendedor== NULL) {
            cout<<"Error al intentar encontrar el vendedor."<<endl;
            return;
        }
        Vendedores obj;
        bool encuentro = false;
        while(fread(&obj, sizeof(Vendedores), 1, vendedor) != 0) {
            if(id == obj.getIdVendedor()) {
                encuentro = true;
                cout<<"El vendedor seleccionado es: "<<obj.getNombre()<<endl;
                cout<<"El DNI del vendedor es: "<<obj.getDni()<<endl;
                cout<<"El correo del vendedor es: "<<obj.getCorreo()<<endl;
                  cout<<"----------------------------------------------------------------------------------------"<<endl;
                break;
            }
        }
        if (!encuentro) {
            cout<<"No se encontró ningún vendedor con ese ID..."<<endl;
        }
        fclose(vendedor);
        system("pause");
    }


    void ModificarEmpleados(){
    FILE *sellers;
    sellers=fopen("registros.dat","rb+");
    if(sellers==NULL){
        cout<<"Error al intentar modificar los vendedores..."<<endl;
    }
    Vendedores obj;
    char nombre[30];
    int dni;
    char correo[35];
    int idBuscado;
    bool estado=false;
    cout<<"INGRESE EL ID DEL VENDEDOR DESEADO:";
    cin>>idBuscado;
    while(fread(&obj,sizeof(Vendedores),1,sellers)!=0){
        if(idBuscado==obj.getIdVendedor()){
            estado=true;
            long busqueda=ftell(sellers)-sizeof(Vendedores);
            cout<<"INGRESE EL NOMBRE DEL VENDEDOR:";
            cin.ignore();
            cin.getline(nombre,30,'\n');
            obj.setNombre(nombre);
            cout<<"INGRESE EL CORREO DEL VENDEDOR:";
            cin.getline(correo,35,'\n');
            obj.setCorreo(correo);
            cout<<"INGRES EL DNI DEL VENDEDOR:";
            cin>>dni;
            obj.setDni(dni);
            fseek(sellers,busqueda,SEEK_SET);
            fwrite(&obj,sizeof(Vendedores),1,sellers);
            cout<<endl;
            cout<<"Vendedor actualizado..."<<endl;
            system("pause");
            break;
        }
    }
    if(!estado){
        cout<<"Id de vendedor no encontrado...";
        system("pause");
    }
    fclose(sellers);
    system("cls");
    }
};


class BajaVendedor{
public:
void bajaVendedor(){
FILE *baja;
baja=fopen("registros.dat","rb+");
if(baja==NULL){
cout<<"SE HA PRODUCIDO UN ERROR"<<endl;
return;
}
Vendedores obj;
int id;
bool encontrado=false;
cout<<"Ingrese el id del vendedor a dar de baja: "<<endl;
cin.ignore();
cin>>id;
while(fread(&obj,sizeof(Vendedores),1,baja)!=0){
if(obj.getIdVendedor()==id&&obj.getEstado()==true){
cout<<"Nombre: "<<obj.getNombre()<<endl;
cout<<"D.N.I: "<<obj.getDni()<<endl;
cout<<"Correo: "<<obj.getCorreo()<<endl;
obj.setEstado(false);
long posicion=ftell(baja)- sizeof(Vendedores);
fseek(baja, posicion, SEEK_SET);
fwrite(&obj, sizeof(Vendedores), 1, baja);
cout<<"EL USUARIO FUE DADO DE BAJA CORRECTAMENTE"<<endl;
encontrado=true;
system("pause");
break;
}
}

if(!encontrado){
cout<<"EL ID INGRESADO NO FUE ENCONTRADO"<<endl;
system("pause");
}
fclose(baja);
system("cls");
}
};
#endif // CLASSVENDEDORES_H_INCLUDED
