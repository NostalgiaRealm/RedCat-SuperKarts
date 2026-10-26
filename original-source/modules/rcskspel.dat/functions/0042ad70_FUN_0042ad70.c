/*
 * FUN_0042ad70 at 0042ad70
 * undefined FUN_0042ad70(void)
 * Address ranges: 0042ad70-0042af0c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0042adc9) */
/* WARNING: Removing unreachable block (ram,0x0042add0) */
/* WARNING: Removing unreachable block (ram,0x0042add4) */
/* WARNING: Removing unreachable block (ram,0x0042add8) */

void FUN_0042ad70(void)

{
  char cVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *local_30;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cd008;
  pvStack_c = ExceptionList;
  uVar2 = 0xffffffff;
  local_30 = (undefined4 *)0x0;
  pcVar5 = (char *)&DAT_004e8db0;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  puVar3 = (undefined1 *)(~uVar2 - 1);
  ExceptionList = &pvStack_c;
  if ((undefined1 *)0xfffffffd < puVar3) {
    ExceptionList = &pvStack_c;
    FUN_004bc15b();
  }
  if (puVar3 == (undefined1 *)0x0) {
    FUN_0040b4f0(1);
  }
  else {
    if (puVar3 != (undefined1 *)0x0) {
      FUN_0040b4f0(1);
      FUN_0040b720(puVar3);
    }
    puVar4 = &DAT_004e8db0;
    for (uVar2 = (uint)puVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *local_30 = *puVar4;
      puVar4 = puVar4 + 1;
      local_30 = local_30 + 1;
    }
    for (uVar2 = (uint)puVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)local_30 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      local_30 = (undefined4 *)((int)local_30 + 1);
    }
    *puVar3 = 0;
  }
  uStack_4 = 0xffffffff;
  FUN_004513c0();
  FUN_00451810();
  FUN_0042ac60();
  FUN_0042b840();
  FUN_0042c170();
  FUN_0042bbf0();
  FUN_0042c0a0();
  FUN_0042c170();
  FUN_0042c230();
  FUN_0042c320();
  FUN_0042bb10();
  FUN_0042bb40();
  FUN_0042bb70();
  FUN_0042bba0();
  FUN_0042bae0();
  FUN_0042bab0();
  FUN_0042b960();
  FUN_0042b930();
  FUN_0042b900();
  FUN_0042b870();
  FUN_0042b810();
  FUN_0042b7b0();
  FUN_0042b7e0();
  FUN_0042b680();
  FUN_0042b610();
  FUN_0042b490();
  FUN_0042b220();
  FUN_0042b340();
  FUN_0042b000();
  FUN_0042b030();
  FUN_0042b1f0();
  FUN_0042afd0();
  FUN_0042afa0();
  FUN_0042af40();
  FUN_0042af70();
  FUN_0042b060();
  FUN_0042af10();
  ExceptionList = pvStack_c;
  return;
}

