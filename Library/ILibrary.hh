#ifndef		IMUTEX_H_
# define	IMUTEX_H_

# include <string>

class ILibrary
{
	public:
		enum LibraryState
		{
			LOAD,
			UNLOAD
		};
	virtual ~ILibrary(void) {};

	virtual bool	load(const std::string &) = 0;
	virtual bool	unload(void) = 0;
	virtual LibraryState	getState() const = 0;
	virtual const std::string	&getName() const = 0;
	virtual const char	*getLastError() const = 0;
	virtual void	*getSymbol(const std::string &) const = 0;
};

#endif /* !IMUTEX_H_ */
