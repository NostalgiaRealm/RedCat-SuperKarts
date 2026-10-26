/*
 * FUN_0042b370 at 0042b370
 * undefined __register FUN_0042b370(int * param_1, int * param_2, undefined4 param_3)
 * Address ranges: 0042b370-0042b479
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b370(int *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX;
  
  cVar5 = (char)param_3;
  FUN_0043ec20(param_1,(int)param_2,cVar5);
  if (cVar5 == '\0') {
    uVar2 = FUN_00403024(param_2,(int)&PTR_FUN_004260b4);
    if ((char)uVar2 == '\0') {
      if (((((*(byte *)(param_1 + 8) & 1) == 0) && (param_1[0x8c] == 0)) &&
          (param_1 == (int *)param_2[1])) &&
         (uVar2 = FUN_00403024(param_2,(int)&PTR_FUN_00435264), (char)uVar2 != '\0')) {
        FUN_0042c708(param_1,param_2);
      }
    }
    else {
      if (param_1[0xb2] == 0) {
        iVar3 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX_00);
        param_1[0xb2] = iVar3;
      }
      FUN_0040f504((int *)param_1[0xb2],(int)param_2);
    }
  }
  else if (cVar5 == '\x01') {
    piVar1 = (int *)param_1[0xb2];
    uVar2 = extraout_ECX;
    if ((piVar1 == (int *)0x0) ||
       (uVar4 = FUN_00403024(param_2,(int)&PTR_FUN_004260b4), uVar2 = extraout_ECX_01,
       (char)uVar4 == '\0')) {
      if (param_2 == (int *)param_1[0x8c]) {
        FUN_0042c708(param_1,(int *)0x0);
        uVar2 = extraout_ECX_02;
      }
      if (param_2 == (int *)param_1[0x90]) {
        FUN_0042c6e0(param_1,0,uVar2);
        uVar2 = extraout_ECX_03;
      }
      if (param_2 == (int *)param_1[0x92]) {
        FUN_0042c6bc((int)param_1,(int *)0x0,uVar2);
      }
    }
    else {
      FUN_0040f848(piVar1,(int)param_2);
    }
  }
  if (param_1[0x8e] != 0) {
    (**(code **)(*(int *)param_1[0x8e] + 0x10))((int *)param_1[0x8e],param_2,param_3);
  }
  return;
}

