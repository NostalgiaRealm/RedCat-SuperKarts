/*
 * FUN_00412b70 at 00412b70
 * undefined4 __cdecl FUN_00412b70(int param_1)
 * Address ranges: 00412b70-00412bb7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00412b70(int param_1)

{
  if ((param_1 < 0) || (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_control_pointer__c_00434a14);
  }
  return *(undefined4 *)(DAT_0043d850 + 0xc + param_1 * 0x1c);
}

