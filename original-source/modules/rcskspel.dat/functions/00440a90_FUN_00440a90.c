/*
 * FUN_00440a90 at 00440a90
 * undefined FUN_00440a90(void)
 * Address ranges: 00440a90-00440bf0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440a90(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 auStack_2c [4];
  char *pcStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  int iStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cd620;
  pvStack_c = ExceptionList;
  iVar2 = DAT_0067ee20 + param_1 * 0xd0;
  if (*(int *)(*(int *)(iVar2 + 0x24) * 0x50 + 4 + DAT_00680ae0) == 0x35) {
    uVar3 = 0xffffffff;
    ExceptionList = &pvStack_c;
    *(float *)(iVar2 + 0xa4) = *(float *)(iVar2 + 0xa4) * 1.25;
    pcStack_28 = (char *)0x0;
    auStack_2c[0] = (undefined1)param_1;
    pcVar5 = s_FIRE_TURBO_004ecbec;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    uStack_24 = 0;
    uStack_20 = 0;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      pcVar5 = s_FIRE_TURBO_004ecbec;
      pcVar6 = pcStack_28;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar6 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      }
      pcStack_28[uVar3] = '\0';
      uStack_24 = uVar3;
    }
    puVar8 = auStack_2c;
    uStack_4 = 0;
    uVar7 = 10;
    FUN_004371f0(10,puVar8);
    FUN_00437b10(uVar7,puVar8);
    uStack_4 = 0xffffffff;
    if (pcStack_28 != (char *)0x0) {
      cVar1 = pcStack_28[-1];
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(pcStack_28 + -1);
      }
      else {
        pcStack_28[-1] = cVar1 + -1;
      }
    }
    uVar7 = FUN_00438310(auStack_1c);
    uStack_4 = 1;
    FUN_004387a0(DAT_00508610,uVar7);
    if (iStack_18 != 0) {
      cVar1 = *(char *)(iStack_18 + -1);
      if ((cVar1 != '\0') && (cVar1 != -1)) {
        *(char *)(iStack_18 + -1) = cVar1 + -1;
        ExceptionList = pvStack_c;
        return;
      }
      FUN_004bc150((char *)(iStack_18 + -1));
    }
  }
  ExceptionList = pvStack_c;
  return;
}

