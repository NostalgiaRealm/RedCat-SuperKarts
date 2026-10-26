/*
 * FUN_004786e0 at 004786e0
 * undefined FUN_004786e0(void)
 * Address ranges: 004786e0-00478b61
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004786e0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c [16];
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0d10;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_0047f750();
  local_2c[0] = local_2e;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar6 = &DAT_004f7e1c;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f7e1c,~uVar4 - 1);
  iVar5 = *(int *)(iVar2 + 0x74);
  local_4 = 0;
  if (iVar5 != *(int *)(iVar2 + 0x78)) {
    do {
      iVar3 = FUN_0045aab0(local_2c);
      if (iVar3 == 0) {
        local_4 = 0xffffffff;
        *(code **)(*(int *)(iVar5 + 0x10) + 0x4c) = FUN_00478b90;
        FUN_0040b4f0(1);
        local_2c[0] = local_2e;
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar6 = &DAT_004f7e24;
        goto code_r0x004787b1;
      }
      iVar5 = iVar5 + 0x14;
    } while (iVar5 != *(int *)(iVar2 + 0x78));
  }
  local_2e = local_2d;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2e,&DAT_004d9d80);
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    if (cVar1 == '\0') break;
code_r0x004787b1:
    if (uVar4 == 0) break;
  }
  FUN_0040b540(&DAT_004f7e24,~uVar4 - 1);
  iVar5 = *(int *)(iVar2 + 0x74);
  local_4 = 1;
  if (iVar5 != *(int *)(iVar2 + 0x78)) {
    do {
      iVar3 = FUN_0045aab0(local_2c);
      if (iVar3 == 0) {
        local_4 = 0xffffffff;
        *(code **)(*(int *)(iVar5 + 0x10) + 0x4c) = FUN_00478da0;
        FUN_0040b4f0(1);
        local_2c[0] = local_2e;
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar6 = &DAT_004f7e2c;
        goto code_r0x0047883d;
      }
      iVar5 = iVar5 + 0x14;
    } while (iVar5 != *(int *)(iVar2 + 0x78));
  }
  local_2e = local_2d;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2e,&DAT_004d9d80);
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    if (cVar1 == '\0') break;
code_r0x0047883d:
    if (uVar4 == 0) break;
  }
  FUN_0040b540(&DAT_004f7e2c,~uVar4 - 1);
  iVar5 = *(int *)(iVar2 + 0x74);
  local_4 = 2;
  if (iVar5 != *(int *)(iVar2 + 0x78)) {
    do {
      iVar3 = FUN_0045aab0(local_2c);
      if (iVar3 == 0) {
        local_4 = 0xffffffff;
        *(code **)(*(int *)(iVar5 + 0x10) + 0x4c) = FUN_00478fb0;
        FUN_0040b4f0(1);
        local_2c[0] = local_2e;
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar6 = &DAT_004f7e34;
        goto code_r0x004788c9;
      }
      iVar5 = iVar5 + 0x14;
    } while (iVar5 != *(int *)(iVar2 + 0x78));
  }
  local_2e = local_2d;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2e,&DAT_004d9d80);
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    if (cVar1 == '\0') break;
code_r0x004788c9:
    if (uVar4 == 0) break;
  }
  FUN_0040b540(&DAT_004f7e34,~uVar4 - 1);
  iVar5 = *(int *)(iVar2 + 0x74);
  local_4 = 3;
  if (iVar5 != *(int *)(iVar2 + 0x78)) {
    do {
      iVar3 = FUN_0045aab0(local_2c);
      if (iVar3 == 0) {
        local_4 = 0xffffffff;
        *(code **)(*(int *)(iVar5 + 0x10) + 0x4c) = FUN_00478b70;
        FUN_0040b4f0(1);
        *(code **)(iVar2 + 0x9c) = FUN_004791c0;
        *(code **)(iVar2 + 0x98) = FUN_00479320;
        local_2c[0] = local_2e;
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar6 = &DAT_004f7e3c;
        goto code_r0x00478969;
      }
      iVar5 = iVar5 + 0x14;
    } while (iVar5 != *(int *)(iVar2 + 0x78));
  }
  local_2e = local_2d;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2e,&DAT_004d9d80);
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    if (cVar1 == '\0') break;
code_r0x00478969:
    if (uVar4 == 0) break;
  }
  FUN_0040b540(&DAT_004f7e3c,~uVar4 - 1);
  iVar5 = *(int *)(iVar2 + 0x74);
  local_4 = 4;
  if (iVar5 != *(int *)(iVar2 + 0x78)) {
    do {
      iVar3 = FUN_0045aab0(local_2c);
      if (iVar3 == 0) {
        local_4 = 0xffffffff;
        *(code **)(*(int *)(iVar5 + 0x10) + 0x44) = FUN_004794f0;
        FUN_0040b4f0(1);
        local_2c[0] = local_2e;
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar6 = &DAT_004f7e44;
        goto code_r0x004789f5;
      }
      iVar5 = iVar5 + 0x14;
    } while (iVar5 != *(int *)(iVar2 + 0x78));
  }
  local_2e = local_2d;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2e,&DAT_004d9d80);
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    if (cVar1 == '\0') break;
code_r0x004789f5:
    if (uVar4 == 0) break;
  }
  FUN_0040b540(&DAT_004f7e44,~uVar4 - 1);
  iVar5 = *(int *)(iVar2 + 0x74);
  local_4 = 5;
  if (iVar5 != *(int *)(iVar2 + 0x78)) {
    do {
      iVar3 = FUN_0045aab0(local_2c);
      if (iVar3 == 0) {
        *(code **)(*(int *)(iVar5 + 0x10) + 0x44) = FUN_004796a0;
        local_4 = 0xffffffff;
        FUN_0040b4f0(1);
        FUN_004798a0(s_btnMed_004f7e4c,&local_2e);
        local_4 = 6;
        iVar2 = FUN_00479960(local_2c);
        *(code **)(iVar2 + 0x44) = FUN_004794f0;
        local_4 = 0xffffffff;
        FUN_0040b4f0(1);
        FUN_004798a0(s_btnMed_004f7e54,&local_2e);
        local_4 = 7;
        iVar2 = FUN_00479960(local_2c);
        *(code **)(iVar2 + 0x44) = FUN_004796a0;
        local_4 = 0xffffffff;
        FUN_0040b4f0(1);
        FUN_004798a0(s_btnMax_004f7e5c,&local_2e);
        local_4 = 8;
        iVar2 = FUN_00479960(local_2c);
        *(code **)(iVar2 + 0x44) = FUN_004794f0;
        local_4 = 0xffffffff;
        FUN_0040b4f0(1);
        FUN_004798a0(s_btnMax_004f7e64,&local_2d);
        local_4 = 9;
        iVar2 = FUN_00479960(local_1c);
        *(code **)(iVar2 + 0x44) = FUN_004796a0;
        local_4 = 0xffffffff;
        FUN_0040b4f0(1);
        ExceptionList = local_c;
        return;
      }
      iVar5 = iVar5 + 0x14;
    } while (iVar5 != *(int *)(iVar2 + 0x78));
  }
  local_2e = local_2d;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2e,&DAT_004d9d80);
}

