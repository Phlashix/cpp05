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


void Form::BeSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.GetGrade() <= _GradeToSign)
        _IsSigned = true;
    else
        throw GradeTooLowException();
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

