/*
 * FUN_00410410 at 00410410
 * undefined __register FUN_00410410(int * param_1, int * param_2)
 * Address ranges: 00410410-00410495
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410410(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  FUN_00405490(param_2);
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)FUN_00403088(param_1,extraout_EDX,extraout_ECX);
    if (piVar1 == (int *)0x0) {
      uVar2 = FUN_00403024(param_1,(int)&PTR_FUN_0040e948);
      if (((char)uVar2 != '\0') && ((*(byte *)(param_1 + 8) & 0x10) != 0)) {
        FUN_00405490(param_2);
        (**(code **)(*param_1 + 0x28))();
      }
    }
    else {
      uVar2 = FUN_00403024(param_1,(int)&PTR_FUN_0040e948);
      if (((char)uVar2 == '\0') || ((*(byte *)(param_1 + 8) & 0x10) != 0)) {
        piVar3 = FUN_00405490(param_2);
        FUN_00410410(piVar1,piVar3);
      }
    }
  }
  return;
}

