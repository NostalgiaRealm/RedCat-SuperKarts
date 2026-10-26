/*
 * FUN_00410614 at 00410614
 * undefined FUN_00410614(void)
 * Address ranges: 00410614-0041069d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410614(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_10;
  int *piStack_c;
  int *piStack_8;
  
  puStack_20 = &stack0xfffffffc;
  uStack_10 = 0;
  puStack_24 = &LAB_004106bb;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_2c = (undefined1 *)0x41063e;
  piStack_c = param_2;
  piStack_8 = param_1;
  FUN_0041073c(param_1);
  puStack_30 = &LAB_0041069e;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  puStack_2c = &stack0xfffffffc;
  iVar2 = (**(code **)(*piStack_c + 0x14))();
  if (-1 < iVar2 + -1) {
    iVar4 = 0;
    do {
      (**(code **)(*piStack_c + 0xc))(piStack_c,iVar4,&uStack_10);
      uVar1 = uStack_10;
      uVar3 = (**(code **)(*piStack_c + 0x18))(piStack_c,iVar4);
      (**(code **)(*piStack_8 + 0x38))(piStack_8,uVar1,uVar3);
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  *in_FS_OFFSET = uStack_34;
  puStack_2c = &LAB_004106a5;
  puStack_30 = (undefined1 *)0x41069d;
  FUN_004107f8(piStack_8);
  return;
}

