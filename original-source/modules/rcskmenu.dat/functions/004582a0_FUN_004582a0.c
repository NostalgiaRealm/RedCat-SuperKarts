/*
 * FUN_004582a0 at 004582a0
 * undefined FUN_004582a0(void)
 * Address ranges: 004582a0-004583b8;004583c3-004583ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004582a0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 unaff_EBX;
  int iVar3;
  undefined4 unaff_ESI;
  undefined4 *unaff_EDI;
  int *in_FS_OFFSET;
  int *piVar4;
  undefined4 uVar5;
  int iStack_4c;
  undefined *puStack_48;
  undefined1 *puStack_44;
  char *pcStack_40;
  undefined *puStack_3c;
  undefined1 *puStack_38;
  int iStack_34;
  undefined *puStack_30;
  undefined1 *puStack_2c;
  int iStack_28;
  undefined *puStack_24;
  undefined1 *puStack_20;
  int iStack_10;
  int *piStack_c;
  int *piStack_8;
  
  puStack_20 = &stack0xfffffffc;
  puStack_2c = &stack0xfffffffc;
  iStack_10 = 4;
  do {
    piStack_8 = (int *)0x0;
    iStack_10 = iStack_10 + -1;
  } while (iStack_10 != 0);
  puStack_24 = &UNK_0045840f;
  iStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_28;
  puStack_30 = &UNK_004583ed;
  iStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_34;
  puStack_38 = (undefined1 *)0x4582e0;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&puStack_24);
  puStack_38 = (undefined1 *)0x4582eb;
  FUN_004081c4(puStack_24,(int *)&puStack_20);
  puStack_38 = puStack_20;
  puStack_3c = &UNK_00458428;
  pcStack_40 = "shellimg.dat";
  puStack_44 = (undefined1 *)0x458305;
  FUN_00403e90((int *)&stack0xffffffe4,3);
  puStack_44 = (undefined1 *)0x458314;
  piStack_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',unaff_EDI);
  puStack_48 = &UNK_004583b9;
  iStack_4c = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_4c;
  puStack_44 = &stack0xfffffffc;
  piStack_8 = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  iVar3 = 0;
  do {
    uVar5 = 0;
    piVar4 = &iStack_10;
    FUN_00407f60(iVar3,&iStack_28);
    (**(code **)*piStack_c)(piStack_c,"ADVSEQUENCE",iStack_28,piVar4,uVar5);
    iVar2 = FUN_00403dd0(iStack_10);
    if (0 < iVar2) {
      FUN_00454510((int)piStack_8,iStack_10);
      FUN_0045471c((int)piStack_8,0,(int *)&stack0xffffffec);
      FUN_0045471c((int)piStack_8,1,(int *)&stack0xffffffe8);
      uVar1 = FUN_0045427c(unaff_EBX);
      *(undefined1 *)(param_1 + 4 + iVar3 * 2) = uVar1;
      uVar1 = FUN_004542e8(unaff_ESI);
      *(undefined1 *)(param_1 + 5 + iVar3 * 2) = uVar1;
      *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x1e);
  *in_FS_OFFSET = iStack_4c;
  *in_FS_OFFSET = (int)pcStack_40;
  puStack_38 = &UNK_004583f4;
  if (piStack_8 != (int *)0x0) {
    puStack_3c = (undefined *)0x4583de;
    FUN_00402eac(piStack_8);
  }
  if (piStack_c != (int *)0x0) {
    puStack_3c = (undefined *)0x4583ec;
    FUN_00402eac(piStack_c);
  }
  return;
}

