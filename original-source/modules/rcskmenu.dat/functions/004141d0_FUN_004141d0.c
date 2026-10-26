/*
 * FUN_004141d0 at 004141d0
 * undefined __register FUN_004141d0(undefined4 param_1, undefined4 param_2, uint param_3, uint param_4)
 * Address ranges: 004141d0-0041422e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004141d0(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  char cVar1;
  bool bVar2;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint uVar3;
  uint extraout_ECX_01;
  uint uVar4;
  uint extraout_ECX_02;
  uint extraout_ECX_03;
  uint extraout_ECX_04;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 uVar5;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  int *piVar6;
  
  piVar6 = (int *)(param_4 - 4);
  while( true ) {
    bVar2 = FUN_00412660(*piVar6,param_2,param_3);
    if (bVar2) break;
    cVar1 = FUN_00412910(*piVar6,extraout_EDX_05,extraout_ECX_04);
    uVar3 = extraout_ECX;
    uVar5 = extraout_EDX;
    if ((byte)(cVar1 - 2U) < 3) {
      FUN_00414230(*piVar6,extraout_EDX,extraout_ECX);
      uVar3 = extraout_ECX_00;
      uVar5 = extraout_EDX_00;
    }
    uVar4 = param_4;
    FUN_00414154(1,uVar5,uVar3,param_4);
    uVar5 = extraout_EDX_01;
    while( true ) {
      bVar2 = FUN_00412660(*piVar6,uVar5,uVar4);
      if (bVar2) break;
      FUN_00414398(*piVar6,extraout_EDX_03,extraout_ECX_02);
      uVar4 = extraout_ECX_01;
      uVar5 = extraout_EDX_02;
    }
    FUN_004133a8(*piVar6,extraout_EDX_03,extraout_ECX_02);
    param_3 = extraout_ECX_03;
    param_2 = extraout_EDX_04;
  }
  FUN_004133a8(*piVar6,extraout_EDX_05,extraout_ECX_04);
  return;
}

