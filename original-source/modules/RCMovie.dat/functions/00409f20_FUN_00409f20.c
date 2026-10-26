/*
 * FUN_00409f20 at 00409f20
 * undefined __cdecl FUN_00409f20(FILE * param_1)
 * Address ranges: 00409f20-00409fc4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00409f20(FILE *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (FILE *)0x0) {
    FUN_0040187a((byte *)s__s__d____null_ptr_assignment___0043134c);
  }
  else if (DAT_0043d468 == 0) {
    FUN_004015a6((byte *)s__s__d____file_close_00431378);
    FUN_0041f368(param_1);
  }
  else {
    iVar1 = FUN_00427d94((int)param_1);
    iVar2 = FUN_00427d94(DAT_0043d458);
    if (iVar1 == iVar2) {
      if (DAT_0043d468 == 0) {
        FUN_0040187a((byte *)s__s__d____unopened_resource_file_a_0043139c);
      }
    }
    else {
      FUN_0041f368(param_1);
    }
  }
  return;
}

