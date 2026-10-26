/*
 * FUN_0049dcb0 at 0049dcb0
 * undefined FUN_0049dcb0(void)
 * Address ranges: 0049dcb0-0049dd1a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0049dcb0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (*param_1 != 0) {
    iVar2 = 0;
    if (0 < param_1[1]) {
      do {
        FUN_0049f2a0(*(int *)(*param_1 + iVar2 * 4) != 0,
                     s__s___d__Trying_to_delete_a_NULL_p_004fbecc,
                     s_D__work_rcracer_oursoundlib_soun_004fbe98,0x71,iVar2);
        iVar1 = *(int *)(*param_1 + iVar2 * 4);
        if (iVar1 != 0) {
          FUN_0049d380();
          FUN_004bc150(iVar1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[1]);
    }
    FUN_004bc150(*param_1);
    *param_1 = 0;
  }
  return;
}

