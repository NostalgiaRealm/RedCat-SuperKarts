/*
 * FUN_00451288 at 00451288
 * undefined __register FUN_00451288(int * param_1, int * param_2, char param_3)
 * Address ranges: 00451288-00451575
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451288(int *param_1,int *param_2,char param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 extraout_ECX;
  undefined1 *puVar5;
  uint *puVar6;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_7a8;
  undefined1 *puStack_7a4;
  undefined1 *puStack_7a0;
  undefined4 *local_790;
  undefined4 *local_78c;
  undefined4 *local_788;
  int local_784 [12];
  uint local_754 [256];
  uint local_354;
  uint local_350;
  uint local_34c;
  undefined1 local_348 [772];
  ushort local_44;
  ushort local_42;
  ushort local_3e;
  int local_3c;
  char local_35;
  int *local_34;
  int *local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  ushort local_1e;
  int local_1c;
  int local_c;
  
  puStack_7a0 = &stack0xfffffffc;
  local_790 = (undefined4 *)0x0;
  local_78c = (undefined4 *)0x0;
  local_788 = (undefined4 *)0x0;
  puStack_7a4 = &LAB_00451576;
  uStack_7a8 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_7a8;
  local_35 = param_3;
  local_34 = param_2;
  local_30 = param_1;
  iVar2 = (**(code **)(*param_2 + 4))(param_2,&local_2c,4);
  if (iVar2 == 0) {
    FUN_004507f8(local_30,-1,extraout_ECX);
  }
  else {
    if (iVar2 != 4) {
      FUN_00405438((undefined4 *)PTR_PTR_0047c860,(int *)&local_788);
      piVar3 = FUN_0040ac64((int *)&DAT_00415bf4,'\x01',local_788);
      FUN_00403604(piVar3);
    }
    bVar1 = false;
    if (local_2c == 0xc) {
      FUN_004118e8(local_34,&local_44,8);
      local_c = 0;
      local_1c = 0;
      local_1e = local_3e;
      local_24 = (uint)local_42;
      local_28 = (uint)local_44;
      bVar1 = true;
    }
    else if (local_2c == 0x28) {
      FUN_004118e8(local_34,&local_28,0x24);
    }
    else {
      FUN_00405438((undefined4 *)PTR_PTR_0047c860,(int *)&local_78c);
      piVar3 = FUN_0040ac64((int *)&DAT_00415bf4,'\x01',local_78c);
      FUN_00403604(piVar3);
    }
    if (local_1c == 3) {
      FUN_004118e8(local_34,&local_354,0xc);
      FUN_00450398(local_354,local_350,local_34c,local_784);
    }
    else if (local_1e == 0x10) {
      FUN_004502d4(5,5,5,local_784);
    }
    else if (local_1e == 0x20) {
      FUN_004502d4(8,8,8,local_784);
    }
    else {
      FUN_004502d4(8,8,8,local_784);
    }
    iVar2 = local_c;
    if ((local_c == 0) && (local_1e < 9)) {
      iVar2 = 1 << ((byte)local_1e & 0x1f);
    }
    if (0x100 < iVar2) {
      iVar2 = 0x100;
    }
    FUN_00402b54(local_754,0x400,0);
    if (bVar1) {
      FUN_004118e8(local_34,local_348,iVar2 * 3);
      if (-1 < iVar2 + -1) {
        local_3c = iVar2;
        puVar5 = local_348;
        puVar6 = local_754;
        do {
          uVar4 = FUN_004503f8(puVar5[2],puVar5[1],*puVar5);
          *puVar6 = uVar4;
          puVar6 = puVar6 + 1;
          puVar5 = puVar5 + 3;
          local_3c = local_3c + -1;
        } while (local_3c != 0);
      }
    }
    else {
      FUN_004118e8(local_34,local_754,iVar2 << 2);
    }
    FUN_004508a8(local_30,local_28,(local_24 ^ (int)local_24 >> 0x1f) - ((int)local_24 >> 0x1f),
                 local_1c - 1U < 2,local_35,local_754,local_784,(uint)local_1e);
    if (local_1c == 0) {
      FUN_00451204();
    }
    else if (local_1c == 1) {
      FUN_004511ac();
    }
    else if (local_1c == 2) {
      FUN_00451154();
    }
    else if (local_1c == 3) {
      FUN_00451204();
    }
    else {
      FUN_00405438((undefined4 *)PTR_PTR_0047c860,(int *)&local_790);
      piVar3 = FUN_0040ac64((int *)&DAT_00415bf4,'\x01',local_790);
      FUN_00403604(piVar3);
    }
  }
  *in_FS_OFFSET = uStack_7a8;
  puStack_7a0 = &LAB_0045157d;
  puStack_7a4 = (undefined1 *)0x451575;
  FUN_00403b74((int *)&local_790,3);
  return;
}

