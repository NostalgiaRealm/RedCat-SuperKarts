/*
 * FUN_0040580c at 0040580c
 * undefined __register FUN_0040580c(undefined * param_1)
 * Address ranges: 0040580c-00405845
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040580c(undefined *param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) != 0xd7b1) {
    if (2 < *(int *)(param_1 + 4) - 0xd7b1U) {
      if (param_1 == &DAT_0047d050) {
        return;
      }
      iVar1 = 0x67;
      goto LAB_00405831;
    }
    iVar1 = (**(code **)(param_1 + 0x1c))();
    if (iVar1 != 0) goto LAB_00405831;
  }
  iVar1 = (**(code **)(param_1 + 0x24))(param_1);
  if (iVar1 == 0) {
    return;
  }
LAB_00405831:
  FUN_00402804(iVar1);
  return;
}

