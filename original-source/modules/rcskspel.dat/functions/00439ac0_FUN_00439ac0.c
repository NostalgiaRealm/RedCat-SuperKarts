/*
 * FUN_00439ac0 at 00439ac0
 * undefined FUN_00439ac0(void)
 * Address ranges: 00439ac0-00439bf6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00439ac0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  piVar1 = (int *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x1c) == *(int *)(param_1 + 0x14)) {
    puVar2 = *(undefined4 **)(param_1 + 0x20);
    *(undefined4 **)(param_1 + 0x20) = puVar2 + -1;
    FUN_004bc150(*puVar2);
    if (*(int *)(param_1 + 0x2c) == 0) {
      if (*(undefined4 **)(param_1 + 0x10) == *(undefined4 **)(param_1 + 0x20)) {
        FUN_004bc150(**(undefined4 **)(param_1 + 0x10));
      }
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *piVar1 = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x20) = 0;
      FUN_004bc150(*(undefined4 *)(param_1 + 0x24));
    }
    else {
      iVar3 = **(int **)(param_1 + 0x20);
      *piVar1 = iVar3;
      *(int *)(param_1 + 0x18) = iVar3 + 0x1000;
      *(int *)(param_1 + 0x1c) = iVar3 + 0x1000;
      *(int **)(param_1 + 0x20) = *(int **)(param_1 + 0x20);
    }
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -4;
  }
  iVar3 = *(int *)(param_1 + 0x2c) + -1;
  *(int *)(param_1 + 0x2c) = iVar3;
  if (iVar3 == 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x20);
    *(undefined4 **)(param_1 + 0x20) = puVar2 + -1;
    FUN_004bc150(*puVar2);
    if (*(int *)(param_1 + 0x2c) == 0) {
      if (*(undefined4 **)(param_1 + 0x10) == *(undefined4 **)(param_1 + 0x20)) {
        FUN_004bc150(**(undefined4 **)(param_1 + 0x10));
      }
      *(undefined4 *)(param_1 + 4) = 0;
      *piVar1 = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0;
      FUN_004bc150(*(undefined4 *)(param_1 + 0x24));
      return;
    }
    iVar3 = **(int **)(param_1 + 0x20);
    *piVar1 = iVar3;
    *(int *)(param_1 + 0x18) = iVar3 + 0x1000;
    *(int *)(param_1 + 0x1c) = iVar3 + 0x1000;
    *(int **)(param_1 + 0x20) = *(int **)(param_1 + 0x20);
  }
  return;
}

