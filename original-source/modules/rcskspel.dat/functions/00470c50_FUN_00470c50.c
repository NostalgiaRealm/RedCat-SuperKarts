/*
 * FUN_00470c50 at 00470c50
 * undefined FUN_00470c50(void)
 * Address ranges: 00470c50-00470f43
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00470c50(int param_1,int param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  int local_44;
  int local_40;
  undefined1 local_3c [4];
  undefined1 *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c [4];
  char *local_28;
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0866;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00470560();
  pcVar3 = (&PTR_DAT_004f63d8)[iVar2];
  local_2c[0] = (undefined1)param_2;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = pcVar3;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(pcVar3,~uVar6 - 1);
  local_1c[0] = (undefined1)param_2;
  local_4 = 0;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar3 = param_3;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(param_3,~uVar6 - 1);
  local_4._0_1_ = 1;
  FUN_00459040(local_3c,local_1c,local_2c);
  local_4._0_1_ = 3;
  FUN_0040b4f0(1);
  pcVar3 = local_28;
  if (local_28 == (char *)0x0) {
    pcVar3 = "";
  }
  iVar2 = __strcmpi(pcVar3,&DAT_004f665c);
  if (iVar2 == 0) {
    puVar4 = local_38;
    if (local_38 == (undefined1 *)0x0) {
      puVar4 = &DAT_004d2404;
    }
    iVar2 = FUN_004ac010(puVar4,&local_44,&local_40,0x800,&DAT_006ab7c8);
    *(int *)(param_1 + param_2 * 4) = iVar2;
    if (iVar2 == 0) {
      if (local_38 == (undefined1 *)0x0) {
        local_38 = &DAT_004d2404;
      }
      FUN_004afee0(s__s__d____Failed_loading_tga_surf_004f6694,
                   s_D__work_rcsk_Code_game_rcr_stop__004f6664,0x157,local_38);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0040b4f0(1);
      local_4 = 0xffffffff;
      FUN_0040b4f0(1);
      ExceptionList = local_c;
      return 0;
    }
  }
  else {
    puVar4 = local_38;
    if (local_38 == (undefined1 *)0x0) {
      puVar4 = &DAT_004d2404;
    }
    iVar2 = FUN_004b2c80(puVar4,&local_44,&local_40);
    *(int *)(param_1 + param_2 * 4) = iVar2;
    if (iVar2 == 0) {
      puVar4 = local_38;
      if (local_38 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      FUN_004afee0(s__s__d____Failed_loading_pcx_surf_004f66f0,
                   s_D__work_rcsk_Code_game_rcr_stop__004f66c0,0x165,puVar4);
      if (local_38 != (undefined1 *)0x0) {
        cVar1 = local_38[-1];
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(local_38 + -1);
        }
        else {
          local_38[-1] = cVar1 + -1;
        }
      }
      local_38 = (undefined1 *)0x0;
      local_34 = 0;
      local_30 = 0;
      if (local_28 != (char *)0x0) {
        cVar1 = local_28[-1];
        if ((cVar1 != '\0') && (cVar1 != -1)) {
          local_28[-1] = cVar1 + -1;
          ExceptionList = local_c;
          return 0;
        }
        FUN_004bc150(local_28 + -1);
      }
      ExceptionList = local_c;
      return 0;
    }
  }
  uVar5 = FUN_004705c0();
  FUN_00430e10(*(undefined4 *)(param_1 + param_2 * 4),uVar5);
  if (DAT_0053b9f0 == 0) {
    *(int *)(param_1 + 0x90 + param_2 * 8) = local_44;
    *(int *)(param_1 + 0x94 + param_2 * 8) = local_40;
  }
  else {
    *(int *)(param_1 + 0x90 + param_2 * 8) = (DAT_004fe930 * local_44) / 0x280;
    *(int *)(param_1 + 0x94 + param_2 * 8) = (DAT_004fe934 * local_40) / 0x1e0;
  }
  if (local_38 != (undefined1 *)0x0) {
    cVar1 = local_38[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_38 + -1);
    }
    else {
      local_38[-1] = cVar1 + -1;
    }
  }
  local_38 = (undefined1 *)0x0;
  local_34 = 0;
  local_30 = 0;
  if (local_28 != (char *)0x0) {
    cVar1 = local_28[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_28 + -1);
    }
    else {
      local_28[-1] = cVar1 + -1;
    }
  }
  ExceptionList = local_c;
  return 1;
}

