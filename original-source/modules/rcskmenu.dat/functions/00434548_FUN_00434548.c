/*
 * FUN_00434548 at 00434548
 * undefined __register FUN_00434548(int * param_1, int * param_2)
 * Address ranges: 00434548-0043478e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00434548(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_EDX;
  int iVar4;
  int iVar5;
  undefined4 *in_FS_OFFSET;
  int *piVar6;
  undefined4 uStack_74;
  undefined4 uStack_68;
  undefined1 *puStack_64;
  undefined1 *puStack_60;
  undefined4 uStack_5c;
  undefined1 *puStack_58;
  undefined1 *puStack_54;
  int local_44 [4];
  int local_34 [4];
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  puStack_54 = (undefined1 *)0x434565;
  local_8 = param_1;
  FUN_004118e8(param_2,&local_1c,4);
  puStack_54 = (undefined1 *)0x434574;
  FUN_004118e8(param_2,&local_20,4);
  puStack_54 = (undefined1 *)0x434580;
  local_c = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX);
  puStack_58 = &LAB_004347c9;
  uStack_5c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_5c;
  puStack_60 = (undefined1 *)0x434598;
  puStack_54 = &stack0xfffffffc;
  iVar1 = FUN_00411894(param_2);
  puStack_60 = (undefined1 *)0x4345a4;
  (**(code **)(*local_c + 0x50))(local_c,param_2);
  puStack_60 = (undefined1 *)0x4345b0;
  FUN_004118a4(param_2,local_1c + iVar1);
  puStack_60 = (undefined1 *)0x4345bc;
  local_14 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX_00);
  puStack_64 = &LAB_004347ac;
  uStack_68 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_68;
  puStack_60 = &stack0xfffffffc;
  (**(code **)(*local_14 + 0x50))(local_14,param_2);
  local_10 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX_01);
  (**(code **)(*local_10 + 0x40))(local_10,local_8[10]);
  (**(code **)(*local_10 + 0x34))(local_10,local_8[9]);
  local_18 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX_02);
  FUN_0041dabc(local_18,1);
  (**(code **)(*local_18 + 0x40))(local_18,local_8[10]);
  (**(code **)(*local_18 + 0x34))(local_18,local_8[9]);
  uStack_74 = 0x434651;
  FUN_0040ebe8(0,0,local_8[10],local_34,local_8[9]);
  FUN_00434960((int)local_8);
  uStack_74 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_74;
  iVar1 = (**(code **)(*local_c + 0x20))();
  if (-1 < iVar1 / local_8[9] + -1) {
    iVar5 = 0;
    local_24 = iVar1 / local_8[9];
    do {
      if (local_20 == 0) break;
      iVar1 = (**(code **)(*local_c + 0x2c))();
      iVar1 = iVar1 / local_8[10];
      if (-1 < iVar1 + -1) {
        iVar4 = 0;
        do {
          if (local_20 == 0) break;
          FUN_0040ec04(local_8[10] * iVar4,local_8[9] * iVar5,local_8[10],local_44,local_8[9]);
          piVar6 = local_44;
          piVar2 = (int *)FUN_0041cd5c(local_c);
          piVar3 = (int *)FUN_0041cd5c(local_10);
          FUN_004183d0(piVar3,local_34,piVar2,piVar6);
          FUN_0040ec04(local_8[10] * iVar4,local_8[9] * iVar5,local_8[10],local_44,local_8[9]);
          piVar6 = local_44;
          piVar2 = (int *)FUN_0041cd5c(local_14);
          piVar3 = (int *)FUN_0041cd5c(local_18);
          FUN_004183d0(piVar3,local_34,piVar2,piVar6);
          FUN_00433ae4(local_8,local_10,local_18);
          local_20 = local_20 + -1;
          iVar4 = iVar4 + 1;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      iVar5 = iVar5 + 1;
      local_24 = local_24 + -1;
    } while (local_24 != 0);
  }
  *in_FS_OFFSET = uStack_74;
  FUN_00402eac(local_10);
  FUN_00402eac(local_18);
  FUN_00434964(local_8,extraout_EDX,extraout_ECX_03);
  return;
}

