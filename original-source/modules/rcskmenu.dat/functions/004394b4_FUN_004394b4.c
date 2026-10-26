/*
 * FUN_004394b4 at 004394b4
 * undefined4 __register FUN_004394b4(int * param_1)
 * Address ranges: 004394b4-00439527
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004394b4(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)FUN_004393f8((int)param_1);
  if (piVar2 != (int *)0x0) {
    if ((*(byte *)(piVar2 + 8) & 0x10) == 0) {
      FUN_0043855c((int)piVar2);
    }
    (**(code **)(*piVar2 + 0x40))();
    cVar1 = FUN_00438ba0((int)piVar2,'\0');
    if ((cVar1 != '\0') || (cVar1 = FUN_00439070((int)piVar2,'\0'), cVar1 != '\0')) {
      FUN_00436650(piVar2);
    }
    return 1;
  }
  if ((*(byte *)(param_1 + 8) & 0x10) != 0) {
    return 0;
  }
  uVar3 = FUN_00403024(param_1,(int)&PTR_FUN_0043553c);
  if ((char)uVar3 == '\0') {
    return 0;
  }
  FUN_0043855c(param_1[10]);
  return 0;
}

