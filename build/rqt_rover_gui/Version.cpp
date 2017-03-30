// This file is used by cmake to generate a .cpp file that contains the build
// time and git version. The values are set in CMakeLists.txt using the
// configure_file command. This method should keep the git version display
// current in the GUI with minimal recompilation.

#include "Version.h"

const QString GIT_BRANCH = "master";
const QString GIT_VERSION = "";
const QString BUILD_TIME = "2017-03-29-20:48";
