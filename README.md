# usdproxy
Partial binding of [pixar usd](https://github.com/PixarAnimationStudios/OpenUSD) for C# language. Binding provide "vanilla" access
to USD functions, with minimal binding logic.

# Dependencies
* VS Studio 2022
* [OpenUSD](https://github.com/PixarAnimationStudios/OpenUSD)
* [Swig 4.0.1](https://www.swig.org)

# Build dependencies

1. Create ```c:/libs``` directory
2. Run build script ```python BuildUsd.py c:/libs/usdbuild c:/libs/usd```
3. Create required variables (see output of command)

Last command will download and install OpenUSD with all dependencies

# Build project
After dependencies installation

1. Create build directory in project directory ```mkdir build```
2. Configure project
```cmake -DCMAKE_PREFIX_PATH=c:/libs/usd -DEXPORT=true -DCMAKE_INSTALL_PREFIX=c:/lib/usdproxy -DBOOST_ROOT=c:/libs/usdbuild/libs ..```
3. Open Project in Visual Studio. Solution file should be in Build directory
4. Select in VS Studio RelWithDebug and build project

After successull build, C# binding files will be in `BUILDDIR/src/swig` files (*.cs files).
To rebuild binding, please, remove all *.cs files `BUILDIR/src/swig/*.cs`.

# Add USD binding class / function
Workflow for adding USD class and class functions. 

1. Find corresponding USD class in library. For exapmle, SdfPath
2. Create `src/SdfPath.h` and `src/SdfPath.cpp` files
3. Add to `src/CMakeLists.txt` this files
4. Use such skeleton for header class
```c++
#pragma once

#include "usdlib.h"                       // <-- common macroses, etc
#include <pxr/usd/sdf/path.h>             // concrete USD class include

namespace usdproxy
{

class SdfPath
{
public:
LIBUSDPROXY_API                           // <-- required for dll symbols export
SdfPath() = default;                      // <-- required for C# biding

LIBUSDPROXY_API
explicit SdfPath(const SdfPath& sdfPath); // <-- required for C# binding

LIBUSDPROXY_API
explicit SdfPath(const pxr::SdfPath& path); // <-- nice to have for easy work

LIBUSDPROXY_API
const pxr::SdfPath& Get() const;            // <-- nice to have for easy work

LIBUSDPROXY_API
SdfPath AppendElementString(const std::string& element); // <-- some proxy function

private:
pxr::SdfPath m_sdfPath;                     // <-- concrete USD implementation
};

} // namespace usdproxy
```
5. Create `SdfPath.cpp` file with implementation (see `src/SdfPath.cpp`)
6. Create `swig/SdfPath.i` file (for swig binding) with content
```
%module SdfPath

%{
#include "SdfPath.h"             // <-- add this include for swig cxx generated file
%}

%include "SdfPath.h"             // <-- swig will parse src/SdfPath.h for binding generation
```
7. Edit `swig/usdlib.i` file, add `%include SdfPath.i`

## Note
Do not use move constructor and operator= as binding sometimes has issue with them.

## Possible build issues
### Boost not found
This project uses boost, provided by OpenUSD. Be sure:
* No BOOST_ROOT env. variable in system
* No c:/boost directory present in system
* No PYTHONPATH env. variable from older builds
* Check PATH variable for libs (should be empty)

### Compilation error in OpenUSD
* Check that build in RelWithDebug mode or release. Debug build doesn't work