/*
 * FUN_00413014 at 00413014
 * undefined __register FUN_00413014(int * param_1, int * param_2, uint param_3)
 * Address ranges: 00413014-004130d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00413014(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  uint extraout_ECX;
  uint extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  uint extraout_ECX_03;
  uint extraout_ECX_04;
  uint uVar5;
  uint extraout_ECX_05;
  int *extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  int *extraout_EDX_02;
  int *extraout_EDX_03;
  int *piVar6;
  undefined4 extraout_EDX_04;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  
  piVar6 = param_2;
  while( true ) {
    puStack_20 = (undefined1 *)0x413036;
    bVar3 = FUN_00412660((int)param_1,piVar6,param_3);
    if (bVar3) break;
    puStack_20 = (undefined1 *)0x41302e;
    FUN_0041350c(param_1,param_2);
    param_3 = extraout_ECX;
    piVar6 = extraout_EDX;
  }
  puStack_20 = (undefined1 *)0x413042;
  FUN_004133a8((int)param_1,extraout_EDX_00,extraout_ECX_00);
  iVar1 = param_1[0xb];
  iVar2 = param_1[10];
  puStack_20 = (undefined1 *)0x41305f;
  iVar4 = FUN_00403088(param_2,extraout_EDX_01,extraout_ECX_01);
  param_1[0xb] = iVar4;
  puStack_24 = &LAB_004130d6;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_20 = &stack0xfffffffc;
  iVar4 = FUN_00403088(param_2,param_1,extraout_ECX_02);
  param_1[10] = iVar4;
  uVar5 = extraout_ECX_03;
  piVar6 = extraout_EDX_02;
  if (iVar4 == 0) {
    param_1[10] = param_1[6];
    piVar6 = param_1;
  }
  while( true ) {
    bVar3 = FUN_00412660((int)param_1,piVar6,uVar5);
    if (bVar3) break;
    FUN_00412dcc(param_1,(int *)0x0);
    uVar5 = extraout_ECX_04;
    piVar6 = extraout_EDX_03;
  }
  FUN_004133a8((int)param_1,extraout_EDX_04,extraout_ECX_05);
  *in_FS_OFFSET = uStack_28;
  param_1[0xb] = iVar1;
  param_1[10] = iVar2;
  return;
}

