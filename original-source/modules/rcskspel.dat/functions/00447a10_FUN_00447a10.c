/*
 * FUN_00447a10 at 00447a10
 * undefined FUN_00447a10(void)
 * Address ranges: 00447a10-00447a88
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00447a23) */

void __fastcall FUN_00447a10(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(iVar1 + 8);
  iVar2 = *(int *)(iVar1 + 4);
  for (iVar4 = iVar2; iVar4 != iVar3; iVar4 = iVar4 + 0x2c) {
    FUN_00445a40();
  }
  *(int *)(iVar1 + 8) = iVar2;
  return;
}

