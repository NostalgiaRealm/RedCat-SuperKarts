/*
 * FUN_004791c0 at 004791c0
 * undefined FUN_004791c0(void)
 * Address ranges: 004791c0-00479315
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004791c0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 *puVar9;
  undefined1 auStack_1d [5];
  undefined4 *puStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d0d22;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = FUN_0047f750();
  iVar3 = FUN_004b3830(0x1b);
  if (iVar3 == 0) {
    ExceptionList = pvStack_c;
    return;
  }
  iVar3 = FUN_004b3830(0x1b);
  while (iVar3 != 0) {
    FUN_004baf80();
    iVar3 = FUN_004b3830(0x1b);
  }
  uVar6 = 0xffffffff;
  pcVar8 = &DAT_004f7e6c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6 - 1;
  puStack_18 = (undefined4 *)0x0;
  uStack_14 = 0;
  uStack_10 = 0;
  cVar1 = FUN_0040b600(uVar6,1);
  if (cVar1 != '\0') {
    puVar4 = (undefined4 *)&DAT_004f7e6c;
    puVar9 = puStack_18;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar9 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar9 = puVar9 + 1;
    }
    for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    *(undefined1 *)((int)puStack_18 + uVar6) = 0;
    uStack_14 = uVar6;
  }
  uStack_4 = 0;
  iVar3 = *(int *)(iVar2 + 0x74);
  if (iVar3 != *(int *)(iVar2 + 0x78)) {
    do {
      puVar4 = puStack_18;
      if (puStack_18 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)&DAT_004d2404;
      }
      iVar5 = FUN_00460440(0,*(undefined4 *)(iVar3 + 8),puVar4,uStack_14);
      if (iVar5 == 0) {
        FUN_0047d6e0();
        if (puStack_18 == (undefined4 *)0x0) {
          ExceptionList = pvStack_c;
          return;
        }
        cVar1 = *(char *)((int)puStack_18 + -1);
        if ((cVar1 != '\0') && (cVar1 != -1)) {
          *(char *)((int)puStack_18 + -1) = cVar1 + -1;
          ExceptionList = pvStack_c;
          return;
        }
        FUN_004bc150((char *)((int)puStack_18 + -1));
        ExceptionList = pvStack_c;
        return;
      }
      iVar3 = iVar3 + 0x14;
    } while (iVar3 != *(int *)(iVar2 + 0x78));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(auStack_1d,&DAT_004d9d80);
}

