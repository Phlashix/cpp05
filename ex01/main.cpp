#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    std::cout << "\n========== BUREAUCRAT TEST ==========\n" << std::endl;

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


        std::cout << "\n--- Add grade ---\n" << std::endl;

        lily.AddGrade(2);
        lily.Print();


        std::cout << "\n--- Add grade error ---\n" << std::endl;

        try
        {
            eva.AddGrade(1);
        }
        catch (std::exception& e)
        {
            std::cout << "eva: " << e.what() << std::endl;
        }


        std::cout << "\n--- Remove grade ---\n" << std::endl;

        bob.DecrementGrade(2);
        bob.Print();


        std::cout << "\n--- Remove grade error ---\n" << std::endl;

        try
        {
            jose.DecrementGrade(2);
        }
        catch (std::exception& e)
        {
            std::cout << "jose: " << e.what() << std::endl;
        }


        std::cout << "\n--- Multiple grade changes ---\n" << std::endl;

        bob.AddGrade(1);
        bob.AddGrade(1);
        bob.Print();

        lily.DecrementGrade(10);
        lily.Print();


        std::cout << "\n========== FORM TEST ==========\n" << std::endl;


        std::cout << "\n--- Form creation ---\n" << std::endl;

        Form contract("Contract", 50, 25);

        std::cout << "Name : "
                  << contract.GetFormName()
                  << std::endl;

        std::cout << "Signed : "
                  << (contract.getSigned() ? "Yes" : "No")
                  << std::endl;

        std::cout << "Grade to sign : "
                  << contract.getGradeToSign()
                  << std::endl;

        std::cout << "Grade to execute : "
                  << contract.getGradeToExecute()
                  << std::endl;


        std::cout << "\n--- Form signature success ---\n" << std::endl;

        Bureaucrat boss("boss", 10);

        contract.BeSigned(boss);

        std::cout << "Signed : "
                  << (contract.getSigned() ? "Yes" : "No")
                  << std::endl;



        std::cout << "\n--- Form signature failed ---\n" << std::endl;

        try
        {
            Bureaucrat intern("intern", 100);
            Form secret("Secret", 50, 25);

            secret.BeSigned(intern);
        }
        catch (std::exception& e)
        {
            std::cout << "intern: "
                      << e.what()
                      << std::endl;
        }



        std::cout << "\n--- Form creation error high ---\n" << std::endl;

        try
        {
            Form badHigh("BadHigh", 0, 20);
        }
        catch (std::exception& e)
        {
            std::cout << "BadHigh: "
                      << e.what()
                      << std::endl;
        }



        std::cout << "\n--- Form creation error low ---\n" << std::endl;

        try
        {
            Form badLow("BadLow", 50, 200);
        }
        catch (std::exception& e)
        {
            std::cout << "BadLow: "
                      << e.what()
                      << std::endl;
        }

    }
    catch (std::exception& e)
    {
        std::cout << "Error: "
                  << e.what()
                  << std::endl;
    }



    std::cout << "\n========== BOUNDARY TEST ==========\n"
              << std::endl;


    try
    {
        Bureaucrat top("top", 1);
        top.AddGrade(1);
    }
    catch (std::exception& e)
    {
        std::cout << "grade 1 increment: "
                  << e.what()
                  << std::endl;
    }


    try
    {
        Bureaucrat bottom("bottom", 150);
        bottom.DecrementGrade(1);
    }
    catch (std::exception& e)
    {
        std::cout << "grade 150 decrement: "
                  << e.what()
                  << std::endl;
    }



    std::cout << "\n========== CREATION ERROR TEST ==========\n"
              << std::endl;


    try
    {
        Bureaucrat lola("lola", -1);
        lola.Print();
    }
    catch (std::exception& e)
    {
        std::cout << "lola: "
                  << e.what()
                  << std::endl;
    }


    try
    {
        Bureaucrat gg("gg", 152);
        gg.Print();
    }
    catch (std::exception& e)
    {
        std::cout << "gg: "
                  << e.what()
                  << std::endl;
    }


    std::cout << "\n========== END TEST ==========\n"
              << std::endl;

    return 0;
}