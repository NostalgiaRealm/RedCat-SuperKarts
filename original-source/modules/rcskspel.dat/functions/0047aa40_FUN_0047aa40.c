/*
 * FUN_0047aa40 at 0047aa40
 * undefined FUN_0047aa40(void)
 * Address ranges: 0047aa40-0047ab95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047aa40(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  undefined1 auStack_1d [5];
  char *pcStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d0d9a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = FUN_004b3830(0x1b);
  if (iVar2 == 0) {
    ExceptionList = pvStack_c;
    return;
  }
  iVar2 = FUN_004b3830(0x1b);
  while (iVar2 != 0) {
    FUN_004baf80();
    iVar2 = FUN_004b3830(0x1b);
  }
  uVar6 = 0xffffffff;
  pcVar4 = s_btnGame_004f8040;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6 - 1;
  pcStack_18 = (char *)0x0;
  uStack_14 = 0;
  uStack_10 = 0;
  cVar1 = FUN_0040b600(uVar6,1);
  if (cVar1 != '\0') {
    pcVar4 = s_btnGame_004f8040;
    pcVar8 = pcStack_18;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar8 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar8 = pcVar8 + 1;
    }
    pcStack_18[uVar6] = '\0';
    uStack_14 = uVar6;
  }
  uStack_4 = 0;
  iVar3 = FUN_0047f750();
  iVar2 = *(int *)(iVar3 + 0x74);
  if (iVar2 != *(int *)(iVar3 + 0x78)) {
    do {
      pcVar4 = pcStack_18;
      if (pcStack_18 == (char *)0x0) {
        pcVar4 = "";
      }
      iVar5 = FUN_00460440(0,*(undefined4 *)(iVar2 + 8),pcVar4,uStack_14);
      if (iVar5 == 0) {
        FUN_0047d6e0();
        if (pcStack_18 == (char *)0x0) {
          ExceptionList = pvStack_c;
          return;
        }
        cVar1 = pcStack_18[-1];
        if ((cVar1 != '\0') && (cVar1 != -1)) {
          pcStack_18[-1] = cVar1 + -1;
          ExceptionList = pvStack_c;
          return;
        }
        FUN_004bc150(pcStack_18 + -1);
        ExceptionList = pvStack_c;
        return;
      }
      iVar2 = iVar2 + 0x14;
    } while (iVar2 != *(int *)(iVar3 + 0x78));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(auStack_1d,&DAT_004d9d80);
}

