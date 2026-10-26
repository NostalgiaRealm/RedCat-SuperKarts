/*
 * FUN_00449868 at 00449868
 * int __register FUN_00449868(int param_1)
 * Address ranges: 00449868-00449895
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00449868(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)PTR_DAT_0047c734)();
  iVar2 = -iVar1;
  *(bool *)(param_1 + 0x20) = iVar1 != 0;
  if (iVar1 != 0) {
    iVar2 = SystemParametersInfoA(0x68,0,(PVOID)(param_1 + 0x10),0);
  }
  return iVar2;
}

