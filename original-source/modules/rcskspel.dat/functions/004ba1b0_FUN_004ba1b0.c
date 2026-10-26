/*
 * FUN_004ba1b0 at 004ba1b0
 * undefined FUN_004ba1b0(void)
 * Address ranges: 004ba1b0-004ba3f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004ba1b0(int param_1)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  int local_4;
  
  iVar1 = DAT_006ab880 +
          *(int *)(*(int *)(DAT_006ab894 + 8 + DAT_00501c88 * 0xc) + 4 + DAT_00501c8c * 8) * 0x20;
  local_18 = *(int *)(iVar1 + 8) + DAT_00501c6c;
  local_14 = *(int *)(iVar1 + 0xc) + DAT_00501c70;
  if ((((-1 < local_18) && (DAT_00501c6c <= DAT_004fe930)) && (-1 < local_14)) &&
     (DAT_00501c70 <= DAT_004fe934)) {
    local_20 = DAT_00501c6c;
    if (DAT_00501c6c < 0) {
      local_20 = 0;
    }
    local_1c = DAT_00501c70;
    if (DAT_00501c70 < 0) {
      local_1c = 0;
    }
    if (DAT_004fe934 < local_14) {
      local_14 = DAT_004fe934;
    }
    if (DAT_004fe930 < local_18) {
      local_18 = DAT_004fe930;
    }
    if ((local_20 < local_18) && (local_1c < local_14)) {
      local_8 = local_18 - local_20;
      local_4 = local_14 - local_1c;
      local_10 = 0;
      local_c = 0;
      if (param_1 == 0) {
        FUN_004b08e0(DAT_006a64bc);
        puVar2 = &local_10;
        uVar4 = 0;
        uVar3 = 0x1000000;
        iVar1 = (**(code **)(*DAT_006a64bc + 0x14))
                          (DAT_006a64bc,&local_20,DAT_006ab980,puVar2,0x1000000,0);
        if (iVar1 == 0) {
          return;
        }
        uVar3 = FUN_004b0190(iVar1,unaff_ESI,unaff_EBX,local_20,local_1c,puVar2,uVar3,uVar4,
                             unaff_EDI);
        uVar4 = 0x2a3;
      }
      else if (param_1 == 1) {
        FUN_004b08e0(DAT_006a64c0);
        puVar2 = &local_10;
        uVar4 = 0;
        uVar3 = 0x1000000;
        iVar1 = (**(code **)(*DAT_006a64c0 + 0x14))
                          (DAT_006a64c0,&local_20,DAT_006ab980,puVar2,0x1000000,0);
        if (iVar1 == 0) {
          return;
        }
        uVar3 = FUN_004b0190(iVar1,unaff_ESI,unaff_EBX,local_20,local_1c,puVar2,uVar3,uVar4,
                             unaff_EDI);
        uVar4 = 0x2ad;
      }
      else {
        if (param_1 != 2) {
          return;
        }
        FUN_004b08e0(DAT_006a64a0);
        puVar2 = &local_10;
        uVar4 = 0;
        uVar3 = 0x1000000;
        iVar1 = (**(code **)(*DAT_006a64a0 + 0x14))
                          (DAT_006a64a0,&local_20,DAT_006ab980,puVar2,0x1000000,0);
        if (iVar1 == 0) {
          return;
        }
        uVar3 = FUN_004b0190(iVar1,unaff_ESI,unaff_EBX,local_20,local_1c,puVar2,uVar3,uVar4,
                             unaff_EDI);
        uVar4 = 0x2b7;
      }
      FUN_004afee0(s__s__d_____restore_mouse_button__b_00501efc,
                   s_C__libraries_dxdraw_Mouse_cpp_00501cc8,uVar4,uVar3);
    }
  }
  return;
}

