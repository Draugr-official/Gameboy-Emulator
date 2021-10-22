#include <exception>
#include <string>

struct FatalException : public std::exception
{
public:
    FatalException(std::string& message);
    const char* what() const throw ();
}