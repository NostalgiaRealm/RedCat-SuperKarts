/*
 * FUN_0047a100 at 0047a100
 * undefined FUN_0047a100(void)
 * Address ranges: 0047a100-0047a2c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047a100(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  char *pcVar11;
  undefined4 *puVar12;
  undefined1 local_21;
  int local_20;
  undefined1 local_1c;
  undefined4 *local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0d38;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_20 = FUN_0047f750();
  puVar2 = DAT_00544e8c;
  if (DAT_00544e8c == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004b1d60(puVar2);
  puVar2 = DAT_00544e7c;
  if (DAT_00544e7c == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  puVar3 = DAT_00544e6c;
  if (DAT_00544e6c == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  iVar4 = FUN_004b1ed0(puVar3,puVar2);
  if ((iVar4 < 0) || (3 < iVar4)) {
    FUN_004afce0(s__s__d____Invalid_control_type__d_004f7f28,
                 s_D__work_rcsk_Code_game_ReqHelp_c_004f7f04,0x7d,iVar4);
    iVar4 = 0;
  }
  iVar5 = FUN_00481730();
  if (iVar5 == 0) {
    puVar10 = &DAT_00544e98 + iVar4 * 0x10;
  }
  else {
    puVar10 = &DAT_00544ec8 + iVar4 * 0x10;
  }
  FUN_0047fce0(puVar10);
  local_1c = local_21;
  uVar8 = 0xffffffff;
  pcVar11 = (char *)&DAT_004f7f4c;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar1 != '\0');
  uVar8 = ~uVar8 - 1;
  local_18 = (undefined4 *)0x0;
  local_14 = 0;
  local_10 = 0;
  cVar1 = FUN_0040b600(uVar8,1);
  iVar4 = local_20;
  if (cVar1 != '\0') {
    puVar6 = &DAT_004f7f4c;
    puVar12 = local_18;
    for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar12 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar12 = puVar12 + 1;
    }
    for (uVar9 = uVar8 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined1 *)puVar12 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    *(undefined1 *)((int)local_18 + uVar8) = 0;
    local_14 = uVar8;
  }
  local_4 = 0;
  iVar5 = *(int *)(local_20 + 0x74);
  if (iVar5 != *(int *)(local_20 + 0x78)) {
    do {
      puVar6 = local_18;
      if (local_18 == (undefined4 *)0x0) {
        puVar6 = (undefined4 *)&DAT_004d2404;
      }
      iVar7 = FUN_00460440(0,*(undefined4 *)(iVar5 + 8),puVar6,local_14);
      if (iVar7 == 0) {
        *(code **)(*(int *)(iVar5 + 0x10) + 0x4c) = FUN_0047a2d0;
        if (local_18 != (undefined4 *)0x0) {
          cVar1 = *(char *)((int)local_18 + -1);
          if ((cVar1 != '\0') && (cVar1 != -1)) {
            *(char *)((int)local_18 + -1) = cVar1 + -1;
            *(code **)(iVar4 + 0x9c) = FUN_0047a2f0;
            ExceptionList = local_c;
            return;
          }
          FUN_004bc150((char *)((int)local_18 + -1));
        }
        *(code **)(iVar4 + 0x9c) = FUN_0047a2f0;
        ExceptionList = local_c;
        return;
      }
      iVar5 = iVar5 + 0x14;
    } while (iVar5 != *(int *)(iVar4 + 0x78));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_21,&DAT_004d9d80);
}

