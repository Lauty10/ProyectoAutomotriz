#ifndef CLASSFECHA_H_INCLUDED
#define CLASSFECHA_H_INCLUDED

class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(int d=0, int m=0, int a=0){
    this->dia=d;
    this->mes=m;
    this->anio=a;
    }
    void agregarFecha(){
    cout<<"Ingrese el dia de la fecha:";
    cin>>dia;
    cout<<"Ingrese el mes de la fecha:";
    cin>>mes;
    cout<<"Ingrese el anio de la fecha:";
    cin>>anio;
    }
    void setDia(int d){
    this->dia=d;
    }
    void setMes(int m){
    this->mes=m;
    }
    void setAnio(int a){
    this->anio=a;
    }

    int getMes(){
     return mes;
    }
    int getAnio(){
    return anio;
    }
    int getDia(){
    return dia;
    }
    void mostrarFecha(){
    cout<<this->dia<<"/"<<this->mes<<"/"<<anio<<endl;
    }
    ~Fecha(){};
};


#endif // CLASSFECHA_H_INCLUDED
