/*
 * FUN_004392f0 at 004392f0
 * undefined FUN_004392f0(void)
 * Address ranges: 004392f0-00439341
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00439303) */

void __fastcall FUN_004392f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(iVar1 + 8);
  iVar2 = *(int *)(iVar1 + 4);
  for (iVar4 = iVar2; iVar4 != iVar3; iVar4 = iVar4 + 0x14) {
    FUN_0040b4b0();
  }
  *(int *)(iVar1 + 8) = iVar2;
  return;
}

