/*
 * FUN_00438b80 at 00438b80
 * undefined FUN_00438b80(void)
 * Address ranges: 00438b80-00438c0b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00438b80(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc) + 4;
  iVar2 = *(int *)(param_1 + 0x2c) + -1;
  *(int *)(param_1 + 0xc) = iVar3;
  *(int *)(param_1 + 0x2c) = iVar2;
  if ((iVar2 == 0) || (iVar3 == *(int *)(param_1 + 8))) {
    puVar1 = *(undefined4 **)(param_1 + 0x10);
    *(undefined4 **)(param_1 + 0x10) = puVar1 + 1;
    FUN_004bc150(*puVar1);
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
      return;
    }
    iVar2 = **(int **)(param_1 + 0x10);
    *(int *)(param_1 + 4) = iVar2;
    *(int *)(param_1 + 8) = iVar2 + 0x1000;
    *(int *)(param_1 + 0xc) = iVar2;
    *(int **)(param_1 + 0x10) = *(int **)(param_1 + 0x10);
  }
  return;
}

