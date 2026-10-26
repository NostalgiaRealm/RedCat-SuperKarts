/*
 * FUN_00410754 at 00410754
 * byte __register FUN_00410754(void)
 * Address ranges: 00410754-004107a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte FUN_00410754(void)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int in_stack_00000004;
  
  piVar1 = *(int **)(*(int *)(in_stack_00000004 + -4) + 0x20);
  if (piVar1 == (int *)0x0) {
    iVar4 = (**(code **)(**(int **)(in_stack_00000004 + -8) + 0x14))();
    bVar2 = 0 < iVar4;
  }
  else {
    bVar2 = 1;
    uVar3 = FUN_00403024(piVar1,(int)&PTR_FUN_0040e1c8);
    if ((char)uVar3 != '\0') {
      bVar2 = FUN_0041080c(*(int **)(in_stack_00000004 + -8),piVar1);
      bVar2 = bVar2 ^ 1;
    }
  }
  return bVar2;
}

