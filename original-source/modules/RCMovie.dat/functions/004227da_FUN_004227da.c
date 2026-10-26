/*
 * FUN_004227da at 004227da
 * undefined __cdecl FUN_004227da(undefined4 param_1, char * param_2, size_t param_3, int param_4)
 * Address ranges: 004227da-00422874
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004227da(undefined4 param_1,char *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  DAT_0043e448 = (int *)FUN_00425b11();
  DAT_0043e450 = DAT_0043e448[1] + -1;
  iVar1 = *DAT_0043e448;
  FUN_00425a9a(param_2 + (iVar1 == 0x2d),param_3,(int)DAT_0043e448);
  DAT_0043e454 = DAT_0043e450 < DAT_0043e448[1] + -1;
  DAT_0043e450 = DAT_0043e448[1] + -1;
  if ((DAT_0043e450 < -4) || ((int)param_3 <= DAT_0043e450)) {
    FUN_00422875(param_1,param_2,param_3,param_4);
  }
  else {
    pcVar2 = param_2 + (iVar1 == 0x2d);
    if ((bool)DAT_0043e454) {
      do {
        pcVar3 = pcVar2;
        pcVar2 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      pcVar3[-1] = '\0';
    }
    FUN_0042289c(param_1,param_2,param_3);
  }
  return;
}

