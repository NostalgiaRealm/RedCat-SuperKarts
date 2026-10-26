/*
 * FUN_004c1b15 at 004c1b15
 * undefined FUN_004c1b15(void)
 * Address ranges: 004c1b15-004c1baf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c1b15(undefined8 *param_1,int param_2,int param_3,undefined4 param_4)

{
  char *pcVar1;
  char *pcVar2;
  
  DAT_006b6764 = (int *)FUN_004c947d(*param_1);
  DAT_006b676c = DAT_006b6764[1] + -1;
  pcVar1 = (char *)((uint)(*DAT_006b6764 == 0x2d) + param_2);
  FUN_004c9406(pcVar1,param_3,DAT_006b6764);
  DAT_006b6770 = DAT_006b676c < DAT_006b6764[1] + -1;
  DAT_006b676c = DAT_006b6764[1] + -1;
  if ((DAT_006b676c < -4) || (param_3 <= DAT_006b676c)) {
    FUN_004c1bb0(param_1,param_2,param_3,param_4);
  }
  else {
    if ((bool)DAT_006b6770) {
      do {
        pcVar2 = pcVar1;
        pcVar1 = pcVar2 + 1;
      } while (*pcVar2 != '\0');
      pcVar2[-1] = '\0';
    }
    FUN_004c1bd7(param_1,param_2,param_3);
  }
  return;
}

