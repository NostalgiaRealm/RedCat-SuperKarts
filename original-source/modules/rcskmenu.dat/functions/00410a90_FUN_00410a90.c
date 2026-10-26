/*
 * FUN_00410a90 at 00410a90
 * undefined FUN_00410a90(void)
 * Address ranges: 00410a90-00410b66
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410a90(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  int iStack_1c;
  undefined4 *puStack_18;
  int iStack_14;
  int iStack_10;
  int *piStack_c;
  int *piStack_8;
  
  puStack_2c = &stack0xfffffffc;
  iStack_1c = 0;
  puStack_18 = (undefined4 *)0x0;
  puStack_30 = &LAB_00410b67;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  piStack_c = param_2;
  piStack_8 = param_1;
  iVar1 = (**(code **)(*param_1 + 0x14))();
  uVar3 = 0;
  iStack_14 = iVar1;
  if (-1 < iVar1 + -1) {
    iStack_10 = 0;
    do {
      (**(code **)(*piStack_8 + 0xc))(piStack_8,iStack_10,&iStack_1c);
      iVar2 = FUN_00403dd0(iStack_1c);
      uVar3 = uVar3 + iVar2 + 2;
      iStack_10 = iStack_10 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  FUN_00403c38(piStack_c,(undefined4 *)0x0,uVar3);
  puVar4 = (undefined4 *)*piStack_c;
  if (-1 < iStack_14 + -1) {
    iStack_10 = 0;
    iVar1 = iStack_14;
    do {
      (**(code **)(*piStack_8 + 0xc))(piStack_8,iStack_10,&puStack_18);
      uVar3 = FUN_00403dd0((int)puStack_18);
      if (uVar3 != 0) {
        FUN_0040282c(puStack_18,puVar4,uVar3);
        puVar4 = (undefined4 *)((int)puVar4 + uVar3);
      }
      *(undefined1 *)puVar4 = 0xd;
      *(undefined1 *)((int)puVar4 + 1) = 10;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
      iStack_10 = iStack_10 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  *in_FS_OFFSET = uStack_34;
  puStack_2c = &LAB_00410b6e;
  puStack_30 = (undefined1 *)0x410b66;
  FUN_00403b74(&iStack_1c,2);
  return;
}

