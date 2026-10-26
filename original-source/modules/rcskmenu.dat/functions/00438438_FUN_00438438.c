/*
 * FUN_00438438 at 00438438
 * undefined __register FUN_00438438(int * param_1, undefined4 param_2, undefined4 param_3, char param_4)
 * Address ranges: 00438438-0043848e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00438438(int *param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((param_4 != '\0') && ((param_1[10] != 0 || (param_1[0x18] != 0)))) {
    FUN_00436650(param_1);
  }
  if ((int *)param_1[0x16] == (int *)0x0) {
    piVar1 = (int *)param_1[1];
    uVar2 = FUN_00403024(piVar1,(int)&PTR_FUN_00435264);
    if ((char)uVar2 != '\0') {
      FUN_00439fcc(piVar1);
    }
  }
  else {
    FUN_00438438((int *)param_1[0x16],param_1,param_3,'\0');
  }
  return;
}

