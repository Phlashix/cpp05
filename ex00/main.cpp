#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "\n---Create---\n" << std::endl;

    try
    {
        Bureaucrat bob("bob", 3);
        Bureaucrat lily("lily", 5);
        Bureaucrat jose("jose", 149);
        Bureaucrat eva("eva", 1);

        bob.Print();
        lily.Print();
        jose.Print();
        eva.Print();


        std::cout << "\n---Add grade---\n" << std::endl;

        lily.AddGrade(2);
        lily.Print();


        std::cout << "\n---Add grade err---\n" << std::endl;

        try
        {
            eva.AddGrade(1);
        }
        catch (std::exception& e)
        {
            std::cout << "eva: " << e.what() << std::endl;
        }


        std::cout << "\n---Remove grade---\n" << std::endl;

        bob.DecrementGrade(2);
        bob.Print();


        std::cout << "\n---Remove grade err---\n" << std::endl;

        try
        {
            jose.DecrementGrade(2);
        }
        catch (std::exception& e)
        {
            std::cout << "jose: " << e.what() << std::endl;
        }


        std::cout << "\n---Multiple add---\n" << std::endl;

        bob.AddGrade(1);
        bob.AddGrade(1);
        bob.Print();


        std::cout << "\n---Multiple remove---\n" << std::endl;

        lily.DecrementGrade(10);
        lily.Print();

    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }


    std::cout << "\n---Create error---\n" << std::endl;

    try
    {
        Bureaucrat lola("lola", -1);
        lola.Print();
    }
    catch (std::exception& e)
    {
        std::cout << "lola: " << e.what() << std::endl;
    }


    try
    {
        Bureaucrat gg("gg", 152);
        gg.Print();
    }
    catch (std::exception& e)
    {
        std::cout << "gg: " << e.what() << std::endl;
    }


    std::cout << "\n---Boundary test---\n" << std::endl;

    try
    {
        Bureaucrat top("top", 1);
        top.AddGrade(1);
    }
    catch (std::exception& e)
    {
        std::cout << "grade 1 increment: " << e.what() << std::endl;
    }


    try
    {
        Bureaucrat bottom("bottom", 150);
        bottom.DecrementGrade(1);
    }
    catch (std::exception& e)
    {
        std::cout << "grade 150 decrement: " << e.what() << std::endl;
    }


    return 0;
}