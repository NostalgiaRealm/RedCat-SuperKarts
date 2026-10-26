/*
 * FUN_0047abd0 at 0047abd0
 * undefined FUN_0047abd0(void)
 * Address ranges: 0047abd0-0047adb4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047abd0(void)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined4 *local_28;
  uint local_24;
  undefined1 local_1c;
  undefined1 *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0dc0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_0047f750();
  local_1c = local_2d;
  uVar6 = 0xffffffff;
  pcVar9 = &DAT_004f8048;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  local_18 = (undefined1 *)0x0;
  local_14 = 0;
  local_10 = 0;
  FUN_0040b540(&DAT_004f8048,~uVar6 - 1);
  iVar8 = *(int *)(iVar2 + 0x74);
  local_4 = 0;
  if (iVar8 != *(int *)(iVar2 + 0x78)) {
    do {
      puVar3 = local_18;
      if (local_18 == (undefined1 *)0x0) {
        puVar3 = &DAT_004d2404;
      }
      iVar4 = FUN_00460440(0,*(undefined4 *)(iVar8 + 8),puVar3,local_14);
      if (iVar4 == 0) {
        local_4 = 0xffffffff;
        *(code **)(*(int *)(iVar8 + 0x10) + 0x4c) = FUN_0047adc0;
        if (local_18 != (undefined1 *)0x0) {
          cVar1 = local_18[-1];
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_004bc150(local_18 + -1);
          }
          else {
            local_18[-1] = cVar1 + -1;
          }
        }
        local_2c = local_2d;
        FUN_0040b4f0(0);
        uVar6 = 0xffffffff;
        pcVar9 = (char *)&DAT_004f8050;
        goto code_r0x0047acce;
      }
      iVar8 = iVar8 + 0x14;
    } while (iVar8 != *(int *)(iVar2 + 0x78));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2d,&DAT_004d9d80);
  while( true ) {
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    if (cVar1 == '\0') break;
code_r0x0047acce:
    if (uVar6 == 0) break;
  }
  uVar6 = ~uVar6 - 1;
  cVar1 = FUN_0040b600(uVar6,1);
  if (cVar1 != '\0') {
    puVar5 = &DAT_004f8050;
    puVar10 = local_28;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar10 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    *(undefined1 *)((int)local_28 + uVar6) = 0;
    local_24 = uVar6;
  }
  iVar8 = *(int *)(iVar2 + 0x74);
  local_4 = 1;
  if (iVar8 != *(int *)(iVar2 + 0x78)) {
    do {
      puVar5 = local_28;
      if (local_28 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)&DAT_004d2404;
      }
      iVar4 = FUN_00460440(0,*(undefined4 *)(iVar8 + 8),puVar5,local_24);
      if (iVar4 == 0) {
        *(undefined1 **)(*(int *)(iVar8 + 0x10) + 0x4c) = &LAB_0047add0;
        if (local_28 != (undefined4 *)0x0) {
          cVar1 = *(char *)((int)local_28 + -1);
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_004bc150((char *)((int)local_28 + -1));
          }
          else {
            *(char *)((int)local_28 + -1) = cVar1 + -1;
          }
        }
        *(code **)(iVar2 + 0x9c) = FUN_0047adf0;
        *(code **)(iVar2 + 0x98) = FUN_0047af50;
        ExceptionList = local_c;
        return;
      }
      iVar8 = iVar8 + 0x14;
    } while (iVar8 != *(int *)(iVar2 + 0x78));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_2d,&DAT_004d9d80);
}

