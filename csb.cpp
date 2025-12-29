#include "csb.hpp"

void csb::configure()
{
  csb::target_name = "CSTemplate";
  csb::target_artifact = EXECUTABLE;
  csb::target_linkage = STATIC;
  csb::target_subsystem = CONSOLE;
  csb::target_configuration = RELEASE;
  csb::cxx_standard = CXX20;
  csb::warning_level = W4;
  csb::include_files = csb::choose_files({"program/include"});
  csb::source_files = csb::choose_files({"program/source"});
  if (csb::host_platform == WINDOWS)
    csb::libraries = {"kernel32"};
  else if (csb::host_platform == LINUX)
    csb::libraries = {"c"};
}

int csb::clean()
{
  csb::clean_build();
  return csb::success;
}

int csb::build()
{
  csb::generate_compile_commands();
  csb::compile();
  csb::link();
  return csb::success;
}

int csb::run()
{
  csb::run_target();
  return csb::success;
}

CSB_MAIN()
