/*
 * FUN_00413960 at 00413960
 * undefined __register FUN_00413960(int * param_1, int * param_2, undefined4 * param_3)
 * Address ranges: 00413960-004139bc;00413a01-00413beb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00413960(int *param_1,int *param_2,undefined4 *param_3)

{
  byte *pbVar1;
  undefined1 *puVar2;
  byte bVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  undefined4 *extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  uint extraout_ECX_02;
  undefined4 extraout_ECX_03;
  int *extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar7;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  int local_2c;
  undefined4 *local_28;
  LPCSTR local_24;
  byte *local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 *local_10;
  int *local_c;
  int *local_8;
  
  puStack_34 = &stack0xfffffffc;
  puVar7 = &stack0xfffffffc;
  local_2c = 0;
  local_28 = (undefined4 *)0x0;
  local_24 = (LPCSTR)0x0;
  local_20 = (byte *)0x0;
  local_1c = 0;
  puStack_38 = &LAB_00413bec;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  puVar2 = &stack0xfffffffc;
  local_10 = param_3;
  local_c = param_2;
  local_8 = param_1;
  if (param_3[2] == 0) {
    FUN_004124a8((undefined4 *)PTR_PTR_0047c8b0);
    param_3 = extraout_ECX;
    param_2 = extraout_EDX;
    puVar2 = puStack_34;
  }
  puStack_34 = puVar2;
  pbVar1 = *(byte **)*local_10;
  switch((uint)*pbVar1) {
  case 1:
    cVar4 = FUN_00412910((int)local_8,param_2,(uint)param_3);
    if (cVar4 == '\a') {
      FUN_004131f0((int)local_8,&local_1c,extraout_ECX_00);
      FUN_004136e0(local_c,local_10,local_1c);
    }
    else {
      iVar6 = FUN_004132f0((int)local_8,extraout_EDX_00,extraout_ECX_00);
      FUN_0040d3f4(local_c,local_10,iVar6);
    }
    break;
  case 2:
    bVar3 = FUN_004129c8((int)local_8,param_2,(uint)param_3);
    FUN_0040d3f4(local_c,local_10,(uint)bVar3);
    break;
  case 3:
    FUN_004131f0((int)local_8,(int *)&local_20,(uint)param_3);
    iVar6 = FUN_004124d8((char *)pbVar1,local_20);
    FUN_0040d3f4(local_c,local_10,iVar6);
    break;
  case 4:
    FUN_004130e4((int)local_8,param_2,(uint)param_3);
    FUN_0040d604(local_c,local_10);
    break;
  case 5:
  case 10:
  case 0xb:
    FUN_00414028((int)local_8,(int *)&local_24,(uint)param_3);
    FUN_0040d5d8(local_c,local_10,local_24);
    break;
  case 6:
    iVar6 = FUN_00413f0c((int)local_8,(int)pbVar1);
    FUN_0040d3f4(local_c,local_10,iVar6);
    break;
  case 7:
    cVar4 = FUN_00412910((int)local_8,param_2,(uint)param_3);
    if (cVar4 == '\r') {
      FUN_004140d0((int)local_8,extraout_EDX_01,extraout_ECX_01);
      FUN_0040d3f4(local_c,local_10,0);
    }
    else if (cVar4 == '\x0e') {
      FUN_004140d0((int)local_8,extraout_EDX_01,extraout_ECX_01);
      piVar5 = (int *)FUN_0040d380(local_c,local_10);
      FUN_00412a4c((int)local_8,piVar5);
    }
    else {
      FUN_004131f0((int)local_8,(int *)&local_28,extraout_ECX_01);
      FUN_00413728((int)local_c,(int)local_10,local_28,(int)puVar7);
    }
    break;
  case 8:
    cVar4 = FUN_00412910((int)local_8,param_2,(uint)param_3);
    if (cVar4 == '\r') {
      FUN_004140d0((int)local_8,extraout_EDX_02,extraout_ECX_02);
      FUN_0040d6f0(local_c,(int)local_10,(undefined4 *)&DAT_0047b31c);
    }
    else {
      FUN_004131f0((int)local_8,&local_2c,extraout_ECX_02);
      local_18 = (**(code **)(*local_8 + 0x18))(local_8,local_8[6],local_2c);
      local_14 = local_8[6];
      if (local_18 != 0) {
        FUN_0040d6f0(local_c,(int)local_10,&local_18);
      }
    }
    break;
  case 0xc:
    FUN_00413768((uint)*pbVar1,param_2,param_3,(int)&stack0xfffffffc);
    break;
  case 0x10:
    iVar6 = FUN_0041335c((int)local_8,param_2,(uint)param_3);
    FUN_0040d728(local_c,(int)local_10,extraout_ECX_03,iVar6,extraout_EDX_03);
  }
  *in_FS_OFFSET = uStack_3c;
  puStack_34 = &LAB_00413bf3;
  puStack_38 = (undefined1 *)0x413beb;
  FUN_00403b74(&local_2c,5);
  return;
}

