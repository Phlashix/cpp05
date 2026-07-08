#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "===== BUREAUCRAT TESTS =====" << std::endl;

	try
	{
		Bureaucrat bob("Bob", 50);
		Bureaucrat alice("Alice", 1);
		Bureaucrat low("Low", 150);

		bob.print();
		alice.print();
		low.print();

		std::cout << "\n===== INCREMENT TEST =====" << std::endl;
		bob.AddGrade(2);
		bob.print();

		std::cout << "\n===== DECREMENT TEST =====" << std::endl;
		low.DecrementGrade(1);
		low.print();

		std::cout << "\n===== COPY TEST =====" << std::endl;
		Bureaucrat copy(bob);
		copy.print();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	std::cout << "\n===== INVALID BUREAUCRAT =====" << std::endl;

	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "TooHigh OK : " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("TooLow", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "TooLow OK : " << e.what() << std::endl;
	}


	std::cout << "\n===== FORM CREATION =====" << std::endl;

	try
	{
		Form contract("Contract", 50, 25);
		contract.print();

		Bureaucrat boss("Boss", 10);

		std::cout << "\nBoss signs contract" << std::endl;
		boss.SignForm(contract);

		contract.print();
	}
	catch (std::exception &e)
	{
		std::cout << "Form exception : " << e.what() << std::endl;
	}


	std::cout << "\n===== FORM SIGN FAILURE =====" << std::endl;

	try
	{
		Form secret("Secret", 10, 5);
		Bureaucrat intern("Intern", 100);

		secret.print();

		std::cout << "Intern tries to sign" << std::endl;
		intern.SignForm(secret);
	}
	catch (std::exception &e)
	{
		std::cout << "Expected failure OK : " << e.what() << std::endl;
	}


	std::cout << "\n===== MULTIPLE FORM TESTS =====" << std::endl;

	try
	{
		Form easy("EasyForm", 150, 150);
		Form hard("HardForm", 1, 1);

		Bureaucrat normal("Normal", 100);
		Bureaucrat master("Master", 1);

		std::cout << "\nEasy form before:" << std::endl;
		easy.print();

		normal.SignForm(easy);

		std::cout << "\nHard form before:" << std::endl;
		hard.print();

		master.SignForm(hard);

		hard.print();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	std::cout << "\n===== INVALID FORMS =====" << std::endl;

	try
	{
		Form badHigh("BadHigh", 0, 10);
	}
	catch (std::exception &e)
	{
		std::cout << "BadHigh OK : " << e.what() << std::endl;
	}

	try
	{
		Form badLow("BadLow", 150, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "BadLow OK : " << e.what() << std::endl;
	}


	std::cout << "\n===== END TESTS =====" << std::endl;

	return 0;
}