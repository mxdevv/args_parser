#ifndef __ARGS_PARSER_H__
#define __ARGS_PARSER_H__

#include <string>
#include <vector>
#include <unordered_map>

namespace args {

enum class type_t {
  required, optional
};

class short_key_t {
public:
  short_key_t(char sym, int parametrs_count, type_t type, std::string&& description)
    : sym(sym), parametrs_count(parametrs_count), type(type), description(description)
  { }
  
private:
  char sym;
  int parametrs_count;
  type_t type;
  std::string description;
};

class arguments_parser_t {
public:
  arguments_parser_t() = default;

  void operator () (int argc, char** argv) {
    this->argc = argc;
    this->argv = argv;
  }

  ;

private:
  int argc;
  char** argv;

  std::unordered_map<char, short_key_t> must_short_keys;
  std::unordered_map<char, short_key_t> fact_short_keys;
};

} // namespace args

#endif
