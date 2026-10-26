/*
 * __frnd at 004c855c
 * undefined __frnd(void)
 * Address ranges: 004c855c-004c856d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __frnd  Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2019 Release
 */

/* Library Function - Single Match
    __frnd
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2019 Release */

float10 __frnd(double param_1)

{
  return (float10)ROUND(param_1);
}

