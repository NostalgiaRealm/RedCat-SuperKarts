/*
 * FUN_00438ad0 at 00438ad0
 * undefined FUN_00438ad0(void)
 * Address ranges: 00438ad0-00438b71
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00438ad0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  while (iVar1 != 0) {
    iVar3 = *(int *)(param_1 + 0xc) + 4;
    *(int *)(param_1 + 0xc) = iVar3;
    *(int *)(param_1 + 0x2c) = iVar1 + -1;
    if ((iVar1 + -1 == 0) || (iVar3 == *(int *)(param_1 + 8))) {
      puVar2 = *(undefined4 **)(param_1 + 0x10);
      *(undefined4 **)(param_1 + 0x10) = puVar2 + 1;
      FUN_004bc150(*puVar2);
      if (*(int *)(param_1 + 0x2c) == 0) {
        *(undefined4 *)(param_1 + 4) = 0;
        *(undefined4 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0xc) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0;
        *(undefined4 *)(param_1 + 0x14) = 0;
        *(undefined4 *)(param_1 + 0x18) = 0;
        *(undefined4 *)(param_1 + 0x1c) = 0;
        *(undefined4 *)(param_1 + 0x20) = 0;
        FUN_004bc150(*(undefined4 *)(param_1 + 0x24));
      }
      else {
        iVar1 = **(int **)(param_1 + 0x10);
        *(int *)(param_1 + 4) = iVar1;
        *(int *)(param_1 + 8) = iVar1 + 0x1000;
        *(int *)(param_1 + 0xc) = iVar1;
        *(int **)(param_1 + 0x10) = *(int **)(param_1 + 0x10);
      }
    }
    iVar1 = *(int *)(param_1 + 0x2c);
  }
  return;
}

