/*
 * FUN_004389b0 at 004389b0
 * undefined FUN_004389b0(void)
 * Address ranges: 004389b0-00438acf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004389b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_c = ExceptionList;
  puStack_8 = &LAB_004cd518;
  iVar1 = *(int *)(param_1 + 0x3c);
  local_4 = 0;
  ExceptionList = &local_c;
  *(undefined ***)(param_1 + 0x38) = &PTR_FUN_004d265c;
  if (iVar1 != 0) {
    iVar4 = *(int *)(iVar1 + 8);
    for (iVar3 = *(int *)(iVar1 + 4); iVar3 != iVar4; iVar3 = iVar3 + 0x14) {
      FUN_0040b4b0();
    }
    FUN_004bc150(*(undefined4 *)(iVar1 + 4));
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_004bc150(iVar1);
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  iVar1 = *(int *)(param_1 + 0x30);
  while (iVar1 != 0) {
    iVar4 = *(int *)(param_1 + 0x10) + 4;
    *(int *)(param_1 + 0x10) = iVar4;
    *(int *)(param_1 + 0x30) = iVar1 + -1;
    if ((iVar1 + -1 == 0) || (iVar4 == *(int *)(param_1 + 0xc))) {
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
  ExceptionList = local_c;
  return;
}

