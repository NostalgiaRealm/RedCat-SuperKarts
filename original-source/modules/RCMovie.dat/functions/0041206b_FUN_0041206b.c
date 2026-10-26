/*
 * FUN_0041206b at 0041206b
 * undefined __cdecl FUN_0041206b(int param_1)
 * Address ranges: 0041206b-004120d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041206b(int param_1)

{
  if (DAT_0043d850 != 0) {
    FUN_0040187a((byte *)s_trying_to_change_the_focus_of_an_00434280);
  }
  if (param_1 == 0) {
    DAT_0043d854 = 0;
  }
  else if (param_1 == 1) {
    DAT_0043d854 = 1;
  }
  else {
    FUN_0040187a((byte *)s_trying_to_set_an_illegal_from_fo_004342d4);
  }
  return;
}

