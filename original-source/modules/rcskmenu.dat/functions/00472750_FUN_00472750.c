/*
 * FUN_00472750 at 00472750
 * undefined __register FUN_00472750(void)
 * Address ranges: 00472750-00472857;0047286c-00472889
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00472750(void)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uStack_48;
  undefined1 *puStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  int local_18;
  undefined4 *local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  puStack_28 = &stack0xfffffffc;
  puStack_34 = &stack0xfffffffc;
  puStack_40 = &stack0xfffffffc;
  local_8 = (int *)0x0;
  local_c = 0;
  local_10 = (int *)0x0;
  local_14 = (undefined4 *)0x0;
  local_18 = 0;
  puStack_2c = &LAB_004728b4;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_38 = &LAB_0047288a;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  puStack_44 = &LAB_00472858;
  uStack_48 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_48;
  FUN_00403e1c((int *)&local_14,*(undefined4 **)PTR_DAT_0047c694,(undefined4 *)"race.ini");
  local_8 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_14);
  local_10 = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  iVar1 = (**(code **)(*local_8 + 8))(local_8,"CHARDATA","count");
  if ((0 < iVar1) && (-1 < iVar1 + -1)) {
    iVar3 = 0;
    do {
      uVar5 = 0;
      piVar4 = &local_c;
      FUN_00407f60(iVar3,&local_18);
      (**(code **)*local_8)(local_8,"RACERS",local_18,piVar4,uVar5);
      iVar2 = FUN_00403dd0(local_c);
      if (0 < iVar2) {
        FUN_00454510((int)local_10,local_c);
        uVar5 = FUN_004546b4((int)local_10,1);
        (&DAT_0047e2f4)[iVar3 * 9] = uVar5;
        uVar5 = FUN_004546b4((int)local_10,2);
        (&DAT_0047e2f8)[iVar3 * 9] = uVar5;
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  *in_FS_OFFSET = 0;
  *in_FS_OFFSET = puStack_40;
  puStack_38 = &LAB_00472891;
  uStack_3c = 0x472881;
  FUN_00402eac(local_8);
  uStack_3c = 0x472889;
  FUN_00402eac(local_10);
  return;
}

