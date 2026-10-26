/*
 * FUN_004065df at 004065df
 * undefined8 __fastcall FUN_004065df(undefined4 param_1, undefined4 param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10, char param_11)
 * Address ranges: 004065df-0040661c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall
FUN_004065df(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10,char param_11)

{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = (char *)(param_3 + param_9);
  pcVar3 = (char *)(param_5 + param_10);
  iVar2 = param_7;
  do {
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      if (cVar1 != param_11) {
        *pcVar4 = cVar1;
      }
      pcVar4 = pcVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    pcVar4 = pcVar4 + param_4;
    pcVar3 = pcVar3 + param_6;
    param_8 = param_8 + -1;
    iVar2 = param_7;
  } while (param_8 != 0);
  return CONCAT44(param_2,in_EAX);
}

