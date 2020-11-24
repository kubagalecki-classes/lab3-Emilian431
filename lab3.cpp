#include <iostream>
const double pi = 3.141592;

class BytGeometryczny
{
public:
    BytGeometryczny() { std ::cout << "Byt Geometryczny stworzony" << std ::endl; };
    virtual void id() { std ::cout << "Funkcja id w klasie bytgeometryczny" << std ::endl; }
    virtual ~BytGeometryczny() { std ::cout << "Byt Geometryczny usuniety" << std ::endl; };
};

class Figura : public BytGeometryczny
{
public:
    double Pole;
    double getPole() const { return Pole; }
    Figura() { Pole = 0; }
    Figura(double x) : Pole{x} {}
    void virtual id()
    {
        std ::cout << "To jest figura" << std::endl;
    } // nic sie nie dzieje po wykomentowaniu
    virtual ~Figura() { std::cout << "Destruktor figury" << std::endl; }

private:
};

class Kolo : public Figura
{
public:
    Kolo(double r) : Figura(pi * r * r) { std ::cout << "Kolo o polu=" << getPole() << std ::endl; }
    void id() override { std ::cout << "To jest kolo o polu:" << getPole() << std ::endl; }
    virtual ~Kolo() { std::cout << "Destruktor kola" << std::endl; }
};

class Kwadrat : public Figura
{
public:
    Kwadrat(double a) : Figura(a * a)
    {
        std ::cout << "Kwadrat o polu=" << getPole() << std ::endl;
    }
    void id() override { std ::cout << "To jest kwadrat o polu:" << getPole() << std ::endl; }
    virtual ~Kwadrat() { std::cout << "Destruktor kwadratu" << std::endl; }
};

class WektorFigur : Figura
{
public:
    int        liczbafigur = 1000;
    Figura*    tab[1000];
    static int licznikfigur;

    WektorFigur(int n) : liczbafigur{n} { licznikfigur += n; };

    Figura* operator[](int i)
    {

        if (i < liczbafigur)
            return tab[i];
        else
            return nullptr;
    };

    void push(Figura* pointer)
    {
        tab[liczbafigur] = pointer;
        ++licznikfigur;
    };

    void pop()
    {
        tab[liczbafigur - 1] = nullptr;
        --licznikfigur;
    };

    // double& operator=(const Figura& other) { this->Pole = other.Pole; }

    virtual ~WektorFigur()
    {
        for (int i = 0; i < liczbafigur; i++) {
            delete tab[i];
            std ::cout << "figura " << i << " zniszczona" << std ::endl;
            --licznikfigur;
        }
    };

    void print()
    {
        for (int i = 0; i < liczbafigur; i++) {
            std ::cout << i << ". " << tab[i] << std ::endl;
        }
    }
};

int WektorFigur::licznikfigur = 0; // licznik figur klasy wektorfigur

class FabrykaFigur
{
public:
    Figura* operator()(const std::string& str, double n)
    {
        if (str == "Kwadrat") {
            Kwadrat{n};
        }
        else {
            if (str == "Kolo") {
                Kolo{n};
            }
            else {
                return nullptr;
            }
        }
    }

private:
};

void id(Figura& b)
{
    b.id();
}

int main()
{
    FabrykaFigur()("Kwadrat", 5);
}
