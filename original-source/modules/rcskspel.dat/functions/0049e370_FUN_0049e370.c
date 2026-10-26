/*
 * FUN_0049e370 at 0049e370
 * undefined FUN_0049e370(void)
 * Address ranges: 0049e370-0049e488
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0049e370(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  uint local_108;
  char local_100 [256];
  
  iVar3 = -1;
  pcVar6 = param_1;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  local_108 = 0;
  pcVar6 = param_1;
  if (iVar3 == -2) {
    return 0;
  }
  do {
    pcVar2 = _strchr(pcVar6,0x7c);
    if (pcVar2 == (char *)0x0) {
      uVar4 = 0xffffffff;
      do {
        pcVar7 = pcVar6;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar6 = pcVar7 + -uVar4;
      pcVar7 = local_100;
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
    }
    else {
      _strncpy(local_100,pcVar6,(int)pcVar2 - (int)pcVar6);
      local_100[(int)pcVar2 - (int)pcVar6] = '\0';
    }
    uVar4 = FUN_0049e2f0(local_100);
    if (uVar4 == 0) {
      FUN_0049df30();
      FUN_004afee0(s__s___d__Sample_group__s_not_foun_004fc350,
                   s_D__work_rcracer_oursoundlib_soun_004fc23c,0x10c,local_100);
    }
    local_108 = local_108 | uVar4;
    if (pcVar2 == (char *)0x0) {
LAB_0049e432:
      uVar4 = 0xffffffff;
      pcVar6 = param_1;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      pcVar6 = param_1 + (~uVar4 - 1);
    }
    else {
      uVar4 = 0xffffffff;
      pcVar6 = pcVar2;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      if (~uVar4 - 1 < 2) goto LAB_0049e432;
      pcVar6 = pcVar2 + 1;
    }
    iVar3 = -1;
    pcVar2 = pcVar6;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (iVar3 == -2) {
      return local_108;
    }
  } while( true );
}

