/*
 * FUN_0043eb8c at 0043eb8c
 * undefined __register FUN_0043eb8c(int * param_1, int * param_2)
 * Address ranges: 0043eb8c-0043ec1c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043eb8c(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint uVar3;
  
  *(ushort *)(param_1 + 0x11) = *(ushort *)(param_1 + 0x11) | 8;
  piVar1 = (int *)param_2[0xb];
  uVar2 = FUN_00403024(piVar1,(int)&PTR_FUN_0043be00);
  uVar3 = extraout_ECX;
  if ((char)uVar2 != '\0') {
    (**(code **)(*param_1 + 0x60))(param_1,piVar1);
    uVar3 = extraout_ECX_00;
  }
  FUN_00414be4(param_1,param_2,uVar3);
  *(ushort *)(param_1 + 0x11) = *(ushort *)(param_1 + 0x11) & 0xfff7;
  if (param_1[9] != 0) {
    FUN_004405f0((int)param_1,0xb009,0,0);
    FUN_004405f0((int)param_1,0xb008,0,0);
    FUN_004405f0((int)param_1,0xb023,0,0);
    FUN_004405f0((int)param_1,0xb035,0,0);
    FUN_004405f0((int)param_1,0xb03d,0,0);
  }
  return;
}

