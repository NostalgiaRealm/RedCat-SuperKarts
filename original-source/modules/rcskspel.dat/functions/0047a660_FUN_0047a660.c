/*
 * FUN_0047a660 at 0047a660
 * undefined FUN_0047a660(void)
 * Address ranges: 0047a660-0047a9b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047a660(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined1 local_2d;
  undefined1 local_2c [4];
  undefined4 *local_28;
  undefined1 local_1c [4];
  char *local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0d88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_0047f750();
  local_2c[0] = local_2d;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar8 = &DAT_004f7fa8;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f7fa8,~uVar4 - 1);
  iVar6 = *(int *)(iVar2 + 0x74);
  local_4 = 0;
  if (iVar6 != *(int *)(iVar2 + 0x78)) {
    do {
      iVar3 = FUN_0045aab0(local_2c);
      if (iVar3 == 0) {
        local_4 = 0xffffffff;
        *(code **)(*(int *)(iVar6 + 0x10) + 0x4c) = FUN_0047a9e0;
        FUN_0040b4f0(1);
        local_2c[0] = local_2d;
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar8 = s_btnSound_004f7fb0;
        goto code_r0x0047a72e;
      }
      iVar6 = iVar6 + 0x14;
    } while (iVar6 != *(int *)(iVar2 + 0x78));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2d,&DAT_004d9d80);
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    if (cVar1 == '\0') break;
code_r0x0047a72e:
    if (uVar4 == 0) break;
  }
  FUN_0040b540(s_btnSound_004f7fb0,~uVar4 - 1);
  iVar6 = *(int *)(iVar2 + 0x74);
  local_4 = 1;
  if (iVar6 != *(int *)(iVar2 + 0x78)) {
    do {
      iVar3 = FUN_0045aab0(local_2c);
      if (iVar3 == 0) {
        local_4 = 0xffffffff;
        *(code **)(*(int *)(iVar6 + 0x10) + 0x4c) = FUN_0047aa00;
        FUN_0040b4f0(1);
        local_2c[0] = local_2d;
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar8 = s_btnDisplay_004f7fbc;
        goto code_r0x0047a7ba;
      }
      iVar6 = iVar6 + 0x14;
    } while (iVar6 != *(int *)(iVar2 + 0x78));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2d,&DAT_004d9d80);
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    if (cVar1 == '\0') break;
code_r0x0047a7ba:
    if (uVar4 == 0) break;
  }
  FUN_0040b540(s_btnDisplay_004f7fbc,~uVar4 - 1);
  iVar6 = *(int *)(iVar2 + 0x74);
  local_4 = 2;
  if (iVar6 != *(int *)(iVar2 + 0x78)) {
    do {
      iVar3 = FUN_0045aab0(local_2c);
      if (iVar3 == 0) {
        local_4 = 0xffffffff;
        *(code **)(*(int *)(iVar6 + 0x10) + 0x4c) = FUN_0047a9c0;
        FUN_0040b4f0(1);
        local_2c[0] = local_2d;
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar8 = (char *)&DAT_004f7fc8;
        goto code_r0x0047a848;
      }
      iVar6 = iVar6 + 0x14;
    } while (iVar6 != *(int *)(iVar2 + 0x78));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2d,&DAT_004d9d80);
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    if (cVar1 == '\0') break;
code_r0x0047a848:
    if (uVar4 == 0) break;
  }
  uVar4 = ~uVar4 - 1;
  cVar1 = FUN_0040b600(uVar4,1);
  if (cVar1 != '\0') {
    puVar7 = &DAT_004f7fc8;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *local_28 = *puVar7;
      puVar7 = puVar7 + 1;
      local_28 = local_28 + 1;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)local_28 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      local_28 = (undefined4 *)((int)local_28 + 1);
    }
    FUN_0040b5e0(uVar4);
  }
  iVar6 = *(int *)(iVar2 + 0x74);
  local_4 = 3;
  if (iVar6 != *(int *)(iVar2 + 0x78)) {
    do {
      iVar3 = FUN_0045aab0(local_2c);
      if (iVar3 == 0) {
        local_4 = 0xffffffff;
        *(code **)(*(int *)(iVar6 + 0x10) + 0x4c) = FUN_0047aa20;
        FUN_0040b4f0(1);
        local_1c[0] = local_2d;
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar8 = s_btnGame_004f7fd0;
        goto code_r0x0047a8ff;
      }
      iVar6 = iVar6 + 0x14;
    } while (iVar6 != *(int *)(iVar2 + 0x78));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2d,&DAT_004d9d80);
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    if (cVar1 == '\0') break;
code_r0x0047a8ff:
    if (uVar4 == 0) break;
  }
  uVar4 = ~uVar4 - 1;
  cVar1 = FUN_0040b600(uVar4,1);
  if (cVar1 != '\0') {
    pcVar8 = s_btnGame_004f7fd0;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)local_18 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      local_18 = local_18 + 4;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *local_18 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      local_18 = local_18 + 1;
    }
    FUN_0040b5e0(uVar4);
  }
  iVar6 = *(int *)(iVar2 + 0x74);
  local_4 = 4;
  if (iVar6 != *(int *)(iVar2 + 0x78)) {
    do {
      iVar3 = FUN_0045aab0(local_1c);
      if (iVar3 == 0) {
        local_4 = 0xffffffff;
        *(code **)(*(int *)(iVar6 + 0x10) + 0x4c) = FUN_0047aa30;
        FUN_0040b4f0(1);
        *(code **)(iVar2 + 0x9c) = FUN_0047aa40;
        ExceptionList = local_c;
        return;
      }
      iVar6 = iVar6 + 0x14;
    } while (iVar6 != *(int *)(iVar2 + 0x78));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2d,&DAT_004d9d80);
}

