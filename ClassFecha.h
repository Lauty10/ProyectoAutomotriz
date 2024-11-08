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
    void setDia(int d){
    this->dia=d;
    }
    void setMes(int m){
    this->mes=m;
    }
    void setAnio(int a){
    this->anio=a;
    }
    int getDia(){
    return dia;
    }
    int getMes(){
    return mes;
    }
    int getAnio(){
    return anio;
    }
    void mostrarFecha();
    ~Fecha(){};
};


#endif // CLASSFECHA_H_INCLUDED
