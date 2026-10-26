/*
 * FUN_004ca62f at 004ca62f
 * undefined FUN_004ca62f(void)
 * Address ranges: 004ca62f-004ca7b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004ca62f(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  LPCSTR lpName;
  int *piVar5;
  bool bVar6;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  pcVar1 = (char *)FUN_004cb4e3(param_1,0x3d);
  if (pcVar1 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == pcVar1) {
    return 0xffffffff;
  }
  bVar6 = pcVar1[1] == '\0';
  if (DAT_006b6710 == DAT_006b6714) {
    DAT_006b6710 = (int *)FUN_004ca80e(DAT_006b6710);
  }
  if (DAT_006b6710 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_006b6718 == (undefined4 *)0x0)) {
      if (bVar6) {
        return 0;
      }
      DAT_006b6710 = _malloc(4);
      if (DAT_006b6710 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_006b6710 = 0;
      if (DAT_006b6718 == (undefined4 *)0x0) {
        DAT_006b6718 = _malloc(4);
        if (DAT_006b6718 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_006b6718 = 0;
      }
    }
    else {
      iVar2 = FUN_004c8787();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_006b6710;
  iVar2 = FUN_004ca7b6(param_1,(int)pcVar1 - (int)param_1);
  if ((iVar2 < 0) || (*piVar3 == 0)) {
    if (bVar6) {
      return 0;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    piVar3 = (int *)FUN_004c1c70(piVar3,iVar2 * 4 + 8);
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar3[iVar2] = (int)param_1;
    piVar3[iVar2 + 1] = 0;
  }
  else {
    if (!bVar6) {
      piVar3[iVar2] = (int)param_1;
      goto LAB_004ca763;
    }
    piVar5 = piVar3 + iVar2;
    FUN_004bff99(piVar3[iVar2]);
    for (; *piVar5 != 0; piVar5 = piVar5 + 1) {
      iVar2 = iVar2 + 1;
      *piVar5 = piVar5[1];
    }
    piVar3 = (int *)FUN_004c1c70(piVar3,iVar2 << 2);
    if (piVar3 == (int *)0x0) goto LAB_004ca763;
  }
  DAT_006b6710 = piVar3;
LAB_004ca763:
  if (param_2 != 0) {
    sVar4 = _strlen(param_1);
    lpName = _malloc(sVar4 + 2);
    if (lpName != (LPCSTR)0x0) {
      FUN_004c51f0(lpName,param_1);
      pcVar1[(int)lpName - (int)param_1] = '\0';
      SetEnvironmentVariableA
                (lpName,(LPCSTR)(~-(uint)bVar6 & (uint)(pcVar1 + ((int)lpName - (int)param_1) + 1)))
      ;
      FUN_004bff99(lpName);
    }
  }
  return 0;
}

