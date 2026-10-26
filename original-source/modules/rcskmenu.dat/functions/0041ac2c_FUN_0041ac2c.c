/*
 * FUN_0041ac2c at 0041ac2c
 * bool __register FUN_0041ac2c(void)
 * Address ranges: 0041ac2c-0041aca7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0041ac2c(void)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  bool bVar5;
  int in_stack_00000004;
  
  piVar1 = *(int **)(*(int *)(in_stack_00000004 + -4) + 0x20);
  if (piVar1 == (int *)0x0) {
    bVar5 = *(int *)(*(int *)(in_stack_00000004 + -8) + 4) != 0;
  }
  else {
    bVar5 = true;
    uVar4 = FUN_00403024(piVar1,(int)&PTR_FUN_00416588);
    if ((char)uVar4 != '\0') {
      if ((*(int *)(*(int *)(in_stack_00000004 + -8) + 4) == piVar1[1]) ||
         (((piVar2 = *(int **)(*(int *)(in_stack_00000004 + -8) + 4), piVar2 != (int *)0x0 &&
           (piVar1[1] != 0)) &&
          (cVar3 = (**(code **)(*piVar2 + 0x18))(piVar2,piVar1[1]), cVar3 != '\0')))) {
        bVar5 = false;
      }
      else {
        bVar5 = true;
      }
    }
  }
  return bVar5;
}

