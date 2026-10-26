/*
 * FUN_00427bc0 at 00427bc0
 * undefined FUN_00427bc0(void)
 * Address ranges: 00427bc0-00427c3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00427bc0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_4;
  
  local_4 = 0;
  do {
    iVar6 = 0;
    puVar4 = &DAT_0052d5a0;
    do {
      iVar1 = FUN_004274f0(local_4);
      iVar2 = FUN_00427520(iVar6);
      puVar5 = puVar4 + 8;
      iVar6 = iVar6 + 1;
      puVar7 = (undefined4 *)(&DAT_0052d6d8 + iVar1 * 0x134 + iVar2 * 0x20);
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar4 = puVar5;
    } while ((int)puVar5 < 0x52d660);
    iVar6 = FUN_004274f0(local_4);
    local_4 = local_4 + 1;
    *(undefined4 *)(&DAT_0052d7c8 + iVar6 * 0x134) = 0;
  } while (local_4 < 100);
  return;
}

