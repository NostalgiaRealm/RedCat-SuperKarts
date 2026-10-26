/*
 * FUN_004057e5 at 004057e5
 * undefined __register FUN_004057e5(int param_1)
 * Address ranges: 004057e5-00405809
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004057e5(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) == 0xd7b2) {
    iVar1 = (**(code **)(param_1 + 0x20))();
    if (iVar1 != 0) {
LAB_00405805:
      FUN_00402804(iVar1);
      return;
    }
  }
  else if (*(int *)(param_1 + 4) != 0xd7b1) {
    iVar1 = 0x67;
    goto LAB_00405805;
  }
  return;
}

