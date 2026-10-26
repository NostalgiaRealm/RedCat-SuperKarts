/*
 * FUN_00419f5c at 00419f5c
 * uint __register FUN_00419f5c(void)
 * Address ranges: 00419f5c-00419fb2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00419f5c(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_stack_00000004;
  
  if (*(int *)(*(int *)(in_stack_00000004 + -4) + 0x20) == 0) {
    uVar3 = (**(code **)(**(int **)(in_stack_00000004 + -8) + 0x1c))();
    return uVar3 ^ 1;
  }
  piVar1 = *(int **)(*(int *)(in_stack_00000004 + -4) + 0x20);
  uVar2 = FUN_00403024(piVar1,(int)&PTR_FUN_004164a4);
  if (((char)uVar2 != '\0') &&
     (uVar2 = (**(code **)(**(int **)(in_stack_00000004 + -8) + 0x18))
                        (*(int **)(in_stack_00000004 + -8),piVar1), (char)uVar2 != '\0')) {
    return 0;
  }
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}

