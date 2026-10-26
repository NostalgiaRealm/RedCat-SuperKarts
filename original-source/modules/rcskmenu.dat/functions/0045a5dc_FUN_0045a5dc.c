/*
 * FUN_0045a5dc at 0045a5dc
 * undefined __register FUN_0045a5dc(int param_1, undefined4 * param_2)
 * Address ranges: 0045a5dc-0045a7df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045a5dc(int param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  uint *in_FS_OFFSET;
  uint uStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  uint uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined *local_24;
  undefined4 *local_20;
  undefined *local_1c;
  undefined4 *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  undefined4 *local_8;
  
  local_20 = (undefined4 *)0x0;
  local_24 = (undefined *)0x0;
  local_18 = (undefined4 *)0x0;
  local_1c = (undefined *)0x0;
  puStack_30 = (undefined1 *)0x45a5ff;
  local_8 = param_2;
  FUN_00403f84((int)param_2);
  puStack_34 = &LAB_0045a80c;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = (uint)&uStack_38;
  puStack_40 = &LAB_0045a7e0;
  uStack_44 = *in_FS_OFFSET;
  *in_FS_OFFSET = (uint)&uStack_44;
  puStack_3c = &stack0xfffffffc;
  puStack_30 = &stack0xfffffffc;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_1c);
  FUN_004081c4(local_1c,(int *)&local_18);
  FUN_00403dd8((int *)&local_18,(undefined4 *)"race.ini");
  local_14 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_18);
  uVar2 = FUN_0045aa8c(CONCAT31((int3)((uint)local_14 >> 8),*(undefined1 *)(param_1 + 0x22)));
  (**(code **)(*local_14 + 0xc))(local_14,"PLAYER",&DAT_0045a838,uVar2);
  (**(code **)(*local_14 + 0xc))
            (local_14,"RACETYPEINFO","opponents",
             *(undefined4 *)(PTR_DAT_0047c9ac + (uint)*(byte *)(param_1 + 0x24) * 4));
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_24);
  FUN_004081c4(local_24,(int *)&local_20);
  FUN_00403dd8((int *)&local_20,(undefined4 *)"game.ini");
  local_10 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_20);
  (**(code **)(*local_10 + 0xc))(local_10,"OPTIONS","Difficulty",*(undefined1 *)(param_1 + 0x10));
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_8);
  (**(code **)(*local_c + 4))(local_c,"playerdata",&DAT_0045a8b8,*(undefined4 *)(param_1 + 0xc));
  (**(code **)(*local_c + 0xc))(local_c,"playerdata","character",*(undefined1 *)(param_1 + 0x22));
  (**(code **)(*local_c + 0xc))(local_c,"playerdata","adventure",*(undefined4 *)(param_1 + 0x14));
  (**(code **)(*local_c + 0xc))(local_c,"playerdata","cartype",*(undefined1 *)(param_1 + 0x23));
  (**(code **)(*local_c + 0xc))(local_c,"playerdata","racetype",*(undefined1 *)(param_1 + 0x24));
  (**(code **)(*local_c + 0xc))(local_c,"playerdata","country",*(undefined1 *)(param_1 + 0x25));
  (**(code **)(*local_c + 0xc))(local_c,"playerdata","completed",*(undefined1 *)(param_1 + 0x26));
  bVar1 = *(byte *)(param_1 + 0x10);
  (**(code **)(*local_c + 0xc))(local_c,"playerdata","difficulty");
  FUN_00454818(*(int *)(param_1 + 0x18),local_8);
  *in_FS_OFFSET = (uint)bVar1;
  FUN_00402eac(local_10);
  FUN_00402eac(local_c);
  FUN_00402eac(local_14);
  return;
}

