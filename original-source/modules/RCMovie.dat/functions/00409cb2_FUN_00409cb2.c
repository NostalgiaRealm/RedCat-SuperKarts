/*
 * FUN_00409cb2 at 00409cb2
 * DWORD __cdecl FUN_00409cb2(int param_1)
 * Address ranges: 00409cb2-00409d68
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

DWORD __cdecl FUN_00409cb2(int param_1)

{
  uint uVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    FUN_0040187a((byte *)s__s__d____null_ptr_assignment___004311cc);
  }
  if (DAT_0043d468 == 0) {
    uVar1 = FUN_00427d94(param_1);
    DVar2 = FUN_00427d1c(uVar1);
  }
  else {
    iVar3 = FUN_00427d94(param_1);
    iVar4 = FUN_00427d94(DAT_0043d458);
    if (iVar3 == iVar4) {
      if (DAT_0043d468 == 0) {
        FUN_0040187a((byte *)s__s__d____attempt_at_reading_unop_004311f8);
      }
      DVar2 = DAT_0043d450 - DAT_0043d464;
    }
    else {
      uVar1 = FUN_00427d94(param_1);
      DVar2 = FUN_00427d1c(uVar1);
    }
  }
  return DVar2;
}

