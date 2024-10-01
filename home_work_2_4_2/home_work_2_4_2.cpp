#include <iostream>
#include <string>

struct figura
{
protected:
    int nSide{};
    std::string name{ "Фигура: " };
    int line_a{};
    int line_b{};
    int line_c{};
    int line_d{};
    int corner_A{};
    int corner_B{};
    int corner_C{};
    int corner_D{};

public:
    virtual void printBadge()
    {
        std::cout << name << std::endl;
        std::cout << "Стороны:  а="  << line_a << " b=" << line_b << " c=" << line_c << std::endl;
        std::cout << "Углы:  А=" << corner_A << " B=" << corner_B << " C=" << corner_C << std::endl;
    }
};

struct triangle : public figura
{
protected:
    triangle(int a, int b, int c, int А, int В, int C)
    {
        nSide = 3;
        name = { "Треугольник: " };
        line_a = a;
        line_b = b;
        line_c = c;
        corner_A = А;
        corner_B = В;
        corner_C = C;
    }
public:
    triangle():triangle(10, 20, 30, 50, 60, 70){}
    

};
struct quadrilateral : public figura
{
protected:
    quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
    {
        nSide = 4;
        name = { "Четырехугольник: " };
        line_a = a;
        line_b = b;
        line_c = c;
        line_d = d;
        corner_A = A;
        corner_B = B;
        corner_C = C;
        corner_D = D;
    }
public:
    quadrilateral() : quadrilateral(10, 20, 30, 50, 60, 70, 57, 45) {}

    void printBadge() override
    {
        std::cout << name << std::endl;
        std::cout << "Стороны:  а=" << line_a << " b=" << line_b << " c=" << line_c << " d=" << line_d << std::endl;
        std::cout << "Углы:  А=" << corner_A << " B=" << corner_B << " C=" << corner_C << " D=" << corner_D << std::endl;

    }

};

struct straighTriangle : public triangle
{
private:
    straighTriangle(int a, int b, int c, int А, int В)
    {
        name = { "Прямоугольный треугольник: " };
        line_a = a;
        line_b = b;
        line_c = c;
        corner_A = А;
        corner_B = В;
        corner_C = 90;
     }
public:
    straighTriangle() : straighTriangle(10, 20, 30, 30, 60) {};
};

struct isoscelesTriangle : public triangle
{
private:
    isoscelesTriangle(int a, int b, int А, int В)
    {
        name = { "Равнобедренный треугольник: " };
        line_a = a;
        line_b = b;
        line_c = a;
        corner_A = А;
        corner_B = В;
        corner_C = А;
    }
public:
    isoscelesTriangle() : isoscelesTriangle(10, 20, 30, 60) {};
    
};

struct equilateralTriangle : public triangle
{
private:
    equilateralTriangle(int a, int А)
    {
        name = { "Равносторонний треугольник: " };
        line_a = a;
        line_b = a;
        line_c = a;
        corner_A = А;
        corner_B = А;
        corner_C = А;
    } 
public:
    equilateralTriangle() : equilateralTriangle(10, 60) {};
};
struct rectangle : public quadrilateral
{
private:
    rectangle(int a, int b)
    {
        name = { "Прямоугольник: " };
        line_a = a;
        line_b = b;
        line_c = a;
        line_d = b;
        corner_A = 90;
        corner_B = 90;
        corner_C = 90;
        corner_D = 90;
    } 
public:
    rectangle(): rectangle(10, 30) {};
};

struct square : public quadrilateral
{
private:
    square(int a)
    {
        name = { "Квадрат: " };
        line_a = a;
        line_b = a;
        line_c = a;
        line_d = a;
        corner_A = 90;
        corner_B = 90;
        corner_C = 90;
        corner_D = 90;
    }
public:
    square() : square(30) {};
};

struct parallelogram : public quadrilateral
{
private:
    parallelogram(int a, int b, int А, int В)
    {
        name = { "Параллелограмм: " };
        line_a = a;
        line_b = b;
        line_c = a;
        line_d = b;
        corner_A = А;
        corner_B = В;
        corner_C = А;
        corner_D = В;
    } 
public:
    parallelogram() : parallelogram(30, 40, 20, 30) {};
};

struct rhomb : public quadrilateral
{
private:
    rhomb(int a, int А, int В)
    {
        name = { "Ромб: " };
        line_a = a;
        line_b = a;
        line_c = a;
        line_d = a;
        corner_A = А;
        corner_B = В;
        corner_C = А;
        corner_D = В;
        
    } 
public:
    rhomb() : rhomb(10, 20, 30) {};
};

void print_info(figura*e) {
    e->printBadge();
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
     figura* figury[10]{};
     figury[0] = new triangle;
     figury[1] = new straighTriangle;
     figury[2] = new isoscelesTriangle;
     figury[3] = new equilateralTriangle;
     figury[4] = new quadrilateral;
     figury[5] = new rectangle;
     figury[6] = new square;
     figury[7] = new parallelogram;
     figury[8] = new rhomb;

     for (int i = 0; i < 9; i++)
     {
         print_info(figury[i]);
         std::cout << std::endl;
     }

     for (int i = 0; i < 9; i++)
     {
         delete figury[i];

     }
}
