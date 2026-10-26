/*
 * FUN_00439400 at 00439400
 * undefined FUN_00439400(void)
 * Address ranges: 00439400-0043945f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00439413) */

void __fastcall FUN_00439400(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(iVar1 + 8);
  iVar2 = *(int *)(iVar1 + 4);
  for (iVar4 = iVar2; iVar4 != iVar3; iVar4 = iVar4 + 0x44) {
    FUN_004389b0();
  }
  *(int *)(iVar1 + 8) = iVar2;
  return;
}

