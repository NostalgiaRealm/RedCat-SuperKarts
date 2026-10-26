/*
 * FUN_00401d1f at 00401d1f
 * int __cdecl FUN_00401d1f(int * param_1)
 * Address ranges: 00401d1f-00401d59
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00401d1f(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = flsall(0);
    return iVar1;
  }
  iVar1 = FUN_00401d5a(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) != 0) {
    iVar1 = FUN_004046d3(param_1[4]);
    return -(uint)(iVar1 != 0);
  }
  return 0;
}

