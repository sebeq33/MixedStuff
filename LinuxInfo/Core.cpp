//
// Core.cpp for MyGKrellM in /home/canda_j//piscine/tek2/rush3/piscine_cpp_rush3-2016-bequig_s/src
//
// Made by julien canda
// Login   <canda_j@epitech.net>
//
// Started on  Sat Jan 26 17:29:16 2013 julien canda
// Last update Sun Jan 27 06:40:04 2013 sebastien bequignon
//

#include "Core.hh"

Core::Core() : _previous_work0(0), _previous_total0(0), _previous_work1(0), _previous_total1(0), _previous_work2(0), _previous_total2(0), _previous_work3(0), _previous_total3(0), _core0Usage(0), _core1Usage(0), _core2Usage(0), _core3Usage(0), _core(0),  _frequency(2.80), _model(""), _numberCores(4)
{
}

Core::~Core()
{
}

static std::string getDataInLine(std::string a_line, int n, bool flag)
{
  char *pos = const_cast<char *>(a_line.c_str());
  char *end;
  std::string return_value;

  if (flag)
    while (*pos != ':')
      ++pos;
  for (int i = 0; i < n; i++)
    {
      while (*pos != ' ' && *pos != '\t')
	++pos;
      while (*pos != '\0' && (*pos == ' ' || *pos == '\t'))
	++pos;
    }
  for (end = pos; *end != '\0' && *end != ' ' && *end != '\t'; end++);
  return_value = std::string(pos, end);
  return (return_value);
}

void Core::calcul_usage(float *_previous_work, float *_previous_total, float *_coreUsage, std::ifstream *file_try)
{
  std::string   line_try;
  std::string	line;
  float		total_try = 0;
  float		work_try = 0;

  getline(*file_try, line_try);
  line_try = line_try.substr(5);

  for (int i = 0; i < 10; ++i)
    {
      total_try += atoi(getDataInLine(line_try, i, 0).c_str());
    }
  for (int i = 0; i < 3; ++i)
    {
      work_try += atoi(getDataInLine(line_try, i, 0).c_str());
    }

  *_coreUsage = ((work_try - *_previous_work) / (total_try - *_previous_total)) * 100;
  *_previous_work = work_try;
  *_previous_total = total_try;
}

void Core::updateData()
{
  std::ifstream file_try;
  std::string	line;

  file_try.open("/proc/stat");
  if (file_try.is_open())
    {
      getline(file_try, line);
      calcul_usage(&_previous_work0, &_previous_total0, &_core0Usage, &file_try);
      calcul_usage(&_previous_work1, &_previous_total1, &_core1Usage, &file_try);
      calcul_usage(&_previous_work2, &_previous_total2, &_core2Usage, &file_try);
      calcul_usage(&_previous_work3, &_previous_total3, &_core3Usage, &file_try);

      _core = (_core0Usage + _core1Usage + _core2Usage + _core3Usage) / 4;
    }
  file_try.close();

  file_try.open("/proc/cpuinfo");
  if (file_try.is_open())
    {
      for (int i = 0; i < 4; ++i)
	{
	  getline(file_try, line);
	}
      getline(file_try, line);
      _model = line.substr(13);
      _frequency = atof(_model.substr(_model.size() - 7).c_str());
      std::cout << _model << std::endl;
      std::cout << _frequency << std::endl;
    }
}

TypeModule  Core::getType() const
{
  return (CORE);
}

float Core::getUsage0() const
{
  return (_core0Usage);
}

float Core::getUsage1() const
{
  return (_core1Usage);
}

float Core::getUsage2() const
{
  return (_core2Usage);
}

float Core::getUsage3() const
{
  return (_core3Usage);
}

float Core::getCore() const
{
  return (_core);
}

float Core::getFrequency() const
{
  return (_frequency);
}

std::string const &Core::getModel() const
{
  return (_model);
}

int Core::getNumberCores() const
{
  return (_numberCores);
}
