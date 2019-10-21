#include "args_parser.hpp"

#include <iostream>

int main(int argc, char** argv)
{
  args::arguments_parser_t arguments_parser;

  args::short_key_t key_c { 'c', 1, args::type_t::required,
      "this key set count of numbers" };

  arguments_parser(argc, argv);
}
