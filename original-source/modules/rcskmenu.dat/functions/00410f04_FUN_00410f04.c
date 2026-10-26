/*
 * FUN_00410f04 at 00410f04
 * undefined FUN_00410f04(void)
 * Address ranges: 00410f04-00410f82
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410f04(int *param_1,int param_2)

{
  bool bVar1;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint uVar2;
  uint extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  int iStack_10;
  int iStack_c;
  int *piStack_8;
  
  puStack_14 = &stack0xfffffffc;
  iStack_10 = 0;
  puStack_18 = &LAB_00410fa8;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puStack_20 = (undefined1 *)0x410f2b;
  iStack_c = param_2;
  piStack_8 = param_1;
  FUN_004133a0(param_2,param_2,0);
  puStack_20 = (undefined1 *)0x410f33;
  FUN_0041073c(piStack_8);
  puStack_24 = &LAB_00410f83;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_20 = &stack0xfffffffc;
  (**(code **)(*piStack_8 + 0x40))();
  uVar2 = extraout_ECX;
  uVar3 = extraout_EDX;
  while( true ) {
    bVar1 = FUN_00412660(iStack_c,uVar3,uVar2);
    if (bVar1) break;
    FUN_00414028(iStack_c,&iStack_10,extraout_ECX_01);
    (**(code **)(*piStack_8 + 0x34))(piStack_8,iStack_10);
    uVar2 = extraout_ECX_00;
    uVar3 = extraout_EDX_00;
  }
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00410f8a;
  puStack_24 = (undefined1 *)0x410f82;
  FUN_004107f8(piStack_8);
  return;
}

