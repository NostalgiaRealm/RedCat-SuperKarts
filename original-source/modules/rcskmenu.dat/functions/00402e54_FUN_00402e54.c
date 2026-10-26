/*
 * FUN_00402e54 at 00402e54
 * undefined __register FUN_00402e54(int * param_1)
 * Address ranges: 00402e54-00402e78
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402e54(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1;
  do {
    iVar1 = *(int *)(*piVar2 + -0x40);
    piVar2 = *(int **)(*piVar2 + -0x24);
    if (iVar1 != 0) {
      FUN_004043cc((int)param_1,iVar1);
    }
  } while (piVar2 != (int *)0x0);
  FUN_0040272c((int)param_1);
  return;
}

