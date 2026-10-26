/*
 * FUN_004b3830 at 004b3830
 * undefined FUN_004b3830(void)
 * Address ranges: 004b3830-004b387a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b3830(uint param_1)

{
  SHORT SVar1;
  
  if ((param_1 & 0x100) == 0) {
    SVar1 = GetAsyncKeyState(0x10);
    if (-1 < SVar1) {
      SVar1 = GetAsyncKeyState(param_1);
      return (-1 < SVar1) - 1;
    }
  }
  else {
    SVar1 = GetAsyncKeyState(0x10);
    if (SVar1 < 0) {
      SVar1 = GetAsyncKeyState(param_1);
      return (-1 < SVar1) - 1;
    }
  }
  return 0;
}

