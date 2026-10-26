/*
 * FUN_00428800 at 00428800
 * undefined FUN_00428800(void)
 * Address ranges: 00428800-0042887f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00428800(void)

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
    puVar4 = &DAT_00534f30;
    do {
      iVar1 = FUN_00427ed0(local_4);
      iVar2 = FUN_00427f00(iVar6);
      puVar5 = puVar4 + 8;
      iVar6 = iVar6 + 1;
      puVar7 = (undefined4 *)(&DAT_00535060 + iVar1 * 300 + iVar2 * 0x20);
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar4 = puVar5;
    } while ((int)puVar5 < 0x534ff0);
    iVar6 = FUN_00427ed0(local_4);
    local_4 = local_4 + 1;
    *(undefined4 *)(&DAT_00535148 + iVar6 * 300) = 0;
  } while (local_4 < 0x46);
  return;
}

