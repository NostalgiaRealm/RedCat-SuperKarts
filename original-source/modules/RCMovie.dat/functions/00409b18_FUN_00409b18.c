/*
 * FUN_00409b18 at 00409b18
 * int __cdecl FUN_00409b18(int * param_1, int param_2, DWORD param_3)
 * Address ranges: 00409b18-00409cb1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00409b18(int *param_1,int param_2,DWORD param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    FUN_0040187a((byte *)s__s__d____null_ptr_assignment___00431100);
  }
  if (DAT_0043d468 == 0) {
    iVar1 = FUN_0041fd07(param_1,param_2,param_3);
  }
  else {
    iVar1 = FUN_00427d94((int)param_1);
    iVar2 = FUN_00427d94((int)DAT_0043d458);
    if (iVar1 == iVar2) {
      if (param_3 == 0) {
        if ((DAT_0043d450 < DAT_0043d464 + param_2) || (DAT_0043d464 + param_2 < DAT_0043d464)) {
          FUN_0040187a((byte *)s__s__d____fseeking_past_end_or_be_0043112c);
          iVar1 = 0x3e9;
        }
        else {
          iVar1 = FUN_0041fd07(DAT_0043d458,DAT_0043d464 + param_2,0);
        }
      }
      else if (param_3 == 1) {
        iVar1 = FUN_0041fd07(DAT_0043d458,DAT_0043d464 + param_2,0);
      }
      else if (param_3 == 2) {
        if (DAT_0043d450 < DAT_0043d450 + param_2) {
          FUN_0040187a((byte *)s__s__d____fseeking_past_end_file__00431168);
          iVar1 = 0x3e9;
        }
        else {
          iVar1 = FUN_0041fd07(DAT_0043d458,DAT_0043d450 + param_2,0);
        }
      }
      else {
        FUN_0040187a((byte *)s__s__d____illegal_fseek_cmd__004311a0);
        iVar1 = 0x3e9;
      }
    }
    else {
      iVar1 = FUN_0041fd07(param_1,param_2,param_3);
    }
  }
  return iVar1;
}

