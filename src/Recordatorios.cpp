#include <iostream>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    // Completar declaraciones funciones
    Fecha(int mes, int dia);
    int mes();
    int dia();
    //ej 10
    void incrementar_dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif

  private:
    //Completar miembros internos
    int mes_;
    int dia_;
};

int Fecha::mes() {
    return mes_;
}

int Fecha::dia() {
    return dia_;
}

Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia) {} ;

//8 ostream fecha

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = (this->dia() == o.dia()
            && this-> mes() == o.mes());
    // Completar iguadad (ej 9)
    return igual_dia;
}

// 10
void Fecha::incrementar_dia() {
    if (dia_ < dias_en_mes(mes_)){
        dia_++;
    } else{ // dia_ == dias_en_mes(mes_)
        dia_ = 1;
        if (mes_ == 12){
            mes_ = 1;
        } else{
            mes_++;
        }
    }
}

#endif


// Ejercicio 11, 12

// Clase Horario

class Horario {
    public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator==(Horario o);

    //12
    bool operator<(Horario o);

    private:
    uint hora_;
    uint min_;
};

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min){};

uint Horario::hora() {
    return hora_;
};

uint Horario::min() {
    return min_;
};

//ostream horario << y ==

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
};

bool Horario::operator==(Horario o) {
    bool igual_Hora = (this->hora() == o.hora()
                      && this-> min() == o.min());
    return igual_Hora;
}

bool Horario::operator<(Horario o) {
    bool esMenor;
    if (this->hora() < o.hora()){
        esMenor = true;
    } else{ // >=
        if(this->hora() > o.hora()){
            esMenor = false;
        } else {
            esMenor = this->min() < o.min();
        }
    }
    return esMenor;
};

// Ejercicio 13

// Clase Recordatorio

class Recordatorio{
    public:
    Recordatorio(Fecha f, Horario h, string mensaje);
    Fecha f();
    Horario h();
    string mensaje();

    private:
    Fecha f_;
    Horario h_;
    string mensaje_;
    ;
};

Recordatorio::Recordatorio(Fecha f, Horario h, string mensaje) :
f_(f.mes(), f.dia()), h_(h.hora(), h.min()), mensaje_(mensaje){}

Fecha Recordatorio::f() {
    return f_;
}

Horario Recordatorio::h() {
    return h_;
}

string Recordatorio::mensaje() {
    return mensaje_;
}

// ostream Recordatorio

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje() << " @ " << r.f() << " " << r.h();
    return os;
};

// Ejercicio 14

class Agenda{};

// Clase Agenda

