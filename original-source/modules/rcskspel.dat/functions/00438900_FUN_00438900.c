/*
 * FUN_00438900 at 00438900
 * undefined FUN_00438900(void)
 * Address ranges: 00438900-004389a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00438900(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x30);
  while (iVar1 != 0) {
    iVar3 = *(int *)(param_1 + 0x10) + 4;
    *(int *)(param_1 + 0x10) = iVar3;
    *(int *)(param_1 + 0x30) = iVar1 + -1;
    if ((iVar1 + -1 == 0) || (iVar3 == *(int *)(param_1 + 0xc))) {
      puVar2 = *(undefined4 **)(param_1 + 0x14);
      *(undefined4 **)(param_1 + 0x14) = puVar2 + 1;
      FUN_004bc150(*puVar2);
      if (*(int *)(param_1 + 0x30) == 0) {
        *(undefined4 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0xc) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0;
        *(undefined4 *)(param_1 + 0x14) = 0;
        *(undefined4 *)(param_1 + 0x18) = 0;
        *(undefined4 *)(param_1 + 0x1c) = 0;
        *(undefined4 *)(param_1 + 0x20) = 0;
        *(undefined4 *)(param_1 + 0x24) = 0;
        FUN_004bc150(*(undefined4 *)(param_1 + 0x28));
      }
      else {
        iVar1 = **(int **)(param_1 + 0x14);
        *(int *)(param_1 + 8) = iVar1;
        *(int *)(param_1 + 0xc) = iVar1 + 0x1000;
        *(int *)(param_1 + 0x10) = iVar1;
        *(int **)(param_1 + 0x14) = *(int **)(param_1 + 0x14);
      }
    }
    iVar1 = *(int *)(param_1 + 0x30);
  }
  return;
}

