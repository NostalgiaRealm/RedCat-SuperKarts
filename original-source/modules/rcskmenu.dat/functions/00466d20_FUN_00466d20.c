/*
 * FUN_00466d20 at 00466d20
 * undefined __register FUN_00466d20(int * param_1, int * param_2)
 * Address ranges: 00466d20-00466d50
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466d20(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  FUN_00441a54(param_1,param_2);
  piVar1 = (int *)param_2[0xb];
  uVar2 = FUN_00403024(piVar1,(int)&PTR_FUN_00464ed4);
  if ((char)uVar2 != '\0') {
    FUN_00466d7c(param_1,piVar1);
  }
  return;
}

