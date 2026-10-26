/*
 * FUN_004a3c50 at 004a3c50
 * undefined FUN_004a3c50(void)
 * Address ranges: 004a3c50-004a3d8e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_004a3c50(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 uStack_84;
  char local_80 [15];
  undefined1 local_71;
  
  _strncpy(local_80,param_1,0xe);
  local_71 = 0;
  pcVar2 = _strstr(local_80,&DAT_004fcacc);
  if (pcVar2 != (char *)0x0) {
    *pcVar2 = '\0';
  }
  if (DAT_006a5edc == 0) {
    uVar4 = 0xffffffff;
    pcVar2 = (char *)&DAT_004f6c28;
    do {
      pcVar8 = pcVar2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar5 = -1;
    pcVar2 = local_80;
    do {
      pcVar7 = pcVar2;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    pcVar2 = pcVar8 + -uVar4;
    pcVar8 = pcVar7 + -1;
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar8 = pcVar8 + 1;
    }
    uVar3 = FUN_004b3080(local_80,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  if (DAT_006a5edc != 1) {
    FUN_004afee0(s__s__d____Unknown_texture_source_t_004fc9fc,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0x114,DAT_006a5edc);
    return uStack_84;
  }
  uVar4 = 0xffffffff;
  pcVar2 = &DAT_004f6c30;
  do {
    pcVar8 = pcVar2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar5 = -1;
  pcVar2 = local_80;
  do {
    pcVar7 = pcVar2;
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pcVar7 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar7;
  } while (cVar1 != '\0');
  pcVar2 = pcVar8 + -uVar4;
  pcVar8 = pcVar7 + -1;
  for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar3 = FUN_004ac010(local_80,param_2,param_3,param_4,param_5);
  return uVar3;
}

