# usdproxy
Dummy proxy object for C-like languages for pixar usd library

## building

1. Create ```c:/libs``` directory
2. Run python ```python Build.py c:/libs/usdbuild c:/libs/usd```
3. Create build directory in project directory ```mkdir build``` 
4. Configure project ```cmake -DCMAKE_PREFIX_PATH=c:/libs/usd -DEXPORT=1```
5. Create ENV variable `USD_ROOT` and set it to `c:/libs/usd`
6. Create ENV variable `USD_DEPS` and set it to `c:/libs/usdbuild/libs`






