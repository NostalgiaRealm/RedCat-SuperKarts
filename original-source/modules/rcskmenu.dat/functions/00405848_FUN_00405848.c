/*
 * FUN_00405848 at 00405848
 * undefined __register FUN_00405848(undefined * param_1, undefined4 param_2)
 * Address ranges: 00405848-00405882
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00405848(undefined *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) != 0xd7b0) {
    if (3 < *(int *)(param_1 + 4) - 0xd7b0U) {
      FUN_00402804(0x66);
      return;
    }
    FUN_0040580c(param_1);
  }
  *(undefined4 *)(param_1 + 4) = param_2;
  iVar1 = (**(code **)(param_1 + 0x18))(param_1);
  if (iVar1 != 0) {
    FUN_00402804(iVar1);
  }
  return;
}

