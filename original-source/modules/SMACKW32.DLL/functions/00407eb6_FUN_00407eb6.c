/*
 * FUN_00407eb6 at 00407eb6
 * undefined4 __fastcall FUN_00407eb6(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00407eb1-00407ec1;00407ed9-00407eea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_00407eb6(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_00407f92(param_1,param_2);
  iVar1 = (int)((ulonglong)uVar2 >> 0x20);
  if ((iVar1 != 2) && (iVar1 != 3)) {
    return 1;
  }
  return 0;
}

