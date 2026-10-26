/*
 * FUN_004408fc at 004408fc
 * undefined __register FUN_004408fc(int param_1)
 * Address ranges: 004408fc-00440965
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004408fc(int param_1)

{
  int iVar1;
  
  if (*(short *)(param_1 + 0x10a) != 0) {
    iVar1 = FUN_0043ea94(param_1);
    if (iVar1 != 0) {
      iVar1 = FUN_0043ea94(param_1);
      if (*(int *)(iVar1 + 0x30) != *(int *)(param_1 + 0x108)) {
        (**(code **)(param_1 + 0x108))(*(undefined4 *)(param_1 + 0x10c),param_1);
        return;
      }
    }
  }
  if (((*(byte *)(param_1 + 0x20) & 0x10) == 0) && (*(int *)(param_1 + 0x5c) != 0)) {
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x18))();
  }
  else if (*(short *)(param_1 + 0x10a) != 0) {
    (**(code **)(param_1 + 0x108))(*(undefined4 *)(param_1 + 0x10c),param_1);
  }
  return;
}

