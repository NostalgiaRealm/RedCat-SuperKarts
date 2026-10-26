/*
 * FUN_00409468 at 00409468
 * undefined4 __fastcall FUN_00409468(undefined4 param_1, undefined2 param_2)
 * Address ranges: 00409468-00409479;0040948b-0040948d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_00409468(undefined4 param_1,undefined2 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (DAT_0040f0e0 != '\0') {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)(param_2);
    return uVar2;
  }
  return 0;
}

