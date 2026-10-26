/*
 * FUN_00409214 at 00409214
 * undefined __fastcall FUN_00409214(undefined4 param_1)
 * Address ranges: 00409214-00409264
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00409214(undefined4 param_1)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x44))(DAT_0043d408,param_1), iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_set_listener_orie_00430bfc);
  }
  return;
}

