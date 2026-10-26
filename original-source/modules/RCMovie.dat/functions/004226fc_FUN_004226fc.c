/*
 * FUN_004226fc at 004226fc
 * char * __cdecl FUN_004226fc(undefined4 param_1, char * param_2, size_t param_3)
 * Address ranges: 004226fc-004227d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * __cdecl FUN_004226fc(undefined4 param_1,char *param_2,size_t param_3)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  
  piVar1 = DAT_0043e448;
  if (DAT_0043e44c == '\0') {
    piVar1 = (int *)FUN_00425b11();
    FUN_00425a9a(param_2 + (*piVar1 == 0x2d),piVar1[1] + param_3,(int)piVar1);
  }
  else if (DAT_0043e450 == param_3) {
    iVar2 = (*DAT_0043e448 == 0x2d) + DAT_0043e450;
    param_2[iVar2] = '0';
    (param_2 + iVar2)[1] = '\0';
  }
  pcVar3 = param_2;
  if (*piVar1 == 0x2d) {
    *param_2 = '-';
    pcVar3 = param_2 + 1;
  }
  if (piVar1[1] < 1) {
    FUN_00422910(pcVar3,1);
    *pcVar3 = '0';
    pcVar3 = pcVar3 + 1;
  }
  else {
    pcVar3 = pcVar3 + piVar1[1];
  }
  if (0 < (int)param_3) {
    FUN_00422910(pcVar3,1);
    *pcVar3 = DAT_00437470;
    iVar2 = piVar1[1];
    if (iVar2 < 0) {
      if ((DAT_0043e44c != '\0') || (-iVar2 <= (int)param_3)) {
        param_3 = -iVar2;
      }
      FUN_00422910(pcVar3 + 1,param_3);
      _memset(pcVar3 + 1,0x30,param_3);
    }
  }
  return param_2;
}

