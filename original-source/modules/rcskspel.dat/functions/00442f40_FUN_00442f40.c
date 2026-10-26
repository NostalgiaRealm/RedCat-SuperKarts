/*
 * FUN_00442f40 at 00442f40
 * undefined FUN_00442f40(void)
 * Address ranges: 00442f40-00442f92
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

LRESULT FUN_00442f40(int param_1,WPARAM param_2,LPARAM param_3)

{
  LRESULT LVar1;
  
  if (param_1 < 0) {
    LVar1 = CallNextHookEx(DAT_0053d340,param_1,param_2,param_3);
    return LVar1;
  }
  if (((param_2 != 0x5b) && (param_2 != 0x5c)) && (param_2 != 0x5d)) {
    LVar1 = CallNextHookEx(DAT_0053d340,param_1,param_2,param_3);
    return LVar1;
  }
  return 1;
}

