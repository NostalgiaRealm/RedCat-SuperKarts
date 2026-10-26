/*
 * FUN_004b9f30 at 004b9f30
 * undefined FUN_004b9f30(void)
 * Address ranges: 004b9f30-004ba1a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b9f30(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  uVar3 = DAT_00501c70;
  uVar1 = DAT_00501c6c;
  iVar2 = DAT_006ab880 +
          *(int *)(*(int *)(DAT_006ab894 + 8 + DAT_00501c88 * 0xc) + 4 + DAT_00501c8c * 8) * 0x20;
  local_8 = *(int *)(iVar2 + 8) + DAT_006ab954;
  local_4 = *(int *)(iVar2 + 0xc) + DAT_006ab958;
  if (local_8 < 0) {
    return;
  }
  if (DAT_004fe930 < DAT_006ab954) {
    return;
  }
  if (local_4 < 0) {
    return;
  }
  if (DAT_006ab958 <= DAT_004fe934) {
    local_10 = DAT_006ab954;
    if (DAT_006ab954 < 0) {
      local_10 = 0;
    }
    local_c = DAT_006ab958;
    if (DAT_006ab958 < 0) {
      local_c = 0;
    }
    if (DAT_004fe934 < local_4) {
      local_4 = DAT_004fe934;
    }
    if (DAT_004fe930 < local_8) {
      local_8 = DAT_004fe930;
    }
    if (local_8 <= local_10) {
      return;
    }
    if (local_4 <= local_c) {
      return;
    }
    local_18 = local_8 - local_10;
    local_14 = local_4 - local_c;
    local_20 = 0;
    local_1c = 0;
    if (param_1 == 0) {
      FUN_004b08e0(DAT_006a64bc);
      piVar4 = &local_10;
      uVar6 = 0;
      uVar5 = 0x1000000;
      iVar2 = (**(code **)(*DAT_006ab980 + 0x14))
                        (DAT_006ab980,&local_20,DAT_006a64bc,piVar4,0x1000000,0);
      uVar3 = DAT_00501c70;
      uVar1 = DAT_00501c6c;
      if (iVar2 == 0) {
        DAT_00501c6c = DAT_006ab954;
        DAT_00501c70 = DAT_006ab958;
        _DAT_00501c74 = uVar1;
        _DAT_00501c78 = uVar3;
        return;
      }
      uVar1 = FUN_004b0190(iVar2,unaff_ESI,unaff_EBX,local_20,local_1c,piVar4,uVar5,uVar6,unaff_EDI)
      ;
      uVar3 = 0x242;
    }
    else if (param_1 == 1) {
      FUN_004b08e0(DAT_006a64c0);
      piVar4 = &local_10;
      uVar6 = 0;
      uVar5 = 0x1000000;
      iVar2 = (**(code **)(*DAT_006ab980 + 0x14))
                        (DAT_006ab980,&local_20,DAT_006a64c0,piVar4,0x1000000,0);
      uVar3 = DAT_00501c70;
      uVar1 = DAT_00501c6c;
      if (iVar2 == 0) {
        DAT_00501c6c = DAT_006ab954;
        DAT_00501c70 = DAT_006ab958;
        _DAT_00501c74 = uVar1;
        _DAT_00501c78 = uVar3;
        return;
      }
      uVar1 = FUN_004b0190(iVar2,unaff_ESI,unaff_EBX,local_20,local_1c,piVar4,uVar5,uVar6,unaff_EDI)
      ;
      uVar3 = 0x24c;
    }
    else {
      if (param_1 != 2) {
        DAT_00501c6c = DAT_006ab954;
        DAT_00501c70 = DAT_006ab958;
        _DAT_00501c74 = uVar1;
        _DAT_00501c78 = uVar3;
        return;
      }
      FUN_004b08e0(DAT_006a64a0);
      piVar4 = &local_10;
      uVar6 = 0;
      uVar5 = 0x1000000;
      iVar2 = (**(code **)(*DAT_006ab980 + 0x14))
                        (DAT_006ab980,&local_20,DAT_006a64a0,piVar4,0x1000000,0);
      uVar3 = DAT_00501c70;
      uVar1 = DAT_00501c6c;
      if (iVar2 == 0) {
        DAT_00501c6c = DAT_006ab954;
        DAT_00501c70 = DAT_006ab958;
        _DAT_00501c74 = uVar1;
        _DAT_00501c78 = uVar3;
        return;
      }
      uVar1 = FUN_004b0190(iVar2,unaff_ESI,unaff_EBX,local_20,local_1c,piVar4,uVar5,uVar6,unaff_EDI)
      ;
      uVar3 = 0x256;
    }
    FUN_004afee0(s__s__d_____store_mouse_button__bl_00501e78,
                 s_C__libraries_dxdraw_Mouse_cpp_00501cc8,uVar3,uVar1);
    _DAT_00501c78 = DAT_00501c70;
    _DAT_00501c74 = DAT_00501c6c;
    DAT_00501c70 = DAT_006ab958;
    DAT_00501c6c = DAT_006ab954;
    return;
  }
  return;
}

