/*
 * FUN_0044ec30 at 0044ec30
 * undefined FUN_0044ec30(void)
 * Address ranges: 0044ec30-0044efa9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0044ed81) */

void __thiscall FUN_0044ec30(int param_1,int param_2)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  undefined1 local_b8 [4];
  int local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  int local_a8;
  char local_a4 [20];
  undefined1 local_90 [84];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [16];
  undefined1 local_20 [20];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cdae6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00412870(param_2,0,0xffffffff);
  puVar2 = *(undefined1 **)(param_2 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004b1f10(puVar2,s_texture_004f0bb8,local_a4,0x14);
  uVar5 = 0xffffffff;
  pcVar7 = local_a4;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5 - 1;
  local_a8 = param_1 + 0x14;
  cVar1 = FUN_0040b600(uVar5,1);
  if (cVar1 != '\0') {
    pcVar7 = local_a4;
    pcVar9 = *(char **)(param_1 + 0x18);
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
    FUN_0040b5e0(uVar5);
  }
  uVar3 = FUN_0041b630(local_30,param_1 + 0x14,&DAT_004f0bc0);
  local_4 = 0;
  FUN_00412870(uVar3,0,0xffffffff);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  puVar2 = *(undefined1 **)(param_2 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004afce0(s_retrieve_animsize_of_list__s_004f0bc8,puVar2);
  puVar2 = &DAT_004d2404;
  if (*(undefined1 **)(param_2 + 4) != (undefined1 *)0x0) {
    puVar2 = *(undefined1 **)(param_2 + 4);
  }
  iVar4 = FUN_004b1ed0(puVar2,s_COUNT_004f0be8);
  FUN_004afce0(s_Clearing_Data_004f0bf0);
  uVar3 = *(undefined4 *)(param_1 + 0x28);
  FUN_0044aa50(uVar3,*(undefined4 *)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x2c) = uVar3;
  FUN_004afce0(s_Data_Cleared_004f0c00);
  iVar8 = 0;
  if (0 < iVar4) {
    do {
      FUN_004afce0(s_load_anim__d_____________________004f0c10,iVar8);
      FUN_004be8cb(local_20,0x14,&DAT_004f0c3c,iVar8);
      puVar2 = *(undefined1 **)(param_2 + 4);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_004d2404;
      }
      FUN_004b1f10(puVar2,local_20,local_a4,0x14);
      FUN_0044e970();
      local_4 = 1;
      FUN_004afce0(s_Buffer__s_004f0c40,local_a4);
      uVar5 = 0xffffffff;
      pcVar7 = local_a4;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      local_b4 = 0;
      local_b0 = 0;
      local_ac = 0;
      FUN_0040b540(local_a4,~uVar5 - 1);
      local_4._0_1_ = 2;
      FUN_0044e460(param_2,local_b8,local_a8);
      local_4 = CONCAT31(local_4._1_3_,1);
      if (local_b4 != 0) {
        cVar1 = *(char *)(local_b4 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(local_b4 + -1));
        }
        else {
          *(char *)(local_b4 + -1) = cVar1 + -1;
        }
      }
      local_b4 = 0;
      local_b0 = 0;
      local_ac = 0;
      FUN_004afce0(s_Loading_anim_SUCCEEDED_004f0c4c);
      FUN_0044f580(*(undefined4 *)(param_1 + 0x2c),1,local_90);
      FUN_004afce0(s_anim__d_loaded___________________004f0c64,iVar8);
      local_4 = 5;
      FUN_0048b600(local_3c,local_38);
      FUN_004bc150(local_3c);
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_4._0_1_ = 4;
      FUN_0040b4f0(1);
      local_4 = CONCAT31(local_4._1_3_,3);
      FUN_0040b4f0(1);
      local_4 = 0xffffffff;
      FUN_0040b4f0(1);
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar4);
  }
  ExceptionList = local_c;
  return;
}

