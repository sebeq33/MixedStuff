#ifndef   SOCKETEXCEPTION_HH_
# define  SOCKETEXCEPTION_HH_

# include <exception>

class SocketException : public std::exception
{
  protected:
    const char  *_message;
  public:
    SocketException(const char *message);
    virtual ~SocketException() throw() {}

    virtual const char *what() const throw();
};

class SocketExceptionIO : public SocketException
{
  public:
    SocketExceptionIO(const char* message);
    virtual ~SocketExceptionIO() throw() {}

    virtual const char*	what() const throw();
};

#endif /* !SOCKETEXCEPTION_HH_ */
