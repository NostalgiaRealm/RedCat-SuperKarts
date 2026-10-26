/*
 * FUN_004bc7cd at 004bc7cd
 * undefined FUN_004bc7cd(void)
 * Address ranges: 004bc7cd-004bc7eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_004bc7cd(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_004be1ce();
  *param_1 = uVar1;
  if (*(int *)(DAT_006b6690 + 4) != -1) {
    *(int *)(DAT_006b6690 + 4) = *(int *)(DAT_006b6690 + 4) + 1;
  }
  return param_1;
}

