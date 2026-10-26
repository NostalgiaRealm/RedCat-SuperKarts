/*
 * FUN_0040f6a3 at 0040f6a3
 * undefined4 __stdcall FUN_0040f6a3(int param_1)
 * Address ranges: 0040f6a3-0040f71b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040f6a3(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 0x54);
  FUN_004015a6((byte *)s_mode__d__d__d_0043312c);
  iVar3 = FUN_0040f145(iVar3,iVar1,iVar2);
  if (iVar3 != -1) {
    *(undefined4 *)(&DAT_0042c378 + iVar3 * 0x14) = 1;
  }
  return 1;
}

