/*
 * FUN_00437d50 at 00437d50
 * undefined FUN_00437d50(void)
 * Address ranges: 00437d50-00437e25
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00437d50(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 local_1c [4];
  undefined4 *local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puVar4 = (undefined4 *)PTR_s_RCRSOUND_INI_004ebe04;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd421;
  local_c = ExceptionList;
  if (DAT_0053bf74 == '\0') {
    uVar2 = 0xffffffff;
    local_18 = (undefined4 *)0x0;
    local_14 = 0;
    local_10 = 0;
    pcVar5 = PTR_s_RCRSOUND_INI_004ebe04;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2 - 1;
    ExceptionList = &local_c;
    cVar1 = FUN_0040b600(uVar2,1);
    if (cVar1 != '\0') {
      puVar6 = local_18;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      *(undefined1 *)((int)local_18 + uVar2) = 0;
      local_14 = uVar2;
    }
    puVar7 = local_1c;
    local_4 = 0;
    FUN_004371f0(puVar7);
    FUN_00437560(puVar7);
    if (local_18 != (undefined4 *)0x0) {
      cVar1 = *(char *)((int)local_18 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)((int)local_18 + -1));
      }
      else {
        *(char *)((int)local_18 + -1) = cVar1 + -1;
      }
    }
    DAT_0053bf74 = '\x01';
  }
  ExceptionList = local_c;
  return;
}

