#------------------------------------------------------------------------------
# CLING - the C++ LLVM-based InterpreterG :)
#
# This file is dual-licensed: you can choose to license it under the University
# of Illinois Open Source License or the GNU Lesser General Public License. See
# LICENSE.TXT for details.
#------------------------------------------------------------------------------
set(LLVM_LINK_COMPONENTS
  analysis
  core
  coroutines
  coverage
  executionengine
  ipo
  lto
  mc
  object
  option
  orcjit
  runtimedyld
  scalaropts
  support
  target
  transformutils
  binaryformat
  ${LLVM_TARGETS_TO_BUILD}
)
set(LIBS
  clangCodeGen
  clangDriver
  clangFrontend
  clangParse
  clangSema
  clangAnalysis
  clangEdit
  clangRewrite
  clangRewriteFrontend
  clangSerialization
  clangAST
  clangBasic
  clangLex
)

find_library(DL_LIBRARY_PATH dl)
if (DL_LIBRARY_PATH)
  list(APPEND LIBS dl)
endif()

# set(LLDB_DIR "${LLVM_MAIN_SRC_DIR}/../lldb/cmake/modules")

# find_package(LLDB REQUIRED CONFIG)

# # 如果 find_package 失败，可以手动指定路径
# if (LLDB_FOUND)
#   message(STATUS "Found LLDB: ${LLDB_LIBRARY}")
#   include_directories(${LLDB_INCLUDE_DIRS})
#   list(APPEND LIBS ${LLDB_LIBRARY})
# else()
# #   message(FATAL_ERROR "LLDB not found! Make sure LLDB is installed.")
# endif()

add_cling_library(clingDebugger OBJECT
  Debugger.cpp
  LINK_LIBS
  ${LIBS}
)

if ( MSVC )
  set_target_properties(clingDebugger PROPERTIES
  COMPILE_FLAGS "/D_HAS_EXCEPTIONS=0")
endif ()
