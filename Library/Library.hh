#ifndef		LIBRARY_HH_
# define	LIBRARY_HH_


# ifdef WIN32
	# include <windows.h>
# else
	# include <dlfcn.h>
# endif
# include "ILibrary.hh"

class Library : public ILibrary
{
	public:
		Library();
		virtual ~Library();

		virtual bool	load(const std::string &);
		virtual bool	unload(void);
		virtual LibraryState	getState() const;
		virtual const std::string	&getName() const;
		virtual const char	*getLastError() const;
		virtual void	*getSymbol(const std::string &) const;

	private:
		Library(Library const &);
		Library &operator=(Library const &);

		LibraryState	state;
		std::string		name;
		# ifdef WIN32
			HINSTANCE lib;
		# else
			void	*lib;
		# endif
};

#endif /* !MUTEX_H_ */
