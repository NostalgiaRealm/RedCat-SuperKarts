/*
 * FUN_0041ef10 at 0041ef10
 * undefined4 __fastcall FUN_0041ef10(int param_1)
 * Address ranges: 0041ef10-0041ef5c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0041ef10(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 4) == '\0') {
    uVar2 = FUN_004015a6((byte *)s__s__d____Not_initialized_00437048);
    return uVar2 & 0xffffff00;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0xd) + 0x1c))(*(int **)(param_1 + 0xd),0);
  if (-1 < iVar1) {
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  uVar2 = FUN_004015a6((byte *)s__s__d____Couldn_t_stop_file_00437064);
  return uVar2 & 0xffffff00;
}

