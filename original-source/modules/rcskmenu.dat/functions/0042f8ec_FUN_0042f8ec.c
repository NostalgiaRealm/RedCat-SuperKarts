/*
 * FUN_0042f8ec at 0042f8ec
 * undefined __register FUN_0042f8ec(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0042f8ec-0042f9e7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f8ec(int *param_1,char param_2,undefined4 param_3)

{
  char cVar1;
  undefined **ppuVar2;
  undefined4 extraout_ECX;
  undefined1 extraout_DL;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar3;
  byte **ppbVar4;
  undefined4 uStack_144;
  undefined1 *puStack_140;
  undefined1 *puStack_13c;
  undefined4 uStack_138;
  undefined1 *puStack_134;
  undefined1 *puStack_130;
  undefined4 in_stack_fffffed4;
  undefined4 in_stack_fffffed8;
  byte *local_118;
  byte local_114 [256];
  byte *local_14;
  undefined1 local_10;
  undefined1 local_9;
  int *local_8;
  
  local_118 = (byte *)0x0;
  local_9 = 0;
  if (param_2 != '\0') {
    puStack_130 = (undefined1 *)0x42f90a;
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_fffffed4,in_stack_fffffed8);
    param_3 = extraout_ECX;
    local_9 = extraout_DL;
  }
  puStack_134 = &LAB_0042fa08;
  uStack_138 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_138;
  puStack_13c = (undefined1 *)0x42f92c;
  puStack_130 = &stack0xfffffffc;
  local_8 = param_1;
  FUN_0040bf7c(*(int *)PTR_DAT_0047c9b0);
  puStack_140 = &LAB_0042f9e8;
  uStack_144 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_144;
  puStack_13c = &stack0xfffffffc;
  (**(code **)(*local_8 + 0x38))(local_8,0,param_3);
  ppuVar2 = (undefined **)FUN_00402df4(local_8);
  if ((ppuVar2 != &PTR_FUN_00428f6c) && ((*(byte *)(local_8 + 8) & 0x10) == 0)) {
    cVar1 = FUN_0040f420(local_8,&PTR_FUN_00428f6c);
    if (cVar1 == '\0') {
      FUN_00402df8(*local_8,local_114);
      local_14 = local_114;
      local_10 = 4;
      ppbVar4 = &local_14;
      uVar3 = 0;
      FUN_00405438((undefined4 *)PTR_PTR_0047c7b4,(int *)&local_118);
      uVar3 = FUN_0040aca0((int)&DAT_0040dbe8,'\x01',local_118,uVar3,ppbVar4);
      FUN_00403604(uVar3);
    }
    if ((char)local_8[0x12] != '\0') {
      (**(code **)(*local_8 + 0x30))();
    }
  }
  *in_FS_OFFSET = 0;
  puStack_140 = &LAB_0042f9ef;
  uStack_144 = 0x42f9e7;
  FUN_0040bfc8(*(int *)PTR_DAT_0047c9b0);
  return;
}

