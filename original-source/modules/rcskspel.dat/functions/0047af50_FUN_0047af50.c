/*
 * FUN_0047af50 at 0047af50
 * undefined FUN_0047af50(void)
 * Address ranges: 0047af50-0047b130
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047af50(void)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_EBX;
  int iVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined4 uStack_30;
  undefined4 *puStack_2c;
  uint uStack_28;
  int local_1c;
  undefined1 *local_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0dec;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = FUN_0047f750();
  local_1c = CONCAT31(local_1c._1_3_,uStack_30._3_1_);
  uVar6 = 0xffffffff;
  pcVar9 = &DAT_004f8060;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  local_18 = (undefined1 *)0x0;
  local_14 = (void *)0x0;
  local_10 = 0;
  FUN_0040b540(&DAT_004f8060,~uVar6 - 1);
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
        (**(code **)(**(int **)(iVar8 + 0x10) + 0x14))(0);
        puStack_8 = (undefined1 *)0xffffffff;
        if (local_1c != 0) {
          cVar1 = *(char *)(local_1c + -1);
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_004bc150((char *)(local_1c + -1));
          }
          else {
            *(char *)(local_1c + -1) = cVar1 + -1;
          }
        }
        uStack_30 = CONCAT31(uStack_30._1_3_,(char)((uint)unaff_EBX >> 0x18));
        FUN_0040b4f0(0);
        uVar6 = 0xffffffff;
        pcVar9 = (char *)&DAT_004f8068;
        goto code_r0x0047b04d;
      }
      iVar8 = iVar8 + 0x14;
    } while (iVar8 != *(int *)(iVar2 + 0x78));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int)&uStack_30 + 3,&DAT_004d9d80);
  while( true ) {
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    if (cVar1 == '\0') break;
code_r0x0047b04d:
    if (uVar6 == 0) break;
  }
  uVar6 = ~uVar6 - 1;
  cVar1 = FUN_0040b600(uVar6,1);
  if (cVar1 != '\0') {
    puVar5 = &DAT_004f8068;
    puVar10 = puStack_2c;
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
    *(undefined1 *)((int)puStack_2c + uVar6) = 0;
    uStack_28 = uVar6;
  }
  iVar8 = *(int *)(iVar2 + 0x74);
  puStack_8 = (undefined1 *)0x1;
  if (iVar8 != *(int *)(iVar2 + 0x78)) {
    do {
      puVar5 = puStack_2c;
      if (puStack_2c == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)&DAT_004d2404;
      }
      iVar4 = FUN_00460440(0,*(undefined4 *)(iVar8 + 8),puVar5,uStack_28);
      if (iVar4 == 0) {
        (**(code **)(**(int **)(iVar8 + 0x10) + 0x14))(0);
        if (uStack_30 != 0) {
          cVar1 = *(char *)(uStack_30 + -1);
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_004bc150((char *)(uStack_30 + -1));
            ExceptionList = local_14;
            return;
          }
          *(char *)(uStack_30 + -1) = cVar1 + -1;
        }
        ExceptionList = local_14;
        return;
      }
      iVar8 = iVar8 + 0x14;
    } while (iVar8 != *(int *)(iVar2 + 0x78));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&stack0xffffffcf,&DAT_004d9d80);
}

