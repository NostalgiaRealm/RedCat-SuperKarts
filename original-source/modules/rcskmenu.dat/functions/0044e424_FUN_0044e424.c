/*
 * FUN_0044e424 at 0044e424
 * undefined __register FUN_0044e424(int param_1)
 * Address ranges: 0044e424-0044e462
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044e424(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_0044df58(*(int *)(param_1 + 8));
  iVar1 = iVar1 + -1;
  if (-1 < iVar1) {
    do {
      piVar2 = (int *)(**(code **)**(undefined4 **)(param_1 + 8))
                                (*(undefined4 **)(param_1 + 8),iVar1);
      puVar3 = (undefined4 *)FUN_0040303c(piVar2,(int)&PTR_FUN_0044e0a8);
      (**(code **)*puVar3)();
      (**(code **)(**(int **)(param_1 + 8) + 0x10))(*(int **)(param_1 + 8),iVar1);
      iVar1 = iVar1 + -1;
    } while (iVar1 != -1);
  }
  return;
}

