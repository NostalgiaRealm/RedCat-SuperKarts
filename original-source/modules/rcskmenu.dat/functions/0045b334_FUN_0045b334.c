/*
 * FUN_0045b334 at 0045b334
 * undefined __register FUN_0045b334(int param_1)
 * Address ranges: 0045b334-0045b4f0;0045b4fb-0045b510
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045b334(int param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  uint *in_FS_OFFSET;
  uint uStack_5c;
  undefined1 *puStack_58;
  undefined1 *puStack_54;
  uint uStack_50;
  undefined1 *puStack_4c;
  undefined1 *puStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  uint uStack_38;
  char *pcStack_34;
  undefined *local_30;
  undefined4 *local_2c;
  undefined *local_28;
  undefined4 *local_24;
  undefined *local_20;
  
  local_20 = &stack0xfffffffc;
  iVar3 = 6;
  do {
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  local_24 = (undefined4 *)&LAB_0045b68c;
  local_28 = (undefined *)*in_FS_OFFSET;
  *in_FS_OFFSET = (uint)&local_28;
  local_2c = (undefined4 *)0x45b367;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_20);
  local_2c = (undefined4 *)0x45b372;
  FUN_004081c4(local_20,(int *)&stack0xffffffe4);
  local_30 = &DAT_0045b6a4;
  pcStack_34 = "settings.ini";
  uStack_38 = 0x45b38c;
  local_2c = unaff_EDI;
  FUN_00403e90((int *)&stack0xffffffe8,3);
  uStack_38 = 0x45b39b;
  piVar2 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',unaff_ESI);
  uStack_38 = 0x45b3ad;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_28);
  uStack_38 = 0x45b3b8;
  FUN_004081c4(local_28,(int *)&local_24);
  uStack_38 = 0x45b3c5;
  FUN_00403dd8((int *)&local_24,(undefined4 *)"race.ini");
  uStack_38 = 0x45b3d4;
  FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_24);
  uStack_38 = (uint)*(byte *)(param_1 + 6);
  uStack_3c = 0x45b3f1;
  (**(code **)(*piVar2 + 0xc))(piVar2,"settings","rendermode");
  uStack_3c = 0x45b3f9;
  bVar1 = FUN_0045bba8(param_1);
  uStack_3c = bVar1 & 0x7f;
  uStack_40 = 0x45b40f;
  (**(code **)(*piVar2 + 0xc))(piVar2,"shell","shellstate");
  uStack_40 = *(undefined4 *)(param_1 + 0x14);
  uStack_44 = 0x45b428;
  (**(code **)(*piVar2 + 0xc))(piVar2,"shell","lastplayer");
  uStack_44 = (uint)*(byte *)(param_1 + 0x18);
  puStack_48 = (undefined1 *)0x45b442;
  (**(code **)(*piVar2 + 0xc))(piVar2,"shell","startinfo");
  puStack_4c = &LAB_0045b511;
  uStack_50 = *in_FS_OFFSET;
  *in_FS_OFFSET = (uint)&uStack_50;
  puStack_58 = &LAB_0045b4f1;
  uStack_5c = *in_FS_OFFSET;
  *in_FS_OFFSET = (uint)&uStack_5c;
  puStack_54 = &stack0xfffffffc;
  puStack_48 = &stack0xfffffffc;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_30);
  FUN_004081c4(local_30,(int *)&local_2c);
  FUN_00403dd8((int *)&local_2c,(undefined4 *)"game.ini");
  piVar2 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_2c);
  (**(code **)(*piVar2 + 0xc))(piVar2,"PROGRAM","resolution",*(undefined1 *)(param_1 + 5));
  (**(code **)(*piVar2 + 0xc))(piVar2,"OPTIONS","FILTER",(uint)*(byte *)(param_1 + 0x34) * 2);
  bVar1 = *(byte *)(param_1 + 0x40);
  (**(code **)(*piVar2 + 0xc))(piVar2,"OPTIONS","WAITVBL");
  *in_FS_OFFSET = (uint)bVar1;
  *in_FS_OFFSET = uStack_5c;
  puStack_54 = &LAB_0045b518;
  puStack_58 = (undefined1 *)0x45b510;
  FUN_00402eac(piVar2);
  return;
}

