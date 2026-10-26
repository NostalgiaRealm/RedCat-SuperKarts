/*
 * FUN_00453d10 at 00453d10
 * undefined FUN_00453d10(void)
 * Address ranges: 00453d10-00453da8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00453d10(int *param_1)

{
  int *piVar1;
  int *piVar2;
  RECT RStack_1c;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0xa8))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))(piVar1,*(undefined1 *)((int)param_1 + 0x131));
    piVar2 = (int *)FUN_0040303c(piVar1,(int)&PTR_FUN_00450238);
    FUN_00452714(piVar2,*(char *)((int)param_1 + 0x132));
    FUN_0040303c(piVar1,(int)&PTR_FUN_00450238);
    FUN_004526fc(piVar2,param_1[0x4d]);
    (**(code **)(*param_1 + 0xa4))(param_1,&RStack_1c);
    FUN_004186bc((int *)param_1[0x48],&RStack_1c,piVar1);
  }
  if ((*(byte *)(param_1 + 8) & 0x10) != 0) {
    (**(code **)(*param_1 + 0x40))(param_1,&RStack_1c);
    FUN_00418504((int *)param_1[0x48],&RStack_1c);
  }
  return;
}

