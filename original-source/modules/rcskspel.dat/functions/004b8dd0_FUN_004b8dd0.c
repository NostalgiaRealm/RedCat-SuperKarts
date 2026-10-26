/*
 * FUN_004b8dd0 at 004b8dd0
 * undefined FUN_004b8dd0(void)
 * Address ranges: 004b8dd0-004b8e8d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b8dd0(undefined4 *param_1,char *param_2,char *param_3)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  iVar3 = FUN_004b8db0();
  if (iVar3 == -1) {
    FUN_004afee0(s__s__d____Unable_to_allocate_new_D_00501608,
                 s_C__libraries_dxdraw_Hwinfo_cpp_0050137c,0x122);
  }
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)(DAT_006ab8f4 + iVar3 * 0xd8);
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
    puVar1[2] = param_1[2];
    puVar1[3] = param_1[3];
  }
  uVar4 = 0xffffffff;
  do {
    pcVar6 = param_2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = param_2 + 1;
    cVar2 = *param_2;
    param_2 = pcVar6;
  } while (cVar2 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar6 + -uVar4;
  pcVar7 = (char *)(iVar3 * 0xd8 + 0x10 + DAT_006ab8f4);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  do {
    pcVar6 = param_3;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = param_3 + 1;
    cVar2 = *param_3;
    param_3 = pcVar6;
  } while (cVar2 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar6 + -uVar4;
  pcVar7 = (char *)(iVar3 * 0xd8 + 0x74 + DAT_006ab8f4);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  DAT_00501334 = iVar3;
  return;
}

