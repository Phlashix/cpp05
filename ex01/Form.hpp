#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _Name;
        bool _IsSigned;
        const int _GradeToSign;
        const int _GradeToExecute;
        

    public:
        Form(std::string name, int gradeToSign, int gradeToExecute);
        void    BeSigned(Bureaucrat& bureaucrat);

        std::string GetFormName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;


        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};
#endif