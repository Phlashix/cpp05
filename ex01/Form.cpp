#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : _Name(name),
      _IsSigned(false),
      _GradeToSign(gradeToSign),
      _GradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}


void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.GetGrade() <= _GradeToSign)
        _IsSigned = true;
    else
        throw GradeTooLowException();
}


void Form::print() const
{
    std::cout << "Name : " << _Name << std::endl;
    std::cout << "Signed : " 
              << (_IsSigned ? "Yes" : "No")
              << std::endl;
    std::cout << "Grade to sign : "
              << _GradeToSign
              << std::endl;
    std::cout << "Grade to execute : "
              << _GradeToExecute
              << std::endl;
}

/*  --------------Getters------------- */


std::string Form::GetFormName() const
{
    return _Name;
}

bool Form::getSigned() const
{
    return _IsSigned;
}

int Form::getGradeToSign() const
{
    return _GradeToSign;
}

int Form::getGradeToExecute() const
{
    return _GradeToExecute;
}

/*------------------------------------*/

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

