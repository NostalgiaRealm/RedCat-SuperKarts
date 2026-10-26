/*
 * FUN_00407f56 at 00407f56
 * undefined8 __fastcall FUN_00407f56(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00407f56-00407f8c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_00407f56(undefined4 param_1,undefined4 param_2)

{
  BOOL BVar1;
  
  if (DAT_0040eff4 != '\0') {
    BVar1 = SetConsoleCtrlHandler((PHANDLER_ROUTINE)&DAT_00407e92,0);
    if (BVar1 != 0) {
      DAT_0040eff4 = '\0';
    }
  }
  return CONCAT44(param_2,(uint)(DAT_0040eff4 == '\0'));
}

