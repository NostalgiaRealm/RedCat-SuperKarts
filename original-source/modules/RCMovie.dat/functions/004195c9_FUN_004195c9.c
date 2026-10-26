/*
 * FUN_004195c9 at 004195c9
 * undefined __cdecl FUN_004195c9(int * param_1, int * param_2)
 * Address ranges: 004195c9-00419653
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004195c9(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  
  if (*(int *)(param_1[3] + 0x90) == 0) {
    FUN_0040187a((byte *)s__s__d_____show_edit_string__tryi_00435fb4);
  }
  FUN_004194cd(param_1,param_2);
  pbVar4 = &DAT_0043600c;
  iVar1 = param_2[1] + param_1[0xc] * param_1[0x11];
  iVar3 = *param_2;
  iVar2 = FUN_00412061();
  FUN_0041635e(iVar2,iVar3,iVar1,pbVar4);
  FUN_00419275((int)param_1,param_2);
  return;
}

