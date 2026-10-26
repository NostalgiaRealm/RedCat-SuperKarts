/*
 * FUN_00408e95 at 00408e95
 * undefined4 __cdecl FUN_00408e95(undefined4 * param_1, undefined4 * param_2, undefined4 * param_3)
 * Address ranges: 00408e95-00408f0f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00408e95(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  FUN_00409770(&local_14);
  if (DAT_0043d43c != 0) {
    local_8 = (**(code **)(*DAT_0043d408 + 0x1c))(DAT_0043d408,&local_14);
    if (local_8 != 0) {
      FUN_00405af0(local_8);
      FUN_0040187a((byte *)s__s__d____error_get_listener_posi_00430a7c);
    }
    *param_1 = local_14;
    *param_2 = local_10;
    *param_3 = local_c;
  }
  return 0;
}

