/*
 * FUN_0046d710 at 0046d710
 * undefined FUN_0046d710(void)
 * Address ranges: 0046d710-0046d7fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046d710(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d04e8;
  iVar2 = *(int *)(param_1 + 0x60);
  local_4 = 0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  while (iVar2 != 0) {
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 0x1c;
    FUN_0040b4f0(1);
    iVar2 = *(int *)(param_1 + 0x60) + -1;
    *(int *)(param_1 + 0x60) = iVar2;
    if ((iVar2 == 0) || (*(int *)(param_1 + 0x40) == *(int *)(param_1 + 0x3c))) {
      puVar1 = *(undefined4 **)(param_1 + 0x44);
      *(undefined4 **)(param_1 + 0x44) = puVar1 + 1;
      FUN_004bc150(*puVar1);
      if (*(int *)(param_1 + 0x60) == 0) {
        *(undefined4 *)(param_1 + 0x38) = 0;
        *(undefined4 *)(param_1 + 0x3c) = 0;
        *(undefined4 *)(param_1 + 0x40) = 0;
        *(undefined4 *)(param_1 + 0x44) = 0;
        *(undefined4 *)(param_1 + 0x48) = 0;
        *(undefined4 *)(param_1 + 0x4c) = 0;
        *(undefined4 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x54) = 0;
        FUN_004bc150(*(undefined4 *)(param_1 + 0x58));
      }
      else {
        iVar2 = **(int **)(param_1 + 0x44);
        *(int *)(param_1 + 0x38) = iVar2;
        *(int *)(param_1 + 0x3c) = iVar2 + 0xff8;
        *(int *)(param_1 + 0x40) = iVar2;
        *(int **)(param_1 + 0x44) = *(int **)(param_1 + 0x44);
      }
    }
    iVar2 = *(int *)(param_1 + 0x60);
  }
  local_4 = 0xffffffff;
  FUN_004662d0();
  ExceptionList = local_c;
  return;
}

