#include "Library.hh"
#include <iostream>

Library::Library():
	state(UNLOAD),
	lib(NULL)
{
}

Library::~Library()
{
}

bool	Library::load(const std::string &str)
{
  if (str == "")
    return (false);
  name = str;
# ifdef WIN32
  std::string	libName = str + ".dll";
  if ((lib = LoadLibrary(TEXT(str.c_str()))) == NULL)
    return (false);
# else
  std::string	libName = str + ".so";
  if ((lib = dlopen(libName.c_str(), RTLD_LAZY)) == NULL)
    {
      std::cerr << dlerror() << std::endl;
      return (false);
    }
# endif

  state = LOAD;
  return (true);
}

bool	Library::unload(void)
{
# ifdef WIN32
  if (lib != NULL && !FreeLibrary(lib))
    return (false);
# else
  if (lib != NULL && dlclose(lib) != 0)
    return (false);
# endif
  state = UNLOAD;
  return (true);
}

ILibrary::LibraryState	Library::getState() const
{
  return (state);
}

const std::string	&Library::getName() const
{
  return (name);
}

const char	*Library::getLastError() const
{
# ifdef WIN32
  if (lib == NULL && state == UNLOAD)
    return ("Error: unable to load DLL");
  else
    return ("Error: unable to find DLL function");
# else
  return (dlerror());
# endif
}

void	*Library::getSymbol(const std::string &str) const
{
# ifdef WIN32
  return(reinterpret_cast<void *>(GetProcAddress(lib, str.c_str())));
# else
  return(reinterpret_cast<void *>(dlsym(lib, str.c_str())));
# endif
}
