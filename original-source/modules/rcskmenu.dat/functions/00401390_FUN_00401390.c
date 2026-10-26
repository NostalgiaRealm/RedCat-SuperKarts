/*
 * FUN_00401390 at 00401390
 * WORD __register FUN_00401390(void)
 * Address ranges: 00401390-004013b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

WORD FUN_00401390(void)

{
  WORD WVar1;
  _STARTUPINFOA _Stack_48;
  
  GetStartupInfoA(&_Stack_48);
  WVar1 = 10;
  if (((byte)_Stack_48.dwFlags & 1) != 0) {
    WVar1 = _Stack_48.wShowWindow;
  }
  return WVar1;
}

