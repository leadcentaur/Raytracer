using namespace std;

class invalidMatrixException : public std::runtime_error
{
    public:
        invalidMatrixException(std::string const& msg):
            std::runtime_error(msg)
        {}
};