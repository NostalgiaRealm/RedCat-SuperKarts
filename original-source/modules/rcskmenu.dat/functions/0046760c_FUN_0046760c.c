/*
 * FUN_0046760c at 0046760c
 * undefined __register FUN_0046760c(int * param_1, char param_2)
 * Address ranges: 0046760c-0046765d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046760c(int *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  WPARAM WVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  
  iVar2 = FUN_00467318((int)param_1,param_1[0x91],param_2,'\x01');
  if ((iVar2 != 0) && (iVar2 != param_1[0x91])) {
    cVar1 = FUN_00403088(param_1,extraout_EDX,extraout_ECX);
    if (cVar1 != '\0') {
      WVar3 = FUN_00466cc0(iVar2);
      FUN_0046655c(param_1,WVar3);
      FUN_00403088(param_1,extraout_EDX_00,extraout_ECX_00);
    }
  }
  return;
}

