/*
 * FUN_00409752 at 00409752
 * undefined4 __fastcall FUN_00409752(undefined4 param_1, char * param_2)
 * Address ranges: 00409752-0040976c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_00409752(undefined4 param_1,char *param_2)

{
  int in_EAX;
  undefined4 extraout_ECX;
  char *pcVar1;
  int unaff_EBX;
  
  pcVar1 = param_2;
  if ((unaff_EBX == 10) && (in_EAX < 0)) {
    *param_2 = '-';
    pcVar1 = param_2 + 1;
  }
  FUN_00409708(param_2,pcVar1);
  return extraout_ECX;
}

