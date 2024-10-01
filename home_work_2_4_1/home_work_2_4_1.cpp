#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>
#include <cstdlib>

struct figura
{
protected:
    int nSide{};
    std::string name{"Фигура: "};
public:
 virtual void print_nSide()
  {
   std::cout << name << nSide << std::endl;
  }
};

struct triangle : public figura
{
    triangle()
    {
        nSide = 3;
        name = { "Треугольник: " };
    }

};
struct quadrilateral : public figura
{
    quadrilateral()
    {
        nSide = 4;
        name = { "Четырехугольник: " };
     }

 };
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");


    figura figura;
    triangle triangle;
    quadrilateral quadrilateral;
    std::cout <<"Количество сторон: " << std::endl;
    figura.print_nSide();
    triangle.print_nSide();
    quadrilateral.print_nSide();
}
