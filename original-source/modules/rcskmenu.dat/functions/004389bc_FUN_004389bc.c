/*
 * FUN_004389bc at 004389bc
 * undefined __register FUN_004389bc(void)
 * Address ranges: 004389bc-00438a3c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004389bc(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_stack_00000004;
  
  (**(code **)(**(int **)(in_stack_00000004 + -8) + 8))
            (*(int **)(in_stack_00000004 + -8),*(undefined4 *)(in_stack_00000004 + -0xc));
  uVar1 = (**(code **)(**(int **)(in_stack_00000004 + -0xc) + 0x14))();
  *(undefined4 *)(in_stack_00000004 + -0x10) = uVar1;
  iVar2 = (**(code **)(**(int **)(in_stack_00000004 + -0x14) + 0x14))();
  if (-1 < iVar2 + -1) {
    iVar4 = 0;
    do {
      uVar1 = (**(code **)(**(int **)(in_stack_00000004 + -0x14) + 0x18))
                        (*(int **)(in_stack_00000004 + -0x14),iVar4);
      iVar3 = (**(code **)(**(int **)(in_stack_00000004 + -0x14) + 0x18))
                        (*(int **)(in_stack_00000004 + -0x14),iVar4);
      (**(code **)(**(int **)(in_stack_00000004 + -8) + 0x38))
                (*(int **)(in_stack_00000004 + -8),*(undefined4 *)(iVar3 + 0x24),uVar1);
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_00403be8((int *)(in_stack_00000004 + -0x18),*(int *)(in_stack_00000004 + -4));
  return;
}

