/*
 * FUN_0041eec0 at 0041eec0
 * undefined4 __fastcall FUN_0041eec0(int param_1)
 * Address ranges: 0041eec0-0041ef0c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0041eec0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 4) == '\0') {
    uVar2 = FUN_004015a6((byte *)s__s__d____Not_initialized_for_pla_00437000);
    return uVar2 & 0xffffff00;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0xd) + 0x1c))(*(int **)(param_1 + 0xd),1);
  if (-1 < iVar1) {
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  uVar2 = FUN_004015a6((byte *)s__s__d____Couldn_t_play_file_00437028);
  return uVar2 & 0xffffff00;
}

