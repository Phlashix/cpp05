#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _Name(name), _Grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();

    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::GetName() const
{
    return _Name;
}

int Bureaucrat::GetGrade() const
{
    return _Grade;
}

void Bureaucrat::AddGrade(int add)
{
    if (_Grade - add < 1)
        throw GradeTooHighException();

    _Grade -= add;
}

void Bureaucrat::DecrementGrade(int remove)
{
    if (_Grade + remove > 150)
        throw GradeTooLowException();

    _Grade += remove;
}

void Bureaucrat::Print() const
{
    std::cout << _Name
              << ", bureaucrat grade "
              << _Grade
              << "." 
              << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}