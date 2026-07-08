#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        const std::string _Name;
        int _Grade;

    public:
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        std::string GetName() const;
        int GetGrade() const;
        void AddGrade(int add);
        void DecrementGrade(int remove);
        void Print() const;
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