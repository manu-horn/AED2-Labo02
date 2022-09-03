#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int _alto;
        int _ancho;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : _alto(alto), _ancho(ancho) {};

uint Rectangulo::alto() {
    // Completar
    return _alto;
}

// Completar definición: ancho
uint Rectangulo::ancho() {
    // Completar
    return _ancho;
}

// Completar definición: area
float Rectangulo::area() {
    // Completar
    return (_alto * _ancho);
}
// Ejercicio 2

// Clase Elipse

class Elipse {
    public:
    Elipse(uint a, uint b);
    uint r_a();
    uint r_b();
    float area();

    private:
    float PI = 3.14;
    int r_a_;
    int r_b_;
};

Elipse::Elipse(uint a, uint b) : r_a_(a), r_b_(b) {}

uint Elipse::r_b() {
    return r_b_;
}

uint Elipse::r_a() {
    return r_a_;
}

float Elipse::area() {
    return (Elipse::PI * r_a_ * r_b_);
}

// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo _r;
};

Cuadrado::Cuadrado(uint lado): _r(lado, lado) {}

uint Cuadrado::lado() {
    // Completar
    return _r.alto();
}

float Cuadrado::area() {
    // Completar
    return _r.area();
}

// Ejercicio 4

// Clase Circulo

class Circulo{
    public:
    Circulo(uint radio);
    uint radio();
    float area();
    ;
    private: // uso clase Elipse
    Elipse e_;
    ;
};

Circulo::Circulo(uint radio) :  e_(radio, radio) {};

uint Circulo::radio() {
    return e_.r_a();
}

float Circulo::area() {
    return e_.area();
};



// Ejercicio 5: Imprimir en pantalla

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

// ostream Elipse

ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}

// Ejercicio 6

// circulo

ostream& operator<<(ostream& os, Circulo c) {
    os << "Circ(" << c.radio() << ")";
    return os;
}

// cuadrado

ostream& operator<<(ostream& os, Cuadrado c) {
    os << "Cuad(" << c.lado() << ")";
    return os;
}