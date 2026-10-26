/*
 * FUN_004c0025 at 004c0025
 * undefined FUN_004c0025(void)
 * Address ranges: 004c0025-004c00b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c0025(char *param_1,char *param_2,char *param_3,char *param_4,char *param_5)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    *param_1 = *param_2;
    param_1[1] = ':';
    param_1 = param_1 + 2;
  }
  if ((param_3 != (char *)0x0) && (cVar1 = *param_3, pcVar2 = param_3, cVar1 != '\0')) {
    do {
      pcVar3 = param_1;
      *pcVar3 = cVar1;
      cVar1 = pcVar2[1];
      param_1 = pcVar3 + 1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char *)FUN_004c6eb8(param_3,pcVar2);
    if ((*pcVar2 != '/') && (*pcVar2 != '\\')) {
      *param_1 = '\\';
      param_1 = pcVar3 + 2;
    }
  }
  if (param_4 != (char *)0x0) {
    cVar1 = *param_4;
    while (cVar1 != '\0') {
      *param_1 = cVar1;
      pcVar2 = param_4 + 1;
      param_1 = param_1 + 1;
      param_4 = param_4 + 1;
      cVar1 = *pcVar2;
    }
  }
  if (param_5 == (char *)0x0) {
    *param_1 = '\0';
  }
  else {
    if ((*param_5 != '\0') && (*param_5 != '.')) {
      *param_1 = '.';
      param_1 = param_1 + 1;
    }
    do {
      cVar1 = *param_5;
      *param_1 = cVar1;
      param_1 = param_1 + 1;
      param_5 = param_5 + 1;
    } while (cVar1 != '\0');
  }
  return;
}

