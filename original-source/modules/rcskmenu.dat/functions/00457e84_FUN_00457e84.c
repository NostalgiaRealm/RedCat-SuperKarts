/*
 * FUN_00457e84 at 00457e84
 * undefined FUN_00457e84(void)
 * Address ranges: 00457e84-00457f9f;00457faa-00457fc5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00457e84(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar6;
  undefined4 uStack_5c;
  undefined *puStack_58;
  undefined1 *puStack_54;
  char *pcStack_50;
  undefined *puStack_4c;
  undefined *puStack_48;
  undefined4 uStack_44;
  undefined *puStack_40;
  undefined1 *puStack_3c;
  undefined4 uStack_38;
  undefined *puStack_34;
  undefined1 *puStack_30;
  int iStack_20;
  undefined *puStack_1c;
  int iStack_18;
  undefined4 *puStack_14;
  int iStack_10;
  int *piStack_c;
  int iStack_8;
  
  puStack_30 = &stack0xfffffffc;
  puStack_3c = &stack0xfffffffc;
  piStack_c = (int *)0x0;
  iStack_10 = 0;
  puStack_14 = (undefined4 *)0x0;
  iStack_18 = 0;
  puStack_1c = (undefined *)0x0;
  iStack_20 = 0;
  puStack_34 = &UNK_00457fe8;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_40 = &UNK_00457fc6;
  uStack_44 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_44;
  puStack_48 = (undefined *)0x457ec1;
  iStack_8 = param_1;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&puStack_1c);
  puStack_48 = (undefined *)0x457ecc;
  FUN_004081c4(puStack_1c,&iStack_18);
  puStack_48 = (undefined *)iStack_18;
  puStack_4c = &UNK_00458000;
  pcStack_50 = "shellimg.dat";
  puStack_54 = (undefined1 *)0x457ee6;
  FUN_00403e90((int *)&puStack_14,3);
  puStack_54 = (undefined1 *)0x457ef5;
  piStack_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',puStack_14);
  puStack_58 = &UNK_00457fa0;
  uStack_5c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_5c;
  uVar4 = 0;
  puStack_54 = &stack0xfffffffc;
  do {
    uVar6 = 0;
    FUN_00407f60(uVar4 & 0x7f,&iStack_20);
    uVar1 = (**(code **)(*piStack_c + 8))(piStack_c,"LOCKEDSTATE",iStack_20,uVar6);
    *(undefined1 *)(iStack_8 + 4 + (uVar4 & 0x7f)) = uVar1;
    uVar4 = uVar4 + 1;
  } while ((char)uVar4 != '\x06');
  bVar3 = 0;
  puVar5 = (undefined4 *)PTR_PTR_0047c7dc;
  do {
    uVar1 = (**(code **)(*piStack_c + 8))(piStack_c,"REQUIREDTYPES",*puVar5,0);
    *(undefined1 *)(iStack_8 + 0xf + (uint)bVar3) = uVar1;
    (**(code **)*piStack_c)(piStack_c,"LOCKS",*puVar5,&iStack_10,0);
    iVar2 = FUN_00403dd0(iStack_10);
    if (0 < iVar2) {
      uVar1 = FUN_0045427c(iStack_10);
      *(undefined1 *)(iStack_8 + 10 + (uint)bVar3) = uVar1;
    }
    bVar3 = bVar3 + 1;
    puVar5 = puVar5 + 1;
  } while (bVar3 != 5);
  *in_FS_OFFSET = uStack_5c;
  *in_FS_OFFSET = pcStack_50;
  puStack_48 = &UNK_00457fcd;
  if (piStack_c != (int *)0x0) {
    puStack_4c = (undefined *)0x457fc5;
    FUN_00402eac(piStack_c);
  }
  return;
}

