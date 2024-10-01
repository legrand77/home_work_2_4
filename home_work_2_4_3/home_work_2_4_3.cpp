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

    void print_name()
    {
        std::cout << name << std::endl; 
    }
   
    void print_nSide()
    {
        std::cout << "Количество сторон: " << nSide << std::endl;
    }
    void print_Side()
    {
        std::cout << "Стороны:  а=" << line_a << " b=" << line_b << " c=" << line_c ;
    }
    void print_Corner()
    {
        std::cout << "Углы:  А=" << corner_A << " B=" << corner_B << " C=" << corner_C;
    }

   virtual int right()
    {
        if (line_a == 0 && line_b == 0 && line_c == 0)
        {
            return 1;
        }
    }

   void print_right()
   {
       if (right() == 1)
       {
           std::cout << "Правильная" << std::endl;
       }
       else
       {
           std::cout << "Неправильная" << std::endl;
       }
   }
public:
   
    virtual void printBadge()
    {
        print_name();
        print_right();
        print_nSide();
        if (line_a !=0 && line_b !=0 && line_c !=0){
        print_Side(); std::cout << std::endl;
        print_Corner(); std::cout << std::endl; 
        }
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
    int right() override
    {
        if ((corner_A + corner_B + corner_C  == 180) && nSide == 3)
        {
            return 1;
        }
    }
 
public:
    triangle() :triangle(10, 20, 30, 50, 60, 70) {}


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
    int right() override
    {
        if ((corner_A + corner_B + corner_C + corner_D == 360) && nSide == 4)
        {
            return 1;
        }
        
    }

public:
    quadrilateral() : quadrilateral(10, 20, 30, 50, 60, 70, 57, 45) {}
  
    void printBadge() override
    {
        print_name();
        print_right() ;
        print_nSide();
        print_Side();std::cout <<  " d=" << line_d << std::endl;
        print_Corner();std::cout  << " D=" << corner_D << std::endl;
      
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
    int right() override
    {
        if ((triangle::right() == 1) && corner_C == 90)
        {
            return 1;
        }
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
    int right() override
    {
        if ((triangle::right() == 1) && (line_a = line_c) && (corner_A = corner_C))
        {
            return 1;
        }
    }

public:
    isoscelesTriangle() : isoscelesTriangle(10, 20, 30, 120) {};

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
    int right() override
    {
        if ((triangle::right() == 1) && (line_a = line_c) && (line_a = line_b) && (corner_A = corner_C) && (corner_A = corner_B))
        {
            return 1;
        }
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
    int right() override
    {
        if ((quadrilateral::right() == 1) && (line_a = line_c) && (line_b = line_c) && (corner_A = 90) && (corner_B = 90) && (corner_C = 90) && (corner_D = 90))
        {
            return 1;
        }
    }

public:
    rectangle() : rectangle(10, 30) {};
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
    int right() override
    {
        if ((quadrilateral::right() == 1) && (line_a = line_b) && (line_b = line_c) && (line_c = line_d) && (corner_A = 90) && (corner_B = 90) && (corner_C = 90) && (corner_D = 90))
        {
            return 1;
        }
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
    int right() override
    {
        if ((quadrilateral::right() == 1) && (line_a = line_c) && (line_b = line_d)  && (corner_A = corner_C) && (corner_B = corner_D))
        {
            return 1;
        }
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
    int right() override
    {
        if ((quadrilateral::right() == 1) && (line_a = line_b) && (line_b = line_c) && (line_c = line_d) && (corner_A = corner_C) && (corner_B = corner_D))
        {
            return 1;
        }
    }

public:
    rhomb() : rhomb(10, 20, 30) {};
};

void print_info(figura* e) {
    e->printBadge();
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    figura* figury[10]{};
    figury[0] = new figura;
    figury[1] = new triangle;
    figury[2] = new straighTriangle;
    figury[3] = new isoscelesTriangle;
    figury[4] = new equilateralTriangle;
    figury[5] = new quadrilateral;
    figury[6] = new rectangle;
    figury[7] = new square;
    figury[8] = new parallelogram;
    figury[9] = new rhomb;

    for (int i = 0; i < 10; i++)
    {
        print_info(figury[i]);
        std::cout << std::endl;
    }

    for (int i = 0; i < 10; i++)
    {
        delete figury[i];

    }
}
