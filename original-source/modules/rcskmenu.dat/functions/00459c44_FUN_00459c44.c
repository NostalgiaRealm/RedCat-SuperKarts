/*
 * FUN_00459c44 at 00459c44
 * undefined FUN_00459c44(void)
 * Address ranges: 00459c44-00459da5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00459c44(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  undefined4 unaff_EBX;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  int *in_FS_OFFSET;
  undefined1 *puVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 *puStack_2c;
  undefined4 *puStack_28;
  int iStack_24;
  undefined *puStack_20;
  undefined4 *puStack_1c;
  
  puStack_1c = (undefined4 *)&stack0xfffffffc;
  iVar3 = 5;
  do {
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puStack_20 = &UNK_00459da6;
  iStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_24;
  puStack_28 = (undefined4 *)0x459c76;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&puStack_20);
  puStack_28 = (undefined4 *)0x459c81;
  FUN_004081c4(puStack_20,(int *)&puStack_1c);
  puStack_28 = puStack_1c;
  puStack_2c = (undefined4 *)&UNK_00459dc0;
  pcVar7 = "shellang.ini";
  FUN_00403e90((int *)&stack0xffffffe8,3);
  piVar1 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',unaff_EDI);
  uVar2 = (**(code **)(*piVar1 + 8))(piVar1,"language","language",0,pcVar7);
  *(undefined4 *)(param_1 + 0x1d4) = uVar2;
  uVar6 = 0;
  puVar5 = &stack0xffffffec;
  FUN_00407f60(uVar2,&iStack_24);
  (**(code **)*piVar1)(piVar1,"language",iStack_24,puVar5,uVar6);
  if (unaff_ESI != 0) {
    iVar3 = 0;
    bVar4 = 0;
    do {
      FUN_00407f60(iVar3,(int *)&stack0xfffffff0);
      (**(code **)*piVar1)(piVar1,unaff_ESI,unaff_EBX,&puStack_28,&UNK_00459dfc);
      FUN_00403ba4((int *)(param_1 + 4 + (uint)bVar4 * 4),puStack_28);
      iVar3 = iVar3 + 1;
      bVar4 = bVar4 + 1;
    } while (bVar4 != 0x53);
    FUN_00403dd8((int *)&stack0xffffffec,(undefined4 *)"_IMAGES");
    iVar3 = 0;
    bVar4 = 0;
    do {
      FUN_00407f60(iVar3,(int *)&stack0xfffffff0);
      (**(code **)*piVar1)(piVar1,unaff_ESI,unaff_EBX,&puStack_2c,0);
      FUN_00403ba4((int *)(param_1 + 0x150 + (uint)bVar4 * 4),puStack_2c);
      iVar3 = iVar3 + 1;
      bVar4 = bVar4 + 1;
    } while (bVar4 != 0x21);
    FUN_00402eac(piVar1);
  }
  *in_FS_OFFSET = (int)puVar5;
  FUN_00403b74((int *)&puStack_2c,8);
  return;
}

