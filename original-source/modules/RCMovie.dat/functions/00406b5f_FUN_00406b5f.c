/*
 * FUN_00406b5f at 00406b5f
 * uint __cdecl FUN_00406b5f(uint param_1)
 * Address ranges: 00406b5f-00406d13
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __cdecl FUN_00406b5f(uint param_1)

{
  int iVar1;
  uint local_10;
  uint local_c;
  
  local_c = (uint)(param_1 == 0);
  for (local_10 = 0; (int)local_10 < DAT_0043d414; local_10 = local_10 + 1) {
    if ((((local_10 != local_c) && (local_10 != param_1)) &&
        (iVar1 = FUN_00406327(local_10), iVar1 == 0)) &&
       (*(int *)(DAT_0043d420 + 0x38 + local_10 * 0x44) <
        *(int *)(DAT_0043d420 + 0x38 + local_c * 0x44))) {
      local_c = local_10;
    }
  }
  FUN_004015a6((byte *)s_deleting__d_0042f750);
  iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + local_c * 0x44) + 0x48))
                    (*(undefined4 *)(DAT_0043d420 + 0x28 + local_c * 0x44));
  if (iVar1 != 0) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_releasing_sound_b_0042f76c);
  }
  (**(code **)(**(int **)(DAT_0043d420 + 0x28 + local_c * 0x44) + 8))
            (*(undefined4 *)(DAT_0043d420 + 0x28 + local_c * 0x44));
  *(undefined4 *)(DAT_0043d420 + 0x30 + local_c * 0x44) = 0;
  *(undefined4 *)(DAT_0043d420 + 0x38 + local_c * 0x44) = 0;
  for (local_10 = 0; (int)local_10 < DAT_0043d414; local_10 = local_10 + 1) {
    if (((*(int *)(DAT_0043d420 + 0x38 + local_10 * 0x44) != 10000) && (local_10 != local_c)) &&
       (1 < *(int *)(DAT_0043d420 + 0x38 + local_10 * 0x44))) {
      *(int *)(DAT_0043d420 + 0x38 + local_10 * 0x44) =
           *(int *)(DAT_0043d420 + 0x38 + local_10 * 0x44) + -1;
    }
  }
  return local_c;
}

