# usdproxy
Partial binding of [pixar usd](https://github.com/PixarAnimationStudios/OpenUSD) for C# language


## building

1. Create ```c:/libs``` directory
2. Run build script ```python BuildUsd.py c:/libs/usdbuild c:/libs/usd```
3. Create build directory in project directory ```mkdir build``` 
4. Configure project ```cmake -DCMAKE_PREFIX_PATH=c:/libs/usd -DEXPORT=true -DCMAKE_INSTALL_PREFIX=c:/lib/usdproxy -DBOOST_ROOT=c:/libs/usdbuild/libs ..```
5. Create ENV variable `USD_ROOT` and set it to `c:/libs/usd`
6. Create ENV variable `USD_DEPS` and set it to `c:/libs/usdbuild/libs`






