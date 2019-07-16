#include <iostream>
#include <utility>
#include <string>
#include <memory>
#include <iomanip>


class password_validator
{
public:
    virtual bool validate(std::string password) = 0;
    virtual ~password_validator(){};
};


class length_validator final: public password_validator
{
public:
    length_validator(unsigned int min_length): length(min_length){}

    virtual bool validate(std::string password) override
    {
        return password.length() >= length;
    }    

private:
    unsigned int length{0};
};


class password_validator_decorator : public password_validator
{
public:
    explicit password_validator_decorator(std::unique_ptr<password_validator> validator): 
		inner_validator(std::move(validator))
    {}

    virtual bool validate(std::string password) override
    {
        return inner_validator->validate(password);
    }
private:
    std::unique_ptr<password_validator> inner_validator;
};



class digit_password_validator final: public password_validator_decorator
{
public:
    explicit digit_password_validator(std::unique_ptr<password_validator> validator):
		password_validator_decorator(std::move(validator))
    {}

    virtual bool validate(std::string password) override
    {
        if(!password_validator_decorator::validate(password))
            return false;

        return password.find_first_of("0123456789") != std::string::npos;
    }
};



class symbol_password_validator final: public password_validator_decorator
{
public:
    explicit symbol_password_validator(std::unique_ptr<password_validator> validator):
		password_validator_decorator(std::move(validator))
    {}

    virtual bool validate(std::string password) override
    {
        if(!password_validator_decorator::validate(password))
            return false;

        return password.find_first_of("!@#$%^&*(){}[]?<>") != std::string::npos;
    }
};



class case_password_validator final: public password_validator_decorator
{
public:
    explicit case_password_validator(std::unique_ptr<password_validator> validator):
		password_validator_decorator(std::move(validator))
    {}

    virtual bool validate(std::string password) override
    {
        if(!password_validator_decorator::validate(password))
            return false;

        bool haslower = false;
        bool hasupper = false;
        
        for(auto c : password)
        {
            if(islower(c)) haslower = true;
            else if(isupper(c)) hasupper = true;
        }
        
        return haslower && hasupper;
    }

};



int main()
{
    auto validator1 = std::make_unique<case_password_validator>(
				std::make_unique<symbol_password_validator>(
					std::make_unique<digit_password_validator>(
						std::make_unique<length_validator>(8))));
    
    std::string password{""};
    std::cout << "Enter password string : " << std::endl;
    std::cin >> password;
    std::cout << std::boolalpha;
    std::cout << "\nPassword is " << validator1->validate(password) << std::endl;

    return 0;
}
